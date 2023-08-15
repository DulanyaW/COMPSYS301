/*******************************************************************************
* File Name: MB_QB.h  
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

#if !defined(CY_PINS_MB_QB_H) /* Pins MB_QB_H */
#define CY_PINS_MB_QB_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MB_QB_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MB_QB__PORT == 15 && ((MB_QB__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    MB_QB_Write(uint8 value) ;
void    MB_QB_SetDriveMode(uint8 mode) ;
uint8   MB_QB_ReadDataReg(void) ;
uint8   MB_QB_Read(void) ;
uint8   MB_QB_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define MB_QB_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define MB_QB_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define MB_QB_DM_RES_UP          PIN_DM_RES_UP
#define MB_QB_DM_RES_DWN         PIN_DM_RES_DWN
#define MB_QB_DM_OD_LO           PIN_DM_OD_LO
#define MB_QB_DM_OD_HI           PIN_DM_OD_HI
#define MB_QB_DM_STRONG          PIN_DM_STRONG
#define MB_QB_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define MB_QB_MASK               MB_QB__MASK
#define MB_QB_SHIFT              MB_QB__SHIFT
#define MB_QB_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MB_QB_PS                     (* (reg8 *) MB_QB__PS)
/* Data Register */
#define MB_QB_DR                     (* (reg8 *) MB_QB__DR)
/* Port Number */
#define MB_QB_PRT_NUM                (* (reg8 *) MB_QB__PRT) 
/* Connect to Analog Globals */                                                  
#define MB_QB_AG                     (* (reg8 *) MB_QB__AG)                       
/* Analog MUX bux enable */
#define MB_QB_AMUX                   (* (reg8 *) MB_QB__AMUX) 
/* Bidirectional Enable */                                                        
#define MB_QB_BIE                    (* (reg8 *) MB_QB__BIE)
/* Bit-mask for Aliased Register Access */
#define MB_QB_BIT_MASK               (* (reg8 *) MB_QB__BIT_MASK)
/* Bypass Enable */
#define MB_QB_BYP                    (* (reg8 *) MB_QB__BYP)
/* Port wide control signals */                                                   
#define MB_QB_CTL                    (* (reg8 *) MB_QB__CTL)
/* Drive Modes */
#define MB_QB_DM0                    (* (reg8 *) MB_QB__DM0) 
#define MB_QB_DM1                    (* (reg8 *) MB_QB__DM1)
#define MB_QB_DM2                    (* (reg8 *) MB_QB__DM2) 
/* Input Buffer Disable Override */
#define MB_QB_INP_DIS                (* (reg8 *) MB_QB__INP_DIS)
/* LCD Common or Segment Drive */
#define MB_QB_LCD_COM_SEG            (* (reg8 *) MB_QB__LCD_COM_SEG)
/* Enable Segment LCD */
#define MB_QB_LCD_EN                 (* (reg8 *) MB_QB__LCD_EN)
/* Slew Rate Control */
#define MB_QB_SLW                    (* (reg8 *) MB_QB__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MB_QB_PRTDSI__CAPS_SEL       (* (reg8 *) MB_QB__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MB_QB_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MB_QB__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MB_QB_PRTDSI__OE_SEL0        (* (reg8 *) MB_QB__PRTDSI__OE_SEL0) 
#define MB_QB_PRTDSI__OE_SEL1        (* (reg8 *) MB_QB__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MB_QB_PRTDSI__OUT_SEL0       (* (reg8 *) MB_QB__PRTDSI__OUT_SEL0) 
#define MB_QB_PRTDSI__OUT_SEL1       (* (reg8 *) MB_QB__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MB_QB_PRTDSI__SYNC_OUT       (* (reg8 *) MB_QB__PRTDSI__SYNC_OUT) 


#if defined(MB_QB__INTSTAT)  /* Interrupt Registers */

    #define MB_QB_INTSTAT                (* (reg8 *) MB_QB__INTSTAT)
    #define MB_QB_SNAP                   (* (reg8 *) MB_QB__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MB_QB_H */


/* [] END OF FILE */
