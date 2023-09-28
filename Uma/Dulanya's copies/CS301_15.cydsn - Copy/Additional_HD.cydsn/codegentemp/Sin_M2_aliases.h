/*******************************************************************************
* File Name: Sin_M2.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Sin_M2_ALIASES_H) /* Pins Sin_M2_ALIASES_H */
#define CY_PINS_Sin_M2_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Sin_M2_0			(Sin_M2__0__PC)
#define Sin_M2_0_INTR	((uint16)((uint16)0x0001u << Sin_M2__0__SHIFT))

#define Sin_M2_INTR_ALL	 ((uint16)(Sin_M2_0_INTR))

#endif /* End Pins Sin_M2_ALIASES_H */


/* [] END OF FILE */
