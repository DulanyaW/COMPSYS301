/*******************************************************************************
* File Name: isrBT.h
* Version 1.70
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
#if !defined(CY_ISR_isrBT_H)
#define CY_ISR_isrBT_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isrBT_Start(void);
void isrBT_StartEx(cyisraddress address);
void isrBT_Stop(void);

CY_ISR_PROTO(isrBT_Interrupt);

void isrBT_SetVector(cyisraddress address);
cyisraddress isrBT_GetVector(void);

void isrBT_SetPriority(uint8 priority);
uint8 isrBT_GetPriority(void);

void isrBT_Enable(void);
uint8 isrBT_GetState(void);
void isrBT_Disable(void);

void isrBT_SetPending(void);
void isrBT_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isrBT ISR. */
#define isrBT_INTC_VECTOR            ((reg32 *) isrBT__INTC_VECT)

/* Address of the isrBT ISR priority. */
#define isrBT_INTC_PRIOR             ((reg8 *) isrBT__INTC_PRIOR_REG)

/* Priority of the isrBT interrupt. */
#define isrBT_INTC_PRIOR_NUMBER      isrBT__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isrBT interrupt. */
#define isrBT_INTC_SET_EN            ((reg32 *) isrBT__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isrBT interrupt. */
#define isrBT_INTC_CLR_EN            ((reg32 *) isrBT__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isrBT interrupt state to pending. */
#define isrBT_INTC_SET_PD            ((reg32 *) isrBT__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isrBT interrupt. */
#define isrBT_INTC_CLR_PD            ((reg32 *) isrBT__INTC_CLR_PD_REG)


#endif /* CY_ISR_isrBT_H */


/* [] END OF FILE */
