/*******************************************************************************
* File Name: timer_isr_3.h
* Version 1.71
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_timer_isr_3_H)
#define CY_ISR_timer_isr_3_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void timer_isr_3_Start(void);
void timer_isr_3_StartEx(cyisraddress address);
void timer_isr_3_Stop(void);

CY_ISR_PROTO(timer_isr_3_Interrupt);

void timer_isr_3_SetVector(cyisraddress address);
cyisraddress timer_isr_3_GetVector(void);

void timer_isr_3_SetPriority(uint8 priority);
uint8 timer_isr_3_GetPriority(void);

void timer_isr_3_Enable(void);
uint8 timer_isr_3_GetState(void);
void timer_isr_3_Disable(void);

void timer_isr_3_SetPending(void);
void timer_isr_3_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the timer_isr_3 ISR. */
#define timer_isr_3_INTC_VECTOR            ((reg32 *) timer_isr_3__INTC_VECT)

/* Address of the timer_isr_3 ISR priority. */
#define timer_isr_3_INTC_PRIOR             ((reg8 *) timer_isr_3__INTC_PRIOR_REG)

/* Priority of the timer_isr_3 interrupt. */
#define timer_isr_3_INTC_PRIOR_NUMBER      timer_isr_3__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable timer_isr_3 interrupt. */
#define timer_isr_3_INTC_SET_EN            ((reg32 *) timer_isr_3__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the timer_isr_3 interrupt. */
#define timer_isr_3_INTC_CLR_EN            ((reg32 *) timer_isr_3__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the timer_isr_3 interrupt state to pending. */
#define timer_isr_3_INTC_SET_PD            ((reg32 *) timer_isr_3__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the timer_isr_3 interrupt. */
#define timer_isr_3_INTC_CLR_PD            ((reg32 *) timer_isr_3__INTC_CLR_PD_REG)


#endif /* CY_ISR_timer_isr_3_H */


/* [] END OF FILE */
