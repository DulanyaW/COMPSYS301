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
uint8 counter = 1;
uint8 ready_to_send = 0;
char bufferi[64];
char bufferj[64];


//distance calculation paras
int32 encoderCounts_M1 = 0;  
int32 encoderCounts_M2 = 0;  
int32 CPR = 228;  // Adjusted for 4x resolution(228/4)
float wheelCircumference_cm = (M_PI*64.46)/10;// wheel circumference wheelDiameter_mm = 64.46)
double timeInterval_s = 10.924;  // Effective time interval( (timer period )2.731*4)
float32  distance_M1 = 0;
float32  distance_M2 = 0;
float32  current_distance_M1 = 0;
float32  current_distance_M2 = 0;
float32 target_diatance = 100;//50cm
float32 speed_M1 = 0;
float32 speed_M2 = 0;
int32 encoder_value_sum_M1 = 0;
int32 encoder_value_sum_M2 = 0;

void stopMotors() {
    PWM_1_WriteCompare(50);  // Set PWM duty cycle to 50 to stop motor 1
    PWM_2_WriteCompare(50);  // Set PWM duty cycle to 50 to stop motor 2
}



CY_ISR(isr_TC_handler){ 
    if (counter % 4 != 0){
     counter++;
    }else{
        // Encoder counts (negative due to counterclockwise rotation)
        encoderCounts_M1 = abs(QuadDec_M1_GetCounter());//QuadDec_M1_GetCounter();
        encoderCounts_M2 = abs(QuadDec_M2_GetCounter());
        
        // sum of encodercounts
        encoder_value_sum_M1 += encoderCounts_M1;
        encoder_value_sum_M2 += encoderCounts_M2;
        
        // distance calculations 
        distance_M1 = (encoder_value_sum_M1/CPR) * wheelCircumference_cm;
        distance_M2 = (encoder_value_sum_M2/CPR) * wheelCircumference_cm;
        
        
        
        counter = 1;
        ready_to_send = 1;
        
        //reset the encoder counters 
        QuadDec_M1_SetCounter(0);
        QuadDec_M2_SetCounter(0);     
    }
        Timer_1_ReadStatusRegister();
}





 
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    /*Start PWM Clk*/
    Timer_1_Start();
    Clock_PWM_Start(); 
    //Start PWM
    PWM_1_Start();
    PWM_2_Start();
    QuadDec_M1_Start();
    QuadDec_M2_Start();
    timer_1_isr_StartEx(isr_TC_handler);
    PWM_1_WritePeriod(100);
    PWM_2_WritePeriod(100);
    
    // write comparision int for MC33926 duty cycle must me larger than 10% and less than 90%
    PWM_1_WriteCompare(80);
    PWM_2_WriteCompare(80);
   

    for(;;)
    {  
        
        if((distance_M1 >=target_diatance)){// M1 is faster than M2 
            LED_1_Write(1);
           // stopMotors(); 
        }
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
