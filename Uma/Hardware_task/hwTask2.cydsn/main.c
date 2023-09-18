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
int32 wheel_circumference = 100;
int32 encoder_count_i = 0;
int32 encoder_count_j = 0;
int32 cpr = 0;
int32 ppr = 0;
int32 distance_i = 0;
int32 distance_j = 0;
int8 target_distance = 0;// need to decide
int8 current_distance_i = 0;
int8 current_distance_j = 0;
int32 prev_encoder_value_i = 0;
double prev_encoder_value_j = 0;
double wheel_circumference_mm = 64.46;
int CPR_value = 228;

CY_ISR(isr_TC_handler){
    
    if (counter % 4 != 0){
     counter++;
    }else{
        // 2.731ms *4 ~=11 ms
        ci = QuadDec_M1_GetCounter();
        cj = QuadDec_M2_GetCounter();
        speedi = (uint32)(-ci * 8.13/4);
        speedj = (uint32)(-cj * 8.13/4);
        counter = 1;
        ready_to_send = 1;
        QuadDec_M1_SetCounter(0);
        QuadDec_M2_SetCounter(0);
    }
    Timer_1_ReadStatusRegister();
    
}
//stop motor 1
void stop_M1(){
    PWM_1_WriteCompare(0);
}

//stop motor 2
void stop_M2(){
    PWM_2_WriteCompare(0);
}
 
void distance_based_Stopping(encoder_count_i,encoder_count_j){  
    //calculate disances since the last reading
    distance_i = (encoder_count_i/cpr)*wheel_circumference;
    distance_j = (encoder_count_j/cpr)*wheel_circumference;
    //calculate distance and add distance to calculate total distance travel
    current_distance_i = ((encoder_count_i - prev_encoder_value_i)/cpr)*wheel_circumference;
    current_distance_j = ((encoder_count_j - prev_encoder_value_j)/cpr)*wheel_circumference;
    
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
    /*Start PWM Clk*/
    Clock_PWM_Start(); 
    //Start PWM
    PWM_1_Start();
    PWM_2_Start();
    // write comparision int for MC33926 duty cycle must me larger than 10% and less than 90%
    PWM_2_WriteCompare(60);
    PWM_1_WriteCompare(60);
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
        if (ready_to_send == 1){
            sprintf(bufferi, "speed_M1: %ld\r\n", speedi);
            usbPutString(bufferi);
            
            sprintf(bufferj, "speed_M2: %ld\r\n", speedj);
            usbPutString(bufferj);
            ready_to_send = 0;
            
            distance_based_Stopping(ci,cj);
            
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
