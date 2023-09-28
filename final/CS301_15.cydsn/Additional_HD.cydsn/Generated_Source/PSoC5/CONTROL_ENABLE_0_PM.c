/*******************************************************************************
* File Name: CONTROL_ENABLE_0_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "CONTROL_ENABLE_0.h"

/* Check for removal by optimization */
#if !defined(CONTROL_ENABLE_0_Sync_ctrl_reg__REMOVED)

static CONTROL_ENABLE_0_BACKUP_STRUCT  CONTROL_ENABLE_0_backup = {0u};

    
/*******************************************************************************
* Function Name: CONTROL_ENABLE_0_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void CONTROL_ENABLE_0_SaveConfig(void) 
{
    CONTROL_ENABLE_0_backup.controlState = CONTROL_ENABLE_0_Control;
}


/*******************************************************************************
* Function Name: CONTROL_ENABLE_0_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void CONTROL_ENABLE_0_RestoreConfig(void) 
{
     CONTROL_ENABLE_0_Control = CONTROL_ENABLE_0_backup.controlState;
}


/*******************************************************************************
* Function Name: CONTROL_ENABLE_0_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void CONTROL_ENABLE_0_Sleep(void) 
{
    CONTROL_ENABLE_0_SaveConfig();
}


/*******************************************************************************
* Function Name: CONTROL_ENABLE_0_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void CONTROL_ENABLE_0_Wakeup(void)  
{
    CONTROL_ENABLE_0_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
