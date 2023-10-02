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

#include <project.h>
#include "defines.h"

extern int16 speedL, speedR;
extern int16 posL, posR;


void get_position(void);
void get_speed(void);

//------------------------------------------------------
void get_position()
{
    int pl, pr;

    pl = QuadDec_M1_GetCounter();
    pr = QuadDec_M2_GetCounter();

    posL = pl;
    posR = pr;
}
//------------------------------------------------------
void get_speed()
{
    int16 pl, pr;
    
    // get current position.
    pl = QuadDec_M1_GetCounter();
    pr = QuadDec_M2_GetCounter();
    
    speedL = pl - posL;
    speedR = pr - posR;
    posL = pl;
    posR = pr;
    
    
//    // Speed of Motor 1
//    state = QuadDec_M1_GetEvents();
//    speed = pl - posL;
//    if ((state & QuadDec_M1_COUNTER_OVERFLOW) != 0x00)
//        speed += 32767;
//    
//    if ((state & QuadDec_M1_COUNTER_UNDERFLOW) != 0x00)
//        speed += -32768;
//    speedL = speed;
//    posL = pl;
//    
//    // Speed of Motor 2
//    state = QuadDec_M2_GetEvents();
//    speed = pr - posR;
//    if ((state & QuadDec_M2_COUNTER_OVERFLOW) != 0x00)
//        speed += 32767;
//    
//    if ((state & QuadDec_M2_COUNTER_UNDERFLOW) != 0x00)
//        speed += -32768;
//    speedR = speed;    
//    posR = pr;
}
//------------------------------------------------------
/* [] END OF FILE */
