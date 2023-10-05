/*******************************************************************************
* File Name: D2_Right.h  
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

#if !defined(CY_PINS_D2_Right_H) /* Pins D2_Right_H */
#define CY_PINS_D2_Right_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "D2_Right_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 D2_Right__PORT == 15 && ((D2_Right__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    D2_Right_Write(uint8 value);
void    D2_Right_SetDriveMode(uint8 mode);
uint8   D2_Right_ReadDataReg(void);
uint8   D2_Right_Read(void);
void    D2_Right_SetInterruptMode(uint16 position, uint16 mode);
uint8   D2_Right_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the D2_Right_SetDriveMode() function.
     *  @{
     */
        #define D2_Right_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define D2_Right_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define D2_Right_DM_RES_UP          PIN_DM_RES_UP
        #define D2_Right_DM_RES_DWN         PIN_DM_RES_DWN
        #define D2_Right_DM_OD_LO           PIN_DM_OD_LO
        #define D2_Right_DM_OD_HI           PIN_DM_OD_HI
        #define D2_Right_DM_STRONG          PIN_DM_STRONG
        #define D2_Right_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define D2_Right_MASK               D2_Right__MASK
#define D2_Right_SHIFT              D2_Right__SHIFT
#define D2_Right_WIDTH              1u

/* Interrupt constants */
#if defined(D2_Right__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in D2_Right_SetInterruptMode() function.
     *  @{
     */
        #define D2_Right_INTR_NONE      (uint16)(0x0000u)
        #define D2_Right_INTR_RISING    (uint16)(0x0001u)
        #define D2_Right_INTR_FALLING   (uint16)(0x0002u)
        #define D2_Right_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define D2_Right_INTR_MASK      (0x01u) 
#endif /* (D2_Right__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define D2_Right_PS                     (* (reg8 *) D2_Right__PS)
/* Data Register */
#define D2_Right_DR                     (* (reg8 *) D2_Right__DR)
/* Port Number */
#define D2_Right_PRT_NUM                (* (reg8 *) D2_Right__PRT) 
/* Connect to Analog Globals */                                                  
#define D2_Right_AG                     (* (reg8 *) D2_Right__AG)                       
/* Analog MUX bux enable */
#define D2_Right_AMUX                   (* (reg8 *) D2_Right__AMUX) 
/* Bidirectional Enable */                                                        
#define D2_Right_BIE                    (* (reg8 *) D2_Right__BIE)
/* Bit-mask for Aliased Register Access */
#define D2_Right_BIT_MASK               (* (reg8 *) D2_Right__BIT_MASK)
/* Bypass Enable */
#define D2_Right_BYP                    (* (reg8 *) D2_Right__BYP)
/* Port wide control signals */                                                   
#define D2_Right_CTL                    (* (reg8 *) D2_Right__CTL)
/* Drive Modes */
#define D2_Right_DM0                    (* (reg8 *) D2_Right__DM0) 
#define D2_Right_DM1                    (* (reg8 *) D2_Right__DM1)
#define D2_Right_DM2                    (* (reg8 *) D2_Right__DM2) 
/* Input Buffer Disable Override */
#define D2_Right_INP_DIS                (* (reg8 *) D2_Right__INP_DIS)
/* LCD Common or Segment Drive */
#define D2_Right_LCD_COM_SEG            (* (reg8 *) D2_Right__LCD_COM_SEG)
/* Enable Segment LCD */
#define D2_Right_LCD_EN                 (* (reg8 *) D2_Right__LCD_EN)
/* Slew Rate Control */
#define D2_Right_SLW                    (* (reg8 *) D2_Right__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define D2_Right_PRTDSI__CAPS_SEL       (* (reg8 *) D2_Right__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define D2_Right_PRTDSI__DBL_SYNC_IN    (* (reg8 *) D2_Right__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define D2_Right_PRTDSI__OE_SEL0        (* (reg8 *) D2_Right__PRTDSI__OE_SEL0) 
#define D2_Right_PRTDSI__OE_SEL1        (* (reg8 *) D2_Right__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define D2_Right_PRTDSI__OUT_SEL0       (* (reg8 *) D2_Right__PRTDSI__OUT_SEL0) 
#define D2_Right_PRTDSI__OUT_SEL1       (* (reg8 *) D2_Right__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define D2_Right_PRTDSI__SYNC_OUT       (* (reg8 *) D2_Right__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(D2_Right__SIO_CFG)
    #define D2_Right_SIO_HYST_EN        (* (reg8 *) D2_Right__SIO_HYST_EN)
    #define D2_Right_SIO_REG_HIFREQ     (* (reg8 *) D2_Right__SIO_REG_HIFREQ)
    #define D2_Right_SIO_CFG            (* (reg8 *) D2_Right__SIO_CFG)
    #define D2_Right_SIO_DIFF           (* (reg8 *) D2_Right__SIO_DIFF)
#endif /* (D2_Right__SIO_CFG) */

/* Interrupt Registers */
#if defined(D2_Right__INTSTAT)
    #define D2_Right_INTSTAT            (* (reg8 *) D2_Right__INTSTAT)
    #define D2_Right_SNAP               (* (reg8 *) D2_Right__SNAP)
    
	#define D2_Right_0_INTTYPE_REG 		(* (reg8 *) D2_Right__0__INTTYPE)
#endif /* (D2_Right__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_D2_Right_H */


/* [] END OF FILE */
