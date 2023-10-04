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
#include "project.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <project.h>
#include <stdbool.h>
#include <math.h>
#include <cytypes.h>
#include "cyapicallbacks.h"

//distance calculation paras
int32 encoderCounts_M1 = 0;  
int32 encoderCounts_M2 = 0;  
int32 CPR = 228; 
float wheelCircumference_cm = 20.30725;
double timeInterval_ms = 0.01;//10.924
float32  distance_M1 = 0;
float32  distance_M2 = 0;
float32  current_distance_M1 = 0;
float32  current_distance_M2 = 0;
float32 target_diatance = 0;//cm
volatile float32 speed_M1 = 0;
volatile float32 speed_M2 = 0;
int32 encoder_value_sum_M1 = 0;
int32 encoder_value_sum_M2 = 0;
uint8 counter = 1;
bool isTurning=false;

CY_ISR(counter_isr_handler){
    if (counter <= 10){
        counter++;
        //speed_M1 = (encoderCounts_M1/CPR * wheelCircumference_cm)/0.02;
        //speed_M2 = (encoderCounts_M2/CPR * wheelCircumference_cm)/0.02;
    }
    else {
        counter = 1;
        // Encoder counts (negative due to counterclockwise rotation)
        encoderCounts_M1 = abs(QuadDec_M1_GetCounter());//QuadDec_M1_GetCounter();
        encoderCounts_M2 = abs(QuadDec_M2_GetCounter());
        
        // sum of encodercounts
        encoder_value_sum_M1 += encoderCounts_M1;
        encoder_value_sum_M2 += encoderCounts_M2;
        
        
        // distance calculations 
        distance_M1 = (encoder_value_sum_M1/CPR) * wheelCircumference_cm;
        distance_M2 = (encoder_value_sum_M2/CPR) * wheelCircumference_cm;
        

//        //reset the encoder counters 
        QuadDec_M1_SetCounter(0);
        QuadDec_M2_SetCounter(0);     
    }
        Timer_1_ReadStatusRegister();   
}

typedef enum {
    GO_STRAIGHT,
    TURN_LEFT,
    TURN_RIGHT,
    STOP,
} RobotState;

RobotState current_state = STOP;// intialse state

// Sout 0 is black and 1 is white 

void stop(){
    PWM_1_WriteCompare(50);
    PWM_2_WriteCompare(50);
}
void turnLeft(){
    PWM_1_WriteCompare(65);
    PWM_2_WriteCompare(50);
    while((Sout_Left_Read()==0) || Sout_MidLeft_Read() ==1){
        ;;
    }
//    while(Sout_M2_Read()==1){
//        ;;
//    }
    
    while(Sout_MidLeft_Read()==0){
        stop();
        CyDelay(50);
        if( Sout_MidLeft_Read() == 0){
            break;
        }
    }
    if(Sout_MidRight_Read()==0 || Sout_MidLeft_Read()==0){
       isTurning=false;
       current_state=GO_STRAIGHT;
       stop();
       CyDelay(1000);
       PWM_1_WriteCompare(65);
       PWM_2_WriteCompare(60);
    }
    
}
void turnRight(){
    LED_1_Write(1);
    LED_2_Write(1);
    LED_3_Write(1);
    
    PWM_1_WriteCompare(50);
    PWM_2_WriteCompare(70);
     while((Sout_Right_Read()==0) || Sout_MidLeft_Read() == 1){
        ;;
    }
//    while(Sout_M2_Read()==1){
//        ;;
//    }
//    
    while(Sout_MidRight_Read()==0){
        PWM_1_WriteCompare(50);
        PWM_2_WriteCompare(50);
        CyDelay(50);
        if( Sout_MidLeft_Read() == 0){
            break;
        }
    }
    if(Sout_MidRight_Read()==0 || Sout_MidLeft_Read()==0){
       isTurning=false;
       current_state=GO_STRAIGHT;
       stop();
       CyDelay(1000);
       PWM_1_WriteCompare(60);
       PWM_2_WriteCompare(61);
    }
}
    


