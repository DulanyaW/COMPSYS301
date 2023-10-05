/*******************************************************************************
* File Name: Sout_MidRight.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Sout_MidRight_H) /* Pins Sout_MidRight_H */
#define CY_PINS_Sout_MidRight_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Sout_MidRight_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Sout_MidRight__PORT == 15 && ((Sout_MidRight__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Sout_MidRight_Write(uint8 value);
void    Sout_MidRight_SetDriveMode(uint8 mode);
uint8   Sout_MidRight_ReadDataReg(void);
uint8   Sout_MidRight_Read(void);
void    Sout_MidRight_SetInterruptMode(uint16 position, uint16 mode);
uint8   Sout_MidRight_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Sout_MidRight_SetDriveMode() function.
     *  @{
     */
        #define Sout_MidRight_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Sout_MidRight_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Sout_MidRight_DM_RES_UP          PIN_DM_RES_UP
        #define Sout_MidRight_DM_RES_DWN         PIN_DM_RES_DWN
        #define Sout_MidRight_DM_OD_LO           PIN_DM_OD_LO
        #define Sout_MidRight_DM_OD_HI           PIN_DM_OD_HI
        #define Sout_MidRight_DM_STRONG          PIN_DM_STRONG
        #define Sout_MidRight_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Sout_MidRight_MASK               Sout_MidRight__MASK
#define Sout_MidRight_SHIFT              Sout_MidRight__SHIFT
#define Sout_MidRight_WIDTH              1u

/* Interrupt constants */
#if defined(Sout_MidRight__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Sout_MidRight_SetInterruptMode() function.
     *  @{
     */
        #define Sout_MidRight_INTR_NONE      (uint16)(0x0000u)
        #define Sout_MidRight_INTR_RISING    (uint16)(0x0001u)
        #define Sout_MidRight_INTR_FALLING   (uint16)(0x0002u)
        #define Sout_MidRight_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Sout_MidRight_INTR_MASK      (0x01u) 
#endif /* (Sout_MidRight__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Sout_MidRight_PS                     (* (reg8 *) Sout_MidRight__PS)
/* Data Register */
#define Sout_MidRight_DR                     (* (reg8 *) Sout_MidRight__DR)
/* Port Number */
#define Sout_MidRight_PRT_NUM                (* (reg8 *) Sout_MidRight__PRT) 
/* Connect to Analog Globals */                                                  
#define Sout_MidRight_AG                     (* (reg8 *) Sout_MidRight__AG)                       
/* Analog MUX bux enable */
#define Sout_MidRight_AMUX                   (* (reg8 *) Sout_MidRight__AMUX) 
/* Bidirectional Enable */                                                        
#define Sout_MidRight_BIE                    (* (reg8 *) Sout_MidRight__BIE)
/* Bit-mask for Aliased Register Access */
#define Sout_MidRight_BIT_MASK               (* (reg8 *) Sout_MidRight__BIT_MASK)
/* Bypass Enable */
#define Sout_MidRight_BYP                    (* (reg8 *) Sout_MidRight__BYP)
/* Port wide control signals */                                                   
#define Sout_MidRight_CTL                    (* (reg8 *) Sout_MidRight__CTL)
/* Drive Modes */
#define Sout_MidRight_DM0                    (* (reg8 *) Sout_MidRight__DM0) 
#define Sout_MidRight_DM1                    (* (reg8 *) Sout_MidRight__DM1)
#define Sout_MidRight_DM2                    (* (reg8 *) Sout_MidRight__DM2) 
/* Input Buffer Disable Override */
#define Sout_MidRight_INP_DIS                (* (reg8 *) Sout_MidRight__INP_DIS)
/* LCD Common or Segment Drive */
#define Sout_MidRight_LCD_COM_SEG            (* (reg8 *) Sout_MidRight__LCD_COM_SEG)
/* Enable Segment LCD */
#define Sout_MidRight_LCD_EN                 (* (reg8 *) Sout_MidRight__LCD_EN)
/* Slew Rate Control */
#define Sout_MidRight_SLW                    (* (reg8 *) Sout_MidRight__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Sout_MidRight_PRTDSI__CAPS_SEL       (* (reg8 *) Sout_MidRight__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Sout_MidRight_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Sout_MidRight__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Sout_MidRight_PRTDSI__OE_SEL0        (* (reg8 *) Sout_MidRight__PRTDSI__OE_SEL0) 
#define Sout_MidRight_PRTDSI__OE_SEL1        (* (reg8 *) Sout_MidRight__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Sout_MidRight_PRTDSI__OUT_SEL0       (* (reg8 *) Sout_MidRight__PRTDSI__OUT_SEL0) 
#define Sout_MidRight_PRTDSI__OUT_SEL1       (* (reg8 *) Sout_MidRight__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Sout_MidRight_PRTDSI__SYNC_OUT       (* (reg8 *) Sout_MidRight__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Sout_MidRight__SIO_CFG)
    #define Sout_MidRight_SIO_HYST_EN        (* (reg8 *) Sout_MidRight__SIO_HYST_EN)
    #define Sout_MidRight_SIO_REG_HIFREQ     (* (reg8 *) Sout_MidRight__SIO_REG_HIFREQ)
    #define Sout_MidRight_SIO_CFG            (* (reg8 *) Sout_MidRight__SIO_CFG)
    #define Sout_MidRight_SIO_DIFF           (* (reg8 *) Sout_MidRight__SIO_DIFF)
#endif /* (Sout_MidRight__SIO_CFG) */

/* Interrupt Registers */
#if defined(Sout_MidRight__INTSTAT)
    #define Sout_MidRight_INTSTAT            (* (reg8 *) Sout_MidRight__INTSTAT)
    #define Sout_MidRight_SNAP               (* (reg8 *) Sout_MidRight__SNAP)
    
	#define Sout_MidRight_0_INTTYPE_REG 		(* (reg8 *) Sout_MidRight__0__INTTYPE)
#endif /* (Sout_MidRight__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Sout_MidRight_H */


/* [] END OF FILE */
