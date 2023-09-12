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
uint8 ci = 0;
uint8 i = 0;
uint8 counter = 1;

uint16 speed = 0;
uint8 ready_to_send = 0;
char buffer[20];

CY_ISR(isr_TC_handler){
    if (counter != 10){
     counter++;
    }else{
        // 2.731ms *10
        ci = QuadDec_M1_GetCounter();
        speed = ci * 8.13;
        counter = 1;
        sprintf(buffer, "%d", speed);
        ready_to_send = 1;
        QuadDec_M1_SetCounter(0);
    }
    
    
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
    PWM_2_WriteCompare(50);
    PWM_1_WriteCompare(50);
    PWM_1_WritePeriod(100);
    PWM_2_WritePeriod(100);
    //Start UART for operation
    USBUART_1_Start(0, USBUART_1_5V_OPERATION);
    while (USBUART_1_GetConfiguration()==0){};
    QuadDec_M1_Start();
    Timer_1_Start();
    isr_1_StartEx(isr_TC_handler);
    
//    usbPutString(itoa(ci,buffer,10));
    

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        if (ready_to_send == 1){
            usbPutString(buffer);
            //USBUART_1_PutString(buffer);
            ready_to_send = 0;
            printf("%d", speed);
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
