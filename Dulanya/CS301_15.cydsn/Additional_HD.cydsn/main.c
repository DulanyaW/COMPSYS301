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

uint32 count = 0;
uint32 counter = 0;
bool left_on;
bool right_on;
bool middle_on;

uint8 comp0_sum;
uint8 comp1_sum;
uint8 comp2_sum;
uint8 comp3_sum;


void goStraight(){
    PWM_2_WriteCompare(80);
    PWM_1_WriteCompare(20);
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
    
    //check comp values every 1ms
    comp0_sum+=Comp_0_GetCompare();
    comp1_sum+=Comp_1_GetCompare();
    comp2_sum+=Comp_2_GetCompare();
    comp3_sum+=Comp_3_GetCompare();
    
    
    if(count==3){
        //reset to check again every 4ms
        comp0_sum=0;
        comp1_sum=0;
        comp2_sum=0;
        comp3_sum=0;
        count=0;
    }
    if(counter==350){
        PWM_1_WriteCompare(50);
        PWM_2_WriteCompare(50);
    }
    counter++;
    count++;
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
    //right wheel
    PWM_1_WriteCompare(80);
    //PWM2 corresponds to left wheel
    PWM_2_WriteCompare(80);
    
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
                    

    }
}


/* [] END OF FILE */
