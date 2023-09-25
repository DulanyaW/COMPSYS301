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
#define TURN_ANGLE 90 // Desired turn angle in degrees


// Define states for the state machine
typedef enum {
    GO_STRAIGHT,
    TURN_LEFT,
    TURN_RIGHT,
    RIGHT_ADJUST,
    LEFT_ADJUST,
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
int32 prev_encoder_value_M1 = 0;
int32 prev_encoder_value_M2 = 0;
bool turn_start = false;

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

uint8 PWM_R=80;
uint8 PWM_L=81;

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
        encoder_value_sum_M1 += encoderCounts_M1 - prev_encoder_value_M1;
        encoder_value_sum_M2 += encoderCounts_M2 - prev_encoder_value_M2;
        
        current_distance_M1 = ((encoderCounts_M1 - prev_encoder_value_M1)/CPR)*wheelCircumference_cm;
        
        // distance calculations 
        distance_M1 = (encoder_value_sum_M1/CPR) * wheelCircumference_cm;
        distance_M2 = (encoder_value_sum_M2/CPR) * wheelCircumference_cm;

        
        //update prev encoder value
        prev_encoder_value_M1 = encoderCounts_M1;
        prev_encoder_value_M2 = encoderCounts_M2;
        
        
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

    
    for(;;)
    {
          //comp0 and comp1 =0  => straight
           //comp2=0 => left
           //comp3=0 => right
        if(turn_start== false){
            if(comp1_sum==0 && comp0_sum==0){
                    current_state = GO_STRAIGHT;
            }else if(comp2_sum == 0) {
                    QuadDec_M1_SetCounter(0);
                    distance_M1 =0 ; // Reset the distance traveled
                    turn_start= true;
                    current_state = TURN_LEFT;
            }else if(comp3_sum==0){
                    QuadDec_M2_SetCounter(0);
                    distance_M2 =0 ; // Reset the distance traveled
                    current_state = TURN_RIGHT;
            }else if(comp0_sum>0 && comp1_sum>0 && comp2_sum>0 && comp3_sum>0){
                    current_state = STOP;
            }else if(comp0_sum>0 && comp1_sum==0){//s_ML out of line
                    current_state = LEFT_ADJUST;
            }else if(comp0_sum==0 && comp1_sum>0){//s_MR out of line
                    current_state = RIGHT_ADJUST;
            }
        }
            
            
//            if(distance_M1>=(target_diatance/1.03) && target_diatance!=0){
//                LED_1_Write(1);
//                current_state = STOP;
//            }
           

//          PWM_1_WriteCompare(PWM_R);
//          PWM_2_WriteCompare(PWM_L);
     
        switch (current_state) {
            case GO_STRAIGHT:
                PWM_1_WriteCompare(80);
                PWM_2_WriteCompare(81);
                break;
            case TURN_LEFT:
//                while ( comp0_sum==0 || comp1_sum==0 ) {//turn_complete = true;
                    if (((abs(QuadDec_M1_GetCounter())*(360/228))>= 90) ) {//|| (distance_M1 >= 40)
                            //current_state = GO_STRAIGHT;
                            turn_start = false;
                    }else {
//                        while ( comp0_sum==0||comp1_sum==0 ){
                           PWM_1_WriteCompare(87);
                           PWM_2_WriteCompare(10);
//                        }
                    } 
//                }
                break;    
            case TURN_RIGHT:
//                while ( comp0_sum==0 || comp1_sum==0 ) {//turn_complete = true;
//                    if (((abs(QuadDec_M2_GetCounter())*(360/228))>= 90) || (distance_M2 >= 40)) {
//                            current_state = GO_STRAIGHT;
//                    }else {
//                        while ( comp0_sum==0||comp1_sum==0 ){
//                           PWM_1_WriteCompare(0);
//                           PWM_2_WriteCompare(87);
//                        }
//                    } 
//                }
                break;  
            
            case RIGHT_ADJUST:
                PWM_R = PWM_1_ReadCompare();
                PWM_1_WriteCompare(PWM_R+1);
//                PWM_R = PWM_1_ReadCompare();
//                PWM_1_WriteCompare(PWM_R+1);
                break; 
                
                
            case LEFT_ADJUST:
                PWM_L = PWM_2_ReadCompare();
                PWM_2_WriteCompare(PWM_L+1);//2+,1-
//                PWM_R = PWM_1_ReadCompare();
//                PWM_1_WriteCompare(PWM_R-1);
//                
                break; 
            case STOP:
                PWM_1_WriteCompare(50);
                PWM_2_WriteCompare(50);
                break;
        }
    }
}


/* [] END OF FILE */
