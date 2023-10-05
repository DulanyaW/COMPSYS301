/*******************************************************************************
* File Name: EN_Right.h  
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

#if !defined(CY_PINS_EN_Right_H) /* Pins EN_Right_H */
#define CY_PINS_EN_Right_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EN_Right_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 EN_Right__PORT == 15 && ((EN_Right__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    EN_Right_Write(uint8 value);
void    EN_Right_SetDriveMode(uint8 mode);
uint8   EN_Right_ReadDataReg(void);
uint8   EN_Right_Read(void);
void    EN_Right_SetInterruptMode(uint16 position, uint16 mode);
uint8   EN_Right_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the EN_Right_SetDriveMode() function.
     *  @{
     */
        #define EN_Right_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define EN_Right_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define EN_Right_DM_RES_UP          PIN_DM_RES_UP
        #define EN_Right_DM_RES_DWN         PIN_DM_RES_DWN
        #define EN_Right_DM_OD_LO           PIN_DM_OD_LO
        #define EN_Right_DM_OD_HI           PIN_DM_OD_HI
        #define EN_Right_DM_STRONG          PIN_DM_STRONG
        #define EN_Right_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define EN_Right_MASK               EN_Right__MASK
#define EN_Right_SHIFT              EN_Right__SHIFT
#define EN_Right_WIDTH              1u

/* Interrupt constants */
#if defined(EN_Right__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in EN_Right_SetInterruptMode() function.
     *  @{
     */
        #define EN_Right_INTR_NONE      (uint16)(0x0000u)
        #define EN_Right_INTR_RISING    (uint16)(0x0001u)
        #define EN_Right_INTR_FALLING   (uint16)(0x0002u)
        #define EN_Right_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define EN_Right_INTR_MASK      (0x01u) 
#endif /* (EN_Right__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EN_Right_PS                     (* (reg8 *) EN_Right__PS)
/* Data Register */
#define EN_Right_DR                     (* (reg8 *) EN_Right__DR)
/* Port Number */
#define EN_Right_PRT_NUM                (* (reg8 *) EN_Right__PRT) 
/* Connect to Analog Globals */                                                  
#define EN_Right_AG                     (* (reg8 *) EN_Right__AG)                       
/* Analog MUX bux enable */
#define EN_Right_AMUX                   (* (reg8 *) EN_Right__AMUX) 
/* Bidirectional Enable */                                                        
#define EN_Right_BIE                    (* (reg8 *) EN_Right__BIE)
/* Bit-mask for Aliased Register Access */
#define EN_Right_BIT_MASK               (* (reg8 *) EN_Right__BIT_MASK)
/* Bypass Enable */
#define EN_Right_BYP                    (* (reg8 *) EN_Right__BYP)
/* Port wide control signals */                                                   
#define EN_Right_CTL                    (* (reg8 *) EN_Right__CTL)
/* Drive Modes */
#define EN_Right_DM0                    (* (reg8 *) EN_Right__DM0) 
#define EN_Right_DM1                    (* (reg8 *) EN_Right__DM1)
#define EN_Right_DM2                    (* (reg8 *) EN_Right__DM2) 
/* Input Buffer Disable Override */
#define EN_Right_INP_DIS                (* (reg8 *) EN_Right__INP_DIS)
/* LCD Common or Segment Drive */
#define EN_Right_LCD_COM_SEG            (* (reg8 *) EN_Right__LCD_COM_SEG)
/* Enable Segment LCD */
#define EN_Right_LCD_EN                 (* (reg8 *) EN_Right__LCD_EN)
/* Slew Rate Control */
#define EN_Right_SLW                    (* (reg8 *) EN_Right__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EN_Right_PRTDSI__CAPS_SEL       (* (reg8 *) EN_Right__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EN_Right_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EN_Right__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EN_Right_PRTDSI__OE_SEL0        (* (reg8 *) EN_Right__PRTDSI__OE_SEL0) 
#define EN_Right_PRTDSI__OE_SEL1        (* (reg8 *) EN_Right__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EN_Right_PRTDSI__OUT_SEL0       (* (reg8 *) EN_Right__PRTDSI__OUT_SEL0) 
#define EN_Right_PRTDSI__OUT_SEL1       (* (reg8 *) EN_Right__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EN_Right_PRTDSI__SYNC_OUT       (* (reg8 *) EN_Right__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(EN_Right__SIO_CFG)
    #define EN_Right_SIO_HYST_EN        (* (reg8 *) EN_Right__SIO_HYST_EN)
    #define EN_Right_SIO_REG_HIFREQ     (* (reg8 *) EN_Right__SIO_REG_HIFREQ)
    #define EN_Right_SIO_CFG            (* (reg8 *) EN_Right__SIO_CFG)
    #define EN_Right_SIO_DIFF           (* (reg8 *) EN_Right__SIO_DIFF)
#endif /* (EN_Right__SIO_CFG) */

/* Interrupt Registers */
#if defined(EN_Right__INTSTAT)
    #define EN_Right_INTSTAT            (* (reg8 *) EN_Right__INTSTAT)
    #define EN_Right_SNAP               (* (reg8 *) EN_Right__SNAP)
    
	#define EN_Right_0_INTTYPE_REG 		(* (reg8 *) EN_Right__0__INTTYPE)
#endif /* (EN_Right__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_EN_Right_H */


/* [] END OF FILE */
