/*
 *  drivers/misc/mediatek/pmic/mt6360/mt6360_pmu_regmap.c
 *  Driver for MT6360 PMIC regmap
 *
 *  Copyright (C) 2018 Mediatek Technology Inc.
 *  cy_huang <cy_huang@richtek.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *  See http://www.gnu.org/licenses/gpl-2.0.html for more details.
 */

#include <linux/kernel.h>
#include <linux/err.h>
#include <linux/device.h>

#include "../inc/mt6360_pmu.h"

#ifdef CONFIG_RT_REGMAP
RT_REG_DECL(MT6360_PMU_DEV_INFO, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CORE_CTRL1, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_RST1, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CRCEN, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_RST_PAS_CODE1, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_RST_PAS_CODE2, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CORE_CTRL2, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_TM_PAS_CODE1, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_TM_PAS_CODE2, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_TM_PAS_CODE3, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_TM_PAS_CODE4, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_IRQ_IND, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_IRQ_MASK, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_IRQ_SET, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_SHDN_CTRL, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_TM_INF, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_I2C_CTRL, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_CTRL1, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CHG_CTRL2, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CHG_CTRL3, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_CTRL4, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_CTRL5, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_CTRL6, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_CTRL7, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_CTRL8, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_CTRL9, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_CTRL10, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_CTRL11, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_CTRL12, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_CTRL13, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_CTRL14, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_CTRL15, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_CTRL16, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_AICC_RESULT, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_DEVICE_TYPE, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_DCP_CONTROL, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_USB_STATUS1, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_DPDM_CTRL1, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_DPDM_CTRL2, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CHG_PUMP, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_CTRL17, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CHG_CTRL18, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHRDET_CTRL1, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHRDET_CTRL2, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_DPDN_CTRL, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_HIDDEN_CTRL1, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_HIDDEN_CTRL2, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_HIDDEN_CTRL3, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_HIDDEN_CTRL4, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_HIDDEN_CTRL5, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_HIDDEN_CTRL6, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_HIDDEN_CTRL7, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_HIDDEN_CTRL8, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_HIDDEN_CTRL9, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_HIDDEN_CTRL10, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_HIDDEN_CTRL11, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_HIDDEN_CTRL12, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_HIDDEN_CTRL13, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_HIDDEN_CTRL14, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_HIDDEN_CTRL15, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_HIDDEN_CTRL16, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_HIDDEN_CTRL17, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_HIDDEN_CTRL18, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_HIDDEN_CTRL19, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_HIDDEN_CTRL20, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_HIDDEN_CTRL21, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_HIDDEN_CTRL22, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_HIDDEN_CTRL23, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_HIDDEN_CTRL24, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_HIDDEN_CTRL25, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_BC12_CTRL, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_STAT, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_RESV1, 3, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_TYPEC_OTP_TH_SEL_CODEH, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_TYPEC_OTP_TH_SEL_CODEL, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_TYPEC_OTP_HYST_TH, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_TYPEC_OTP_CTRL, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_ADC_BAT_DATA_H, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_ADC_BAT_DATA_L, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_IMID_BACKBST_ON, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_IMID_BACKBST_OFF, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_ADC_CONFIG, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_ADC_EN2, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_ADC_IDLE_T, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_ADC_RPT_1, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_ADC_RPT_2, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_ADC_RPT_3, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_ADC_RPT_ORG1, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_ADC_RPT_ORG2, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_BAT_OVP_TH_SEL_CODEH, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_BAT_OVP_TH_SEL_CODEL, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_CTRL19, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_VDDASUPPLY, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_BC12_MANUAL, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CTD_CTRL, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CHG_CTRL20, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_HIDDEN_CTRL26, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_CHG_HIDDEN_CTRL27, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_RESV2, 4, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_USBID_CTRL1, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_USBID_CTRL2, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_USBID_CTRL3, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_FLED_CFG, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_RESV3, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_FLED1_CTRL, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_FLED_STRB_CTRL, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_FLED1_STRB_CTRL2, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_FLED1_TOR_CTRL, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_FLED2_CTRL, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_RESV4, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_FLED2_STRB_CTRL2, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_FLED2_TOR_CTRL, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_FLED_VMIDTRK_CTRL1, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_FLED_VMID_RTM, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_FLED_VMIDTRK_CTRL2, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_FLED_PWSEL, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_FLED_EN, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_FLED_Hidden1, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_RGB_EN, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_RGB1_ISNK, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_RGB2_ISNK, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_RGB3_ISNK, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_RGB_ML_ISNK, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_RGB1_DIM, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_RGB2_DIM, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_RGB3_DIM, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_RESV5, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_RGB12_Freq, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_RGB34_Freq, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_RGB1_Tr, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_RGB1_Tf, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_RGB1_TON_TOFF, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_RGB2_Tr, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_RGB2_Tf, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_RGB2_TON_TOFF, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_RGB3_Tr, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_RGB3_Tf, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_RGB3_TON_TOFF, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_RGB_Hidden_CTRL1, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_RGB_Hidden_CTRL2, 1, RT_NORMAL_WR_ONCE, {});
RT_REG_DECL(MT6360_PMU_RESV6, 3, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_SPARE1, 6, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_SPARE2, 16, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_SPARE3, 16, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_SPARE4, 16, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CHG_IRQ1, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CHG_IRQ2, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CHG_IRQ3, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CHG_IRQ4, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CHG_IRQ5, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CHG_IRQ6, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_DPDM_IRQ, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CHRDET_IRQ, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_BASE_IRQ, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_FLED_IRQ1, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_FLED_IRQ2, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_RGB_IRQ, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_BUCK1_IRQ, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_BUCK2_IRQ, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_LDO_IRQ1, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_LDO_IRQ2, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CHG_STAT1, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CHG_STAT2, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CHG_STAT3, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CHG_STAT4, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CHG_STAT5, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CHG_STAT6, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_DPDM_STAT, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CHRDET_STAT, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_BASE_STAT, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_FLED_STAT1, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_FLED_STAT2, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_RGB_STAT, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_BUCK1_STAT, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_BUCK2_STAT, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_LDO_STAT1, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_LDO_STAT2, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CHG_MASK1, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CHG_MASK2, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CHG_MASK3, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CHG_MASK4, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CHG_MASK5, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CHG_MASK6, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_DPDM_MASK, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_CHRDET_MASK, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_BASE_MASK, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_FLED_MASK1, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_FLED_MASK2, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_FAULTB_MASK, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_BUCK1_MASK, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_BUCK2_MASK, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_LDO_MASK1, 1, RT_VOLATILE, {});
RT_REG_DECL(MT6360_PMU_LDO_MASK2, 1, RT_VOLATILE, {});

