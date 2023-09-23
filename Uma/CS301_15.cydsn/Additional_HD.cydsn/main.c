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

//distance calculation paras
int32 encoderCounts_M1 = 0;  
int32 encoderCounts_M2 = 0;  
int CPR = 57;  // Adjusted for 4x resolution(228/4)
float wheelCircumference_mm = M_PI * 64.46;// wheel circumference wheelDiameter_mm = 64.46)
float timeInterval_ms = 10.924;  // Effective time interval( (timer period )2.731*4)
float  distance_M1 = 0;
float  distance_M2 = 0;
float target_diatance = 500;
int32 speed_M1 = 0;
int32 speed_M2 = 0;
float encoderCounts_M1_sum=0;
float encoderCounts_M2_sum=0;



uint32 count = 0;
uint32 counter = 0;
bool left_on;
bool right_on;
bool middle_on;

uint8 comp0_sum;
uint8 comp1_sum;
uint8 comp2_sum;
uint8 comp3_sum;

uint8 PWM_R=21;
uint8 PWM_L=80;

void goStraight(){
    PWM_2_WriteCompare(65);
    PWM_1_WriteCompare(35);
}
void turnRight(){
    PWM_2_WriteCompare(70);
    PWM_1_WriteCompare(70);
}
void turnLeft(){
    PWM_2_WriteCompare(30);
    PWM_1_WriteCompare(30);
}



CY_ISR(isr_1_handler) {
    //every 1ms 
    encoderCounts_M1 = QuadDec_M1_GetCounter();
    encoderCounts_M2 = QuadDec_M2_GetCounter();
    encoderCounts_M1 *= -1;
    encoderCounts_M2 *= -1;
        
    distance_M1 = (encoderCounts_M1/CPR) * wheelCircumference_mm;
    distance_M2 = (encoderCounts_M2/CPR) * wheelCircumference_mm;
    
    
    
//    //check comp values every 1ms
//    comp0_sum+=Comp_0_GetCompare();
//    comp1_sum+=Comp_1_GetCompare();
//    comp2_sum+=Comp_2_GetCompare();
//    comp3_sum+=Comp_3_GetCompare();
//    
//    
//    if(count==3){
//        //reset to check again every 4ms
//        comp0_sum=0;
//        comp1_sum=0;
//        comp2_sum=0;
//        comp3_sum=0;
//        count=0;
//    }
//    if(counter==4000){
//        PWM_R=50;
//        PWM_L=50;
//    }
//    counter++;
//    count++;
    Timer_1_ReadStatusRegister();
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
    
    QuadDec_M1_Start();
    QuadDec_M2_Start();
    
    for(;;)
    {
        if(distance_M1>=10){
            LED_1_Write(0);
            //right wheel
           PWM_1_WriteCompare(50);
            //PWM2 corresponds to left wheel
           PWM_2_WriteCompare(50);
           
        }else{
            LED_1_Write(1);
            //right wheel
           PWM_1_WriteCompare(PWM_R);
            //PWM2 corresponds to left wheel
           PWM_2_WriteCompare(PWM_L);
        }
            
           //comp0 and comp1 =0  => straight
           //comp2=0 => left
           //comp3=0 => right
           /* Place your application code here. */
                    

    }
}


/* [] END OF FILE */
