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

#include "mtk_cpufreq_config.h"
#include "mtk_cpufreq_platform.h"

#define NR_FREQ		16
#define ARRAY_COL_SIZE	4



static unsigned int FY_6768Tbl[NR_FREQ * NR_MT_CPU_DVFS][ARRAY_COL_SIZE] = {
	/* Freq, Vproc, post_div, clk_div */

	/* L */
	{ 1700, 74, 2, 1 },
	{ 1625, 69, 2, 1 },
	{ 1500, 63, 2, 1 },
	{ 1450, 61, 2, 1 },
	{ 1375, 57, 2, 1 },
	{ 1325, 55, 2, 1 },
	{ 1275, 53, 2, 1 },
	{ 1175, 48, 2, 1 },
	{ 1100, 44, 2, 1 },
	{ 1050, 42, 2, 1 },
	{ 999, 39, 2, 1 },
	{ 950, 37, 2, 1 },
	{ 900, 35, 2, 1 },
	{ 850, 32, 4, 1 },
	{ 774, 28, 4, 1 },
	{ 500, 24, 4, 1 },



    /* B */
	{ 2000, 99, 1, 1 },		/* 5*6.25 = 31.25 mv*/
	{ 1950, 96, 1, 1 },		/* 4*6.25 = 25.00 mv*/
	{ 1900, 92, 1, 1 },		/* 2*6.25 = 12.50 mv*/
	{ 1850, 89, 1, 1 },		/* 1*6.25 = 6.25 mv*/
	{ 1800, 85, 1, 1 },
	{ 1710, 80, 1, 1 },
	{ 1621, 75, 1, 1 },
	{ 1532, 69, 2, 1 },
	{ 1443, 64, 2, 1 },
	{ 1354, 59, 2, 1 },
	{ 1295, 55, 2, 1 },
	{ 1176, 48, 2, 1 },
	{ 1087, 43, 2, 1 },
	{ 998, 37, 2, 1 },
	{ 909, 32, 2, 1 },
	{ 850, 28, 2, 1 },


	/* CCI */
	{ 1187, 71, 2, 1 },
	{ 1120, 64, 2, 1 },
	{ 1049, 60, 2, 1 },
	{ 1014, 58, 2, 1 },
	{ 961, 54, 2, 1 },
	{ 909, 51, 2, 1 },
	{ 856, 48, 2, 1 },
	{ 821, 45, 2, 1 },
	{ 768, 42, 2, 1 },
	{ 733, 40, 4, 1 },
	{ 698, 37, 4, 1 },
	{ 663, 35, 4, 1 },
	{ 628, 33, 4, 1 },
	{ 593, 31, 4, 1 },
	{ 558, 28, 4, 1 },
	{ 500, 24, 4, 1 },





};

/* 6767_v8*/
static unsigned int FY_6767Tbl[NR_FREQ * NR_MT_CPU_DVFS][ARRAY_COL_SIZE] = {
	/* Freq, Vproc, post_div, clk_div */

	/* L */
	{ 1625, 69, 2, 1 },
	{ 1500, 63, 2, 1 },
	{ 1425, 60, 2, 1 },
	{ 1375, 57, 2, 1 },
	{ 1325, 55, 2, 1 },
	{ 1275, 53, 2, 1 },
	{ 1175, 48, 2, 1 },
	{ 1125, 45, 2, 1 },
	{ 1075, 43, 2, 1 },
	{ 1025, 41, 2, 1 },
	{ 974, 38, 2, 1 },
	{ 925, 36, 2, 1 },
	{ 875, 33, 2, 1 },
	{ 825, 31, 4, 1 },
	{ 774, 28, 4, 1 },
	{ 500, 24, 4, 1 },




    /* B */
	{ 1800, 85, 1, 1 },
	{ 1740, 82, 1, 1 },
	{ 1681, 78, 1, 1 },
	{ 1621, 75, 1, 1 },
	{ 1532, 69, 2, 1 },
	{ 1473, 66, 2, 1 },
	{ 1414, 62, 2, 1 },
	{ 1354, 59, 2, 1 },
	{ 1295, 55, 2, 1 },
	{ 1176, 48, 2, 1 },
	{ 1117, 45, 2, 1 },
	{ 1057, 41, 2, 1 },
	{ 998, 37, 2, 1 },
	{ 939, 34, 2, 1 },
	{ 879, 30, 2, 1 },
	{ 850, 28, 2, 1 },




	/* CCI */
	{ 1136, 65, 2, 1 },
	{ 1049, 60, 2, 1 },
	{ 997, 57, 2, 1 },
	{ 961, 54, 2, 1 },
	{ 926, 52, 2, 1 },
	{ 891, 50, 2, 1 },
	{ 856, 48, 2, 1 },
	{ 821, 45, 2, 1 },
	{ 768, 42, 2, 1 },
	{ 716, 39, 4, 1 },
	{ 680, 36, 4, 1 },
	{ 645, 34, 4, 1 },
	{ 610, 32, 4, 1 },
	{ 575, 30, 4, 1 },
	{ 558, 28, 4, 1 },
	{ 500, 24, 4, 1 },




};

