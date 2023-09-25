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
#define TARGET_ANGLE 90  // 90-degree right turn

//PW2 - left wheel
//PW1 - right wheel
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
<<<<<<< HEAD
float32 target_diatance = 100;//cm
float32 turn_left_diatance = 5.06;//(90/360) * wheelCircumference_cm
float32 turn_back_diatance = 2.53;//cm
=======
float32 target_diatance = 0;//cm
float32 turn_back_diatance = 10.125;//cm
>>>>>>> 551c227b3e607c945d0813acebd402305acd8153

float32 speed_M1 = 0;
float32 speed_M2 = 0;
int32 encoder_value_sum_M1 = 0;
int32 encoder_value_sum_M2 = 0;
uint8 counter = 1;
float current_distance = 0;
int32 current_Encod_Count_M1 = 0;
int32 current_Encod_Count_M2 = 0;


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
<<<<<<< HEAD
        encoder_value_sum_M1 += encoderCounts_M1 - prev_encoder_value_M1;
        encoder_value_sum_M2 += encoderCounts_M2 - prev_encoder_value_M2;
=======
        encoder_value_sum_M1 += encoderCounts_M1;
        encoder_value_sum_M2 += encoderCounts_M2;
>>>>>>> 551c227b3e607c945d0813acebd402305acd8153
        
        // distance calculations 
        distance_M1 = (encoder_value_sum_M1/CPR) * wheelCircumference_cm;
        distance_M2 = (encoder_value_sum_M2/CPR) * wheelCircumference_cm;

<<<<<<< HEAD
        //update prev encoder value
        prev_encoder_value_M1 = encoderCounts_M1;
        prev_encoder_value_M2 = encoderCounts_M2;
        
//      //reset the encoder counters 
//        QuadDec_M1_SetCounter(0);
//        QuadDec_M2_SetCounter(0);     
=======
        //reset the encoder counters 
        QuadDec_M1_SetCounter(0);
        QuadDec_M2_SetCounter(0);     
>>>>>>> 551c227b3e607c945d0813acebd402305acd8153
    }
        Timer_1_ReadStatusRegister();
}


