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
int CPR = 57;  // Adjusted for 4x resolution(228/4)
float wheelCircumference_mm = M_PI * 64.46;// wheel circumference wheelDiameter_mm = 64.46)
float timeInterval_ms = 10.924;  // Effective time interval( (timer period )2.731*4)
float  distance_M1 = 0;
float  distance_M2 = 0;
float  current_distance_M1 = 0;
float  current_distance_M2 = 0;
float target_diatance = 500.00;//50cm
int32 speed_M1 = 0;
int32 speed_M2 = 0;
float encoderCounts_M1_sum=0;
float encoderCounts_M2_sum=0;
int counterstop = 0;

void stopMotors() {
    PWM_1_WriteCompare(50);  // Set PWM duty cycle to 50 to stop motor 1
    PWM_2_WriteCompare(50);  // Set PWM duty cycle to 50 to stop motor 2
}

CY_ISR(isr_TC_handler){
    
    if (counter % 4 != 0){
        LED_1_Write(1);
     counter++;
    }else{
        // Encoder counts (negative due to counterclockwise rotation)
        encoderCounts_M1 = 100;//QuadDec_M1_GetCounter();
        encoderCounts_M2 = QuadDec_M2_GetCounter();
    
        // Adjust for counterclockwise rotation by multiplying counts by -1
//        encoderCounts_M1 *= -1;
//        encoderCounts_M2 *= -1;
        
        //speed calculation
        speed_M1 = encoderCounts_M1 * 8.13/4;
        speed_M2 = encoderCounts_M2 * 8.13/4;
        
        //distance calculations
        current_distance_M1 = (encoderCounts_M1/CPR) * wheelCircumference_mm;
        current_distance_M2 = (encoderCounts_M2/CPR) * wheelCircumference_mm;
//        distance_M1 = (encoderCounts_M1/228) * 202.74;
//        distance_M2 = (encoderCounts_M2/228) * 202.74;
//        
//        encoderCounts_M1_sum += encoderCounts_M1;
//        encoderCounts_M2_sum += encoderCounts_M2;
//    distance_M1 = (encoderCounts_M1_sum/228)*20.25;
//    distance_M2 = (encoderCounts_M2_sum/228)*20.25;     
        
        distance_M1 += current_distance_M1;
        distance_M2 += current_distance_M2;
       
   
        counter = 1;
        ready_to_send = 1;
        
        //reset the encoder counters 
        QuadDec_M1_SetCounter(0);
        QuadDec_M2_SetCounter(0);     
    }
        Timer_1_ReadStatusRegister();
         if(distance_M1 >=target_diatance){
            LED_1_Write(1);
            //right wheel
            stopMotors();            
        } 
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
    PWM_1_WritePeriod(100);
    PWM_2_WritePeriod(100);
    
    // write comparision int for MC33926 duty cycle must me larger than 10% and less than 90%
    PWM_1_WriteCompare(20);
    PWM_2_WriteCompare(20);
   
    
    //Start UART for operation
    USBUART_1_Start(0, USBUART_1_5V_OPERATION);
    while (USBUART_1_GetConfiguration()==0){};
    //sprintf(buffer, "Hello\n");
    //usbPutString(buffer);
    
    
    QuadDec_M1_Start();
    QuadDec_M2_Start();
    
    timer_1_isr_StartEx(isr_TC_handler);
    
//    usbPutString(itoa(ci,buffer,10));
    

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {  
        if(distance_M1>=2000){
            stopMotors();
        }
             
//        if (ready_to_send == 1){
//            sprintf(bufferi, "encoder value: %ld\r\n", encoderCounts_M1);
//            usbPutString(bufferi);
//            
//            sprintf(bufferi, "speed_M1: %ld\r\n", encoderCounts_M2);
//            usbPutString(bufferi);
////            
////            sprintf(bufferj, "distance: %ld\r\n", distance_M1);
////            usbPutString(bufferi);
////            
////            sprintf(bufferj, "Distance: %ld\r\n", distance);
////            usbPutString(bufferj);
//            
//            ready_to_send = 0;            
//        }
//       
//        /* Place your application code here. */
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
