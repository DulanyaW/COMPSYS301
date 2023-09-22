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
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

#include "project.h"
#include "defines.h"

void usbPutString(char *s);
int32 ci = 0;
int32 cj = 0;
int32 ci_sum = 0;
int32 cj_sum = 0;
int32 distance = 0;
int32 target_diatance = 1000;
uint8 counter = 1;

uint32 speedi = 0;
uint32 speedj = 0;
uint8 ready_to_send = 0;
char bufferi[64];
char bufferj[64];

CY_ISR(isr_TC_handler){
    
    if (counter % 4 != 0){
     counter++;
    }else{
        
        // 2.731ms *4 ~=11 ms
        ci = QuadDec_M1_GetCounter();
        cj = QuadDec_M2_GetCounter();
        ci_sum+=ci;
        cj_sum+=cj;
        speedi = (uint32)(-ci * 8.130335909/4);
        speedj = (uint32)(-cj * 8.130335909/4);
        
        distance = speedi * 2.731 * 4;
        
        
        
        counter = 1;
        ready_to_send = 1;
        QuadDec_M1_SetCounter(0);
        QuadDec_M2_SetCounter(0);
        
        
//         if (distance >= target_diatance){
//            PWM_1_WriteCompare(50);
//            PWM_2_WriteCompare(50);
//        }
    }
    distance=(ci_sum/228)*20.2507;
    Timer_1_ReadStatusRegister();
    
}








 
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    /*Start PWM Clk*/
    Clock_PWM_Start(); 
    //Start PWM
    PWM_1_Start();
    PWM_2_Start();
    // write comparision int for MC33926 duty cycle must me larger than 10% and less than 90%
    PWM_1_WriteCompare(20);
    PWM_2_WriteCompare(80);
   
    PWM_1_WritePeriod(100);
    PWM_2_WritePeriod(100);
    //Start UART for operation
    USBUART_1_Start(0, USBUART_1_5V_OPERATION);
    while (USBUART_1_GetConfiguration()==0){};
    //sprintf(buffer, "Hello\n");
    //usbPutString(buffer);
    QuadDec_M1_Start();
    QuadDec_M2_Start();
    Timer_1_Start();
    timer_1_isr_StartEx(isr_TC_handler);
    
//    usbPutString(itoa(ci,buffer,10));
    

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {  
         if (distance >= target_diatance){
            PWM_1_WriteCompare(50);
            PWM_2_WriteCompare(50);
        }
        
        
        if (ready_to_send == 1){
            sprintf(bufferi, "encoder value: %ld\r\n", cj);
            usbPutString(bufferi);
            
            sprintf(bufferi, "speed_M1: %ld\r\n", speedi);
            usbPutString(bufferi);
            
            sprintf(bufferj, "distance: %ld\r\n", distance);
            usbPutString(bufferi);
            
            sprintf(bufferj, "Distance: %ld\r\n", distance);
            usbPutString(bufferj);
            
            ready_to_send = 0;
            
            
        }
       
        /* Place your application code here. */
    }
}


void usbPutString(char *s)
{
// !! Assumes that *s is a string with allocated space >=64 chars     
//  Since USB implementation retricts data packets to 64 chars, this function truncates the
//  length to 62 char (63rd char is a '!')

#ifdef USE_USB     
    while (USBUART_1_CDCIsReady() == 0);
    s[63]='\0';
    s[62]='!';
    USBUART_1_PutData((uint8*)s,strlen(s));
#endif
}
//* ========================================
void usbPutChar(char c)
{
#ifdef USE_USB     
    while (USBUART_1_CDCIsReady() == 0);
    USBUART_1_PutChar(c);
#endif    
}
/* [] END OF FILE */
