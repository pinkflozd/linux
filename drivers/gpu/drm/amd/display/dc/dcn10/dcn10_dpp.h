/* Copyright 2016 Advanced Micro Devices, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * Authors: AMD
 *
 */

#ifndef __DAL_DPP_DCN10_H__
#define __DAL_DPP_DCN10_H__

#include "transform.h"

#define TO_DCN10_DPP(transform)\
	container_of(transform, struct dcn10_dpp, base)

/* TODO: Use correct number of taps. Using polaris values for now */
#define LB_TOTAL_NUMBER_OF_ENTRIES 5124
#define LB_BITS_PER_ENTRY 144

#define TF_SF(reg_name, field_name, post_fix)\
	.field_name = reg_name ## __ ## field_name ## post_fix

#define TF_REG_LIST_DCN(id) \
	SRI(CM_GAMUT_REMAP_CONTROL, CM, id),\
	SRI(CM_GAMUT_REMAP_C11_C12, CM, id),\
	SRI(CM_GAMUT_REMAP_C13_C14, CM, id),\
	SRI(CM_GAMUT_REMAP_C21_C22, CM, id),\
	SRI(CM_GAMUT_REMAP_C23_C24, CM, id),\
	SRI(CM_GAMUT_REMAP_C31_C32, CM, id),\
	SRI(CM_GAMUT_REMAP_C33_C34, CM, id),\
	SRI(DSCL_EXT_OVERSCAN_LEFT_RIGHT, DSCL, id), \
	SRI(DSCL_EXT_OVERSCAN_TOP_BOTTOM, DSCL, id), \
	SRI(OTG_H_BLANK, DSCL, id), \
	SRI(OTG_V_BLANK, DSCL, id), \
	SRI(SCL_MODE, DSCL, id), \
	SRI(LB_DATA_FORMAT, DSCL, id), \
	SRI(LB_MEMORY_CTRL, DSCL, id), \
	SRI(DSCL_AUTOCAL, DSCL, id), \
	SRI(SCL_BLACK_OFFSET, DSCL, id), \
	SRI(DSCL_CONTROL, DSCL, id), \
	SRI(SCL_TAP_CONTROL, DSCL, id), \
	SRI(SCL_COEF_RAM_TAP_SELECT, DSCL, id), \
	SRI(SCL_COEF_RAM_TAP_DATA, DSCL, id), \
	SRI(DSCL_2TAP_CONTROL, DSCL, id), \
	SRI(MPC_SIZE, DSCL, id), \
	SRI(SCL_HORZ_FILTER_SCALE_RATIO, DSCL, id), \
	SRI(SCL_VERT_FILTER_SCALE_RATIO, DSCL, id), \
	SRI(SCL_HORZ_FILTER_SCALE_RATIO_C, DSCL, id), \
	SRI(SCL_VERT_FILTER_SCALE_RATIO_C, DSCL, id), \
	SRI(SCL_HORZ_FILTER_INIT, DSCL, id), \
	SRI(SCL_HORZ_FILTER_INIT_C, DSCL, id), \
	SRI(SCL_VERT_FILTER_INIT, DSCL, id), \
	SRI(SCL_VERT_FILTER_INIT_BOT, DSCL, id), \
	SRI(SCL_VERT_FILTER_INIT_C, DSCL, id), \
	SRI(SCL_VERT_FILTER_INIT_BOT_C, DSCL, id), \
	SRI(RECOUT_START, DSCL, id), \
	SRI(RECOUT_SIZE, DSCL, id)

#define TF_REG_LIST_DCN10(id) \
	TF_REG_LIST_DCN(id), \
	SRI(CM_COMA_C11_C12, CM, id),\
	SRI(CM_COMA_C13_C14, CM, id),\
	SRI(CM_COMA_C21_C22, CM, id),\
	SRI(CM_COMA_C23_C24, CM, id),\
	SRI(CM_COMA_C31_C32, CM, id),\
	SRI(CM_COMA_C33_C34, CM, id),\
	SRI(CM_COMB_C11_C12, CM, id),\
	SRI(CM_COMB_C13_C14, CM, id),\
	SRI(CM_COMB_C21_C22, CM, id),\
	SRI(CM_COMB_C23_C24, CM, id),\
	SRI(CM_COMB_C31_C32, CM, id),\
	SRI(CM_COMB_C33_C34, CM, id)

