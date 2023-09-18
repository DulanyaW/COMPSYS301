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

bool left_on;
bool right_on;
bool middle_on;

CY_ISR(isr_TC_handler){
    PWM_2_WriteCompare(50);
    PWM_1_WriteCompare(50);
   
    Timer_1_ReadStatusRegister();
    
}


CY_ISR(isr_3_interrupt) {
    //every 8.33ms
//    if(Comp_1_GetCompare()==1){
//        LED_Write(1);
//    }rrff 
//    else{
//        LED_Write(0);
//    }
    
    //initialise comp value 
    Comp_0_Init();
    Comp_1_Init();
    Comp_2_Init();
    Comp_3_Init();
    left_on=0;
    right_on=0;
    middle_on=0;

}


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Timer_1_Start();
    Timer_3_Start();
    timer_3_isr_StartEx(isr_TC_handler);
    isr_3_StartEx(isr_3_interrupt);
    
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
    PWM_2_WriteCompare(70);
    PWM_1_WriteCompare(40);
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
