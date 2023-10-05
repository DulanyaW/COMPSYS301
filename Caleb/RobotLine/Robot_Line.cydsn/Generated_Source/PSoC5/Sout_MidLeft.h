/*******************************************************************************
* File Name: Sout_MidLeft.h  
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

#if !defined(CY_PINS_Sout_MidLeft_H) /* Pins Sout_MidLeft_H */
#define CY_PINS_Sout_MidLeft_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Sout_MidLeft_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Sout_MidLeft__PORT == 15 && ((Sout_MidLeft__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Sout_MidLeft_Write(uint8 value);
void    Sout_MidLeft_SetDriveMode(uint8 mode);
uint8   Sout_MidLeft_ReadDataReg(void);
uint8   Sout_MidLeft_Read(void);
void    Sout_MidLeft_SetInterruptMode(uint16 position, uint16 mode);
uint8   Sout_MidLeft_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Sout_MidLeft_SetDriveMode() function.
     *  @{
     */
        #define Sout_MidLeft_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Sout_MidLeft_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Sout_MidLeft_DM_RES_UP          PIN_DM_RES_UP
        #define Sout_MidLeft_DM_RES_DWN         PIN_DM_RES_DWN
        #define Sout_MidLeft_DM_OD_LO           PIN_DM_OD_LO
        #define Sout_MidLeft_DM_OD_HI           PIN_DM_OD_HI
        #define Sout_MidLeft_DM_STRONG          PIN_DM_STRONG
        #define Sout_MidLeft_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Sout_MidLeft_MASK               Sout_MidLeft__MASK
#define Sout_MidLeft_SHIFT              Sout_MidLeft__SHIFT
#define Sout_MidLeft_WIDTH              1u

/* Interrupt constants */
#if defined(Sout_MidLeft__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Sout_MidLeft_SetInterruptMode() function.
     *  @{
     */
        #define Sout_MidLeft_INTR_NONE      (uint16)(0x0000u)
        #define Sout_MidLeft_INTR_RISING    (uint16)(0x0001u)
        #define Sout_MidLeft_INTR_FALLING   (uint16)(0x0002u)
        #define Sout_MidLeft_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Sout_MidLeft_INTR_MASK      (0x01u) 
#endif /* (Sout_MidLeft__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Sout_MidLeft_PS                     (* (reg8 *) Sout_MidLeft__PS)
/* Data Register */
#define Sout_MidLeft_DR                     (* (reg8 *) Sout_MidLeft__DR)
/* Port Number */
#define Sout_MidLeft_PRT_NUM                (* (reg8 *) Sout_MidLeft__PRT) 
/* Connect to Analog Globals */                                                  
#define Sout_MidLeft_AG                     (* (reg8 *) Sout_MidLeft__AG)                       
/* Analog MUX bux enable */
#define Sout_MidLeft_AMUX                   (* (reg8 *) Sout_MidLeft__AMUX) 
/* Bidirectional Enable */                                                        
#define Sout_MidLeft_BIE                    (* (reg8 *) Sout_MidLeft__BIE)
/* Bit-mask for Aliased Register Access */
#define Sout_MidLeft_BIT_MASK               (* (reg8 *) Sout_MidLeft__BIT_MASK)
/* Bypass Enable */
#define Sout_MidLeft_BYP                    (* (reg8 *) Sout_MidLeft__BYP)
/* Port wide control signals */                                                   
#define Sout_MidLeft_CTL                    (* (reg8 *) Sout_MidLeft__CTL)
/* Drive Modes */
#define Sout_MidLeft_DM0                    (* (reg8 *) Sout_MidLeft__DM0) 
#define Sout_MidLeft_DM1                    (* (reg8 *) Sout_MidLeft__DM1)
#define Sout_MidLeft_DM2                    (* (reg8 *) Sout_MidLeft__DM2) 
/* Input Buffer Disable Override */
#define Sout_MidLeft_INP_DIS                (* (reg8 *) Sout_MidLeft__INP_DIS)
/* LCD Common or Segment Drive */
#define Sout_MidLeft_LCD_COM_SEG            (* (reg8 *) Sout_MidLeft__LCD_COM_SEG)
/* Enable Segment LCD */
#define Sout_MidLeft_LCD_EN                 (* (reg8 *) Sout_MidLeft__LCD_EN)
/* Slew Rate Control */
#define Sout_MidLeft_SLW                    (* (reg8 *) Sout_MidLeft__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Sout_MidLeft_PRTDSI__CAPS_SEL       (* (reg8 *) Sout_MidLeft__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Sout_MidLeft_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Sout_MidLeft__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Sout_MidLeft_PRTDSI__OE_SEL0        (* (reg8 *) Sout_MidLeft__PRTDSI__OE_SEL0) 
#define Sout_MidLeft_PRTDSI__OE_SEL1        (* (reg8 *) Sout_MidLeft__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Sout_MidLeft_PRTDSI__OUT_SEL0       (* (reg8 *) Sout_MidLeft__PRTDSI__OUT_SEL0) 
#define Sout_MidLeft_PRTDSI__OUT_SEL1       (* (reg8 *) Sout_MidLeft__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Sout_MidLeft_PRTDSI__SYNC_OUT       (* (reg8 *) Sout_MidLeft__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Sout_MidLeft__SIO_CFG)
    #define Sout_MidLeft_SIO_HYST_EN        (* (reg8 *) Sout_MidLeft__SIO_HYST_EN)
    #define Sout_MidLeft_SIO_REG_HIFREQ     (* (reg8 *) Sout_MidLeft__SIO_REG_HIFREQ)
    #define Sout_MidLeft_SIO_CFG            (* (reg8 *) Sout_MidLeft__SIO_CFG)
    #define Sout_MidLeft_SIO_DIFF           (* (reg8 *) Sout_MidLeft__SIO_DIFF)
#endif /* (Sout_MidLeft__SIO_CFG) */

/* Interrupt Registers */
#if defined(Sout_MidLeft__INTSTAT)
    #define Sout_MidLeft_INTSTAT            (* (reg8 *) Sout_MidLeft__INTSTAT)
    #define Sout_MidLeft_SNAP               (* (reg8 *) Sout_MidLeft__SNAP)
    
	#define Sout_MidLeft_0_INTTYPE_REG 		(* (reg8 *) Sout_MidLeft__0__INTTYPE)
#endif /* (Sout_MidLeft__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Sout_MidLeft_H */


/* [] END OF FILE */