CY_ISR(isr_2_handler) {
    //every 1ms 
<<<<<<< HEAD
    if(turn_counter==400){
         PWM_L=30;
        PWM_R=70; 
    }
    if(turn_counter==950){
        PWM_L=50;
        PWM_R=50;
    }
    
    turn_counter++;   
=======
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
>>>>>>> 551c227b3e607c945d0813acebd402305acd8153
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

//void stop(){
//    PWM_R=50;
//    PWM_L=50;
//}
//void turnLeft(){
//    
//    if(turn_complete){
//       left_on=false;
//    }
//    
//}
//
//void goStraight(){
////    comp0==>middle left comp1==>middle right
//    if(comp0_sum>0 && comp1_sum==0){//s_ML out of line
//        PWM_L=PWM_L+1;
//    }else if(comp0_sum==0 && comp1_sum>0){//s_MR out of line
//        PWM_R=PWM_R+1;
//        
//    }else 
//    if(comp1_sum==0 && comp0_sum==0){
//        PWM_R=80;
//        PWM_L=81;
//    }
//     
//}
//void go_distance(float32 distance){
//    distance_M1=0;
//    target_diatance=distance;
//}

//int tagertAngleEnCount (angle){
//    return ((CPR * angle)/360);
//}


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Timer_1_Start();
    
    isr_1_StartEx(isr_1_handler);
//    isr_3_StartEx(isr_3_handler);
//    isr_2_StartEx(isr_2_handler);
    
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
        
        
        
         if(distance_M1>= 4){
                LED_1_Write(1);
                PWM_1_WriteCompare(50);
                PWM_2_WriteCompare(50);
        }else{
                PWM_1_WriteCompare(75);
                PWM_2_WriteCompare(30); 
        }
        // Perform a 90-degree turn to the right
//        int targetCounts = 2;
//
//
//        // Turn right until the desired angle is reached
//
//
//        if(encoder_value_sum_M1 < targetCounts) {
//                PWM_1_WriteCompare(80);
//                PWM_2_WriteCompare(40); 
//        }else{
//        PWM_1_WriteCompare(50);
//        PWM_2_WriteCompare(50); 
//        }
        // Stop the motors

//        //current_Encod_Count_M1 = abs(QuadDec_M1_GetCounter());
//        target_diatance = 20;
//        if((abs(QuadDec_M1_GetCounter())) <= target_diatance){
//            LED_1_Write(1);
//            PWM_1_WriteCompare(50);
//            PWM_2_WriteCompare(50);    
//        }else{
//            LED_2_Write(1);
//            PWM_1_WriteCompare(80);
//            PWM_2_WriteCompare(20); 
//        }
        
        //int currentAngle = 0;  // Current orientation in degrees
//        QuadDec_M1_SetCounter(0);
//        if((abs(QuadDec_M1_GetCounter()) * (360/228)) >= 90) {
//            LED_1_Write(1);
//
//            PWM_1_WriteCompare(50);
//            PWM_2_WriteCompare(50); 
//        }else{
//        LED_2_Write(1);
//        PWM_1_WriteCompare(80);
//        PWM_2_WriteCompare(20); 
//        }
       
          //comp0 and comp1 =0  => straight
           //comp2=0 => left
           //comp3=0 => right
           /* Place your application code here. */
<<<<<<< HEAD
        
        // Check the left sensor
        if (comp2_sum >= 0) {
            LED_2_Write(1);
            distance_M1 = 0;
            // Left sensor is triggered, change state to TURN_LEFT
            currentState = TURN_LEFT;
            target_diatance = 3;
        }
        
        // Implement state machine logic
        switch (currentState) {
            case GO_STRAIGHT:
                // Implement goStraight logic
                goStraight();
                break;
                
            case TURN_LEFT:
                if(distance_M1 >= distance_M1 + target_diatance ){// M1 is faster than M2 
                    currentState = GO_STRAIGHT;
                    LED_1_Write(1);
                }else {
                    
                }
                turnLeft();
                
//                if(distance_M1 >= distance_M1 + turn_left_diatance){
//                    LED_3_Write(1);
//                    turnLeft();
//                }
                break;
                
            case STOP:
                // Implement logic to stop the robot
               stop();
                break;
        }
       
        //target distance task
//        if(distance_M1 >=target_diatance ){// M1 is faster than M2 
//            LED_1_Write(1);
//            stop(); 
//        }else{
//            goStraight();
=======
//        if(comp1_sum==0 && comp0_sum==0){
//                current_state = GO_STRAIGHT;
//                current_Encod_Count_M1 = abs(QuadDec_M1_GetCounter());
//                current_Encod_Count_M2 = abs(QuadDec_M1_GetCounter());
//        }else if(comp2_sum == 0) {
//                go_distance(0); // Reset the distance traveled
//                turn_complete = false;
//                current_state = TURN_LEFT;
//        }else if(comp3_sum==0){
//                current_state = TURN_RIGHT;
//        }else if(comp0_sum>0 && comp1_sum>0 && comp2_sum>0 && comp3_sum>0){
//                current_state = STOP;
//        }
//        else if(comp0_sum>0 && comp1_sum==0){//s_ML out of line
//                current_state = LEFT_ADJUST;
//        }else if(comp0_sum==0 && comp1_sum>0){//s_MR out of line
//                current_state = RIGHT_ADJUST;
//        }
//            
//            
////            if(distance_M1>=(target_diatance/1.03) && target_diatance!=0){
////                LED_1_Write(1);
////                current_state = STOP;
////            }
//           
//
////          PWM_1_WriteCompare(PWM_R);
////          PWM_2_WriteCompare(PWM_L);
//     
//        switch (current_state) {
//            case GO_STRAIGHT:
//                PWM_1_WriteCompare(70);
//                PWM_2_WriteCompare(0);
//                break;
//            case TURN_LEFT:
////                while (!turn_complete) {
////                    if (distance_M1 >= turn_back_diatance) {
//                    if((abs(QuadDec_M1_GetCounter())) >= current_Encod_Count_M1){
//                        turn_complete = true;
//                        //current_state = GO_STRAIGHT;
//                        current_state = STOP;
//                    } else {
//                        // Implement right turn logic
//                        PWM_1_WriteCompare(71);
//                        PWM_2_WriteCompare(30);
//                    }
////                }
//                break;    
//            case TURN_RIGHT:
//                PWM_1_WriteCompare(11);
//                PWM_2_WriteCompare(70);
//                break;  
//            case LEFT_ADJUST:
//                PWM_L = PWM_1_ReadCompare();
//                PWM_2_WriteCompare(PWM_L+1);
//                break; 
//            case RIGHT_ADJUST:
//                PWM_R = PWM_2_ReadCompare();
//                PWM_1_WriteCompare(PWM_R+1);
//                break; 
//            case STOP:
//                PWM_1_WriteCompare(50);
//                PWM_2_WriteCompare(50);
//                break;
>>>>>>> 551c227b3e607c945d0813acebd402305acd8153
//        }
    }
}


/* [] END OF FILE */