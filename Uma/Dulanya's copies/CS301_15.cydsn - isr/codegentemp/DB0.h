/*******************************************************************************
* File Name: DB0.h  
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

#if !defined(CY_PINS_DB0_H) /* Pins DB0_H */
#define CY_PINS_DB0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DB0_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DB0__PORT == 15 && ((DB0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DB0_Write(uint8 value);
void    DB0_SetDriveMode(uint8 mode);
uint8   DB0_ReadDataReg(void);
uint8   DB0_Read(void);
void    DB0_SetInterruptMode(uint16 position, uint16 mode);
uint8   DB0_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DB0_SetDriveMode() function.
     *  @{
     */
        #define DB0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DB0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DB0_DM_RES_UP          PIN_DM_RES_UP
        #define DB0_DM_RES_DWN         PIN_DM_RES_DWN
        #define DB0_DM_OD_LO           PIN_DM_OD_LO
        #define DB0_DM_OD_HI           PIN_DM_OD_HI
        #define DB0_DM_STRONG          PIN_DM_STRONG
        #define DB0_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DB0_MASK               DB0__MASK
#define DB0_SHIFT              DB0__SHIFT
#define DB0_WIDTH              1u

/* Interrupt constants */
#if defined(DB0__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DB0_SetInterruptMode() function.
     *  @{
     */
        #define DB0_INTR_NONE      (uint16)(0x0000u)
        #define DB0_INTR_RISING    (uint16)(0x0001u)
        #define DB0_INTR_FALLING   (uint16)(0x0002u)
        #define DB0_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DB0_INTR_MASK      (0x01u) 
#endif /* (DB0__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DB0_PS                     (* (reg8 *) DB0__PS)
/* Data Register */
#define DB0_DR                     (* (reg8 *) DB0__DR)
/* Port Number */
#define DB0_PRT_NUM                (* (reg8 *) DB0__PRT) 
/* Connect to Analog Globals */                                                  
#define DB0_AG                     (* (reg8 *) DB0__AG)                       
/* Analog MUX bux enable */
#define DB0_AMUX                   (* (reg8 *) DB0__AMUX) 
/* Bidirectional Enable */                                                        
#define DB0_BIE                    (* (reg8 *) DB0__BIE)
/* Bit-mask for Aliased Register Access */
#define DB0_BIT_MASK               (* (reg8 *) DB0__BIT_MASK)
/* Bypass Enable */
#define DB0_BYP                    (* (reg8 *) DB0__BYP)
/* Port wide control signals */                                                   
#define DB0_CTL                    (* (reg8 *) DB0__CTL)
/* Drive Modes */
#define DB0_DM0                    (* (reg8 *) DB0__DM0) 
#define DB0_DM1                    (* (reg8 *) DB0__DM1)
#define DB0_DM2                    (* (reg8 *) DB0__DM2) 
/* Input Buffer Disable Override */
#define DB0_INP_DIS                (* (reg8 *) DB0__INP_DIS)
/* LCD Common or Segment Drive */
#define DB0_LCD_COM_SEG            (* (reg8 *) DB0__LCD_COM_SEG)
/* Enable Segment LCD */
#define DB0_LCD_EN                 (* (reg8 *) DB0__LCD_EN)
/* Slew Rate Control */
#define DB0_SLW                    (* (reg8 *) DB0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DB0_PRTDSI__CAPS_SEL       (* (reg8 *) DB0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DB0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DB0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DB0_PRTDSI__OE_SEL0        (* (reg8 *) DB0__PRTDSI__OE_SEL0) 
#define DB0_PRTDSI__OE_SEL1        (* (reg8 *) DB0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DB0_PRTDSI__OUT_SEL0       (* (reg8 *) DB0__PRTDSI__OUT_SEL0) 
#define DB0_PRTDSI__OUT_SEL1       (* (reg8 *) DB0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DB0_PRTDSI__SYNC_OUT       (* (reg8 *) DB0__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DB0__SIO_CFG)
    #define DB0_SIO_HYST_EN        (* (reg8 *) DB0__SIO_HYST_EN)
    #define DB0_SIO_REG_HIFREQ     (* (reg8 *) DB0__SIO_REG_HIFREQ)
    #define DB0_SIO_CFG            (* (reg8 *) DB0__SIO_CFG)
    #define DB0_SIO_DIFF           (* (reg8 *) DB0__SIO_DIFF)
#endif /* (DB0__SIO_CFG) */

/* Interrupt Registers */
#if defined(DB0__INTSTAT)
    #define DB0_INTSTAT            (* (reg8 *) DB0__INTSTAT)
    #define DB0_SNAP               (* (reg8 *) DB0__SNAP)
    
	#define DB0_0_INTTYPE_REG 		(* (reg8 *) DB0__0__INTTYPE)
#endif /* (DB0__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DB0_H */


/* [] END OF FILE */