static const rt_register_map_t mt6360_pmu_regmap[] = {
	RT_REG(MT6360_PMU_DEV_INFO),
	RT_REG(MT6360_PMU_CORE_CTRL1),
	RT_REG(MT6360_PMU_RST1),
	RT_REG(MT6360_PMU_CRCEN),
	RT_REG(MT6360_PMU_RST_PAS_CODE1),
	RT_REG(MT6360_PMU_RST_PAS_CODE2),
	RT_REG(MT6360_PMU_CORE_CTRL2),
	RT_REG(MT6360_PMU_TM_PAS_CODE1),
	RT_REG(MT6360_PMU_TM_PAS_CODE2),
	RT_REG(MT6360_PMU_TM_PAS_CODE3),
	RT_REG(MT6360_PMU_TM_PAS_CODE4),
	RT_REG(MT6360_PMU_IRQ_IND),
	RT_REG(MT6360_PMU_IRQ_MASK),
	RT_REG(MT6360_PMU_IRQ_SET),
	RT_REG(MT6360_PMU_SHDN_CTRL),
	RT_REG(MT6360_PMU_TM_INF),
	RT_REG(MT6360_PMU_I2C_CTRL),
	RT_REG(MT6360_PMU_CHG_CTRL1),
	RT_REG(MT6360_PMU_CHG_CTRL2),
	RT_REG(MT6360_PMU_CHG_CTRL3),
	RT_REG(MT6360_PMU_CHG_CTRL4),
	RT_REG(MT6360_PMU_CHG_CTRL5),
	RT_REG(MT6360_PMU_CHG_CTRL6),
	RT_REG(MT6360_PMU_CHG_CTRL7),
	RT_REG(MT6360_PMU_CHG_CTRL8),
	RT_REG(MT6360_PMU_CHG_CTRL9),
	RT_REG(MT6360_PMU_CHG_CTRL10),
	RT_REG(MT6360_PMU_CHG_CTRL11),
	RT_REG(MT6360_PMU_CHG_CTRL12),
	RT_REG(MT6360_PMU_CHG_CTRL13),
	RT_REG(MT6360_PMU_CHG_CTRL14),
	RT_REG(MT6360_PMU_CHG_CTRL15),
	RT_REG(MT6360_PMU_CHG_CTRL16),
	RT_REG(MT6360_PMU_CHG_AICC_RESULT),
	RT_REG(MT6360_PMU_DEVICE_TYPE),
	RT_REG(MT6360_PMU_DCP_CONTROL),
	RT_REG(MT6360_PMU_USB_STATUS1),
	RT_REG(MT6360_PMU_DPDM_CTRL1),
	RT_REG(MT6360_PMU_DPDM_CTRL2),
	RT_REG(MT6360_PMU_CHG_PUMP),
	RT_REG(MT6360_PMU_CHG_CTRL17),
	RT_REG(MT6360_PMU_CHG_CTRL18),
	RT_REG(MT6360_PMU_CHRDET_CTRL1),
	RT_REG(MT6360_PMU_CHRDET_CTRL2),
	RT_REG(MT6360_PMU_DPDN_CTRL),
	RT_REG(MT6360_PMU_CHG_HIDDEN_CTRL1),
	RT_REG(MT6360_PMU_CHG_HIDDEN_CTRL2),
	RT_REG(MT6360_PMU_CHG_HIDDEN_CTRL3),
	RT_REG(MT6360_PMU_CHG_HIDDEN_CTRL4),
	RT_REG(MT6360_PMU_CHG_HIDDEN_CTRL5),
	RT_REG(MT6360_PMU_CHG_HIDDEN_CTRL6),
	RT_REG(MT6360_PMU_CHG_HIDDEN_CTRL7),
	RT_REG(MT6360_PMU_CHG_HIDDEN_CTRL8),
	RT_REG(MT6360_PMU_CHG_HIDDEN_CTRL9),
	RT_REG(MT6360_PMU_CHG_HIDDEN_CTRL10),
	RT_REG(MT6360_PMU_CHG_HIDDEN_CTRL11),
	RT_REG(MT6360_PMU_CHG_HIDDEN_CTRL12),
	RT_REG(MT6360_PMU_CHG_HIDDEN_CTRL13),
	RT_REG(MT6360_PMU_CHG_HIDDEN_CTRL14),
	RT_REG(MT6360_PMU_CHG_HIDDEN_CTRL15),
	RT_REG(MT6360_PMU_CHG_HIDDEN_CTRL16),
	RT_REG(MT6360_PMU_CHG_HIDDEN_CTRL17),
	RT_REG(MT6360_PMU_CHG_HIDDEN_CTRL18),
	RT_REG(MT6360_PMU_CHG_HIDDEN_CTRL19),
	RT_REG(MT6360_PMU_CHG_HIDDEN_CTRL20),
	RT_REG(MT6360_PMU_CHG_HIDDEN_CTRL21),
	RT_REG(MT6360_PMU_CHG_HIDDEN_CTRL22),
	RT_REG(MT6360_PMU_CHG_HIDDEN_CTRL23),
	RT_REG(MT6360_PMU_CHG_HIDDEN_CTRL24),
	RT_REG(MT6360_PMU_CHG_HIDDEN_CTRL25),
	RT_REG(MT6360_PMU_BC12_CTRL),
	RT_REG(MT6360_PMU_CHG_STAT),
	RT_REG(MT6360_PMU_RESV1),
	RT_REG(MT6360_PMU_TYPEC_OTP_TH_SEL_CODEH),
	RT_REG(MT6360_PMU_TYPEC_OTP_TH_SEL_CODEL),
	RT_REG(MT6360_PMU_TYPEC_OTP_HYST_TH),
	RT_REG(MT6360_PMU_TYPEC_OTP_CTRL),
	RT_REG(MT6360_PMU_ADC_BAT_DATA_H),
	RT_REG(MT6360_PMU_ADC_BAT_DATA_L),
	RT_REG(MT6360_PMU_IMID_BACKBST_ON),
	RT_REG(MT6360_PMU_IMID_BACKBST_OFF),
	RT_REG(MT6360_PMU_ADC_CONFIG),
	RT_REG(MT6360_PMU_ADC_EN2),
	RT_REG(MT6360_PMU_ADC_IDLE_T),
	RT_REG(MT6360_PMU_ADC_RPT_1),
	RT_REG(MT6360_PMU_ADC_RPT_2),
	RT_REG(MT6360_PMU_ADC_RPT_3),
	RT_REG(MT6360_PMU_ADC_RPT_ORG1),
	RT_REG(MT6360_PMU_ADC_RPT_ORG2),
	RT_REG(MT6360_PMU_BAT_OVP_TH_SEL_CODEH),
	RT_REG(MT6360_PMU_BAT_OVP_TH_SEL_CODEL),
	RT_REG(MT6360_PMU_CHG_CTRL19),
	RT_REG(MT6360_PMU_VDDASUPPLY),
	RT_REG(MT6360_PMU_BC12_MANUAL),
	RT_REG(MT6360_PMU_CTD_CTRL),
	RT_REG(MT6360_PMU_CHG_CTRL20),
	RT_REG(MT6360_PMU_CHG_HIDDEN_CTRL26),
	RT_REG(MT6360_PMU_CHG_HIDDEN_CTRL27),
	RT_REG(MT6360_PMU_RESV2),
	RT_REG(MT6360_PMU_USBID_CTRL1),
	RT_REG(MT6360_PMU_USBID_CTRL2),
	RT_REG(MT6360_PMU_USBID_CTRL3),
	RT_REG(MT6360_PMU_FLED_CFG),
	RT_REG(MT6360_PMU_RESV3),
	RT_REG(MT6360_PMU_FLED1_CTRL),
	RT_REG(MT6360_PMU_FLED_STRB_CTRL),
	RT_REG(MT6360_PMU_FLED1_STRB_CTRL2),
	RT_REG(MT6360_PMU_FLED1_TOR_CTRL),
	RT_REG(MT6360_PMU_FLED2_CTRL),
	RT_REG(MT6360_PMU_RESV4),
	RT_REG(MT6360_PMU_FLED2_STRB_CTRL2),
	RT_REG(MT6360_PMU_FLED2_TOR_CTRL),
	RT_REG(MT6360_PMU_FLED_VMIDTRK_CTRL1),
	RT_REG(MT6360_PMU_FLED_VMID_RTM),
	RT_REG(MT6360_PMU_FLED_VMIDTRK_CTRL2),
	RT_REG(MT6360_PMU_FLED_PWSEL),
	RT_REG(MT6360_PMU_FLED_EN),
	RT_REG(MT6360_PMU_FLED_Hidden1),
	RT_REG(MT6360_PMU_RGB_EN),
	RT_REG(MT6360_PMU_RGB1_ISNK),
	RT_REG(MT6360_PMU_RGB2_ISNK),
	RT_REG(MT6360_PMU_RGB3_ISNK),
	RT_REG(MT6360_PMU_RGB_ML_ISNK),
	RT_REG(MT6360_PMU_RGB1_DIM),
	RT_REG(MT6360_PMU_RGB2_DIM),
	RT_REG(MT6360_PMU_RGB3_DIM),
	RT_REG(MT6360_PMU_RESV5),
	RT_REG(MT6360_PMU_RGB12_Freq),
	RT_REG(MT6360_PMU_RGB34_Freq),
	RT_REG(MT6360_PMU_RGB1_Tr),
	RT_REG(MT6360_PMU_RGB1_Tf),
	RT_REG(MT6360_PMU_RGB1_TON_TOFF),
	RT_REG(MT6360_PMU_RGB2_Tr),
	RT_REG(MT6360_PMU_RGB2_Tf),
	RT_REG(MT6360_PMU_RGB2_TON_TOFF),
	RT_REG(MT6360_PMU_RGB3_Tr),
	RT_REG(MT6360_PMU_RGB3_Tf),
	RT_REG(MT6360_PMU_RGB3_TON_TOFF),
	RT_REG(MT6360_PMU_RGB_Hidden_CTRL1),
	RT_REG(MT6360_PMU_RGB_Hidden_CTRL2),
	RT_REG(MT6360_PMU_RESV6),
	RT_REG(MT6360_PMU_SPARE1),
	RT_REG(MT6360_PMU_SPARE2),
	RT_REG(MT6360_PMU_SPARE3),
	RT_REG(MT6360_PMU_SPARE4),
	RT_REG(MT6360_PMU_CHG_IRQ1),
	RT_REG(MT6360_PMU_CHG_IRQ2),
	RT_REG(MT6360_PMU_CHG_IRQ3),
	RT_REG(MT6360_PMU_CHG_IRQ4),
	RT_REG(MT6360_PMU_CHG_IRQ5),
	RT_REG(MT6360_PMU_CHG_IRQ6),
	RT_REG(MT6360_PMU_DPDM_IRQ),
	RT_REG(MT6360_PMU_CHRDET_IRQ),
	RT_REG(MT6360_PMU_BASE_IRQ),
	RT_REG(MT6360_PMU_FLED_IRQ1),
	RT_REG(MT6360_PMU_FLED_IRQ2),
	RT_REG(MT6360_PMU_RGB_IRQ),
	RT_REG(MT6360_PMU_BUCK1_IRQ),
	RT_REG(MT6360_PMU_BUCK2_IRQ),
	RT_REG(MT6360_PMU_LDO_IRQ1),
	RT_REG(MT6360_PMU_LDO_IRQ2),
	RT_REG(MT6360_PMU_CHG_STAT1),
	RT_REG(MT6360_PMU_CHG_STAT2),
	RT_REG(MT6360_PMU_CHG_STAT3),
	RT_REG(MT6360_PMU_CHG_STAT4),
	RT_REG(MT6360_PMU_CHG_STAT5),
	RT_REG(MT6360_PMU_CHG_STAT6),
	RT_REG(MT6360_PMU_DPDM_STAT),
	RT_REG(MT6360_PMU_CHRDET_STAT),
	RT_REG(MT6360_PMU_BASE_STAT),
	RT_REG(MT6360_PMU_FLED_STAT1),
	RT_REG(MT6360_PMU_FLED_STAT2),
	RT_REG(MT6360_PMU_RGB_STAT),
	RT_REG(MT6360_PMU_BUCK1_STAT),
	RT_REG(MT6360_PMU_BUCK2_STAT),
	RT_REG(MT6360_PMU_LDO_STAT1),
	RT_REG(MT6360_PMU_LDO_STAT2),
	RT_REG(MT6360_PMU_CHG_MASK1),
	RT_REG(MT6360_PMU_CHG_MASK2),
	RT_REG(MT6360_PMU_CHG_MASK3),
	RT_REG(MT6360_PMU_CHG_MASK4),
	RT_REG(MT6360_PMU_CHG_MASK5),
	RT_REG(MT6360_PMU_CHG_MASK6),
	RT_REG(MT6360_PMU_DPDM_MASK),
	RT_REG(MT6360_PMU_CHRDET_MASK),
	RT_REG(MT6360_PMU_BASE_MASK),
	RT_REG(MT6360_PMU_FLED_MASK1),
	RT_REG(MT6360_PMU_FLED_MASK2),
	RT_REG(MT6360_PMU_FAULTB_MASK),
	RT_REG(MT6360_PMU_BUCK1_MASK),
	RT_REG(MT6360_PMU_BUCK2_MASK),
	RT_REG(MT6360_PMU_LDO_MASK1),
	RT_REG(MT6360_PMU_LDO_MASK2),
};