/* pro_v8 */
static unsigned int proTbl[NR_FREQ * NR_MT_CPU_DVFS][ARRAY_COL_SIZE] = {
	/* Freq, Vproc, post_div, clk_div */

	/* L */
	{ 2000, 92, 1, 1 },
	{ 1950, 89, 1, 1 },
	{ 1900, 86, 1, 1 },
	{ 1850, 83, 1, 1 },
	{ 1800, 80, 1, 1 },
	{ 1700, 74, 2, 1 },
	{ 1625, 69, 2, 1 },
	{ 1500, 63, 2, 1 },
	{ 1375, 57, 2, 1 },
	{ 1275, 53, 2, 1 },
	{ 1175, 48, 2, 1 },
	{ 1075, 43, 2, 1 },
	{ 974, 38, 2, 1 },
	{ 875, 33, 2, 1 },
	{ 774, 28, 4, 1 },
	{ 500, 24, 4, 1 },




	/* B */
	{ 2202, 99, 1, 1 },
	{ 2133, 99, 1, 1 },
	{ 2066, 97, 1, 1 },
	{ 2000, 94, 1, 1 },
	{ 1933, 91, 1, 1 },
	{ 1866, 88, 1, 1 },
	{ 1800, 85, 1, 1 },
	{ 1681, 78, 1, 1 },
	{ 1532, 69, 2, 1 },
	{ 1473, 66, 2, 1 },
	{ 1384, 61, 2, 1 },
	{ 1295, 55, 2, 1 },
	{ 1176, 48, 2, 1 },
	{ 1057, 41, 2, 1 },
	{ 939, 34, 2, 1 },
	{ 850, 28, 2, 1 },




	/* CCI */
	{ 1396, 92, 2, 1 },
	{ 1343, 87, 2, 1 },
	{ 1290, 82, 2, 1 },
	{ 1263, 79, 2, 1 },
	{ 1187, 71, 2, 1 },
	{ 1120, 64, 2, 1 },
	{ 1049, 60, 2, 1 },
	{ 997, 57, 2, 1 },
	{ 944, 53, 2, 1 },
	{ 856, 48, 2, 1 },
	{ 821, 45, 2, 1 },
	{ 751, 41, 2, 1 },
	{ 680, 36, 4, 1 },
	{ 610, 32, 4, 1 },
	{ 558, 28, 4, 1 },
	{ 500, 24, 4, 1 },




};
/* 6768_v7 */
static unsigned int FY_6768Tbl_v7[NR_FREQ * NR_MT_CPU_DVFS][ARRAY_COL_SIZE] = {
	/* Freq, Vproc, post_div, clk_div */

	{ 1700, 68, 2, 1 }, /* L */
	{ 1625, 61, 2, 1 },
	{ 1500, 57, 2, 1 },
	{ 1450, 55, 2, 1 },
	{ 1375, 52, 2, 1 },
	{ 1325, 50, 2, 1 },
	{ 1275, 48, 2, 1 },
	{ 1175, 44, 2, 1 },
	{ 1100, 41, 2, 1 },
	{ 1050, 39, 2, 1 },
	{  999, 37, 2, 1 },
	{  950, 35, 2, 1 },
	{  900, 33, 2, 1 },
	{  850, 31, 4, 1 },
	{  774, 28, 4, 1 },
	{  500, 24, 4, 1 },



	{ 2000, 92, 1, 1 }, /* B */
	{ 1950, 90, 1, 1 },
	{ 1900, 88, 1, 1 },
	{ 1850, 86, 1, 1 },
	{ 1800, 84, 1, 1 },
	{ 1710, 79, 1, 1 },
	{ 1621, 74, 1, 1 },
	{ 1532, 69, 2, 1 },
	{ 1443, 63, 2, 1 },
	{ 1354, 58, 2, 1 },
	{ 1295, 55, 2, 1 },
	{ 1176, 48, 2, 1 },
	{ 1087, 42, 2, 1 },
	{ 998, 37, 2, 1 },
	{ 909, 32, 2, 1 },
	{ 850, 28, 2, 1 },



	{ 1187, 72, 2, 1 }, /* CCI */
	{ 1120, 65, 2, 1 },
	{ 1049, 61, 2, 1 },
	{ 1014, 59, 2, 1 },
	{  961, 55, 2, 1 },
	{  909, 52, 2, 1 },
	{  856, 48, 2, 1 },
	{  821, 46, 2, 1 },
	{  768, 42, 2, 1 },
	{  733, 40, 4, 1 },
	{  698, 38, 4, 1 },
	{  663, 35, 4, 1 },
	{  628, 33, 4, 1 },
	{  593, 31, 4, 1 },
	{  558, 28, 4, 1 },
	{  500, 24, 4, 1 },




};