#define TF_REG_LIST_SH_MASK_DCN(mask_sh)\
	TF_SF(CM0_CM_GAMUT_REMAP_CONTROL, CM_GAMUT_REMAP_MODE, mask_sh),\
	TF_SF(CM0_CM_GAMUT_REMAP_C11_C12, CM_GAMUT_REMAP_C11, mask_sh),\
	TF_SF(CM0_CM_GAMUT_REMAP_C11_C12, CM_GAMUT_REMAP_C12, mask_sh),\
	TF_SF(CM0_CM_GAMUT_REMAP_C13_C14, CM_GAMUT_REMAP_C13, mask_sh),\
	TF_SF(CM0_CM_GAMUT_REMAP_C13_C14, CM_GAMUT_REMAP_C14, mask_sh),\
	TF_SF(CM0_CM_GAMUT_REMAP_C21_C22, CM_GAMUT_REMAP_C21, mask_sh),\
	TF_SF(CM0_CM_GAMUT_REMAP_C21_C22, CM_GAMUT_REMAP_C22, mask_sh),\
	TF_SF(CM0_CM_GAMUT_REMAP_C23_C24, CM_GAMUT_REMAP_C23, mask_sh),\
	TF_SF(CM0_CM_GAMUT_REMAP_C23_C24, CM_GAMUT_REMAP_C24, mask_sh),\
	TF_SF(CM0_CM_GAMUT_REMAP_C31_C32, CM_GAMUT_REMAP_C31, mask_sh),\
	TF_SF(CM0_CM_GAMUT_REMAP_C31_C32, CM_GAMUT_REMAP_C32, mask_sh),\
	TF_SF(CM0_CM_GAMUT_REMAP_C33_C34, CM_GAMUT_REMAP_C33, mask_sh),\
	TF_SF(CM0_CM_GAMUT_REMAP_C33_C34, CM_GAMUT_REMAP_C34, mask_sh),\
	TF_SF(DSCL0_DSCL_EXT_OVERSCAN_LEFT_RIGHT, EXT_OVERSCAN_LEFT, mask_sh),\
	TF_SF(DSCL0_DSCL_EXT_OVERSCAN_LEFT_RIGHT, EXT_OVERSCAN_RIGHT, mask_sh),\
	TF_SF(DSCL0_DSCL_EXT_OVERSCAN_TOP_BOTTOM, EXT_OVERSCAN_BOTTOM, mask_sh),\
	TF_SF(DSCL0_DSCL_EXT_OVERSCAN_TOP_BOTTOM, EXT_OVERSCAN_TOP, mask_sh),\
	TF_SF(DSCL0_OTG_H_BLANK, OTG_H_BLANK_START, mask_sh),\
	TF_SF(DSCL0_OTG_H_BLANK, OTG_H_BLANK_END, mask_sh),\
	TF_SF(DSCL0_OTG_V_BLANK, OTG_V_BLANK_START, mask_sh),\
	TF_SF(DSCL0_OTG_V_BLANK, OTG_V_BLANK_END, mask_sh),\
	TF_SF(DSCL0_LB_DATA_FORMAT, INTERLEAVE_EN, mask_sh),\
	TF_SF(DSCL0_LB_DATA_FORMAT, ALPHA_EN, mask_sh),\
	TF_SF(DSCL0_LB_MEMORY_CTRL, MEMORY_CONFIG, mask_sh),\
	TF_SF(DSCL0_LB_MEMORY_CTRL, LB_MAX_PARTITIONS, mask_sh),\
	TF_SF(DSCL0_DSCL_AUTOCAL, AUTOCAL_MODE, mask_sh),\
	TF_SF(DSCL0_DSCL_AUTOCAL, AUTOCAL_NUM_PIPE, mask_sh),\
	TF_SF(DSCL0_DSCL_AUTOCAL, AUTOCAL_PIPE_ID, mask_sh),\
	TF_SF(DSCL0_SCL_BLACK_OFFSET, SCL_BLACK_OFFSET_RGB_Y, mask_sh),\
	TF_SF(DSCL0_SCL_BLACK_OFFSET, SCL_BLACK_OFFSET_CBCR, mask_sh),\
	TF_SF(DSCL0_DSCL_CONTROL, SCL_BOUNDARY_MODE, mask_sh),\
	TF_SF(DSCL0_SCL_TAP_CONTROL, SCL_V_NUM_TAPS, mask_sh),\
	TF_SF(DSCL0_SCL_TAP_CONTROL, SCL_H_NUM_TAPS, mask_sh),\
	TF_SF(DSCL0_SCL_TAP_CONTROL, SCL_V_NUM_TAPS_C, mask_sh),\
	TF_SF(DSCL0_SCL_TAP_CONTROL, SCL_H_NUM_TAPS_C, mask_sh),\
	TF_SF(DSCL0_SCL_COEF_RAM_TAP_SELECT, SCL_COEF_RAM_TAP_PAIR_IDX, mask_sh),\
	TF_SF(DSCL0_SCL_COEF_RAM_TAP_SELECT, SCL_COEF_RAM_PHASE, mask_sh),\
	TF_SF(DSCL0_SCL_COEF_RAM_TAP_SELECT, SCL_COEF_RAM_FILTER_TYPE, mask_sh),\
	TF_SF(DSCL0_SCL_COEF_RAM_TAP_DATA, SCL_COEF_RAM_EVEN_TAP_COEF, mask_sh),\
	TF_SF(DSCL0_SCL_COEF_RAM_TAP_DATA, SCL_COEF_RAM_EVEN_TAP_COEF_EN, mask_sh),\
	TF_SF(DSCL0_SCL_COEF_RAM_TAP_DATA, SCL_COEF_RAM_ODD_TAP_COEF, mask_sh),\
	TF_SF(DSCL0_SCL_COEF_RAM_TAP_DATA, SCL_COEF_RAM_ODD_TAP_COEF_EN, mask_sh),\
	TF_SF(DSCL0_DSCL_2TAP_CONTROL, SCL_H_2TAP_HARDCODE_COEF_EN, mask_sh),\
	TF_SF(DSCL0_DSCL_2TAP_CONTROL, SCL_H_2TAP_SHARP_EN, mask_sh),\
	TF_SF(DSCL0_DSCL_2TAP_CONTROL, SCL_H_2TAP_SHARP_FACTOR, mask_sh),\
	TF_SF(DSCL0_DSCL_2TAP_CONTROL, SCL_V_2TAP_HARDCODE_COEF_EN, mask_sh),\
	TF_SF(DSCL0_DSCL_2TAP_CONTROL, SCL_V_2TAP_SHARP_EN, mask_sh),\
	TF_SF(DSCL0_DSCL_2TAP_CONTROL, SCL_V_2TAP_SHARP_FACTOR, mask_sh),\
	TF_SF(DSCL0_SCL_MODE, SCL_COEF_RAM_SELECT, mask_sh),\
	TF_SF(DSCL0_SCL_MODE, DSCL_MODE, mask_sh),\
	TF_SF(DSCL0_RECOUT_START, RECOUT_START_X, mask_sh),\
	TF_SF(DSCL0_RECOUT_START, RECOUT_START_Y, mask_sh),\
	TF_SF(DSCL0_RECOUT_SIZE, RECOUT_WIDTH, mask_sh),\
	TF_SF(DSCL0_RECOUT_SIZE, RECOUT_HEIGHT, mask_sh),\
	TF_SF(DSCL0_MPC_SIZE, MPC_WIDTH, mask_sh),\
	TF_SF(DSCL0_MPC_SIZE, MPC_HEIGHT, mask_sh),\
	TF_SF(DSCL0_SCL_HORZ_FILTER_SCALE_RATIO, SCL_H_SCALE_RATIO, mask_sh),\
	TF_SF(DSCL0_SCL_VERT_FILTER_SCALE_RATIO, SCL_V_SCALE_RATIO, mask_sh),\
	TF_SF(DSCL0_SCL_HORZ_FILTER_SCALE_RATIO_C, SCL_H_SCALE_RATIO_C, mask_sh),\
	TF_SF(DSCL0_SCL_VERT_FILTER_SCALE_RATIO_C, SCL_V_SCALE_RATIO_C, mask_sh),\
	TF_SF(DSCL0_SCL_HORZ_FILTER_INIT, SCL_H_INIT_FRAC, mask_sh),\
	TF_SF(DSCL0_SCL_HORZ_FILTER_INIT, SCL_H_INIT_INT, mask_sh),\
	TF_SF(DSCL0_SCL_HORZ_FILTER_INIT_C, SCL_H_INIT_FRAC_C, mask_sh),\
	TF_SF(DSCL0_SCL_HORZ_FILTER_INIT_C, SCL_H_INIT_INT_C, mask_sh),\
	TF_SF(DSCL0_SCL_VERT_FILTER_INIT, SCL_V_INIT_FRAC, mask_sh),\
	TF_SF(DSCL0_SCL_VERT_FILTER_INIT, SCL_V_INIT_INT, mask_sh),\
	TF_SF(DSCL0_SCL_VERT_FILTER_INIT_BOT, SCL_V_INIT_FRAC_BOT, mask_sh),\
	TF_SF(DSCL0_SCL_VERT_FILTER_INIT_BOT, SCL_V_INIT_INT_BOT, mask_sh),\
	TF_SF(DSCL0_SCL_VERT_FILTER_INIT_C, SCL_V_INIT_FRAC_C, mask_sh),\
	TF_SF(DSCL0_SCL_VERT_FILTER_INIT_C, SCL_V_INIT_INT_C, mask_sh),\
	TF_SF(DSCL0_SCL_VERT_FILTER_INIT_BOT_C, SCL_V_INIT_FRAC_BOT_C, mask_sh),\
	TF_SF(DSCL0_SCL_VERT_FILTER_INIT_BOT_C, SCL_V_INIT_INT_BOT_C, mask_sh),\
	TF_SF(DSCL0_SCL_MODE, SCL_CHROMA_COEF_MODE, mask_sh),\
	TF_SF(DSCL0_SCL_MODE, SCL_COEF_RAM_SELECT_CURRENT, mask_sh)

