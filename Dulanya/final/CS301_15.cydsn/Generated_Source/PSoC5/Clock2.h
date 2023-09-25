/*******************************************************************************
* File Name: Clock2.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Clock2_H)
#define CY_CLOCK_Clock2_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void Clock2_Start(void) ;
void Clock2_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void Clock2_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void Clock2_StandbyPower(uint8 state) ;
void Clock2_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 Clock2_GetDividerRegister(void) ;
void Clock2_SetModeRegister(uint8 modeBitMask) ;
void Clock2_ClearModeRegister(uint8 modeBitMask) ;
uint8 Clock2_GetModeRegister(void) ;
void Clock2_SetSourceRegister(uint8 clkSource) ;
uint8 Clock2_GetSourceRegister(void) ;
#if defined(Clock2__CFG3)
void Clock2_SetPhaseRegister(uint8 clkPhase) ;
uint8 Clock2_GetPhaseRegister(void) ;
#endif /* defined(Clock2__CFG3) */

#define Clock2_Enable()                       Clock2_Start()
#define Clock2_Disable()                      Clock2_Stop()
#define Clock2_SetDivider(clkDivider)         Clock2_SetDividerRegister(clkDivider, 1u)
#define Clock2_SetDividerValue(clkDivider)    Clock2_SetDividerRegister((clkDivider) - 1u, 1u)
#define Clock2_SetMode(clkMode)               Clock2_SetModeRegister(clkMode)
#define Clock2_SetSource(clkSource)           Clock2_SetSourceRegister(clkSource)
#if defined(Clock2__CFG3)
#define Clock2_SetPhase(clkPhase)             Clock2_SetPhaseRegister(clkPhase)
#define Clock2_SetPhaseValue(clkPhase)        Clock2_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(Clock2__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define Clock2_CLKEN              (* (reg8 *) Clock2__PM_ACT_CFG)
#define Clock2_CLKEN_PTR          ((reg8 *) Clock2__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define Clock2_CLKSTBY            (* (reg8 *) Clock2__PM_STBY_CFG)
#define Clock2_CLKSTBY_PTR        ((reg8 *) Clock2__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define Clock2_DIV_LSB            (* (reg8 *) Clock2__CFG0)
#define Clock2_DIV_LSB_PTR        ((reg8 *) Clock2__CFG0)
#define Clock2_DIV_PTR            ((reg16 *) Clock2__CFG0)

/* Clock MSB divider configuration register. */
#define Clock2_DIV_MSB            (* (reg8 *) Clock2__CFG1)
#define Clock2_DIV_MSB_PTR        ((reg8 *) Clock2__CFG1)

/* Mode and source configuration register */
#define Clock2_MOD_SRC            (* (reg8 *) Clock2__CFG2)
#define Clock2_MOD_SRC_PTR        ((reg8 *) Clock2__CFG2)

#if defined(Clock2__CFG3)
/* Analog clock phase configuration register */
#define Clock2_PHASE              (* (reg8 *) Clock2__CFG3)
#define Clock2_PHASE_PTR          ((reg8 *) Clock2__CFG3)
#endif /* defined(Clock2__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define Clock2_CLKEN_MASK         Clock2__PM_ACT_MSK
#define Clock2_CLKSTBY_MASK       Clock2__PM_STBY_MSK

/* CFG2 field masks */
#define Clock2_SRC_SEL_MSK        Clock2__CFG2_SRC_SEL_MASK
#define Clock2_MODE_MASK          (~(Clock2_SRC_SEL_MSK))

#if defined(Clock2__CFG3)
/* CFG3 phase mask */
#define Clock2_PHASE_MASK         Clock2__CFG3_PHASE_DLY_MASK
#endif /* defined(Clock2__CFG3) */

#endif /* CY_CLOCK_Clock2_H */


/* [] END OF FILE */
