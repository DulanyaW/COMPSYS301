/*******************************************************************************
* File Name: Timer_TS_PM.c
* Version 2.80
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Timer_TS.h"

static Timer_TS_backupStruct Timer_TS_backup;


/*******************************************************************************
* Function Name: Timer_TS_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_TS_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Timer_TS_SaveConfig(void) 
{
    #if (!Timer_TS_UsingFixedFunction)
        Timer_TS_backup.TimerUdb = Timer_TS_ReadCounter();
        Timer_TS_backup.InterruptMaskValue = Timer_TS_STATUS_MASK;
        #if (Timer_TS_UsingHWCaptureCounter)
            Timer_TS_backup.TimerCaptureCounter = Timer_TS_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Timer_TS_UDB_CONTROL_REG_REMOVED)
            Timer_TS_backup.TimerControlRegister = Timer_TS_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Timer_TS_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_TS_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_TS_RestoreConfig(void) 
{   
    #if (!Timer_TS_UsingFixedFunction)

        Timer_TS_WriteCounter(Timer_TS_backup.TimerUdb);
        Timer_TS_STATUS_MASK =Timer_TS_backup.InterruptMaskValue;
        #if (Timer_TS_UsingHWCaptureCounter)
            Timer_TS_SetCaptureCount(Timer_TS_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Timer_TS_UDB_CONTROL_REG_REMOVED)
            Timer_TS_WriteControlRegister(Timer_TS_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Timer_TS_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_TS_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Timer_TS_Sleep(void) 
{
    #if(!Timer_TS_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Timer_TS_CTRL_ENABLE == (Timer_TS_CONTROL & Timer_TS_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Timer_TS_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Timer_TS_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Timer_TS_Stop();
    Timer_TS_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_TS_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_TS_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_TS_Wakeup(void) 
{
    Timer_TS_RestoreConfig();
    #if(!Timer_TS_UDB_CONTROL_REG_REMOVED)
        if(Timer_TS_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Timer_TS_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
