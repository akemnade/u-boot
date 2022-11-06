/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * (C) Copyright 2022
 * Andreas Kemnade
 *
 * based on Panda data and analysis of running system
 */
#ifndef _EMBT2WS_MUX_DATA_H_
#define _EMBT2WS_MUX_DATA_H_

#include <asm/arch/mux_omap4.h>

const struct pad_conf_entry core_padconf_array_essential[] = {

{GPMC_AD0, (PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M1)}, /* sdmmc2_dat0 */
{GPMC_AD1, (PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M1)}, /* sdmmc2_dat1 */
{GPMC_AD2, (PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M1)}, /* sdmmc2_dat2 */
{GPMC_AD3, (PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M1)}, /* sdmmc2_dat3 */
{GPMC_AD4, (PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M1)}, /* sdmmc2_dat4 */
{GPMC_AD5, (PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M1)}, /* sdmmc2_dat5 */
{GPMC_AD6, (PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M1)}, /* sdmmc2_dat6 */
{GPMC_AD7, (PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M1)}, /* sdmmc2_dat7 */
{GPMC_NOE, (PTU | IEN | OFF_EN | OFF_OUT_PTD | M1)},	 /* sdmmc2_clk */
{GPMC_NWE, (PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M1)}, /* sdmmc2_cmd */
{SDMMC1_CLK, (PTU | OFF_EN | OFF_OUT_PTD | M0)},	 /* sdmmc1_clk */
{SDMMC1_CMD, (PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M0)}, /* sdmmc1_cmd */
{SDMMC1_DAT0, (PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M0)}, /* sdmmc1_dat0 */
{SDMMC1_DAT1, (PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M0)}, /* sdmmc1_dat1 */
{SDMMC1_DAT2, (PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M0)}, /* sdmmc1_dat2 */
{SDMMC1_DAT3, (PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M0)}, /* sdmmc1_dat3 */
{SDMMC1_DAT4, (PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M0)}, /* sdmmc1_dat3 */
{SDMMC1_DAT5, (PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M0)}, /* sdmmc1_dat3 */
{SDMMC1_DAT6, (PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M0)}, /* sdmmc1_dat3 */
{SDMMC1_DAT7, (PTU | IEN | OFF_EN | OFF_PD | OFF_IN | M0)}, /* sdmmc1_dat3 */
{I2C1_SCL, (PTU | IEN | M0)},				/* i2c1_scl */
{I2C1_SDA, (PTU | IEN | M0)},				/* i2c1_sda */
{I2C2_SCL, (IEN | M0)},				/* i2c2_scl */
{I2C2_SDA, (IEN | M0)},				/* i2c2_sda */
{I2C3_SCL, (IEN | M0)},				/* i2c3_scl */
{I2C3_SDA, (IEN | M0)},				/* i2c3_sda */
{I2C4_SCL, (IEN | M0)},				/* i2c4_scl */
{I2C4_SDA, (IEN | M0)},				/* i2c4_sda */
{UART3_RX_IRRX, (IEN | M0)},				/* uart3_rx */
{UART3_TX_IRTX, (M0)},					/* uart3_tx */
{FREF_CLK1_OUT, (PTU | IEN | M0)},				/* gpio_182 */
{FREF_CLK2_OUT, (PTU | IEN | M0)},				/* gpio_182 */

};

const struct pad_conf_entry wkup_padconf_array_essential[] = {

{PAD1_SR_SCL, (PTU | IEN | M0)}, /* sr_scl */
{PAD0_SR_SDA, (PTU | IEN | M0)}, /* sr_sda */
{PAD1_SYS_32K, (IEN | M0)},	 /* sys_32k */
{PAD0_FREF_CLK3_OUT, (M0)}, /* fref_clk3_out */

};

#endif /* _EMBT2WS_MUX_DATA_H_ */