static struct rt_regmap_properties mt6360_pmu_regmap_props = {
	.register_num = ARRAY_SIZE(mt6360_pmu_regmap),
	.rm = mt6360_pmu_regmap,
	.rt_regmap_mode = RT_MULTI_BYTE | RT_DBG_SPECIAL,
	.aliases = "mt6360_pmu",
};

int mt6360_pmu_regmap_register(struct mt6360_pmu_info *mpi,
			       struct rt_regmap_fops *fops)
{
	mt6360_pmu_regmap_props.name = devm_kasprintf(mpi->dev, GFP_KERNEL,
						      "mt6360_pmu.%s",
						      dev_name(mpi->dev));
	mpi->regmap = rt_regmap_device_register(&mt6360_pmu_regmap_props, fops,
						 mpi->dev, mpi->i2c, mpi);
	return mpi->regmap ? 0 : -EINVAL;
}
EXPORT_SYMBOL_GPL(mt6360_pmu_regmap_register);

void mt6360_pmu_regmap_unregister(struct mt6360_pmu_info *mpi)
{
	rt_regmap_device_unregister(mpi->regmap);
}
EXPORT_SYMBOL_GPL(mt6360_pmu_regmap_unregister);
#else
int mt6360_pmu_regmap_register(struct mt6360_pmu_info *mpi,
			       struct rt_regmap_fops *fops)
{
	return 0;
}
EXPORT_SYMBOL_GPL(mt6360_pmu_regmap_register);

void mt6360_pmu_regmap_unregister(struct mt6360_pmu_info *mpi)
{
}
EXPORT_SYMBOL_GPL(mt6360_pmu_regmap_unregister);
#endif /* CONFIG_RT_REGMAP */
