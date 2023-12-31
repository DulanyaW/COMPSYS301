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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <project.h>
#include <stdbool.h>
#include <math.h>
#include "project.h"
#include <cytypes.h> // Include the appropriate header for your platform

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

// Define states for the state machine
typedef enum {
    GO_STRAIGHT,
    TURN_LEFT,
    TURN_RIGHT,
    RIGHT_ADJUST,
    LEFT_ADJUST,
    STOP,
} RobotState;

RobotState current_state = STOP;// intialse state

uint32 count = 0;
uint32 turn_counter = 0;
bool left_on=false;
bool right_on;
bool middle_on;
bool turn_complete;

uint8 comp0_sum;
uint8 comp1_sum;
uint8 comp2_sum;
uint8 comp3_sum;

uint8 PWM_R;
uint8 PWM_L;


CY_ISR(isr_3_handler) {
    if (counter < 20){
        counter++;
    }else{
        counter = 1;
        // Encoder counts (negative due to counterclockwise rotation)
        encoderCounts_M1 = abs(QuadDec_M1_GetCounter());//QuadDec_M1_GetCounter();
        encoderCounts_M2 = abs(QuadDec_M2_GetCounter());
        
        // sum of encodercounts
        encoder_value_sum_M1 += encoderCounts_M1;
        encoder_value_sum_M2 += encoderCounts_M2;
        
        // distance calculations 
        distance_M1 = (encoder_value_sum_M1/CPR) * wheelCircumference_cm;
        distance_M2 = (encoder_value_sum_M2/CPR) * wheelCircumference_cm;

        //reset the encoder counters 
        QuadDec_M1_SetCounter(0);
        QuadDec_M2_SetCounter(0);     
    }
        Timer_1_ReadStatusRegister();
}


CY_ISR(isr_2_handler) {
    //every 1ms 
    if(left_on==true){
        if(turn_counter==0){
            PWM_L=50;
            PWM_R=80; 
           // LED_1_Write(1);
        }
        turn_counter++;
        if(turn_counter==650){
            left_on=false;
            PWM_L=50;
            PWM_R=50;
            turn_counter=0;
            //LED_1_Write(0);
        }
        
    }
}


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
    PWM_R=50;
    PWM_L=50;
}
void turnLeft(){
    
    if(turn_complete){
       left_on=false;
    }
    
}

void goStraight(){
    //comp0==>middle left comp1==>middle right
    if(comp0_sum>0 && comp1_sum==0){//s_ML out of line
        PWM_L=PWM_L+1;
    }else if(comp0_sum==0 && comp1_sum>0){//s_MR out of line
        PWM_R=PWM_R+1;
        
    }else if(comp1_sum==0 && comp0_sum==0){
        PWM_R=80;
        PWM_L=81;
    }
     
}
void go_distance(float32 distance){
    distance_M1=0;
    target_diatance=distance;
}




int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Timer_1_Start();
    
    isr_1_StartEx(isr_1_handler);
    isr_3_StartEx(isr_3_handler);
    isr_2_StartEx(isr_2_handler);
    
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
    
    QuadDec_M1_Start();
    QuadDec_M2_Start();
    
    go_distance(100);
    
    for(;;)
    {
          //comp0 and comp1 =0  => straight
           //comp2=0 => left
           //comp3=0 => right
           /* Place your application code here. */
         if(comp1_sum==0 && comp0_sum==0){
                current_state = GO_STRAIGHT;
        }else if(comp2_sum == 0) {
                current_state = TURN_LEFT;
        }else if(comp3_sum==0){
                current_state = TURN_RIGHT;
        }else if(comp0_sum>0 && comp1_sum>0 && comp2_sum>0 && comp3_sum>0){
                current_state = STOP;
        }
        else if(comp0_sum>0 && comp1_sum==0){//s_ML out of line
                current_state = LEFT_ADJUST;
        }else if(comp0_sum==0 && comp1_sum>0){//s_MR out of line
                current_state = RIGHT_ADJUST;
        }
     
        switch (current_state) {
            case GO_STRAIGHT:
                PWM_R=86;
                PWM_L=87; 
                break;
            case TURN_LEFT:
                PWM_L=0; 
                PWM_R=90;
                break;    
            case TURN_RIGHT:
                PWM_L=87;
                PWM_R=0; 
                break;  
            case STOP:
                PWM_R=50;
                PWM_L=50; 
                break;
            case LEFT_ADJUST:
                PWM_L=PWM_L+1; 
                break; 
            case RIGHT_ADJUST:
                PWM_R=PWM_R+1;
                break; 
        }
        
//            if(comp2_sum==0){
//                //left_on=true;
//                PWM_R=71;
//                PWM_L=10;  
//            }else if(comp3_sum==0){
//                PWM_R=0;
//                PWM_L=86;  
//            }else if(comp0_sum>0 && comp1_sum==0){//s_ML out of line
//                PWM_L=PWM_L+1;
//            }else if(comp0_sum==0 && comp1_sum>0){//s_MR out of line
//                PWM_R=PWM_R+1;    
//            }else if(comp1_sum==0 && comp0_sum==0){//both sensors on the line
//                PWM_R=80;
//                PWM_L=81;
//            }else if(comp0_sum>0 && comp1_sum>0 && comp2_sum>0 && comp3_sum>0){
//                PWM_R=50;
//                PWM_L=50;
//            }
        

            if(distance_M1>=target_diatance && target_diatance!=0){
                LED_1_Write(1);
                stop();
            }

        //PWM1 right wheel
          PWM_1_WriteCompare(PWM_R);
        //PWM2 corresponds to left wheel
          PWM_2_WriteCompare(PWM_L);
              

    }
}


/* [] END OF FILE */
