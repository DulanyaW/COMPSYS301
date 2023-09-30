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
uint8 counter = 1;
uint32 speedi = 0;
uint32 speedj = 0;
uint8 ready_to_send = 0;
char bufferi[64];
char bufferj[64];


// distance calcu
int32 encoder_count_i = 0;
int32 encoder_count_j = 0;
double distance_i = 0;
double distance_j = 0;
int32 target_distance = 100;// need to decide
double current_distance_i = 0;
double current_distance_j = 0;
double wheel_circumference_mm = 20.25;
int CPR_value = 228;



CY_ISR(isr_TC_handler){
    //if counter is not divisible by 4, counter is incremented
    if (counter % 4 != 0){
     counter++;
    }else{
        // 2.731ms *4 ~=11 ms
        encoder_count_i = QuadDec_M1_GetCounter();
        encoder_count_j = QuadDec_M2_GetCounter();
        speedi = (uint32)(-encoder_count_i * 8.13/4);
        speedj = (uint32)(-encoder_count_j * 8.13/4);
        
        double current_distance_i = (double)(-encoder_count_i/CPR_value)*wheel_circumference_mm;
        distance_i += current_distance_i;
        
        
        counter = 1;
        ready_to_send = 1;
        QuadDec_M1_SetCounter(0);
        QuadDec_M2_SetCounter(0);
    }
    Timer_1_ReadStatusRegister();
    
    
}

void stop_M1(){
    PWM_1_WriteCompare(50);
    PWM_2_WriteCompare(50);
}




 
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
        Timer_1_Start();
    isr_1_StartEx(isr_TC_handler);
    /*Start PWM Clk*/
    Clock_PWM_Start(); 
    //Start PWM
    PWM_1_Start();
    PWM_2_Start();
    // write comparision int for MC33926 duty cycle must me larger than 10% and less than 90%
    
    
    PWM_1_WritePeriod(100);
    PWM_2_WritePeriod(100);
    //Start UART for operation
//    USBUART_1_Start(0, USBUART_1_5V_OPERATION);
//    while (USBUART_1_GetConfiguration()==0){};
    //sprintf(buffer, "Hello\n");
    //usbPutString(buffer);
    QuadDec_M1_Start();
    QuadDec_M2_Start();

    
//    usbPutString(itoa(ci,buffer,10));
    

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        
            
       PWM_2_WriteCompare(80);
        PWM_1_WriteCompare(20);

        
        if (ready_to_send == 1){
            sprintf(bufferi, "encode count: %ld\r\n", (long) abs(QuadDec_M1_GetCounter()));
            usbPutString(bufferi);
            
            sprintf(bufferi, "encode count: %ld\r\n", (long) distance_i);
            usbPutString(bufferi);
           
            sprintf(bufferj, "encoder value M2: %ld\r\n", (long) abs(QuadDec_M2_GetCounter()));
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
