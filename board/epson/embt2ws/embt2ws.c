// SPDX-License-Identifier: GPL-2.0+
/*
 * (C) Copyright 2022
 * Andreas Kemnade <andreas@kemnade.info>
 *
 */
#include <common.h>
#include <init.h>
#include <log.h>
#include <net.h>
#include <serial.h>
#include <asm/global_data.h>
#include <asm/mach-types.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/mmc_host_def.h>
#include <asm/arch/clock.h>
#include <asm/emif.h>

#include <asm/arch/gpio.h>
#include <asm/gpio.h>
#include <env.h>
#include <twl6030.h>

#include "embt2ws_mux_data.h"

DECLARE_GLOBAL_DATA_PTR;

const struct omap_sysinfo sysinfo = {
	"Board: OMAP4 Epson EMBT2WS (Moverio BT-200)\n"
};

struct omap4_scrm_regs *const scrm = (struct omap4_scrm_regs *)0x4a30a000;

/**
 * @brief board_init
 *
 * Return: 0
 */
int board_init(void)
{
	gpmc_init();

	/* TODO: to be verified */
	gd->bd->bi_arch_number = MACH_TYPE_OMAP4_PANDA;
	gd->bd->bi_boot_params = (0x80000000 + 0x100); /* boot param addr */

	return 0;
}

static const struct emif_regs emif_regs = {
        .sdram_config_init              = 0x80800eb2,
        .sdram_config                   = 0x80801ab2,
        .ref_ctrl                       = 0x00000618, // ?
        .sdram_tim1                     = 0x10EB0662, // ?
        .sdram_tim2                     = 0x20370DD2, // ?
        .sdram_tim3                     = 0xB1C33F,  // ?
        .read_idle_ctrl                 = 0x000501ff, //?
        .zq_config                      = 0xD00B3215,
        .temp_alert_config              = 0x58016893,
        .emif_ddr_phy_ctlr_1_init       = 0x049ffff5, //?
        .emif_ddr_phy_ctlr_1            = 0x049FF408
};

static const struct dmm_lisa_map_regs lisa_map = {
        .dmm_lisa_map_0 = 0x80720100,
        .dmm_lisa_map_1 = 0xFF020100,
        .dmm_lisa_map_2 = 0,
        .dmm_lisa_map_3 = 0x80640300,
        .is_ma_present  = 0x1
};




#if defined(CONFIG_SPL_OS_BOOT)
int spl_start_uboot(void)
{
	return 1;

}
#endif /* CONFIG_SPL_OS_BOOT */

int board_eth_init(struct bd_info *bis)
{
	return 0;
}

#ifdef CONFIG_SYS_EMIF_PRECALCULATED_TIMING_REGS
/*
 * emif_get_reg_dump() - emif_get_reg_dump strong function
 *
 * @emif_nr - emif base
 * @regs - reg dump of timing values
 *
 * Strong function to override emif_get_reg_dump weak function in sdram_elpida.c
 */
void emif_get_reg_dump(u32 emif_nr, const struct emif_regs **regs)
{
	*regs = &emif_regs;
}

void emif_get_dmm_regs(const struct dmm_lisa_map_regs **dmm_lisa_regs)
{
	*dmm_lisa_regs = &lisa_map;
}

#endif

void set_muxconf_regs(void)
{
	do_set_mux((*ctrl)->control_padconf_core_base,
		   core_padconf_array_essential,
		   sizeof(core_padconf_array_essential) /
		   sizeof(struct pad_conf_entry));

	do_set_mux((*ctrl)->control_padconf_wkup_base,
		   wkup_padconf_array_essential,
		   sizeof(wkup_padconf_array_essential) /
		   sizeof(struct pad_conf_entry));
}

int misc_init_r(void)
{
#ifdef CONFIG_TWL6030_POWER
        twl6030_init_battery_charging();
#endif
	return 0;
}
#if defined(CONFIG_MMC)
int board_mmc_init(struct bd_info *bis)
{
	return omap_mmc_init(0, 0, 0, -1, -1);
}

#if !defined(CONFIG_SPL_BUILD)
void board_mmc_power_init(void)
{
	twl6030_power_mmc_init(0);
}
#endif
#endif