#define TF_REG_LIST_SH_MASK_DCN10(mask_sh)\
	TF_REG_LIST_SH_MASK_DCN(mask_sh),\
	TF_SF(DSCL0_LB_DATA_FORMAT, PIXEL_DEPTH, mask_sh),\
	TF_SF(DSCL0_LB_DATA_FORMAT, PIXEL_EXPAN_MODE, mask_sh),\
	TF_SF(DSCL0_LB_DATA_FORMAT, PIXEL_REDUCE_MODE, mask_sh),\
	TF_SF(DSCL0_LB_DATA_FORMAT, DYNAMIC_PIXEL_DEPTH, mask_sh),\
	TF_SF(DSCL0_LB_DATA_FORMAT, DITHER_EN, mask_sh),\
	TF_SF(CM0_CM_COMA_C11_C12, CM_COMA_C11, mask_sh),\
	TF_SF(CM0_CM_COMA_C11_C12, CM_COMA_C12, mask_sh),\
	TF_SF(CM0_CM_COMA_C13_C14, CM_COMA_C13, mask_sh),\
	TF_SF(CM0_CM_COMA_C13_C14, CM_COMA_C14, mask_sh),\
	TF_SF(CM0_CM_COMA_C21_C22, CM_COMA_C21, mask_sh),\
	TF_SF(CM0_CM_COMA_C21_C22, CM_COMA_C22, mask_sh),\
	TF_SF(CM0_CM_COMA_C23_C24, CM_COMA_C23, mask_sh),\
	TF_SF(CM0_CM_COMA_C23_C24, CM_COMA_C24, mask_sh),\
	TF_SF(CM0_CM_COMA_C31_C32, CM_COMA_C31, mask_sh),\
	TF_SF(CM0_CM_COMA_C31_C32, CM_COMA_C32, mask_sh),\
	TF_SF(CM0_CM_COMA_C33_C34, CM_COMA_C33, mask_sh),\
	TF_SF(CM0_CM_COMA_C33_C34, CM_COMA_C34, mask_sh),\
	TF_SF(CM0_CM_COMB_C11_C12, CM_COMB_C11, mask_sh),\
	TF_SF(CM0_CM_COMB_C11_C12, CM_COMB_C12, mask_sh),\
	TF_SF(CM0_CM_COMB_C13_C14, CM_COMB_C13, mask_sh),\
	TF_SF(CM0_CM_COMB_C13_C14, CM_COMB_C14, mask_sh),\
	TF_SF(CM0_CM_COMB_C21_C22, CM_COMB_C21, mask_sh),\
	TF_SF(CM0_CM_COMB_C21_C22, CM_COMB_C22, mask_sh),\
	TF_SF(CM0_CM_COMB_C23_C24, CM_COMB_C23, mask_sh),\
	TF_SF(CM0_CM_COMB_C23_C24, CM_COMB_C24, mask_sh),\
	TF_SF(CM0_CM_COMB_C31_C32, CM_COMB_C31, mask_sh),\
	TF_SF(CM0_CM_COMB_C33_C34, CM_COMB_C33, mask_sh),\
	TF_SF(CM0_CM_COMB_C31_C32, CM_COMB_C32, mask_sh),\
	TF_SF(CM0_CM_COMB_C33_C34, CM_COMB_C34, mask_sh)