/* 6767_v7*/
static unsigned int FY_6767Tbl_v7[NR_FREQ * NR_MT_CPU_DVFS][ARRAY_COL_SIZE] = {
	/* Freq, Vproc, post_div, clk_div */

	{ 1625, 61, 2, 1 }, /* L */
	{ 1500, 57, 2, 1 },
	{ 1425, 54, 2, 1 },
	{ 1375, 52, 2, 1 },
	{ 1325, 50, 2, 1 },
	{ 1275, 48, 2, 1 },
	{ 1175, 44, 2, 1 },
	{ 1125, 42, 2, 1 },
	{ 1075, 40, 2, 1 },
	{ 1025, 38, 2, 1 },
	{  974, 36, 2, 1 },
	{  925, 34, 2, 1 },
	{  875, 32, 2, 1 },
	{  825, 30, 4, 1 },
	{  774, 28, 4, 1 },
	{  500, 24, 4, 1 },




	{ 1800, 84, 1, 1 }, /* B */
	{ 1740, 81, 1, 1 },
	{ 1681, 77, 1, 1 },
	{ 1621, 74, 1, 1 },
	{ 1532, 69, 2, 1 },
	{ 1473, 65, 2, 1 },
	{ 1414, 62, 2, 1 },
	{ 1354, 58, 2, 1 },
	{ 1295, 55, 2, 1 },
	{ 1176, 48, 2, 1 },
	{ 1117, 44, 2, 1 },
	{ 1057, 41, 2, 1 },
	{  998, 37, 2, 1 },
	{  939, 34, 2, 1 },
	{  879, 30, 2, 1 },
	{  850, 28, 2, 1 },




	{ 1136, 66, 2, 1 }, /* CCI */
	{ 1049, 61, 2, 1 },
	{  997, 57, 2, 1 },
	{  961, 55, 2, 1 },
	{  926, 53, 2, 1 },
	{  891, 50, 2, 1 },
	{  856, 48, 2, 1 },
	{  821, 46, 2, 1 },
	{  768, 42, 2, 1 },
	{  716, 39, 4, 1 },
	{  680, 37, 4, 1 },
	{  645, 34, 4, 1 },
	{  610, 32, 4, 1 },
	{  575, 30, 4, 1 },
	{  558, 28, 4, 1 },
	{  500, 24, 4, 1 },



};

