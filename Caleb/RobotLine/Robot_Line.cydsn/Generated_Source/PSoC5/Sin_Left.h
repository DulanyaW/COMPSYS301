/*******************************************************************************
* File Name: Sin_Left.h  
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

#if !defined(CY_PINS_Sin_Left_H) /* Pins Sin_Left_H */
#define CY_PINS_Sin_Left_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Sin_Left_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Sin_Left__PORT == 15 && ((Sin_Left__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Sin_Left_Write(uint8 value);
void    Sin_Left_SetDriveMode(uint8 mode);
uint8   Sin_Left_ReadDataReg(void);
uint8   Sin_Left_Read(void);
void    Sin_Left_SetInterruptMode(uint16 position, uint16 mode);
uint8   Sin_Left_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Sin_Left_SetDriveMode() function.
     *  @{
     */
        #define Sin_Left_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Sin_Left_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Sin_Left_DM_RES_UP          PIN_DM_RES_UP
        #define Sin_Left_DM_RES_DWN         PIN_DM_RES_DWN
        #define Sin_Left_DM_OD_LO           PIN_DM_OD_LO
        #define Sin_Left_DM_OD_HI           PIN_DM_OD_HI
        #define Sin_Left_DM_STRONG          PIN_DM_STRONG
        #define Sin_Left_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Sin_Left_MASK               Sin_Left__MASK
#define Sin_Left_SHIFT              Sin_Left__SHIFT
#define Sin_Left_WIDTH              1u

/* Interrupt constants */
#if defined(Sin_Left__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Sin_Left_SetInterruptMode() function.
     *  @{
     */
        #define Sin_Left_INTR_NONE      (uint16)(0x0000u)
        #define Sin_Left_INTR_RISING    (uint16)(0x0001u)
        #define Sin_Left_INTR_FALLING   (uint16)(0x0002u)
        #define Sin_Left_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Sin_Left_INTR_MASK      (0x01u) 
#endif /* (Sin_Left__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Sin_Left_PS                     (* (reg8 *) Sin_Left__PS)
/* Data Register */
#define Sin_Left_DR                     (* (reg8 *) Sin_Left__DR)
/* Port Number */
#define Sin_Left_PRT_NUM                (* (reg8 *) Sin_Left__PRT) 
/* Connect to Analog Globals */                                                  
#define Sin_Left_AG                     (* (reg8 *) Sin_Left__AG)                       
/* Analog MUX bux enable */
#define Sin_Left_AMUX                   (* (reg8 *) Sin_Left__AMUX) 
/* Bidirectional Enable */                                                        
#define Sin_Left_BIE                    (* (reg8 *) Sin_Left__BIE)
/* Bit-mask for Aliased Register Access */
#define Sin_Left_BIT_MASK               (* (reg8 *) Sin_Left__BIT_MASK)
/* Bypass Enable */
#define Sin_Left_BYP                    (* (reg8 *) Sin_Left__BYP)
/* Port wide control signals */                                                   
#define Sin_Left_CTL                    (* (reg8 *) Sin_Left__CTL)
/* Drive Modes */
#define Sin_Left_DM0                    (* (reg8 *) Sin_Left__DM0) 
#define Sin_Left_DM1                    (* (reg8 *) Sin_Left__DM1)
#define Sin_Left_DM2                    (* (reg8 *) Sin_Left__DM2) 
/* Input Buffer Disable Override */
#define Sin_Left_INP_DIS                (* (reg8 *) Sin_Left__INP_DIS)
/* LCD Common or Segment Drive */
#define Sin_Left_LCD_COM_SEG            (* (reg8 *) Sin_Left__LCD_COM_SEG)
/* Enable Segment LCD */
#define Sin_Left_LCD_EN                 (* (reg8 *) Sin_Left__LCD_EN)
/* Slew Rate Control */
#define Sin_Left_SLW                    (* (reg8 *) Sin_Left__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Sin_Left_PRTDSI__CAPS_SEL       (* (reg8 *) Sin_Left__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Sin_Left_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Sin_Left__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Sin_Left_PRTDSI__OE_SEL0        (* (reg8 *) Sin_Left__PRTDSI__OE_SEL0) 
#define Sin_Left_PRTDSI__OE_SEL1        (* (reg8 *) Sin_Left__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Sin_Left_PRTDSI__OUT_SEL0       (* (reg8 *) Sin_Left__PRTDSI__OUT_SEL0) 
#define Sin_Left_PRTDSI__OUT_SEL1       (* (reg8 *) Sin_Left__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Sin_Left_PRTDSI__SYNC_OUT       (* (reg8 *) Sin_Left__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Sin_Left__SIO_CFG)
    #define Sin_Left_SIO_HYST_EN        (* (reg8 *) Sin_Left__SIO_HYST_EN)
    #define Sin_Left_SIO_REG_HIFREQ     (* (reg8 *) Sin_Left__SIO_REG_HIFREQ)
    #define Sin_Left_SIO_CFG            (* (reg8 *) Sin_Left__SIO_CFG)
    #define Sin_Left_SIO_DIFF           (* (reg8 *) Sin_Left__SIO_DIFF)
#endif /* (Sin_Left__SIO_CFG) */

/* Interrupt Registers */
#if defined(Sin_Left__INTSTAT)
    #define Sin_Left_INTSTAT            (* (reg8 *) Sin_Left__INTSTAT)
    #define Sin_Left_SNAP               (* (reg8 *) Sin_Left__SNAP)
    
	#define Sin_Left_0_INTTYPE_REG 		(* (reg8 *) Sin_Left__0__INTTYPE)
#endif /* (Sin_Left__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Sin_Left_H */


/* [] END OF FILE */