#define TF_REG_FIELD_LIST(type) \
	type EXT_OVERSCAN_LEFT; \
	type EXT_OVERSCAN_RIGHT; \
	type EXT_OVERSCAN_BOTTOM; \
	type EXT_OVERSCAN_TOP; \
	type OTG_H_BLANK_START; \
	type OTG_H_BLANK_END; \
	type OTG_V_BLANK_START; \
	type OTG_V_BLANK_END; \
	type PIXEL_DEPTH; \
	type PIXEL_EXPAN_MODE; \
	type PIXEL_REDUCE_MODE; \
	type DYNAMIC_PIXEL_DEPTH; \
	type DITHER_EN; \
	type INTERLEAVE_EN; \
	type ALPHA_EN; \
	type MEMORY_CONFIG; \
	type LB_MAX_PARTITIONS; \
	type AUTOCAL_MODE; \
	type AUTOCAL_NUM_PIPE; \
	type AUTOCAL_PIPE_ID; \
	type SCL_BLACK_OFFSET_RGB_Y; \
	type SCL_BLACK_OFFSET_CBCR; \
	type SCL_BOUNDARY_MODE; \
	type SCL_V_NUM_TAPS; \
	type SCL_H_NUM_TAPS; \
	type SCL_V_NUM_TAPS_C; \
	type SCL_H_NUM_TAPS_C; \
	type SCL_COEF_RAM_TAP_PAIR_IDX; \
	type SCL_COEF_RAM_PHASE; \
	type SCL_COEF_RAM_FILTER_TYPE; \
	type SCL_COEF_RAM_EVEN_TAP_COEF; \
	type SCL_COEF_RAM_EVEN_TAP_COEF_EN; \
	type SCL_COEF_RAM_ODD_TAP_COEF; \
	type SCL_COEF_RAM_ODD_TAP_COEF_EN; \
	type SCL_H_2TAP_HARDCODE_COEF_EN; \
	type SCL_H_2TAP_SHARP_EN; \
	type SCL_H_2TAP_SHARP_FACTOR; \
	type SCL_V_2TAP_HARDCODE_COEF_EN; \
	type SCL_V_2TAP_SHARP_EN; \
	type SCL_V_2TAP_SHARP_FACTOR; \
	type SCL_COEF_RAM_SELECT; \
	type DSCL_MODE; \
	type RECOUT_START_X; \
	type RECOUT_START_Y; \
	type RECOUT_WIDTH; \
	type RECOUT_HEIGHT; \
	type MPC_WIDTH; \
	type MPC_HEIGHT; \
	type SCL_H_SCALE_RATIO; \
	type SCL_V_SCALE_RATIO; \
	type SCL_H_SCALE_RATIO_C; \
	type SCL_V_SCALE_RATIO_C; \
	type SCL_H_INIT_FRAC; \
	type SCL_H_INIT_INT; \
	type SCL_H_INIT_FRAC_C; \
	type SCL_H_INIT_INT_C; \
	type SCL_V_INIT_FRAC; \
	type SCL_V_INIT_INT; \
	type SCL_V_INIT_FRAC_BOT; \
	type SCL_V_INIT_INT_BOT; \
	type SCL_V_INIT_FRAC_C; \
	type SCL_V_INIT_INT_C; \
	type SCL_V_INIT_FRAC_BOT_C; \
	type SCL_V_INIT_INT_BOT_C; \
	type SCL_CHROMA_COEF_MODE; \
	type SCL_COEF_RAM_SELECT_CURRENT; \
	type CM_GAMUT_REMAP_MODE; \
	type CM_GAMUT_REMAP_C11; \
	type CM_GAMUT_REMAP_C12; \
	type CM_GAMUT_REMAP_C13; \
	type CM_GAMUT_REMAP_C14; \
	type CM_GAMUT_REMAP_C21; \
	type CM_GAMUT_REMAP_C22; \
	type CM_GAMUT_REMAP_C23; \
	type CM_GAMUT_REMAP_C24; \
	type CM_GAMUT_REMAP_C31; \
	type CM_GAMUT_REMAP_C32; \
	type CM_GAMUT_REMAP_C33; \
	type CM_GAMUT_REMAP_C34; \
	type CM_COMA_C11; \
	type CM_COMA_C12; \
	type CM_COMA_C13; \
	type CM_COMA_C14; \
	type CM_COMA_C21; \
	type CM_COMA_C22; \
	type CM_COMA_C23; \
	type CM_COMA_C24; \
	type CM_COMA_C31; \
	type CM_COMA_C32; \
	type CM_COMA_C33; \
	type CM_COMA_C34; \
	type CM_COMB_C11; \
	type CM_COMB_C12; \
	type CM_COMB_C13; \
	type CM_COMB_C14; \
	type CM_COMB_C21; \
	type CM_COMB_C22; \
	type CM_COMB_C23; \
	type CM_COMB_C24; \
	type CM_COMB_C31; \
	type CM_COMB_C32; \
	type CM_COMB_C33; \
	type CM_COMB_C34

