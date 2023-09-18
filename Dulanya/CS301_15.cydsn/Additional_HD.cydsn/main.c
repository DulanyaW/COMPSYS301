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

CY_ISR(isr_TC_handler){
    //every 8.33ms
    if(middle_on){
        LED_0_Write(1);
    }else{
        LED_0_Write(0);
    }
    if(right_on){
        LED_1_Write(1);
    }else{
        LED_1_Write(0);
    }
    if(left_on){
        LED_2_Write(1);
    }else{
        LED_2_Write(0);
    }
    right_on=0;
    left_on=0;
    middle_on=0;

    Timer_1_ReadStatusRegister();
    
}


CY_ISR(isr_3_interrupt) {
    //every 1.388ms
    if(Comp_0_GetCompare()==1 || Comp_1_GetCompare()==1 ){
        middle_on=1;
    }
    if(Comp_2_GetCompare()==1){
        left_on=1;
    }
    if(Comp_3_GetCompare()==1){
        right_on=1;        
    }
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
    PWM_2_WriteCompare(50);
    PWM_1_WriteCompare(50);
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
