/*******************************************************************************
* File Name: cyfitter.h
* 
* PSoC Creator  4.4
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2020 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice.h"
#include "cydevice_trm.h"

/* Pin_1 */
#define Pin_1__0__INTTYPE CYREG_PICU3_INTTYPE7
#define Pin_1__0__MASK 0x80u
#define Pin_1__0__PC CYREG_PRT3_PC7
#define Pin_1__0__PORT 3u
#define Pin_1__0__SHIFT 7u
#define Pin_1__AG CYREG_PRT3_AG
#define Pin_1__AMUX CYREG_PRT3_AMUX
#define Pin_1__BIE CYREG_PRT3_BIE
#define Pin_1__BIT_MASK CYREG_PRT3_BIT_MASK
#define Pin_1__BYP CYREG_PRT3_BYP
#define Pin_1__CTL CYREG_PRT3_CTL
#define Pin_1__DM0 CYREG_PRT3_DM0
#define Pin_1__DM1 CYREG_PRT3_DM1
#define Pin_1__DM2 CYREG_PRT3_DM2
#define Pin_1__DR CYREG_PRT3_DR
#define Pin_1__INP_DIS CYREG_PRT3_INP_DIS
#define Pin_1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define Pin_1__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define Pin_1__LCD_EN CYREG_PRT3_LCD_EN
#define Pin_1__MASK 0x80u
#define Pin_1__PORT 3u
#define Pin_1__PRT CYREG_PRT3_PRT
#define Pin_1__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define Pin_1__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define Pin_1__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define Pin_1__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define Pin_1__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define Pin_1__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define Pin_1__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define Pin_1__PS CYREG_PRT3_PS
#define Pin_1__SHIFT 7u
#define Pin_1__SLW CYREG_PRT3_SLW

/* ADC_SAR_1 */
#define ADC_SAR_1_ADC_SAR__CLK CYREG_SAR1_CLK
#define ADC_SAR_1_ADC_SAR__CSR0 CYREG_SAR1_CSR0
#define ADC_SAR_1_ADC_SAR__CSR1 CYREG_SAR1_CSR1
#define ADC_SAR_1_ADC_SAR__CSR2 CYREG_SAR1_CSR2
#define ADC_SAR_1_ADC_SAR__CSR3 CYREG_SAR1_CSR3
#define ADC_SAR_1_ADC_SAR__CSR4 CYREG_SAR1_CSR4
#define ADC_SAR_1_ADC_SAR__CSR5 CYREG_SAR1_CSR5
#define ADC_SAR_1_ADC_SAR__CSR6 CYREG_SAR1_CSR6
#define ADC_SAR_1_ADC_SAR__PM_ACT_CFG CYREG_PM_ACT_CFG11
#define ADC_SAR_1_ADC_SAR__PM_ACT_MSK 0x02u
#define ADC_SAR_1_ADC_SAR__PM_STBY_CFG CYREG_PM_STBY_CFG11
#define ADC_SAR_1_ADC_SAR__PM_STBY_MSK 0x02u
#define ADC_SAR_1_ADC_SAR__SW0 CYREG_SAR1_SW0
#define ADC_SAR_1_ADC_SAR__SW2 CYREG_SAR1_SW2
#define ADC_SAR_1_ADC_SAR__SW3 CYREG_SAR1_SW3
#define ADC_SAR_1_ADC_SAR__SW4 CYREG_SAR1_SW4
#define ADC_SAR_1_ADC_SAR__SW6 CYREG_SAR1_SW6
#define ADC_SAR_1_ADC_SAR__TR0 CYREG_SAR1_TR0
#define ADC_SAR_1_ADC_SAR__WRK0 CYREG_SAR1_WRK0
#define ADC_SAR_1_ADC_SAR__WRK1 CYREG_SAR1_WRK1
#define ADC_SAR_1_Bypass__0__INTTYPE CYREG_PICU0_INTTYPE2
#define ADC_SAR_1_Bypass__0__MASK 0x04u
#define ADC_SAR_1_Bypass__0__PC CYREG_PRT0_PC2
#define ADC_SAR_1_Bypass__0__PORT 0u
#define ADC_SAR_1_Bypass__0__SHIFT 2u
#define ADC_SAR_1_Bypass__AG CYREG_PRT0_AG
#define ADC_SAR_1_Bypass__AMUX CYREG_PRT0_AMUX
#define ADC_SAR_1_Bypass__BIE CYREG_PRT0_BIE
#define ADC_SAR_1_Bypass__BIT_MASK CYREG_PRT0_BIT_MASK
#define ADC_SAR_1_Bypass__BYP CYREG_PRT0_BYP
#define ADC_SAR_1_Bypass__CTL CYREG_PRT0_CTL
#define ADC_SAR_1_Bypass__DM0 CYREG_PRT0_DM0
#define ADC_SAR_1_Bypass__DM1 CYREG_PRT0_DM1
#define ADC_SAR_1_Bypass__DM2 CYREG_PRT0_DM2
#define ADC_SAR_1_Bypass__DR CYREG_PRT0_DR
#define ADC_SAR_1_Bypass__INP_DIS CYREG_PRT0_INP_DIS
#define ADC_SAR_1_Bypass__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define ADC_SAR_1_Bypass__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define ADC_SAR_1_Bypass__LCD_EN CYREG_PRT0_LCD_EN
#define ADC_SAR_1_Bypass__MASK 0x04u
#define ADC_SAR_1_Bypass__PORT 0u
#define ADC_SAR_1_Bypass__PRT CYREG_PRT0_PRT
#define ADC_SAR_1_Bypass__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define ADC_SAR_1_Bypass__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define ADC_SAR_1_Bypass__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define ADC_SAR_1_Bypass__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define ADC_SAR_1_Bypass__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define ADC_SAR_1_Bypass__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define ADC_SAR_1_Bypass__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define ADC_SAR_1_Bypass__PS CYREG_PRT0_PS
#define ADC_SAR_1_Bypass__SHIFT 2u
#define ADC_SAR_1_Bypass__SLW CYREG_PRT0_SLW
#define ADC_SAR_1_IRQ__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define ADC_SAR_1_IRQ__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define ADC_SAR_1_IRQ__INTC_MASK 0x01u
#define ADC_SAR_1_IRQ__INTC_NUMBER 0u
#define ADC_SAR_1_IRQ__INTC_PRIOR_NUM 7u
#define ADC_SAR_1_IRQ__INTC_PRIOR_REG CYREG_NVIC_PRI_0
#define ADC_SAR_1_IRQ__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define ADC_SAR_1_IRQ__INTC_SET_PD_REG CYREG_NVIC_SETPEND0
#define ADC_SAR_1_theACLK__CFG0 CYREG_CLKDIST_ACFG0_CFG0
#define ADC_SAR_1_theACLK__CFG1 CYREG_CLKDIST_ACFG0_CFG1
#define ADC_SAR_1_theACLK__CFG2 CYREG_CLKDIST_ACFG0_CFG2
#define ADC_SAR_1_theACLK__CFG2_SRC_SEL_MASK 0x07u
#define ADC_SAR_1_theACLK__CFG3 CYREG_CLKDIST_ACFG0_CFG3
#define ADC_SAR_1_theACLK__CFG3_PHASE_DLY_MASK 0x0Fu
#define ADC_SAR_1_theACLK__INDEX 0x00u
#define ADC_SAR_1_theACLK__PM_ACT_CFG CYREG_PM_ACT_CFG1
#define ADC_SAR_1_theACLK__PM_ACT_MSK 0x01u
#define ADC_SAR_1_theACLK__PM_STBY_CFG CYREG_PM_STBY_CFG1
#define ADC_SAR_1_theACLK__PM_STBY_MSK 0x01u

