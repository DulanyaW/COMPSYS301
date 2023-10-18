/*******************************************************************************
* File Name: isrRF_TX.h
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
#if !defined(CY_ISR_isrRF_TX_H)
#define CY_ISR_isrRF_TX_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isrRF_TX_Start(void);
void isrRF_TX_StartEx(cyisraddress address);
void isrRF_TX_Stop(void);

CY_ISR_PROTO(isrRF_TX_Interrupt);

void isrRF_TX_SetVector(cyisraddress address);
cyisraddress isrRF_TX_GetVector(void);

void isrRF_TX_SetPriority(uint8 priority);
uint8 isrRF_TX_GetPriority(void);

void isrRF_TX_Enable(void);
uint8 isrRF_TX_GetState(void);
void isrRF_TX_Disable(void);

void isrRF_TX_SetPending(void);
void isrRF_TX_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isrRF_TX ISR. */
#define isrRF_TX_INTC_VECTOR            ((reg32 *) isrRF_TX__INTC_VECT)

/* Address of the isrRF_TX ISR priority. */
#define isrRF_TX_INTC_PRIOR             ((reg8 *) isrRF_TX__INTC_PRIOR_REG)

/* Priority of the isrRF_TX interrupt. */
#define isrRF_TX_INTC_PRIOR_NUMBER      isrRF_TX__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isrRF_TX interrupt. */
#define isrRF_TX_INTC_SET_EN            ((reg32 *) isrRF_TX__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isrRF_TX interrupt. */
#define isrRF_TX_INTC_CLR_EN            ((reg32 *) isrRF_TX__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isrRF_TX interrupt state to pending. */
#define isrRF_TX_INTC_SET_PD            ((reg32 *) isrRF_TX__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isrRF_TX interrupt. */
#define isrRF_TX_INTC_CLR_PD            ((reg32 *) isrRF_TX__INTC_CLR_PD_REG)


#endif /* CY_ISR_isrRF_TX_H */


/* [] END OF FILE */
