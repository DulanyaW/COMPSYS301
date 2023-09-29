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

#include <cytypes.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <project.h>
#include <stdbool.h>
#include <math.h>
#define TURN_ANGLE 90 // Desired turn angle in degrees


// Define states for the state machine
typedef enum {
    GO_STRAIGHT,
    TURN_LEFT,
    TURN_RIGHT,
//    RIGHT_ADJUST,
//    LEFT_ADJUST,
    STOP,
} RobotState;

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
float32 turn_back_diatance = 10.125;//cm

float32 speed_M1 = 0;
float32 speed_M2 = 0;
int32 encoder_value_sum_M1 = 0;
int32 encoder_value_sum_M2 = 0;
uint8 counter = 1;
float current_distance = 0;

uint32 turnStartTime = 0;       // Time when the turn started
uint32 turnDuration = 400;      // in milliseconds
bool isTurning = false;         // Flag to indicate whether the robot is turning


uint32 count = 0;
uint8 comp0_sum;
uint8 comp1_sum;
uint8 comp2_sum;
uint8 comp3_sum;



RobotState current_state = GO_STRAIGHT;// intialse state
CY_ISR(isr_3_handler) {
    if (counter < 10){
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

void goStraight(){
    //comp0==>middle left comp1==>middle right
    if(comp0_sum>0 && comp1_sum==0){//s_ML out of line
        
        PWM_2_WriteCompare(PWM_2_ReadCompare()+1);//increase left wheel speed
        
    }else if(comp0_sum==0 && comp1_sum>0){//s_MR out of line
        
        PWM_1_WriteCompare(PWM_1_ReadCompare()+1);//increase right wheel speed
        
    }else {
        
        PWM_1_WriteCompare(70);
        PWM_2_WriteCompare(71);
        
    }
    
     
}

void turnRight(){
    PWM_1_WriteCompare(30);
    PWM_2_WriteCompare(70);
    turnStartTime = Timer_1_ReadCounter(); // Record the start time
    isTurning = true; // Set the turning flag

}
void turnLeft(){
   
    PWM_1_WriteCompare(70);
    PWM_2_WriteCompare(30);
    turnStartTime = Timer_1_ReadCounter(); // Record the start time
    isTurning = true; // Set the turning flag
 
}

void go_distance(float32 distance){
    distance_M1=0;
    goStraight();
    target_diatance=distance;
}




int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Timer_1_Start();
    
    isr_1_StartEx(isr_1_handler);
    isr_3_StartEx(isr_3_handler);
  
    
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
    
    //go_distance(0);
    
    for(;;)
    {
          //comp0 and comp1 =0  => straight
           //comp2=0 => left
           //comp3=0 => right
           /* Place your application code here. */
        
        if(isTurning) {
            // Calculate the elapsed time since the turn started
            uint32 currentTime = Timer_1_ReadCounter();
            uint32 elapsedTime = currentTime - turnStartTime;

            // Check if the turn duration has elapsed
            if (elapsedTime >= turnDuration) {
                // Stop the turn
                stop();
                isTurning = false; // Reset the turning flag
            }
        }else{
        
            if((comp2_sum>0 && comp3_sum>0)==1){//left & right sensor on white light
                goStraight();
            }
      
            if((comp2_sum==0 && comp3_sum>0)==1){//left sensor on black line
                turnLeft();
            }
            if((comp3_sum==0 && comp2_sum>0)==1){//right sensor on black line
                turnRight();
            }
            if((comp3_sum==0 && comp2_sum==0)==1){//right and left sensors on black line
                stop();
            }
        }
    }
}

      
        

/* [] END OF FILE */