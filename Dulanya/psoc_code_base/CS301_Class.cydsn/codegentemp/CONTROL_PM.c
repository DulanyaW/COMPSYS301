/*******************************************************************************
* File Name: CONTROL_PM.c
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

#include "CONTROL.h"

/* Check for removal by optimization */
#if !defined(CONTROL_Sync_ctrl_reg__REMOVED)

static CONTROL_BACKUP_STRUCT  CONTROL_backup = {0u};

    
/*******************************************************************************
* Function Name: CONTROL_SaveConfig
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
void CONTROL_SaveConfig(void) 
{
    CONTROL_backup.controlState = CONTROL_Control;
}


/*******************************************************************************
* Function Name: CONTROL_RestoreConfig
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
void CONTROL_RestoreConfig(void) 
{
     CONTROL_Control = CONTROL_backup.controlState;
}


/*******************************************************************************
* Function Name: CONTROL_Sleep
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
void CONTROL_Sleep(void) 
{
    CONTROL_SaveConfig();
}


/*******************************************************************************
* Function Name: CONTROL_Wakeup
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
void CONTROL_Wakeup(void)  
{
    CONTROL_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
