/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
/* ========================================
 * Fully working code: 
 * PWM      : 
 * Encoder  : 
 * ADC      :
 * USB      : port displays speed and position.
 * CMD: "PW xx"
 * Copyright Univ of Auckland, 2016
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF Univ of Auckland.
 *
 * ========================================
*/
//WORKS 90% of the time
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <project.h>
#include <stdbool.h>
#include <math.h>
#include <cytypes.h> 
#include "Astar.h"

//distance calculation paras
int32 encoderCounts_M1 = 0;  
int32 encoderCounts_M2 = 0;  
int32 CPR = 228;  // Adjusted for 4x resolution(228/4)
float wheelCircumference_cm = (M_PI*64.46)/10;// wheel circumference wheelDiameter_mm = 64.46)
double timeInterval_s = 10.924;  // Effective time interval( (timer period )2.731*4)
float32  distance_M1 = 0;
float32  distance_M2 = 0;
float32  current_distance_M1 = 0;
float32  current_distance_M2 = 0;
float32 target_diatance = 0;//cm
float32 speed_M1 = 0;
float32 speed_M2 = 0;
int32 encoder_value_sum_M1 = 0;
int32 encoder_value_sum_M2 = 0;
uint8 counter = 1;

//define wheel speeds
#define PWM_PERIOD 100
#define PWM_STRAIGHT_L 131
#define PWM_STRAIGHT_R 130
#define PWM_STOP 100

// Define states for the state machine
typedef enum {
    GO_STRAIGHT,
    TURN_LEFT,
    TURN_RIGHT,
    STOP
} RobotState;

RobotState current_state = STOP;// intialse state

uint32 count = 0;
bool isTurning=false;

uint8 comp0_sum;
uint8 comp1_sum;
uint8 comp2_sum;
uint8 comp3_sum;

CY_ISR(isr_1_handler) {
        //every 1ms 
    
    //sum up comp values every 1ms
    comp0_sum+=Comp_0_GetCompare();
    comp1_sum+=Comp_1_GetCompare();
    comp2_sum+=Comp_2_GetCompare();
    comp3_sum+=Comp_3_GetCompare();
      
    if(count==8){
        //reset to check again every 8ms
        comp0_sum=0;
        comp1_sum=0;
        comp2_sum=0;
        comp3_sum=0;
        count=0;
    }
   
    count++;
    Timer_1_ReadStatusRegister();
}

void stop(){
    PWM_1_WriteCompare(50);
    PWM_2_WriteCompare(50);
}

void turnLeft(){
    PWM_1_WriteCompare(70);
    PWM_2_WriteCompare(35);
//    CyDelay(350);
    while(Sout_L_Read()==0){//wait while left is on line
       ;;
    }
    while(!(Sout_M1_Read()==0 &&Sout_M1_Read()==0)){//wait while middle sensors off line
       ;;
    }
    isTurning=false;
    PWM_1_WriteCompare(65);
    PWM_2_WriteCompare(66);

    
}
void turnRight(){
    PWM_1_WriteCompare(35);
    PWM_2_WriteCompare(70);
    while(Sout_R_Read()==0){//wait while left is on line
       ;;
    }
    while(!(Sout_M1_Read()==0 &&Sout_M1_Read()==0)){//wait while middle sensors off line
       ;;
    }
    isTurning=false;
    PWM_1_WriteCompare(65);
    PWM_2_WriteCompare(66);
}
    


void goStraight(){
        //comp0==>middle left comp1==>middle right
    if(comp0_sum>0 && comp1_sum==0){//s_ML out of line
        PWM_2_WriteCompare(PWM_2_ReadCompare() +1);
    }else if(comp0_sum==0 && comp1_sum>0){//s_MR out of line
        PWM_1_WriteCompare(PWM_1_ReadCompare() +1);
        
    }else if(comp1_sum==0 && comp0_sum==0){
        PWM_1_WriteCompare(65);
        PWM_2_WriteCompare(66);
    }
    
    
}




int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Timer_1_Start();
    
    isr_1_StartEx(isr_1_handler);
    
    //start comparators
    Comp_0_Start();
    Comp_1_Start();
    Comp_2_Start();
    Comp_3_Start();
    
    /*Start PWM Clk*/
    Clock_PWM_Start(); 
    //Start PWM
    PWM_1_Start();
    PWM_2_Start();
     
    // write comparision int for MC33926 duty cycle must me larger than 10% and less than 90%

    
    PWM_1_WritePeriod(100);
    PWM_2_WritePeriod(100);
    
    PWM_1_WriteCompare(50);
    PWM_2_WriteCompare(50);
    QuadDec_M1_Start();
    QuadDec_M2_Start();
    
    
//**********************************calculate path    
//    int startX = 0, startY = 0;
//    int targetX = 4, targetY = 4;
//
//    Node* endNode = AStar(startX, startY, targetX, targetY);
//
//    // Print the path
//    printPath(endNode);
//**************************************************    
    QuadDec_M1_SetCounter(0);
    
    for(;;)
    {
          //comp0 and comp1 =0  => straight
           //comp2=0 => left
           //comp3=0 => right
           /* Place your application code here. */
        
//        if(abs(QuadDec_M1_GetCounter()>860)){
//            stop();
//            break;
//        }


       
        if(!isTurning ){//if not turning check the sensors
            if(Sout_M1_Read()==0 || Sout_M2_Read()==0){
                    current_state = GO_STRAIGHT;
            }else if(Sout_L_Read()==0) {//left on
                    current_state = TURN_LEFT;
                    isTurning=true;
            }else if(Sout_R_Read()==0){//right on
                    current_state = TURN_RIGHT;
                    isTurning=true;
            }else {
                    current_state = STOP;
            }
        }
        
        

        
        switch (current_state) {
            case GO_STRAIGHT:
                goStraight();
                break;
            case TURN_LEFT:
                turnLeft();
                break;    
            case TURN_RIGHT:
                turnRight();
                break;  
            case STOP:
                stop();
                break;
        }
             

    }
}

///* [] END OF FILE */