/* pro_v7 */
static unsigned int proTbl_v7[NR_FREQ * NR_MT_CPU_DVFS][ARRAY_COL_SIZE] = {
	/* Freq, Vproc, post_div, clk_div */

	{ 2000, 93, 1, 1 }, /* L */
	{ 1950, 89, 1, 1 },
	{ 1900, 85, 1, 1 },
	{ 1850, 81, 1, 1 },
	{ 1800, 76, 1, 1 },
	{ 1700, 68, 2, 1 },
	{ 1625, 61, 2, 1 },
	{ 1500, 57, 2, 1 },
	{ 1375, 52, 2, 1 },
	{ 1275, 48, 2, 1 },
	{ 1175, 44, 2, 1 },
	{ 1075, 40, 2, 1 },
	{  974, 36, 2, 1 },
	{  875, 32, 2, 1 },
	{  774, 28, 4, 1 },
	{  500, 24, 4, 1 },




	{ 2202, 99, 1, 1 }, /* B */
	{ 2133, 97, 1, 1 },
	{ 2066, 94, 1, 1 },
	{ 2000, 92, 1, 1 },
	{ 1933, 89, 1, 1 },
	{ 1866, 87, 1, 1 },
	{ 1800, 84, 1, 1 },
	{ 1681, 77, 1, 1 },
	{ 1532, 69, 2, 1 },
	{ 1473, 65, 2, 1 },
	{ 1384, 60, 2, 1 },
	{ 1295, 55, 2, 1 },
	{ 1176, 48, 2, 1 },
	{ 1057, 41, 2, 1 },
	{  939, 34, 2, 1 },
	{  850, 28, 2, 1 },




	{ 1396, 93, 2, 1 }, /* CCI */
	{ 1343, 88, 2, 1 },
	{ 1290, 83, 2, 1 },
	{ 1263, 80, 2, 1 },
	{ 1187, 72, 2, 1 },
	{ 1120, 65, 2, 1 },
	{ 1049, 61, 2, 1 },
	{  997, 57, 2, 1 },
	{  944, 54, 2, 1 },
	{  856, 48, 2, 1 },
	{  821, 46, 2, 1 },
	{  751, 41, 2, 1 },
	{  680, 37, 4, 1 },
	{  610, 32, 4, 1 },
	{  558, 28, 4, 1 },
	{  500, 24, 4, 1 },




};

static unsigned int FY_G75Tbl[NR_FREQ * NR_MT_CPU_DVFS][ARRAY_COL_SIZE] = {
	/* Freq, Vproc, post_div, clk_div */

	/* L */
	{ 1800, 81, 1, 1 },
	{ 1625, 69, 2, 1 },
	{ 1500, 63, 2, 1 },
	{ 1450, 61, 2, 1 },
	{ 1375, 57, 2, 1 },
	{ 1325, 55, 2, 1 },
	{ 1275, 53, 2, 1 },
	{ 1175, 48, 2, 1 },
	{ 1100, 44, 2, 1 },
	{ 1050, 42, 2, 1 },
	{ 999, 39, 2, 1 },
	{ 950, 37, 2, 1 },
	{ 900, 35, 2, 1 },
	{ 850, 32, 4, 1 },
	{ 774, 28, 4, 1 },
	{ 500, 24, 4, 1 },



    /* B */
	{ 2000, 94, 1, 1 },
	{ 1950, 92, 1, 1 },
	{ 1900, 90, 1, 1 },
	{ 1850, 88, 1, 1 },
	{ 1800, 85, 1, 1 },
	{ 1710, 80, 1, 1 },
	{ 1621, 75, 1, 1 },
	{ 1532, 69, 2, 1 },
	{ 1443, 64, 2, 1 },
	{ 1354, 59, 2, 1 },
	{ 1295, 55, 2, 1 },
	{ 1176, 48, 2, 1 },
	{ 1087, 43, 2, 1 },
	{ 998, 37, 2, 1 },
	{ 909, 32, 2, 1 },
	{ 850, 28, 2, 1 },


	/* CCI */
	{ 1277, 81, 2, 1 },
	{ 1120, 64, 2, 1 },
	{ 1049, 60, 2, 1 },
	{ 1014, 58, 2, 1 },
	{ 961, 54, 2, 1 },
	{ 909, 51, 2, 1 },
	{ 856, 48, 2, 1 },
	{ 821, 45, 2, 1 },
	{ 768, 42, 2, 1 },
	{ 733, 40, 4, 1 },
	{ 698, 37, 4, 1 },
	{ 663, 35, 4, 1 },
	{ 628, 33, 4, 1 },
	{ 593, 31, 4, 1 },
	{ 558, 28, 4, 1 },
	{ 500, 24, 4, 1 },





};
unsigned int *xrecordTbl[NUM_CPU_LEVEL] = {	/* v1.1 */
	[CPU_LEVEL_0] = &FY_6768Tbl[0][0],	/* 6768_v8 */
	[CPU_LEVEL_1] = &FY_6767Tbl[0][0],	/* 6767_v8 */
	[CPU_LEVEL_2] = &proTbl[0][0],	/* pro_v8 */
	[CPU_LEVEL_3] = &FY_6768Tbl_v7[0][0],	/* 6768_v7 */
	[CPU_LEVEL_4] = &FY_6767Tbl_v7[0][0],	/* 6767_v7 */
	[CPU_LEVEL_5] = &proTbl_v7[0][0],	/* pro_v7 */
	[CPU_LEVEL_6] = &FY_G75Tbl[0][0],	/* G75 */
};

