/*******************************************************************************
* File Name: PWM_A_PM.c
* Version 3.20
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_A.h"

static PWM_A_backupStruct PWM_A_backup;


/*******************************************************************************
* Function Name: PWM_A_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_A_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_A_SaveConfig(void) 
{

    #if(!PWM_A_UsingFixedFunction)
        #if(!PWM_A_PWMModeIsCenterAligned)
            PWM_A_backup.PWMPeriod = PWM_A_ReadPeriod();
        #endif /* (!PWM_A_PWMModeIsCenterAligned) */
        PWM_A_backup.PWMUdb = PWM_A_ReadCounter();
        #if (PWM_A_UseStatus)
            PWM_A_backup.InterruptMaskValue = PWM_A_STATUS_MASK;
        #endif /* (PWM_A_UseStatus) */

        #if(PWM_A_DeadBandMode == PWM_A__B_PWM__DBM_256_CLOCKS || \
            PWM_A_DeadBandMode == PWM_A__B_PWM__DBM_2_4_CLOCKS)
            PWM_A_backup.PWMdeadBandValue = PWM_A_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_A_KillModeMinTime)
             PWM_A_backup.PWMKillCounterPeriod = PWM_A_ReadKillTime();
        #endif /* (PWM_A_KillModeMinTime) */

        #if(PWM_A_UseControl)
            PWM_A_backup.PWMControlRegister = PWM_A_ReadControlRegister();
        #endif /* (PWM_A_UseControl) */
    #endif  /* (!PWM_A_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_A_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_A_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_A_RestoreConfig(void) 
{
        #if(!PWM_A_UsingFixedFunction)
            #if(!PWM_A_PWMModeIsCenterAligned)
                PWM_A_WritePeriod(PWM_A_backup.PWMPeriod);
            #endif /* (!PWM_A_PWMModeIsCenterAligned) */

            PWM_A_WriteCounter(PWM_A_backup.PWMUdb);

            #if (PWM_A_UseStatus)
                PWM_A_STATUS_MASK = PWM_A_backup.InterruptMaskValue;
            #endif /* (PWM_A_UseStatus) */

            #if(PWM_A_DeadBandMode == PWM_A__B_PWM__DBM_256_CLOCKS || \
                PWM_A_DeadBandMode == PWM_A__B_PWM__DBM_2_4_CLOCKS)
                PWM_A_WriteDeadTime(PWM_A_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_A_KillModeMinTime)
                PWM_A_WriteKillTime(PWM_A_backup.PWMKillCounterPeriod);
            #endif /* (PWM_A_KillModeMinTime) */

            #if(PWM_A_UseControl)
                PWM_A_WriteControlRegister(PWM_A_backup.PWMControlRegister);
            #endif /* (PWM_A_UseControl) */
        #endif  /* (!PWM_A_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_A_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_A_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_A_Sleep(void) 
{
    #if(PWM_A_UseControl)
        if(PWM_A_CTRL_ENABLE == (PWM_A_CONTROL & PWM_A_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_A_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_A_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_A_UseControl) */

    /* Stop component */
    PWM_A_Stop();

    /* Save registers configuration */
    PWM_A_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_A_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_A_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_A_Wakeup(void) 
{
     /* Restore registers values */
    PWM_A_RestoreConfig();

    if(PWM_A_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_A_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
