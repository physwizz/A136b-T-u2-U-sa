/*
 * Copyright (C) 2016 MediaTek Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See http://www.gnu.org/licenses/gpl-2.0.html for more details.
 */

#ifndef __MTK_PDC_H
#define __MTK_PDC_H

#define ADAPTER_CAP_MAX_NR 10

struct pd_cap {
	uint8_t selected_cap_idx;
	uint8_t nr;
	uint8_t pdp;
	uint8_t pwr_limit[ADAPTER_CAP_MAX_NR];
	int max_mv[ADAPTER_CAP_MAX_NR];
	int min_mv[ADAPTER_CAP_MAX_NR];
	int ma[ADAPTER_CAP_MAX_NR];
	int maxwatt[ADAPTER_CAP_MAX_NR];
	int minwatt[ADAPTER_CAP_MAX_NR];
	uint8_t type[ADAPTER_CAP_MAX_NR];
	int info[ADAPTER_CAP_MAX_NR];
};

struct pdc_data {
	int input_current_limit;
	int charging_current_limit;
	int battery_cv;
	int min_charger_voltage;
	int pd_vbus_low_bound;
	int pd_vbus_upper_bound;
	int ibus_err;
	int vsys_watt;
#if defined(CONFIG_BATTERY_SAMSUNG)
	int pd_list_select;
	int apdo_num;
	int fpdo_num;
	int unknown_num;
	int prev_available_pdo;
	int was_hard_rst;
	int ps_rdy;
#endif
};

struct pdc {
	struct pd_cap cap;
	struct pdc_data data;

	int pdc_max_watt;
	int pdc_max_watt_setting;

	int pd_cap_max_watt;
	int pd_idx;
	int pd_reset_idx;
	int pd_boost_idx;
	int pd_buck_idx;
	int vbus_l;
	int vbus_h;
#if defined(CONFIG_BATTERY_SAMSUNG)
	struct tcpc_device *tcpc;
#endif
	struct mutex access_lock;
	struct mutex pmic_sync_lock;
	struct wakeup_source suspend_lock;
	int ta_vchr_org;
	bool to_check_chr_type;
	bool to_tune_ta_vchr;
	bool is_cable_out_occur;

	int pdc_input_current_limit_setting;	/* TA */
};

extern int pdc_init(void);
extern bool pdc_is_enable(void);
extern bool pdc_is_connect(void);
extern bool pdc_is_ready(void);
#if defined(CONFIG_BATTERY_SAMSUNG)
extern int pdc_clear(void);
extern int pdc_hard_rst(void);
extern struct pdic_notifier_struct pd_noti;
#if defined(CONFIG_BATTERY_NOTIFIER)
extern void select_pdo(int num);
extern void (*fp_select_pdo)(int num);
extern int (*fp_sec_pd_select_pps)(int num, int ppsVol, int ppsCur);
extern int (*fp_sec_pd_get_apdo_max_power)(unsigned int *pdo_pos,
		unsigned int *taMaxVol, unsigned int *taMaxCur, unsigned int *taMaxPwr);
extern void (*fp_sec_pd_change_src)(int max_cur);

#endif
int pdc_get_setting(void);
#endif
extern int pdc_reset(void);
extern int pdc_stop(void);
extern int pdc_run(void);
extern int pdc_set_data(struct pdc_data data);
extern struct pdc_data *pdc_get_data(void);
#endif /* __MTK_PDC_H */