#ifdef CCI_MAP_TBL_SUPPORT
static unsigned char CCI_6768Tbl[NR_FREQ * NR_CCI_TBL][NR_FREQ] = {
	/* Normal CCI Map */
	{ 3, 4, 4, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
	{ 3, 4, 4, 5, 5, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 9, 9, 9, 9, 9, 9, 9},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 9, 9, 9, 9, 9, 9, 9},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 10, 10, 10, 10, 10, 10, 10},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 11, 11, 11, 11, 11},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 12, 12, 12, 12, 12},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 13, 13, 13, 13, 13},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 13, 14, 14, 14, 14},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 13, 14, 15, 15, 15},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 13, 14, 15, 15, 15},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 13, 14, 15, 15, 15},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 13, 14, 15, 15, 15},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 13, 14, 15, 15, 15},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 13, 14, 15, 15, 15},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 13, 14, 15, 15, 15},

	/* Perf CCI Map */
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 4, 4, 4, 4, 4, 4},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 5, 5, 5, 5, 5},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 5, 5, 5, 5, 5},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 7, 7, 7, 7},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 8, 8, 8, 8},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 8, 9, 9, 9},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 8, 10, 10, 10},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 8, 10, 11, 11},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 8, 10, 12, 12},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 8, 10, 12, 13},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 8, 10, 12, 13},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 8, 10, 12, 13},

};