struct dcn_dpp_shift {
	TF_REG_FIELD_LIST(uint8_t);
};

struct dcn_dpp_mask {
	TF_REG_FIELD_LIST(uint32_t);
};

struct dcn_dpp_registers {
	uint32_t DSCL_EXT_OVERSCAN_LEFT_RIGHT;
	uint32_t DSCL_EXT_OVERSCAN_TOP_BOTTOM;
	uint32_t OTG_H_BLANK;
	uint32_t OTG_V_BLANK;
	uint32_t SCL_MODE;
	uint32_t LB_DATA_FORMAT;
	uint32_t LB_MEMORY_CTRL;
	uint32_t DSCL_AUTOCAL;
	uint32_t SCL_BLACK_OFFSET;
	uint32_t DSCL_CONTROL;
	uint32_t SCL_TAP_CONTROL;
	uint32_t SCL_COEF_RAM_TAP_SELECT;
	uint32_t SCL_COEF_RAM_TAP_DATA;
	uint32_t DSCL_2TAP_CONTROL;
	uint32_t MPC_SIZE;
	uint32_t SCL_HORZ_FILTER_SCALE_RATIO;
	uint32_t SCL_VERT_FILTER_SCALE_RATIO;
	uint32_t SCL_HORZ_FILTER_SCALE_RATIO_C;
	uint32_t SCL_VERT_FILTER_SCALE_RATIO_C;
	uint32_t SCL_HORZ_FILTER_INIT;
	uint32_t SCL_HORZ_FILTER_INIT_C;
	uint32_t SCL_VERT_FILTER_INIT;
	uint32_t SCL_VERT_FILTER_INIT_BOT;
	uint32_t SCL_VERT_FILTER_INIT_C;
	uint32_t SCL_VERT_FILTER_INIT_BOT_C;
	uint32_t RECOUT_START;
	uint32_t RECOUT_SIZE;
	uint32_t CM_GAMUT_REMAP_CONTROL;
	uint32_t CM_GAMUT_REMAP_C11_C12;
	uint32_t CM_GAMUT_REMAP_C13_C14;
	uint32_t CM_GAMUT_REMAP_C21_C22;
	uint32_t CM_GAMUT_REMAP_C23_C24;
	uint32_t CM_GAMUT_REMAP_C31_C32;
	uint32_t CM_GAMUT_REMAP_C33_C34;
	uint32_t CM_COMA_C11_C12;
	uint32_t CM_COMA_C13_C14;
	uint32_t CM_COMA_C21_C22;
	uint32_t CM_COMA_C23_C24;
	uint32_t CM_COMA_C31_C32;
	uint32_t CM_COMA_C33_C34;
	uint32_t CM_COMB_C11_C12;
	uint32_t CM_COMB_C13_C14;
	uint32_t CM_COMB_C21_C22;
	uint32_t CM_COMB_C23_C24;
	uint32_t CM_COMB_C31_C32;
	uint32_t CM_COMB_C33_C34;
};

struct dcn10_dpp {
	struct transform base;

	const struct dcn_dpp_registers *tf_regs;
	const struct dcn_dpp_shift *tf_shift;
	const struct dcn_dpp_mask *tf_mask;

	const uint16_t *filter_v;
	const uint16_t *filter_h;
	const uint16_t *filter_v_c;
	const uint16_t *filter_h_c;
	int lb_pixel_depth_supported;
	int lb_memory_size;
	int lb_bits_per_entry;
};
bool dcn10_dpp_construct(struct dcn10_dpp *xfm110,
	struct dc_context *ctx,
	uint32_t inst,
	const struct dcn_dpp_registers *tf_regs,
	const struct dcn_dpp_shift *tf_shift,
	const struct dcn_dpp_mask *tf_mask);
#endif
