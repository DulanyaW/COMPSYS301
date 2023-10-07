/*******************************************************************************
* File Name: QuadDec_MB_PM.c
* Version 3.0
*
* Description:
*  This file contains the setup, control and status commands to support 
*  component operations in low power mode.  
*
* Note:
*  None.
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "QuadDec_MB.h"

static QuadDec_MB_BACKUP_STRUCT QuadDec_MB_backup = {0u};


/*******************************************************************************
* Function Name: QuadDec_MB_SaveConfig
********************************************************************************
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void QuadDec_MB_SaveConfig(void) 
{
    #if (QuadDec_MB_COUNTER_SIZE == QuadDec_MB_COUNTER_SIZE_8_BIT)
        QuadDec_MB_Cnt8_SaveConfig();
    #else 
        /* (QuadDec_MB_COUNTER_SIZE == QuadDec_MB_COUNTER_SIZE_16_BIT) || 
         * (QuadDec_MB_COUNTER_SIZE == QuadDec_MB_COUNTER_SIZE_32_BIT)
         */
        QuadDec_MB_Cnt16_SaveConfig();
    #endif /* (QuadDec_MB_COUNTER_SIZE == QuadDec_MB_COUNTER_SIZE_8_BIT) */
}


/*******************************************************************************
* Function Name: QuadDec_MB_RestoreConfig
********************************************************************************
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void QuadDec_MB_RestoreConfig(void) 
{
    #if (QuadDec_MB_COUNTER_SIZE == QuadDec_MB_COUNTER_SIZE_8_BIT)
        QuadDec_MB_Cnt8_RestoreConfig();
    #else 
        /* (QuadDec_MB_COUNTER_SIZE == QuadDec_MB_COUNTER_SIZE_16_BIT) || 
         * (QuadDec_MB_COUNTER_SIZE == QuadDec_MB_COUNTER_SIZE_32_BIT) 
         */
        QuadDec_MB_Cnt16_RestoreConfig();
    #endif /* (QuadDec_MB_COUNTER_SIZE == QuadDec_MB_COUNTER_SIZE_8_BIT) */
}


/*******************************************************************************
* Function Name: QuadDec_MB_Sleep
********************************************************************************
* 
* Summary:
*  Prepare Quadrature Decoder Component goes to sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  QuadDec_MB_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void QuadDec_MB_Sleep(void) 
{
    if (0u != (QuadDec_MB_SR_AUX_CONTROL & QuadDec_MB_INTERRUPTS_ENABLE))
    {
        QuadDec_MB_backup.enableState = 1u;
    }
    else /* The Quadrature Decoder Component is disabled */
    {
        QuadDec_MB_backup.enableState = 0u;
    }

    QuadDec_MB_Stop();
    QuadDec_MB_SaveConfig();
}


/*******************************************************************************
* Function Name: QuadDec_MB_Wakeup
********************************************************************************
*
* Summary:
*  Prepare Quadrature Decoder Component to wake up.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  QuadDec_MB_backup - used when non-retention registers are restored.
*
*******************************************************************************/
void QuadDec_MB_Wakeup(void) 
{
    QuadDec_MB_RestoreConfig();

    if (QuadDec_MB_backup.enableState != 0u)
    {
        #if (QuadDec_MB_COUNTER_SIZE == QuadDec_MB_COUNTER_SIZE_8_BIT)
            QuadDec_MB_Cnt8_Enable();
        #else 
            /* (QuadDec_MB_COUNTER_SIZE == QuadDec_MB_COUNTER_SIZE_16_BIT) || 
            *  (QuadDec_MB_COUNTER_SIZE == QuadDec_MB_COUNTER_SIZE_32_BIT) 
            */
            QuadDec_MB_Cnt16_Enable();
        #endif /* (QuadDec_MB_COUNTER_SIZE == QuadDec_MB_COUNTER_SIZE_8_BIT) */

        /* Enable component's operation */
        QuadDec_MB_Enable();
    } /* Do nothing if component's block was disabled before */
}


/* [] END OF FILE */

