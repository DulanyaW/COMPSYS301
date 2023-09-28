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
#include "project.h"
#define TURN_ANGLE 90 // Desired turn angle in degrees

// Define PID controller parameters
float Kp = 1.0;  // Proportional gain
float Ki = 0.1;  // Integral gain
float Kd = 0.01; // Derivative gain

float previous_error = 0;
float integral = 0;
float output = 0;


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




uint32 count = 0;
uint32 turn_counter = 0;
bool left_on=false;
bool right_on;
bool middle_on;
bool turn_complete=true;

uint8 comp0_sum;
uint8 comp1_sum;
uint8 comp2_sum;
uint8 comp3_sum;

uint8 PWM_R=80;
uint8 PWM_L=81;
float error = 0;
bool s0_flag;
bool s1_flag;
bool s2_flag;
bool s3_flag;

RobotState current_state = GO_STRAIGHT;// intialse state




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
   
}

CY_ISR(isr_2_handler) {
    
    if (comp0_sum==0) {
        s0_flag = true;
    }
    if (comp1_sum==0) {
        s1_flag = true;
    }

    if (comp2_sum==0 ) {
        s2_flag = true;
    }
    if (comp3_sum==0 ) {
        s3_flag = true;
    }
    
    
}

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


void stop(){
    PWM_1_WriteCompare(50);
    PWM_2_WriteCompare(50);
}

void goStraight(){
    if(comp0_sum>0 && comp1_sum==0){
        PWM_2_WriteCompare(PWM_2_ReadCompare()+ 1);
    }else if(comp0_sum==0 && comp1_sum>0){
        PWM_1_WriteCompare(PWM_1_ReadCompare()+ 1);
    }else{
        PWM_1_WriteCompare(70);
        PWM_2_WriteCompare(71);
    }
}


// Function to calculate error based on sensor inputs
float calculateError() {
    // Read sensor inputs (s0, s1, s2, s3) from your hardware
//    int s0 = comp0_sum;
//    int s1 = comp1_sum;
//    int s2 = comp2_sum;
//    int s3 = comp3_sum;
        // Read sensor inputs (s0, s1, s2, s3)
    int s0 = Comp_0_GetCompare();
    int s1 = Comp_1_GetCompare();
    int s2 = Comp_2_GetCompare();
    int s3 = Comp_3_GetCompare();
    

    if (s0 == 0 || s1 == 0) {
        // Go straight
        error = 0;
    } else if (s2 == 0) {
        // Turn left
        error = 90; // Positive error
    } else if (s3 == 0) {
        // Turn right
        error = -90; // Negative error
    }

    return error;
}

    


void turnRight(){
    PWM_1_WriteCompare(30);
    PWM_2_WriteCompare(70);  
}

void turnLeft(){
    PWM_1_WriteCompare(70);
    PWM_2_WriteCompare(30);
}


void go_distance(float32 distance){
    distance_M1=0;
    goStraight();
    target_diatance=distance;
}




// Function to control the robot based on PID output
void robotControl(float output) {

    // Determine robot behavior based on PID output
    if (output == 0) {
        // PID output is 0, go straight
        goStraight();
        LED_1_Write(1);
    } else if (output > 0) {
        // Positive output, turn left
        
        while(output==0){
            LED_2_Write(1);
           turnLeft(); 
        }
        goStraight();
        
    } else if (output < 0){
        // Negative output, turn right
        
        while(output==0){
            LED_3_Write(1);
        turnRight();
        }
    }else {
        stop();
    }

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

        if (s0_flag || s1_flag) {
            // Turn logic: go straight
            goStraight();
            // Clear the sensor flags
            s0_flag = false;
            s1_flag = false;
        }
        if (s2_flag) {
            turnLeft();
            // Turn logic: turn 90 degrees left
            // Clear the sensor flag
            s2_flag = false;
        }
        if (s3_flag) {
            turnRight();
            // Turn logic: turn 90 degrees right
            // Clear the sensor flag
            s3_flag = false;
        }
        
        if (s0_flag && s1_flag && s2_flag && s3_flag) {
            stop();;
            // Turn logic: turn 90 degrees right
            // Clear the sensor flag
        }
        
    }
}


/* [] END OF FILE */