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


#include "project.h"
uint32 counter = 1;
bool left_on;
bool right_on;
bool middle_on;
void usbPutString(char *s);
int32 ci = 0;
int32 cj = 0;
uint32 speedi = 0;
uint32 speedj = 0;
uint8 ready_to_send = 0;
char bufferi[64];
char bufferj[64];

// distance calcu
int32 encoder_count_i = 0;
int32 encoder_count_j = 0;
int32 cpr = 0;
int32 ppr = 0;
double distance_i = 0;
double distance_j = 0;
int32 target_distance = 100;// need to decide
double current_distance_i = 0;
double current_distance_j = 0;
int32 prev_encoder_value_i = 0;
double prev_encoder_value_j = 0;
double wheel_circumference_mm = 64.46;
int CPR_value = 228;




CY_ISR(isr_TC_handler){
    //every 8.33ms
//    if(middle_on){
//        LED_0_Write(1);
//    }else{
//        LED_0_Write(0);
//    }
//    if(right_on){
//        LED_1_Write(1);
//    }else{
//        LED_1_Write(0);
//    }
//    if(left_on){
//        LED_2_Write(1);
//    }else{
//        LED_2_Write(0);
//    }
//    right_on=0;
//    left_on=0;
//    middle_on=0;
//
//    Timer_1_ReadStatusRegister();
        if (counter % 4 != 0){
     counter++;
    }else{
        // 2.731ms *4 ~=11 ms
        encoder_count_i = QuadDec_M1_GetCounter();
        encoder_count_j = QuadDec_M2_GetCounter();
        speedi = (uint32)(-encoder_count_i * 8.13/4);
        speedj = (uint32)(-encoder_count_j * 8.13/4);
        counter = 1;
        ready_to_send = 1;
        QuadDec_M1_SetCounter(0);
        QuadDec_M2_SetCounter(0);
    }
    Timer_1_ReadStatusRegister();
    
    
}


//CY_ISR(isr_3_interrupt) {
//    //every 1.388ms
//    if(Comp_0_GetCompare()==1 || Comp_1_GetCompare()==1 ){
//        middle_on=1;
//    }
//    if(Comp_2_GetCompare()==1){
//        left_on=1;
//    }
//    if(Comp_3_GetCompare()==1){
//        right_on=1;        
//    }
//    //initialise comp value 
//    Comp_0_Init();
//    Comp_1_Init();
//    Comp_2_Init();
//    Comp_3_Init();
//    left_on=0;
//    right_on=0;
//    middle_on=0;
//
//}

//stop motor 1
void stop_M1(){
    PWM_1_WriteCompare(50);
}

//stop motor 2
void stop_M2(){
    PWM_2_WriteCompare(50);
}
 
void distance_based_Stopping(encoder_count_i,encoder_count_j){  
    //calculate disances since the last reading
    distance_i = (double)(encoder_count_i/cpr)*wheel_circumference_mm;
    distance_j = (double)(encoder_count_j/cpr)*wheel_circumference_mm;
    //calculate distance and add distance to calculate total distance travel
    double current_distance_i = (double)((encoder_count_i - prev_encoder_value_i)/cpr)*wheel_circumference_mm;
    double current_distance_j = (double)((encoder_count_j - prev_encoder_value_j)/cpr)*wheel_circumference_mm;
    
    distance_i+=current_distance_i;
    distance_j+=current_distance_j;
    
    if(distance_i >= target_distance){
        stop_M1();
    }
    if(distance_j >= target_distance){
        stop_M2();
    }
    
}


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Timer_1_Start();
    Timer_3_Start();
    timer_isr_3_StartEx(isr_TC_handler);
//    isr_3_StartEx(isr_3_interrupt);
    
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
    PWM_2_WriteCompare(80);
    PWM_1_WriteCompare(80);
    PWM_1_WritePeriod(100);
    PWM_2_WritePeriod(100);
    
    QuadDec_M1_Start();
    QuadDec_M2_Start();
    
    for(;;)
    {
        //comp0 and comp1 =0  => straight
        //comp2=0 => left
        //comp3=0 => right
        /* Place your application code here. */
        //distance_based_Stopping(encoder_count_i,encoder_count_j);
        //calculate disances since the last reading
//    distance_i = (double)(encoder_count_i/cpr)*wheel_circumference_mm;
//    distance_j = (double)(encoder_count_j/cpr)*wheel_circumference_mm;
    //calculate distance and add distance to calculate total distance travel
    double current_distance_i = (double)((encoder_count_i - prev_encoder_value_i)/cpr)*wheel_circumference_mm;
    double current_distance_j = (double)((encoder_count_j - prev_encoder_value_j)/cpr)*wheel_circumference_mm;
    
    current_distance_i += current_distance_i;
    current_distance_j += current_distance_j;
    
    if(current_distance_i >= target_distance){
        stop_M1();
        stop_M2();
    }
//    if(distance_j >= target_distance){
//        stop_M2();
//    }
    }
}

/* [] END OF FILE */
