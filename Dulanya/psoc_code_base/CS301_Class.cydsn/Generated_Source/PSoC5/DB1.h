/*******************************************************************************
* File Name: DB1.h  
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

#if !defined(CY_PINS_DB1_H) /* Pins DB1_H */
#define CY_PINS_DB1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DB1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DB1__PORT == 15 && ((DB1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DB1_Write(uint8 value);
void    DB1_SetDriveMode(uint8 mode);
uint8   DB1_ReadDataReg(void);
uint8   DB1_Read(void);
void    DB1_SetInterruptMode(uint16 position, uint16 mode);
uint8   DB1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DB1_SetDriveMode() function.
     *  @{
     */
        #define DB1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DB1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DB1_DM_RES_UP          PIN_DM_RES_UP
        #define DB1_DM_RES_DWN         PIN_DM_RES_DWN
        #define DB1_DM_OD_LO           PIN_DM_OD_LO
        #define DB1_DM_OD_HI           PIN_DM_OD_HI
        #define DB1_DM_STRONG          PIN_DM_STRONG
        #define DB1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DB1_MASK               DB1__MASK
#define DB1_SHIFT              DB1__SHIFT
#define DB1_WIDTH              1u

/* Interrupt constants */
#if defined(DB1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DB1_SetInterruptMode() function.
     *  @{
     */
        #define DB1_INTR_NONE      (uint16)(0x0000u)
        #define DB1_INTR_RISING    (uint16)(0x0001u)
        #define DB1_INTR_FALLING   (uint16)(0x0002u)
        #define DB1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DB1_INTR_MASK      (0x01u) 
#endif /* (DB1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DB1_PS                     (* (reg8 *) DB1__PS)
/* Data Register */
#define DB1_DR                     (* (reg8 *) DB1__DR)
/* Port Number */
#define DB1_PRT_NUM                (* (reg8 *) DB1__PRT) 
/* Connect to Analog Globals */                                                  
#define DB1_AG                     (* (reg8 *) DB1__AG)                       
/* Analog MUX bux enable */
#define DB1_AMUX                   (* (reg8 *) DB1__AMUX) 
/* Bidirectional Enable */                                                        
#define DB1_BIE                    (* (reg8 *) DB1__BIE)
/* Bit-mask for Aliased Register Access */
#define DB1_BIT_MASK               (* (reg8 *) DB1__BIT_MASK)
/* Bypass Enable */
#define DB1_BYP                    (* (reg8 *) DB1__BYP)
/* Port wide control signals */                                                   
#define DB1_CTL                    (* (reg8 *) DB1__CTL)
/* Drive Modes */
#define DB1_DM0                    (* (reg8 *) DB1__DM0) 
#define DB1_DM1                    (* (reg8 *) DB1__DM1)
#define DB1_DM2                    (* (reg8 *) DB1__DM2) 
/* Input Buffer Disable Override */
#define DB1_INP_DIS                (* (reg8 *) DB1__INP_DIS)
/* LCD Common or Segment Drive */
#define DB1_LCD_COM_SEG            (* (reg8 *) DB1__LCD_COM_SEG)
/* Enable Segment LCD */
#define DB1_LCD_EN                 (* (reg8 *) DB1__LCD_EN)
/* Slew Rate Control */
#define DB1_SLW                    (* (reg8 *) DB1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DB1_PRTDSI__CAPS_SEL       (* (reg8 *) DB1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DB1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DB1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DB1_PRTDSI__OE_SEL0        (* (reg8 *) DB1__PRTDSI__OE_SEL0) 
#define DB1_PRTDSI__OE_SEL1        (* (reg8 *) DB1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DB1_PRTDSI__OUT_SEL0       (* (reg8 *) DB1__PRTDSI__OUT_SEL0) 
#define DB1_PRTDSI__OUT_SEL1       (* (reg8 *) DB1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DB1_PRTDSI__SYNC_OUT       (* (reg8 *) DB1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DB1__SIO_CFG)
    #define DB1_SIO_HYST_EN        (* (reg8 *) DB1__SIO_HYST_EN)
    #define DB1_SIO_REG_HIFREQ     (* (reg8 *) DB1__SIO_REG_HIFREQ)
    #define DB1_SIO_CFG            (* (reg8 *) DB1__SIO_CFG)
    #define DB1_SIO_DIFF           (* (reg8 *) DB1__SIO_DIFF)
#endif /* (DB1__SIO_CFG) */

/* Interrupt Registers */
#if defined(DB1__INTSTAT)
    #define DB1_INTSTAT            (* (reg8 *) DB1__INTSTAT)
    #define DB1_SNAP               (* (reg8 *) DB1__SNAP)
    
	#define DB1_0_INTTYPE_REG 		(* (reg8 *) DB1__0__INTTYPE)
#endif /* (DB1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DB1_H */


/* [] END OF FILE */
