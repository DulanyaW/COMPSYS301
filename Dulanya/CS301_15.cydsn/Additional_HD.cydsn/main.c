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
#include <unistd.h> 

#include "project.h"

uint32 count = 0;
uint32 turn_counter = 0;
bool left_on=0;
bool right_on;
bool middle_on;
bool turn_complete;

uint8 comp0_sum;
uint8 comp1_sum;
uint8 comp2_sum;
uint8 comp3_sum;

uint8 PWM_R=70;
uint8 PWM_L=71;

CY_ISR(isr_2_handler) {
    //every 1ms 
    if(turn_counter==400){
        PWM_1_WriteCompare(70);
        PWM_2_WriteCompare(30);
    }
    if(turn_counter==950){
        PWM_1_WriteCompare(50);
        PWM_2_WriteCompare(50);
        turn_complete=true;
    }
    
    turn_counter++;
    
}


CY_ISR(isr_1_handler) {
    //every 1ms 
    
    //check comp values every 1ms
    comp0_sum+=Comp_0_GetCompare();
    comp1_sum+=Comp_1_GetCompare();
    comp2_sum+=Comp_2_GetCompare();
    comp3_sum+=Comp_3_GetCompare();
    
    
    if(count==3){
        //reset to check again every 6ms
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
    PWM_R=50;
    PWM_L=50;
}
void turnLeft(){
    isr_2_StartEx(isr_2_handler);
    
}

void goStraight(){
    //comp0==>middle left comp1==>middle right
   
    if(comp2_sum==0){
        stop();
        
    }else if(comp0_sum>0 && comp1_sum==0){//s_ML out of line
        PWM_L=PWM_L+1;
    }else if(comp0_sum==0 && comp1_sum>0){//s_MR out of line
        PWM_R=PWM_R+1;
        
    }else if(comp1_sum==0 && comp0_sum==0){
        PWM_R=75;
        PWM_L=76;
    }
     
}

void turnRight(){
        
    PWM_R=30;
    PWM_L=71;
    while(comp1_sum==0 && comp0_sum==0);
    PWM_R=50;
    PWM_L=50;
    
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
          //comp0 and comp1 =0  => straight
           //comp2=0 => left
           //comp3=0 => right
           /* Place your application code here. */
     if(comp2_sum==0){
        PWM_R=72;
        PWM_L=38;  
    }else if(comp3_sum==0){
        PWM_R=35;
        PWM_L=73;  
    }else if(comp0_sum>0 && comp1_sum==0){//s_ML out of line
        PWM_L=PWM_L+1;
    }else if(comp0_sum==0 && comp1_sum>0){//s_MR out of line
        PWM_R=PWM_R+1;
        
    }else if(comp1_sum==0 && comp0_sum==0){
        PWM_R=72;
        PWM_L=73;
    }
        
           //PWM1 => right wheel
          PWM_1_WriteCompare(PWM_R);
          //PWM2 => left wheel
          PWM_2_WriteCompare(PWM_L);
        
              

    }
}


/* [] END OF FILE */
