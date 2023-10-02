#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <project.h>
#include <stdbool.h>
#include <math.h>
#include "project.h"
#define TURN_90_ANGLE_EN_COUNT 57 // 90 degrees
#define TURN_180_ANGLE_EN_COUNT 114 // 180 degrees

// Define states for the state machine
typedef enum {
    GO_STRAIGHT,
    TURN_LEFT,
    TURN_RIGHT,
    STOP
} RobotState;
RobotState current_state = GO_STRAIGHT;// intialse state

//distance calculation paras
int32 encoderCounts_M1 = 0;  
int32 encoderCounts_M2 = 0;  
int32 encoder_value_sum_M1 = 0;
int32 encoder_value_sum_M2 = 0;
int32 CPR = 228;  // Adjusted for 4x resolution(228/4)
float wheelCircumference_cm = (M_PI*64.46)/10;// wheel circumference wheelDiameter_mm = 64.46)
double timeInterval_s = 10.924;  // Effective time interval( (timer period )2.731*4)
int32  distance_M1 = 0;
int32  distance_M2 = 0;
int32 target_diatance = 15;//cm


uint32 count = 0;
uint32 counter = 1;
uint8 C0_sum;
uint8 C1_sum;
uint8 C2_sum;
uint8 C3_sum;
uint8 PWM_R=0;
uint8 PWM_L=0;
int32 current_encoder;

bool isTurning=false;// Initialize is_turning to false



void goStraight(){
    if(C0_sum>0 && C1_sum==0){//s_ML out of line
        PWM_L = PWM_2_ReadCompare();
        PWM_2_WriteCompare(PWM_L+1); 
    }else if(C0_sum==0 && C1_sum>0){//s_MR out of line
        PWM_R = PWM_1_ReadCompare();
        PWM_1_WriteCompare(PWM_R+1);
    }else{
        PWM_1_WriteCompare(70);
        PWM_2_WriteCompare(71); 
    }
}
void turnLeft(){
    PWM_1_WriteCompare(70);
    PWM_2_WriteCompare(30); 
}
void turnRight(){
    PWM_1_WriteCompare(30);
    PWM_2_WriteCompare(70); 
}
void reverse(){
    PWM_1_WriteCompare(1);
    PWM_2_WriteCompare(1);
}
void stop(){
    PWM_1_WriteCompare(50);
    PWM_2_WriteCompare(50);
}


CY_ISR(isr_2_handler) {
    if (counter < 10){
        counter++;
    }else{
        counter = 1;
        // Encoder counts (negative due to counterclockwise rotation)
        encoderCounts_M1 = abs(QuadDec_M1_GetCounter());//QuadDec_M1_GetCounter();
        encoderCounts_M2 = abs(QuadDec_M2_GetCounter());
        
        // sum of encodercounts
        encoder_value_sum_M1 += encoderCounts_M1;
        encoder_value_sum_M2 += encoderCounts_M2;
        
        // distance calculations 
        distance_M1 = (encoderCounts_M1/CPR) * wheelCircumference_cm;
        distance_M2 = (encoder_value_sum_M2/CPR) * wheelCircumference_cm;
        
        
        //reset the encoder counters 
        QuadDec_M1_SetCounter(0);
        QuadDec_M2_SetCounter(0);     
    }
        
        Timer_1_ReadStatusRegister();
}

CY_ISR(isr_1_handler) {
    //every 1ms   
    //sum up comp values every 1ms
    C0_sum+=Comp_0_GetCompare();
    C1_sum+=Comp_1_GetCompare();
    C2_sum+=Comp_2_GetCompare();
    C3_sum+=Comp_3_GetCompare();  
    
    if(count==8){//set the state and reset to check again every 8ms
        
        //re-assign states after 8ms
        if(C2_sum==0){//turn left
           current_state=TURN_LEFT;
           isTurning=true;
        }else if(C3_sum==0){//turn right
           current_state=TURN_LEFT;
           isTurning=true;
        }else if(C0_sum==0 || C1_sum==0){
           current_state=GO_STRAIGHT;
           isTurning=false;
        }else{
           current_state=STOP;  
        }
        
        
        C0_sum=0;
        C1_sum=0;
        C2_sum=0;
        C3_sum=0;
        count=0;
    }
    
    count++;
    Timer_1_ReadStatusRegister();
}




int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    Timer_1_Start();
    isr_1_StartEx(isr_1_handler);
    isr_2_StartEx(isr_2_handler);
    Comp_0_Start();
    Comp_1_Start();
    Comp_2_Start();
    Comp_3_Start();
    Clock_PWM_Start(); 
    PWM_1_Start();
    PWM_2_Start();
    PWM_1_WritePeriod(100);
    PWM_2_WritePeriod(100);
    QuadDec_M1_Start();
    QuadDec_M2_Start();
    
    
    
    for(;;)
    {      
         switch (current_state) {
            case GO_STRAIGHT:
                goStraight();
                break;
            case TURN_LEFT:
                turnLeft();
                break;    
            case TURN_RIGHT:
                turnRight();
                break;  
            case STOP:
                stop();
                break;

        }
       

    }
}

/* [] END OF FILE */
////           int32 current_encoder = abs(QuadDec_M2_GetCounter());
//           if(abs(QuadDec_M2_GetCounter()) < 80+encoder_value_sum_M2){
//                turnRight();
//                
//            }else{
//                LED_1_Write(1);
//                stop();   
//            }
//             if(distance_M1>=(target_diatance/1.03) && target_diatance!=0){
//                LED_1_Write(1);
//                current_state = STOP;
//            }