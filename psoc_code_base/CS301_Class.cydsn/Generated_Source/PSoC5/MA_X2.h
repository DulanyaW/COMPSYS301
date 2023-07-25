/*******************************************************************************
* File Name: MA_X2.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_MA_X2_H) /* Pins MA_X2_H */
#define CY_PINS_MA_X2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MA_X2_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MA_X2__PORT == 15 && ((MA_X2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    MA_X2_Write(uint8 value) ;
void    MA_X2_SetDriveMode(uint8 mode) ;
uint8   MA_X2_ReadDataReg(void) ;
uint8   MA_X2_Read(void) ;
uint8   MA_X2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define MA_X2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define MA_X2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define MA_X2_DM_RES_UP          PIN_DM_RES_UP
#define MA_X2_DM_RES_DWN         PIN_DM_RES_DWN
#define MA_X2_DM_OD_LO           PIN_DM_OD_LO
#define MA_X2_DM_OD_HI           PIN_DM_OD_HI
#define MA_X2_DM_STRONG          PIN_DM_STRONG
#define MA_X2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define MA_X2_MASK               MA_X2__MASK
#define MA_X2_SHIFT              MA_X2__SHIFT
#define MA_X2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MA_X2_PS                     (* (reg8 *) MA_X2__PS)
/* Data Register */
#define MA_X2_DR                     (* (reg8 *) MA_X2__DR)
/* Port Number */
#define MA_X2_PRT_NUM                (* (reg8 *) MA_X2__PRT) 
/* Connect to Analog Globals */                                                  
#define MA_X2_AG                     (* (reg8 *) MA_X2__AG)                       
/* Analog MUX bux enable */
#define MA_X2_AMUX                   (* (reg8 *) MA_X2__AMUX) 
/* Bidirectional Enable */                                                        
#define MA_X2_BIE                    (* (reg8 *) MA_X2__BIE)
/* Bit-mask for Aliased Register Access */
#define MA_X2_BIT_MASK               (* (reg8 *) MA_X2__BIT_MASK)
/* Bypass Enable */
#define MA_X2_BYP                    (* (reg8 *) MA_X2__BYP)
/* Port wide control signals */                                                   
#define MA_X2_CTL                    (* (reg8 *) MA_X2__CTL)
/* Drive Modes */
#define MA_X2_DM0                    (* (reg8 *) MA_X2__DM0) 
#define MA_X2_DM1                    (* (reg8 *) MA_X2__DM1)
#define MA_X2_DM2                    (* (reg8 *) MA_X2__DM2) 
/* Input Buffer Disable Override */
#define MA_X2_INP_DIS                (* (reg8 *) MA_X2__INP_DIS)
/* LCD Common or Segment Drive */
#define MA_X2_LCD_COM_SEG            (* (reg8 *) MA_X2__LCD_COM_SEG)
/* Enable Segment LCD */
#define MA_X2_LCD_EN                 (* (reg8 *) MA_X2__LCD_EN)
/* Slew Rate Control */
#define MA_X2_SLW                    (* (reg8 *) MA_X2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MA_X2_PRTDSI__CAPS_SEL       (* (reg8 *) MA_X2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MA_X2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MA_X2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MA_X2_PRTDSI__OE_SEL0        (* (reg8 *) MA_X2__PRTDSI__OE_SEL0) 
#define MA_X2_PRTDSI__OE_SEL1        (* (reg8 *) MA_X2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MA_X2_PRTDSI__OUT_SEL0       (* (reg8 *) MA_X2__PRTDSI__OUT_SEL0) 
#define MA_X2_PRTDSI__OUT_SEL1       (* (reg8 *) MA_X2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MA_X2_PRTDSI__SYNC_OUT       (* (reg8 *) MA_X2__PRTDSI__SYNC_OUT) 


#if defined(MA_X2__INTSTAT)  /* Interrupt Registers */

    #define MA_X2_INTSTAT                (* (reg8 *) MA_X2__INTSTAT)
    #define MA_X2_SNAP                   (* (reg8 *) MA_X2__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MA_X2_H */


/* [] END OF FILE */