void goStraight(){
    
    if (Sout_MidRight_Read() == 0 && Sout_MidLeft_Read() > 0){
        if (speed_M1 >= 5){
            PWM_2_WriteCompare(PWM_2_ReadCompare() -1);
        }
        else {
         PWM_1_WriteCompare(PWM_1_ReadCompare()+ 1);   
        }
        speed_M1;
        speed_M2;
    } else if (Sout_MidRight_Read() > 0 && Sout_MidLeft_Read() == 0){
        if (speed_M2 >= 5)
        PWM_1_WriteCompare(PWM_1_ReadCompare() -1);
    }
    else {
         PWM_2_WriteCompare(PWM_2_ReadCompare()+ 1);   
        }

    
    
////    //comp0==>middle left comp1==>middle right
//    if(comp0_sum>0 && comp1_sum==0){//s_ML out of line
////        
//            PWM_2_WriteCompare(PWM_2_ReadCompare() +1);
////        }
//    }else if(comp0_sum==0 && comp1_sum>0){//s_MR out of line
////
//            PWM_1_WriteCompare(PWM_1_ReadCompare() +1);
////        }
//    }else if(comp1_sum==0 && comp0_sum==0){
//        PWM_1_WriteCompare(65);
//        PWM_2_WriteCompare(66);
//    }
//    if (speed_M1 > speed_M2){
//     if (PWM_1_ReadCompare() >=80){
//        PWM_1_WriteCompare(PWM_1_ReadCompare()-5);   
//    }
//    else{
//        PWM_2_WriteCompare(PWM_2_ReadCompare()+5);
//    }
// }
//    else if (speed_M1 < speed_M2){
//        if (PWM_2_ReadCompare() >=80){
//        PWM_2_WriteCompare(PWM_2_ReadCompare()-5);   
//    }else{
//        PWM_1_WriteCompare(PWM_1_ReadCompare()+5);
//    }
//    }
//    else {}
//        if(comp0_sum>0 && comp1_sum==0){//s_ML out of line
////        
//            //PWM_2_WriteCompare(PWM_2_ReadCompare() +1);
//            if (speed_M1 < speed_M2){
//                if (speed_M1 >= 30){
//                    PWM_1_WriteCompare(PWM_1_ReadCompare() -5);
//                }
//                else{
//                    PWM_1_WriteCompare(PWM_1_ReadCompare() + 5);
//                }
//            }else {
//                if (speed_M2 >= 30){
//                    PWM_2_WriteCompare(PWM_2_ReadCompare() -5);
//                }
//                else{
//                    PWM_2_WriteCompare(PWM_2_ReadCompare() + 5);
//                }
//            }
//            
//          
//            
////        }
//    }else if(comp0_sum==0 && comp1_sum>0){//s_MR out of line
////
//            if (speed_M1 < speed_M2){
//                if (speed_M1 >= 30){
//                    PWM_1_WriteCompare(PWM_1_ReadCompare() -5);
//                }
//                else{
//                    PWM_1_WriteCompare(PWM_1_ReadCompare() + 5);
//                }
//            }else {
//                if (speed_M2 >= 30){
//                    PWM_2_WriteCompare(PWM_2_ReadCompare() -5);
//                }
//                else{
//                    PWM_2_WriteCompare(PWM_2_ReadCompare() + 5);
//                }
//            }
////        }
//    }else if(comp1_sum==0 && comp0_sum==0){
//        ;
//    }
//        
}
     
void go_distance(float32 distance){
    distance_M1=0;
    target_diatance=distance;
}




int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    Timer_1_Start();
    
    Comp_0_Start();
    Comp_1_Start();
    Comp_2_Start();
    Comp_3_Start();
    
    Counter_isr_StartEx(counter_isr_handler);
    
    PWM_1_WritePeriod(100);
    PWM_2_WritePeriod(100);
    PWM_1_WriteCompare(55);
    PWM_2_WriteCompare(56);
    Clock_PWM_Start(); 
    PWM_1_Start();
    PWM_2_Start();
    
    QuadDec_M1_Start();
    QuadDec_M2_Start();
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
        while(!isTurning){
          if (((Sout_MidRight_Read() == 0) || (Sout_MidLeft_Read() == 0)) && ((Sout_Left_Read()) > 1 && (Sout_Right_Read() > 0))) {
            current_state = GO_STRAIGHT;
        } else if(Sout_Left_Read() == 0){
            stop();
            CyDelay(200);
            if (Sout_Left_Read() == 0){
                current_state = TURN_LEFT;
                QuadDec_M1_SetCounter(0);
                isTurning=true;
            }
        } else if (Sout_Right_Read() == 0){
            stop();
            CyDelay(200);
            if(Sout_Right_Read() == 0){
                current_state = TURN_RIGHT;
                QuadDec_M2_SetCounter(0);//reset 
                isTurning=true;
            }
        } else {
           current_state = STOP; 
        }
        
        }
        switch (current_state) {
            case GO_STRAIGHT:
                goStraight();
                break;
            case TURN_LEFT:
                while(isTurning){//keep turning until QuadDec value reached
                    turnLeft();
                };
                current_state=STOP;
                break;    
            case TURN_RIGHT:
                while(isTurning){
                    turnRight();
                };
                current_state=STOP;
                break;  
            case STOP:
                PWM_1_WriteCompare(50);
                PWM_2_WriteCompare(50);
                break;
        }
    }
}

/* [] END OF FILE */