static unsigned char CCI_6767Tbl[NR_FREQ * NR_CCI_TBL][NR_FREQ] = {
	/* Normal CCI Map */
	{ 5, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
	{ 5, 6, 6, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
	{ 5, 6, 6, 7, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
	{ 5, 6, 6, 7, 8, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10},
	{ 5, 6, 6, 7, 8, 9, 9, 10, 11, 11, 11, 11, 11, 11, 11, 11},
	{ 5, 6, 6, 7, 8, 9, 9, 10, 11, 11, 11, 11, 11, 11, 11, 11},
	{ 5, 6, 6, 7, 8, 9, 9, 10, 11, 13, 13, 13, 13, 13, 13, 13},
	{ 5, 6, 6, 7, 8, 9, 9, 10, 11, 13, 14, 14, 14, 14, 14, 14},
	{ 5, 6, 6, 7, 8, 9, 9, 10, 11, 13, 14, 14, 14, 14, 14, 14},
	{ 5, 6, 6, 7, 8, 9, 9, 10, 11, 13, 14, 15, 15, 15, 15, 15},
	{ 5, 6, 6, 7, 8, 9, 9, 10, 11, 13, 14, 15, 15, 15, 15, 15},
	{ 5, 6, 6, 7, 8, 9, 9, 10, 11, 13, 14, 15, 15, 15, 15, 15},
	{ 5, 6, 6, 7, 8, 9, 9, 10, 11, 13, 14, 15, 15, 15, 15, 15},
	{ 5, 6, 6, 7, 8, 9, 9, 10, 11, 13, 14, 15, 15, 15, 15, 15},
	{ 5, 6, 6, 7, 8, 9, 9, 10, 11, 13, 14, 15, 15, 15, 15, 15},
	{ 5, 6, 6, 7, 8, 9, 9, 10, 11, 13, 14, 15, 15, 15, 15, 15},

	/* Perf CCI Map */
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{ 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
	{ 0, 0, 0, 0, 1, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3},
	{ 0, 0, 0, 0, 1, 1, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4},
	{ 0, 0, 0, 0, 1, 1, 2, 3, 5, 5, 5, 5, 5, 5, 5, 5},
	{ 0, 0, 0, 0, 1, 1, 2, 3, 5, 7, 7, 7, 7, 7, 7, 7},
	{ 0, 0, 0, 0, 1, 1, 2, 3, 5, 7, 8, 8, 8, 8, 8, 8},
	{ 0, 0, 0, 0, 1, 1, 2, 3, 5, 7, 8, 8, 8, 8, 8, 8},
	{ 0, 0, 0, 0, 1, 1, 2, 3, 5, 7, 8, 9, 9, 9, 9, 9},
	{ 0, 0, 0, 0, 1, 1, 2, 3, 5, 7, 8, 9, 9, 10, 10, 10},
	{ 0, 0, 0, 0, 1, 1, 2, 3, 5, 7, 8, 9, 9, 11, 11, 11},
	{ 0, 0, 0, 0, 1, 1, 2, 3, 5, 7, 8, 9, 9, 11, 12, 12},
	{ 0, 0, 0, 0, 1, 1, 2, 3, 5, 7, 8, 9, 9, 11, 12, 12},
	{ 0, 0, 0, 0, 1, 1, 2, 3, 5, 7, 8, 9, 9, 11, 12, 12},
	{ 0, 0, 0, 0, 1, 1, 2, 3, 5, 7, 8, 9, 9, 11, 12, 12},

};

static unsigned char CCI_proTbl[NR_FREQ * NR_CCI_TBL][NR_FREQ] = {
	/* Normal CCI Map */
	{ 5, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
	{ 5, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
	{ 5, 6, 6, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
	{ 5, 6, 6, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
	{ 5, 6, 6, 7, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
	{ 5, 6, 6, 7, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
	{ 5, 6, 6, 7, 8, 8, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10},
	{ 5, 6, 6, 7, 8, 8, 9, 9, 11, 11, 11, 11, 11, 11, 11, 11},
	{ 5, 6, 6, 7, 8, 8, 9, 9, 11, 11, 12, 12, 12, 12, 12, 12},
	{ 5, 6, 6, 7, 8, 8, 9, 9, 11, 11, 12, 12, 13, 13, 13, 13},
	{ 5, 6, 6, 7, 8, 8, 9, 9, 11, 11, 12, 12, 13, 13, 13, 13},
	{ 5, 6, 6, 7, 8, 8, 9, 9, 11, 11, 12, 12, 13, 14, 14, 14},
	{ 5, 6, 6, 7, 8, 8, 9, 9, 11, 11, 12, 12, 13, 15, 15, 15},
	{ 5, 6, 6, 7, 8, 8, 9, 9, 11, 11, 12, 12, 13, 15, 15, 15},
	{ 5, 6, 6, 7, 8, 8, 9, 9, 11, 11, 12, 12, 13, 15, 15, 15},
	{ 5, 6, 6, 7, 8, 8, 9, 9, 11, 11, 12, 12, 13, 15, 15, 15},

	/* Perf CCI Map */
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{ 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{ 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
	{ 0, 0, 0, 0, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
	{ 0, 0, 0, 0, 1, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4},
	{ 0, 0, 0, 0, 1, 2, 3, 4, 5, 5, 5, 5, 5, 5, 5, 5},
	{ 0, 0, 0, 0, 1, 2, 3, 4, 6, 6, 6, 6, 6, 6, 6, 6},
	{ 0, 0, 0, 0, 1, 2, 3, 4, 6, 6, 8, 8, 8, 8, 8, 8},
	{ 0, 0, 0, 0, 1, 2, 3, 4, 6, 6, 8, 8, 9, 9, 9, 9},
	{ 0, 0, 0, 0, 1, 2, 3, 4, 6, 6, 8, 8, 10, 10, 10, 10},
	{ 0, 0, 0, 0, 1, 2, 3, 4, 6, 6, 8, 8, 10, 11, 11, 11},
	{ 0, 0, 0, 0, 1, 2, 3, 4, 6, 6, 8, 8, 10, 11, 12, 12},
	{ 0, 0, 0, 0, 1, 2, 3, 4, 6, 6, 8, 8, 10, 11, 12, 13},
	{ 0, 0, 0, 0, 1, 2, 3, 4, 6, 6, 8, 8, 10, 11, 12, 13},
	{ 0, 0, 0, 0, 1, 2, 3, 4, 6, 6, 8, 8, 10, 11, 12, 13},

};

static unsigned char CCI_6768Tbl_v7[NR_FREQ * NR_CCI_TBL][NR_FREQ] = {
	/* Normal CCI Map */
	{ 3, 4, 4, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
	{ 3, 4, 4, 5, 5, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 9, 9, 9, 9, 9, 9, 9},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 9, 9, 9, 9, 9, 9, 9},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 10, 10, 10, 10, 10, 10, 10},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 11, 11, 11, 11, 11},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 12, 12, 12, 12, 12},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 13, 13, 13, 13, 13},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 13, 14, 14, 14, 14},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 13, 14, 15, 15, 15},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 13, 14, 15, 15, 15},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 13, 14, 15, 15, 15},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 13, 14, 15, 15, 15},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 13, 14, 15, 15, 15},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 13, 14, 15, 15, 15},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 13, 14, 15, 15, 15},

	/* Perf CCI Map */
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 4, 4, 4, 4, 4, 4},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 5, 5, 5, 5, 5},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 5, 5, 5, 5, 5},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 7, 7, 7, 7},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 8, 8, 8, 8},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 8, 9, 9, 9},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 8, 10, 10, 10},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 8, 10, 11, 11},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 8, 10, 12, 12},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 8, 10, 12, 13},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 8, 10, 12, 13},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 8, 10, 12, 13},

};

