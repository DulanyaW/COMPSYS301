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
    RIGHT_ADJUST,
    LEFT_ADJUST,
    STOP,
} RobotState;

uint32 count = 0;
uint8 comp0_sum;
uint8 comp1_sum;
uint8 comp2_sum;
uint8 comp3_sum;
uint8 PWM_R=0;
uint8 PWM_L=0;
bool s0_flag;
bool s1_flag;
bool s2_flag;
bool s3_flag;

RobotState current_state = GO_STRAIGHT;// intialse state

CY_ISR(isr_2_handler) {
//void sensor_status(){
    if (comp0_sum==0 ) {
        s0_flag = true;
    }
    if (comp1_sum==0 ) {
        s1_flag = true;
    }
    
    if (comp2_sum==0 ) {
        s2_flag = true;
    }
    if (comp3_sum==0 ) {
        s3_flag = true;
    }    
}


CY_ISR(isr_1_handler) {
    //every 1ms   
    //sum up comp values every 1ms
    comp0_sum+=Comp_0_GetCompare();
    comp1_sum+=Comp_1_GetCompare();
    comp2_sum+=Comp_2_GetCompare();
    comp3_sum+=Comp_3_GetCompare();  
    
    if(count==8){
        //reset to check again every 8ms
        comp0_sum=0;
        comp1_sum=0;
        comp2_sum=0;
        comp3_sum=0;
        count=0;
    }
    count++;
    Timer_1_ReadStatusRegister();
}



int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Timer_1_Start();
    isr_1_StartEx(isr_1_handler);
    isr_2_StartEx(isr_2_handler);
    
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
        //sensor_status();
            if(s0_flag || s1_flag){
                    current_state = GO_STRAIGHT;
            }else if(s1_flag) {
                    QuadDec_M1_SetCounter(0);
                    current_state = TURN_LEFT;
            }else if(s3_flag){
                    QuadDec_M2_SetCounter(0);
                    current_state = TURN_RIGHT;
            }else if(comp0_sum>0 && comp1_sum>0 && comp2_sum>0 && comp3_sum>0){
                    current_state = STOP;
            }else if(comp0_sum>0 && comp1_sum==0){//s_ML out of line
                    current_state = LEFT_ADJUST;
            }else if(comp0_sum==0 && comp1_sum>0){//s_MR out of line
                    current_state = RIGHT_ADJUST;
            }
    
            
            switch (current_state) {
            case GO_STRAIGHT:
                PWM_1_WriteCompare(75);
                PWM_2_WriteCompare(76);
                    break;
            case TURN_LEFT:
                if(abs(QuadDec_M1_GetCounter()) < TURN_90_ANGLE_EN_COUNT){
                    PWM_1_WriteCompare(95);
                    PWM_2_WriteCompare(30);
                }
                LED_1_Write(1);
                if(comp0_sum==0 || comp1_sum==0){
                    s2_flag = false;
                }
                
                current_state = STOP;
                break;   
            case TURN_RIGHT:
                if(abs(QuadDec_M2_GetCounter()) < TURN_90_ANGLE_EN_COUNT){
                    PWM_1_WriteCompare(0);
                    PWM_2_WriteCompare(80);
                    }
                LED_2_Write(1);
                s2_flag = false;
                current_state = STOP;
                break;  
            case RIGHT_ADJUST:
                PWM_R = PWM_1_ReadCompare();
                PWM_1_WriteCompare(PWM_R+1);
                break; 
            case LEFT_ADJUST:
                PWM_L = PWM_2_ReadCompare();
                PWM_2_WriteCompare(PWM_L+1);            
                break; 
            case STOP:
                PWM_1_WriteCompare(50);
                PWM_2_WriteCompare(50);
                break;
        }
    }
}

/* [] END OF FILE */
//             if(distance_M1>=(target_diatance/1.03) && target_diatance!=0){
//                LED_1_Write(1);
//                current_state = STOP;
//            }