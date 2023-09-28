/*******************************************************************************
* File Name: DIRECTION_PM.c
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

#include "DIRECTION.h"

/* Check for removal by optimization */
#if !defined(DIRECTION_Sync_ctrl_reg__REMOVED)

static DIRECTION_BACKUP_STRUCT  DIRECTION_backup = {0u};

    
/*******************************************************************************
* Function Name: DIRECTION_SaveConfig
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
void DIRECTION_SaveConfig(void) 
{
    DIRECTION_backup.controlState = DIRECTION_Control;
}


/*******************************************************************************
* Function Name: DIRECTION_RestoreConfig
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
void DIRECTION_RestoreConfig(void) 
{
     DIRECTION_Control = DIRECTION_backup.controlState;
}


/*******************************************************************************
* Function Name: DIRECTION_Sleep
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
void DIRECTION_Sleep(void) 
{
    DIRECTION_SaveConfig();
}


/*******************************************************************************
* Function Name: DIRECTION_Wakeup
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
void DIRECTION_Wakeup(void)  
{
    DIRECTION_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
