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
volatile int32 encoderCounts_RightWheel = 0;  
volatile int32 encoderCounts_LeftWheel = 0;  
volatile int32 CPR = 228; 
volatile float wheelCircumference_cm = 20.30725;
volatile double timeInterval_ms = 0.01;//10.924
volatile float32  distance_Right = 0; //M1
volatile float32  distance_Left = 0; //M2
volatile float32  current_distance_Right = 0; //M1
volatile float32  current_distance_Left = 0; //M2
volatile float32 target_distance = 0;//cm
volatile float32 speed_RightWheel = 0; //M1
volatile float32 speed_LeftWheel = 0; //M2
volatile int32 encoder_value_sum_RightWheel = 0; //M1
volatile int32 encoder_value_sum_LeftWheel = 0; //M2
volatile uint8 counter = 0;
volatile bool isTurning=false;

CY_ISR(counter_isr_handler){
    if (counter < 10){
        counter++;
        //speed_RightWheel = (encoderCounts_M1/CPR * wheelCircumference_cm)/0.001;
        //speed_LeftWheel = (encoderCounts_M2/CPR * wheelCircumference_cm)/0.001;
    }
    else {
        counter = 0;
        // Encoder counts (negative due to counterclockwise rotation)
        encoderCounts_RightWheel = abs(QuadDec_RightWheel_GetCounter());//QuadDec_M1_GetCounter();
        encoderCounts_LeftWheel = abs(QuadDec_LeftWheel_GetCounter());
        
        // sum of encodercounts
        encoder_value_sum_RightWheel += encoderCounts_RightWheel;
        encoder_value_sum_LeftWheel += encoderCounts_LeftWheel;
        
        
        // distance calculations 
        distance_Right = (encoder_value_sum_RightWheel/CPR) * wheelCircumference_cm;
        distance_Left = (encoder_value_sum_LeftWheel/CPR) * wheelCircumference_cm;
        

        //reset the encoder counters 
        QuadDec_RightWheel_SetCounter(0);
        QuadDec_LeftWheel_SetCounter(0);     
    }
        Timer_1_ReadStatusRegister();  
        speed_RightWheel = (encoderCounts_RightWheel/CPR * wheelCircumference_cm)/0.001;
        speed_LeftWheel = (encoderCounts_LeftWheel/CPR * wheelCircumference_cm)/0.001;
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
        if (speed_RightWheel >= 5){
            while (speed_LeftWheel != speed_RightWheel){
                PWM_2_WriteCompare(PWM_2_ReadCompare() -1);
            }
        }
        else {
            while (speed_LeftWheel != speed_RightWheel){
                PWM_1_WriteCompare(PWM_1_ReadCompare()+ 1); 
            }
        }
    } else if (Sout_MidRight_Read() > 0 && Sout_MidLeft_Read() == 0){
        if (speed_LeftWheel >= 5)
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
    distance_Right=0;
    target_distance=distance;
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    Timer_1_Start();
    
    LED_1_Write(0);
    LED_2_Write(1);
    LED_3_Write(1);
    
    Comp_0_Start();
    Comp_1_Start();
    Comp_2_Start();
    Comp_3_Start();
    
    Counter_isr_StartEx(counter_isr_handler);
    
    PWM_1_WritePeriod(100);
    PWM_2_WritePeriod(100);
    PWM_1_WriteCompare(50);
    PWM_2_WriteCompare(50);
    Clock_PWM_Start(); 
    PWM_1_Start();
    PWM_2_Start();
    
    QuadDec_RightWheel_Start();
    QuadDec_LeftWheel_Start();
   

    for(;;)
    {
    /* Place your application code here. */
    while(!isTurning){
      if (((Sout_MidRight_Read() == 0) || (Sout_MidLeft_Read() == 0)) && ((Sout_Left_Read()) > 1 && (Sout_Right_Read() > 0))) {
        current_state = GO_STRAIGHT;
    } else if(Sout_Left_Read() == 0 && Sout_MidLeft_Read() != 0){
        stop();
        //CyDelay(200);
        if (Sout_Left_Read() == 0){
            current_state = TURN_LEFT;
            QuadDec_RightWheel_SetCounter(0);
            isTurning=true;
        }
    } else if (Sout_Right_Read() == 0 && Sout_MidRight_Read() != 0){
        stop();
        //CyDelay(200);
        if(Sout_Right_Read() == 0){
            current_state = TURN_RIGHT;
            QuadDec_LeftWheel_SetCounter(0);//reset 
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