/* Miscellaneous */
#define BCLK__BUS_CLK__HZ 24000000U
#define BCLK__BUS_CLK__KHZ 24000U
#define BCLK__BUS_CLK__MHZ 24U
#define CY_PROJECT_NAME "hwTask1"
#define CY_VERSION "PSoC Creator  4.4"
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 26u
#define CYDEV_CHIP_DIE_PSOC5LP 2u
#define CYDEV_CHIP_DIE_PSOC5TM 3u
#define CYDEV_CHIP_DIE_TMA4 4u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 5u
#define CYDEV_CHIP_FAMILY_FM3 6u
#define CYDEV_CHIP_FAMILY_FM4 7u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_PSOC6 4u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC5
#define CYDEV_CHIP_JTAG_ID 0x2E123069u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 26u
#define CYDEV_CHIP_MEMBER_4AA 25u
#define CYDEV_CHIP_MEMBER_4AB 30u
#define CYDEV_CHIP_MEMBER_4AC 14u
#define CYDEV_CHIP_MEMBER_4AD 15u
#define CYDEV_CHIP_MEMBER_4AE 16u
#define CYDEV_CHIP_MEMBER_4D 20u
#define CYDEV_CHIP_MEMBER_4E 6u
#define CYDEV_CHIP_MEMBER_4F 27u
#define CYDEV_CHIP_MEMBER_4G 4u
#define CYDEV_CHIP_MEMBER_4H 24u
#define CYDEV_CHIP_MEMBER_4I 32u
#define CYDEV_CHIP_MEMBER_4J 21u
#define CYDEV_CHIP_MEMBER_4K 22u
#define CYDEV_CHIP_MEMBER_4L 31u
#define CYDEV_CHIP_MEMBER_4M 29u
#define CYDEV_CHIP_MEMBER_4N 11u
#define CYDEV_CHIP_MEMBER_4O 8u
#define CYDEV_CHIP_MEMBER_4P 28u
#define CYDEV_CHIP_MEMBER_4Q 17u
#define CYDEV_CHIP_MEMBER_4R 9u
#define CYDEV_CHIP_MEMBER_4S 12u
#define CYDEV_CHIP_MEMBER_4T 10u
#define CYDEV_CHIP_MEMBER_4U 5u
#define CYDEV_CHIP_MEMBER_4V 23u
#define CYDEV_CHIP_MEMBER_4W 13u
#define CYDEV_CHIP_MEMBER_4X 7u
#define CYDEV_CHIP_MEMBER_4Y 18u
#define CYDEV_CHIP_MEMBER_4Z 19u
#define CYDEV_CHIP_MEMBER_5A 3u
#define CYDEV_CHIP_MEMBER_5B 2u
#define CYDEV_CHIP_MEMBER_6A 33u
#define CYDEV_CHIP_MEMBER_FM3 37u
#define CYDEV_CHIP_MEMBER_FM4 38u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 34u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 35u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 36u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_5B
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4AA_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AB_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AC_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AD_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AE_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4R_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4S_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4T_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4V_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4W_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4X_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Y_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Z_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_6A_ES 17u
#define CYDEV_CHIP_REVISION_6A_NO_UDB 33u
#define CYDEV_CHIP_REVISION_6A_PRODUCTION 33u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_5B_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_FASTBOOT_ENABLED 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_DMA 0
#define CYDEV_CONFIGURATION_ECC 1
#define CYDEV_CONFIGURATION_IMOENABLED CYDEV_CONFIG_FASTBOOT_ENABLED
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_ENABLE_MASK 0x20u
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DEBUG
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD_SWV
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_XRES 0
#define CYDEV_DMA_CHANNELS_AVAILABLE 24u
#define CYDEV_ECC_ENABLE 0
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_INSTRUCT_CACHE_ENABLED 1
#define CYDEV_INTR_RISING 0x00000001u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_PROTECTION_ENABLE 0
#define CYDEV_STACK_SIZE 0x0800
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VDDA 5.0
#define CYDEV_VDDA_MV 5000
#define CYDEV_VDDD 5.0
#define CYDEV_VDDD_MV 5000
#define CYDEV_VDDIO0 5.0
#define CYDEV_VDDIO0_MV 5000
#define CYDEV_VDDIO1 5.0
#define CYDEV_VDDIO1_MV 5000
#define CYDEV_VDDIO2 5.0
#define CYDEV_VDDIO2_MV 5000
#define CYDEV_VDDIO3 5.0
#define CYDEV_VDDIO3_MV 5000
#define CYDEV_VIO0 5.0
#define CYDEV_VIO0_MV 5000
#define CYDEV_VIO1 5.0
#define CYDEV_VIO1_MV 5000
#define CYDEV_VIO2 5.0
#define CYDEV_VIO2_MV 5000
#define CYDEV_VIO3 5.0
#define CYDEV_VIO3_MV 5000
#define CYIPBLOCK_ARM_CM3_VERSION 0
#define CYIPBLOCK_P3_ANAIF_VERSION 0
#define CYIPBLOCK_P3_CAN_VERSION 0
#define CYIPBLOCK_P3_CAPSENSE_VERSION 0
#define CYIPBLOCK_P3_COMP_VERSION 0
#define CYIPBLOCK_P3_DECIMATOR_VERSION 0
#define CYIPBLOCK_P3_DFB_VERSION 0
#define CYIPBLOCK_P3_DMA_VERSION 0
#define CYIPBLOCK_P3_DRQ_VERSION 0
#define CYIPBLOCK_P3_DSM_VERSION 0
#define CYIPBLOCK_P3_EMIF_VERSION 0
#define CYIPBLOCK_P3_I2C_VERSION 0
#define CYIPBLOCK_P3_LCD_VERSION 0
#define CYIPBLOCK_P3_LPF_VERSION 0
#define CYIPBLOCK_P3_OPAMP_VERSION 0
#define CYIPBLOCK_P3_PM_VERSION 0
#define CYIPBLOCK_P3_SCCT_VERSION 0
#define CYIPBLOCK_P3_TIMER_VERSION 0
#define CYIPBLOCK_P3_USB_VERSION 0
#define CYIPBLOCK_P3_VIDAC_VERSION 0
#define CYIPBLOCK_P3_VREF_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 0
#define CYIPBLOCK_S8_IRQ_VERSION 0
#define CYIPBLOCK_S8_SAR_VERSION 0
#define CYIPBLOCK_S8_SIO_VERSION 0
#define CYIPBLOCK_S8_UDB_VERSION 0
#define DMA_CHANNELS_USED__MASK0 0x00000000u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
