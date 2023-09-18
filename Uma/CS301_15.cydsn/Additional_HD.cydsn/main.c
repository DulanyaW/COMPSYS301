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


CY_ISR(isr_3_interrupt) {
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
CY_ISR(isr_1_interrupt){
    
    if(Sout_M1_Read()!=0 || Sout_M2_Read()!=0){
        LED_1_Write(1);
    }
    if(Comp_2_GetCompare()!=0){
        LED_1_Write(1);
    }
    if(Comp_3_GetCompare()!=0){
        LED_1_Write(1);
    }

}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Timer_2_Start();
    Timer_1_Start();
    isr_3_StartEx(isr_3_interrupt);
    isr_1_StartEx(isr_1_interrupt);
    Comp_0_Start();
    Comp_1_Start();
    Comp_2_Start();
    Comp_3_Start();
    
    for(;;)
    {
        //comp0 and comp1 =0  => straight
        //comp2=0 => left
        //comp3=0 => right
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
