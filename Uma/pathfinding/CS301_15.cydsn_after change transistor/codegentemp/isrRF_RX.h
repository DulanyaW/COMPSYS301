/*******************************************************************************
* File Name: isrRF_RX.h
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
#if !defined(CY_ISR_isrRF_RX_H)
#define CY_ISR_isrRF_RX_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isrRF_RX_Start(void);
void isrRF_RX_StartEx(cyisraddress address);
void isrRF_RX_Stop(void);

CY_ISR_PROTO(isrRF_RX_Interrupt);

void isrRF_RX_SetVector(cyisraddress address);
cyisraddress isrRF_RX_GetVector(void);

void isrRF_RX_SetPriority(uint8 priority);
uint8 isrRF_RX_GetPriority(void);

void isrRF_RX_Enable(void);
uint8 isrRF_RX_GetState(void);
void isrRF_RX_Disable(void);

void isrRF_RX_SetPending(void);
void isrRF_RX_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isrRF_RX ISR. */
#define isrRF_RX_INTC_VECTOR            ((reg32 *) isrRF_RX__INTC_VECT)

/* Address of the isrRF_RX ISR priority. */
#define isrRF_RX_INTC_PRIOR             ((reg8 *) isrRF_RX__INTC_PRIOR_REG)

/* Priority of the isrRF_RX interrupt. */
#define isrRF_RX_INTC_PRIOR_NUMBER      isrRF_RX__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isrRF_RX interrupt. */
#define isrRF_RX_INTC_SET_EN            ((reg32 *) isrRF_RX__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isrRF_RX interrupt. */
#define isrRF_RX_INTC_CLR_EN            ((reg32 *) isrRF_RX__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isrRF_RX interrupt state to pending. */
#define isrRF_RX_INTC_SET_PD            ((reg32 *) isrRF_RX__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isrRF_RX interrupt. */
#define isrRF_RX_INTC_CLR_PD            ((reg32 *) isrRF_RX__INTC_CLR_PD_REG)


#endif /* CY_ISR_isrRF_RX_H */


/* [] END OF FILE */