static unsigned char CCI_6767Tbl_v7[NR_FREQ * NR_CCI_TBL][NR_FREQ] = {
	/* Normal CCI Map */
	{ 5, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
	{ 5, 6, 6, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
	{ 5, 6, 6, 7, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
	{ 5, 6, 6, 7, 8, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10},
	{ 5, 6, 6, 7, 8, 9, 9, 10, 11, 11, 11, 11, 11, 11, 11, 11},
	{ 5, 6, 6, 7, 8, 9, 9, 10, 11, 11, 11, 11, 11, 11, 11, 11},
	{ 5, 6, 6, 7, 8, 9, 9, 10, 11, 13, 13, 13, 13, 13, 13, 13},
	{ 5, 6, 6, 7, 8, 9, 9, 10, 11, 13, 14, 14, 14, 14, 14, 14},
	{ 5, 6, 6, 7, 8, 9, 9, 10, 11, 13, 14, 14, 14, 14, 14, 14},
	{ 5, 6, 6, 7, 8, 9, 9, 10, 11, 13, 14, 15, 15, 15, 15, 15},
	{ 5, 6, 6, 7, 8, 9, 9, 10, 11, 13, 14, 15, 15, 15, 15, 15},
	{ 5, 6, 6, 7, 8, 9, 9, 10, 11, 13, 14, 15, 15, 15, 15, 15},
	{ 5, 6, 6, 7, 8, 9, 9, 10, 11, 13, 14, 15, 15, 15, 15, 15},
	{ 5, 6, 6, 7, 8, 9, 9, 10, 11, 13, 14, 15, 15, 15, 15, 15},
	{ 5, 6, 6, 7, 8, 9, 9, 10, 11, 13, 14, 15, 15, 15, 15, 15},
	{ 5, 6, 6, 7, 8, 9, 9, 10, 11, 13, 14, 15, 15, 15, 15, 15},

	/* Perf CCI Map */
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{ 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
	{ 0, 0, 0, 0, 1, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3},
	{ 0, 0, 0, 0, 1, 1, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4},
	{ 0, 0, 0, 0, 1, 1, 2, 3, 5, 5, 5, 5, 5, 5, 5, 5},
	{ 0, 0, 0, 0, 1, 1, 2, 3, 5, 7, 7, 7, 7, 7, 7, 7},
	{ 0, 0, 0, 0, 1, 1, 2, 3, 5, 7, 8, 8, 8, 8, 8, 8},
	{ 0, 0, 0, 0, 1, 1, 2, 3, 5, 7, 8, 8, 8, 8, 8, 8},
	{ 0, 0, 0, 0, 1, 1, 2, 3, 5, 7, 8, 9, 9, 9, 9, 9},
	{ 0, 0, 0, 0, 1, 1, 2, 3, 5, 7, 8, 9, 9, 10, 10, 10},
	{ 0, 0, 0, 0, 1, 1, 2, 3, 5, 7, 8, 9, 9, 11, 11, 11},
	{ 0, 0, 0, 0, 1, 1, 2, 3, 5, 7, 8, 9, 9, 11, 12, 12},
	{ 0, 0, 0, 0, 1, 1, 2, 3, 5, 7, 8, 9, 9, 11, 12, 12},
	{ 0, 0, 0, 0, 1, 1, 2, 3, 5, 7, 8, 9, 9, 11, 12, 12},
	{ 0, 0, 0, 0, 1, 1, 2, 3, 5, 7, 8, 9, 9, 11, 12, 12},

};

static unsigned char CCI_proTbl_v7[NR_FREQ * NR_CCI_TBL][NR_FREQ] = {
	/* Normal CCI Map */
	{ 5, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
	{ 5, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
	{ 5, 6, 6, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
	{ 5, 6, 6, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
	{ 5, 6, 6, 7, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
	{ 5, 6, 6, 7, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
	{ 5, 6, 6, 7, 8, 8, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10},
	{ 5, 6, 6, 7, 8, 8, 9, 9, 11, 11, 11, 11, 11, 11, 11, 11},
	{ 5, 6, 6, 7, 8, 8, 9, 9, 11, 11, 12, 12, 12, 12, 12, 12},
	{ 5, 6, 6, 7, 8, 8, 9, 9, 11, 11, 12, 12, 13, 13, 13, 13},
	{ 5, 6, 6, 7, 8, 8, 9, 9, 11, 11, 12, 12, 13, 13, 13, 13},
	{ 5, 6, 6, 7, 8, 8, 9, 9, 11, 11, 12, 12, 13, 14, 14, 14},
	{ 5, 6, 6, 7, 8, 8, 9, 9, 11, 11, 12, 12, 13, 15, 15, 15},
	{ 5, 6, 6, 7, 8, 8, 9, 9, 11, 11, 12, 12, 13, 15, 15, 15},
	{ 5, 6, 6, 7, 8, 8, 9, 9, 11, 11, 12, 12, 13, 15, 15, 15},
	{ 5, 6, 6, 7, 8, 8, 9, 9, 11, 11, 12, 12, 13, 15, 15, 15},

	/* Perf CCI Map */
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{ 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{ 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
	{ 0, 0, 0, 0, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
	{ 0, 0, 0, 0, 1, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4},
	{ 0, 0, 0, 0, 1, 2, 3, 4, 5, 5, 5, 5, 5, 5, 5, 5},
	{ 0, 0, 0, 0, 1, 2, 3, 4, 6, 6, 6, 6, 6, 6, 6, 6},
	{ 0, 0, 0, 0, 1, 2, 3, 4, 6, 6, 8, 8, 8, 8, 8, 8},
	{ 0, 0, 0, 0, 1, 2, 3, 4, 6, 6, 8, 8, 9, 9, 9, 9},
	{ 0, 0, 0, 0, 1, 2, 3, 4, 6, 6, 8, 8, 10, 10, 10, 10},
	{ 0, 0, 0, 0, 1, 2, 3, 4, 6, 6, 8, 8, 10, 11, 11, 11},
	{ 0, 0, 0, 0, 1, 2, 3, 4, 6, 6, 8, 8, 10, 11, 12, 12},
	{ 0, 0, 0, 0, 1, 2, 3, 4, 6, 6, 8, 8, 10, 11, 12, 13},
	{ 0, 0, 0, 0, 1, 2, 3, 4, 6, 6, 8, 8, 10, 11, 12, 13},
	{ 0, 0, 0, 0, 1, 2, 3, 4, 6, 6, 8, 8, 10, 11, 12, 13},

};

static unsigned char CCI_G75Tbl[NR_FREQ * NR_CCI_TBL][NR_FREQ] = {
	/* Normal CCI Map */
	{ 3, 4, 4, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
	{ 3, 4, 4, 5, 5, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 9, 9, 9, 9, 9, 9, 9},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 9, 9, 9, 9, 9, 9, 9},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 10, 10, 10, 10, 10, 10, 10},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 11, 11, 11, 11, 11},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 12, 12, 12, 12, 12},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 13, 13, 13, 13, 13},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 13, 14, 14, 14, 14},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 13, 14, 15, 15, 15},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 13, 14, 15, 15, 15},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 13, 14, 15, 15, 15},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 13, 14, 15, 15, 15},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 13, 14, 15, 15, 15},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 13, 14, 15, 15, 15},
	{ 3, 4, 4, 5, 5, 6, 7, 8, 9, 11, 11, 13, 14, 15, 15, 15},

	/* Perf CCI Map */
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 4, 4, 4, 4, 4, 4},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 5, 5, 5, 5, 5},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 5, 5, 5, 5, 5},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 7, 7, 7, 7},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 8, 8, 8, 8},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 8, 9, 9, 9},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 8, 10, 10, 10},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 8, 10, 11, 11},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 8, 10, 12, 12},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 8, 10, 12, 13},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 8, 10, 12, 13},
	{ 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 7, 8, 10, 12, 13},

};
unsigned char *xrecord_CCI_Tbl[NUM_CPU_LEVEL] = {
	[CPU_LEVEL_0] = &CCI_6768Tbl[0][0],
	[CPU_LEVEL_1] = &CCI_6767Tbl[0][0],
	[CPU_LEVEL_2] = &CCI_proTbl[0][0],
	[CPU_LEVEL_3] = &CCI_6768Tbl_v7[0][0],
	[CPU_LEVEL_4] = &CCI_6767Tbl_v7[0][0],
	[CPU_LEVEL_5] = &CCI_proTbl_v7[0][0],
	[CPU_LEVEL_6] = &CCI_G75Tbl[0][0],
};
#endif
