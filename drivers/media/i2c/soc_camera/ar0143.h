/*
 * ON Semiconductor AR0143 sensor camera wizard 1344x968@30/BGGR/BT601/RAW12
 *
 * Copyright (C) 2018 Cogent Embedded, Inc.
 *
 * This program is free software; you can redistribute  it and/or modify it
 * under  the terms of  the GNU General  Public License as published by the
 * Free Software Foundation;  either version 2 of the  License, or (at your
 * option) any later version.
 */

//#define AR0143_DISPLAY_PATTERN_FIXED
//#define AR0143_DISPLAY_PATTERN_COLOR_BAR

//#define AR0143_EMBEDDED_LINE

#define AR0143_MAX_WIDTH	1344
#define AR0143_MAX_HEIGHT	968

#define AR0143_DELAY		0xffff

#define AR0143_SENSOR_WIDTH	1344
#define AR0143_SENSOR_HEIGHT	968

#define AR0143_X_START		((AR0143_SENSOR_WIDTH - AR0143_MAX_WIDTH) / 2)
#define AR0143_Y_START		((AR0143_SENSOR_HEIGHT - AR0143_MAX_HEIGHT) / 2)
#define AR0143_X_END		(AR0143_X_START + AR0143_MAX_WIDTH - 1)
#define AR0143_Y_END		(AR0143_Y_START + AR0143_MAX_HEIGHT + 1) /* must be +1 and not -1 or 2 lines missed - bug in imager? */

struct ar0143_reg {
	u16	reg;
	u16	val;
};

static const struct ar0143_reg ar0143_regs_wizard[] = {
{0x301A, 0x0001},	// reset
{AR0143_DELAY, 100},
{0x301A, 0x10D8},	// Stream off and setup parallel
{0x3070, 0x0001},
{0x3070, 0x0000},	//  1: Solid color test pattern,
			//  2: Full color bar test pattern,
			//  3: Fade to grey color bar test pattern,
			//256: Walking 1 test pattern (12 bit)
#ifdef AR0143_DISPLAY_PATTERN_FIXED
{0x3070, 0x0001},
#endif
{0x3072, 0x0fff},	// R
{0x3074, 0x0fff},	// G(GR row)
{0x3076, 0x0fff},	// B
{0x3078, 0x0fff},	// G(GB row)
#ifdef AR0143_DISPLAY_PATTERN_COLOR_BAR
{0x3070, 0x0002},
#endif
{AR0143_DELAY, 250},
// start demo init
{0x3100, 0x4000}, // DLO_CONTROL0
{0x3102, 0x6060}, // RESERVED_MFR_3102
{0x3104, 0x6060}, // RESERVED_MFR_3104
{0x3106, 0x6060}, // RESERVED_MFR_3106
{0x3108, 0x0F9F}, // RESERVED_MFR_3108
{0x3280, 0x0FA0}, // T1_BARRIER_C0
{0x3282, 0x0FA0}, // T1_BARRIER_C1
{0x3284, 0x0FA0}, // T1_BARRIER_C2
{0x3286, 0x0FA0}, // T1_BARRIER_C3
{0x3288, 0x0FA0}, // T2_BARRIER_C0
{0x328A, 0x0FA0}, // T2_BARRIER_C1
{0x328C, 0x0FA0}, // T2_BARRIER_C2
{0x328E, 0x0FA0}, // T2_BARRIER_C3
{0x3290, 0x0FA0}, // T3_BARRIER_C0
{0x3292, 0x0FA0}, // T3_BARRIER_C1
{0x3294, 0x0FA0}, // T3_BARRIER_C2
{0x3296, 0x0FA0}, // T3_BARRIER_C3
{0x3298, 0x0FA0}, // T4_BARRIER_C0
{0x329A, 0x0FA0}, // T4_BARRIER_C1
{0x329C, 0x0FA0}, // T4_BARRIER_C2
{0x329E, 0x0FA0}, // T4_BARRIER_C3
{0x3110, 0x0011}, // HDR_CONTROL0
{0x3112, 0x7FE7}, // RESERVED_MFR_3112
{0x3114, 0x0000}, // RESERVED_MFR_3114
{0x3116, 0xC000}, // HDR_CONTROL3
{0x3120, 0x0BA0}, // HDR_SC_CONTROL0
{0x3122, 0x0FA0}, // HDR_SC_CONTROL1
{0x3124, 0x00B4}, // HDR_MD_CONTROL0
{0x3126, 0x0030}, // HDR_MD_CONTROL1
{0x3128, 0x6100}, // RESERVED_MFR_3128
{0x3506, 0x3333}, // RESERVED_MFR_3506
{0x3508, 0x3333}, // RESERVED_MFR_3508
{0x350A, 0x3333}, // RESERVED_MFR_350A
{0x350C, 0x035F}, // RESERVED_MFR_350C
{0x350E, 0xEF14}, // RESERVED_MFR_350E
{0x3086, 0x0600}, // RESERVED_MFR_3086
{0x3C00, 0xDD67}, // RESERVED_MFR_3C00
{0x3092, 0x1C24}, // RESERVED_MFR_3092
{0x3096, 0x147E}, // RESERVED_MFR_3096
{0x3750, 0x147E}, // RESERVED_MFR_3750
{0x30B0, 0x0800}, // DIGITAL_TEST
{0x30FE, 0x0000}, // NOISE_PEDESTAL
{0x32D0, 0x3A02}, // RESERVED_MFR_32D0
{0x32D6, 0x3C04}, // RESERVED_MFR_32D6
{0x3C0C, 0x0516}, // DELAY_BUFFER_LLPCK_RD_WR_OVERLAP
{0x3F94, 0x483e}, // TEMPVSENS0_FLAG_CTRL
{0x3F96, 0xFFFE}, // TEMPVSENS1_FLAG_CTRL
{0x3088, 0x6680}, // LFM_CTRL
{0x33E2, 0x0000}, // SAMPLE_CTRL
{0x3366, 0x7777}, // ANALOG_GAIN
{0x3056, 0x0080}, // GREEN1_GAIN
{0x305C, 0x0080}, // GREEN2_GAIN
{0x3058, 0x0080}, // BLUE_GAIN
{0x305A, 0x0080}, // RED_GAIN
{0x306E, 0x9010}, // DATAPATH_SELECT
{0x3044, 0x0400}, // DARK_CONTROL
{0x30BA, 0x01E2}, // DIGITAL_CTRL
{0x32EA, 0x3C0E}, // RESERVED_MFR_32EA
{0x3362, 0x0000}, // DC_GAIN
{0x3364, 0x005B}, // RESERVED_MFR_3364
{0x3370, 0x0131}, // DBLC_CONTROL
{0x3372, 0x700F}, // DBLC_FS0_CONTROL
{0x3386, 0x0000}, // DBLC_PEDESTAL
{0x3C04, 0x0E80}, // RESERVED_MFR_3C04
{0x30B4, 0x01C7}, // TEMPSENS0_CTRL_REG
{0x30B8, 0x0007}, // TEMPSENS1_CTRL_REG
{0x3F90, 0x8D03}, // TEMPVSENS0_TMG_CTRL
{0x3F92, 0x0D03}, // TEMPVSENS1_TMG_CTRL
{0x3502, 0x0808}, // RESERVED_MFR_3502
{0x3566, 0x1D28}, // RESERVED_MFR_3566
{0x3518, 0x1FFE}, // RESERVED_MFR_3518
{0x3526, 0x0F00}, // RESERVED_MFR_3526
{0x3528, 0xDDDD}, // RESERVED_MFR_3528
{0x352A, 0x089F}, // RESERVED_MFR_352A
{0x352E, 0x0011}, // RESERVED_MFR_352E
{0x3530, 0x4400}, // RESERVED_MFR_3530
{0x3536, 0xFF07}, // RESERVED_MFR_3536
{0x3538, 0xFFFF}, // RESERVED_MFR_3538
{0x353A, 0x9000}, // RESERVED_MFR_353A
{0x353C, 0x3F00}, // RESERVED_MFR_353C
{0x32EC, 0x72A1}, // RESERVED_MFR_32EC
{0x3540, 0xC637}, // RESERVED_MFR_3540
{0x3542, 0x464B}, // RESERVED_MFR_3542
{0x3544, 0x4B50}, // RESERVED_MFR_3544
{0x3546, 0x545A}, // RESERVED_MFR_3546
{0x3548, 0x5A00}, // RESERVED_MFR_3548
{0x354A, 0x007F}, // RESERVED_MFR_354A
{0x3556, 0x101F}, // RESERVED_MFR_3556
{0x3566, 0x3328}, // RESERVED_MFR_3566
{0x337A, 0x0CA3}, // DBLC_SCALE0
{0x3372, 0x710F}, // DBLC_FS0_CONTROL
{0x3520, 0x4688}, // RESERVED_MFR_3520
{0x3522, 0x8840}, // RESERVED_MFR_3522
{0x3524, 0x4046}, // RESERVED_MFR_3524
{0x352C, 0x4646}, // RESERVED_MFR_352C
{0x2512, 0x8000}, // SEQ_CTRL_PORT
{0x2510, 0x0903}, // SEQ_DATA_PORT
{0x2510, 0x3350}, // SEQ_DATA_PORT
{0x2510, 0x2004}, // SEQ_DATA_PORT
{0x2510, 0x1420}, // SEQ_DATA_PORT
{0x2510, 0x1578}, // SEQ_DATA_PORT
{0x2510, 0x087B}, // SEQ_DATA_PORT
{0x2510, 0x24FF}, // SEQ_DATA_PORT
{0x2510, 0x24FF}, // SEQ_DATA_PORT
{0x2510, 0x24EA}, // SEQ_DATA_PORT
{0x2510, 0x2410}, // SEQ_DATA_PORT
{0x2510, 0x2224}, // SEQ_DATA_PORT
{0x2510, 0x1015}, // SEQ_DATA_PORT
{0x2510, 0x5813}, // SEQ_DATA_PORT
{0x2510, 0x0214}, // SEQ_DATA_PORT
{0x2510, 0x0024}, // SEQ_DATA_PORT
{0x2510, 0xFF24}, // SEQ_DATA_PORT
{0x2510, 0xFF24}, // SEQ_DATA_PORT
{0x2510, 0xEA23}, // SEQ_DATA_PORT
{0x2510, 0x2464}, // SEQ_DATA_PORT
{0x2510, 0x7A24}, // SEQ_DATA_PORT
{0x2510, 0x0405}, // SEQ_DATA_PORT
{0x2510, 0x2C40}, // SEQ_DATA_PORT
{0x2510, 0x0AFF}, // SEQ_DATA_PORT
{0x2510, 0x0ACC}, // SEQ_DATA_PORT
{0x2510, 0x0A07}, // SEQ_DATA_PORT
{0x2510, 0x3851}, // SEQ_DATA_PORT
{0x2510, 0x1440}, // SEQ_DATA_PORT
{0x2510, 0x0004}, // SEQ_DATA_PORT
{0x2510, 0x0801}, // SEQ_DATA_PORT
{0x2510, 0x0408}, // SEQ_DATA_PORT
{0x2510, 0x1180}, // SEQ_DATA_PORT
{0x2510, 0x2652}, // SEQ_DATA_PORT
{0x2510, 0x0815}, // SEQ_DATA_PORT
{0x2510, 0x1813}, // SEQ_DATA_PORT
{0x2510, 0xC810}, // SEQ_DATA_PORT
{0x2510, 0x0210}, // SEQ_DATA_PORT
{0x2510, 0x1611}, // SEQ_DATA_PORT
{0x2510, 0x8111}, // SEQ_DATA_PORT
{0x2510, 0x8910}, // SEQ_DATA_PORT
{0x2510, 0x5612}, // SEQ_DATA_PORT
{0x2510, 0x1009}, // SEQ_DATA_PORT
{0x2510, 0x020D}, // SEQ_DATA_PORT
{0x2510, 0x0905}, // SEQ_DATA_PORT
{0x2510, 0x1588}, // SEQ_DATA_PORT
{0x2510, 0x1388}, // SEQ_DATA_PORT
{0x2510, 0x0938}, // SEQ_DATA_PORT
{0x2510, 0x1199}, // SEQ_DATA_PORT
{0x2510, 0x11D9}, // SEQ_DATA_PORT
{0x2510, 0x091E}, // SEQ_DATA_PORT
{0x2510, 0x1214}, // SEQ_DATA_PORT
{0x2510, 0x10D6}, // SEQ_DATA_PORT
{0x2510, 0x0901}, // SEQ_DATA_PORT
{0x2510, 0x1210}, // SEQ_DATA_PORT
{0x2510, 0x1212}, // SEQ_DATA_PORT
{0x2510, 0x1210}, // SEQ_DATA_PORT
{0x2510, 0x11DD}, // SEQ_DATA_PORT
{0x2510, 0x11D9}, // SEQ_DATA_PORT
{0x2510, 0x0901}, // SEQ_DATA_PORT
{0x2510, 0x1441}, // SEQ_DATA_PORT
{0x2510, 0x0904}, // SEQ_DATA_PORT
{0x2510, 0x1056}, // SEQ_DATA_PORT
{0x2510, 0x0811}, // SEQ_DATA_PORT
{0x2510, 0xDB09}, // SEQ_DATA_PORT
{0x2510, 0x0311}, // SEQ_DATA_PORT
{0x2510, 0xFB11}, // SEQ_DATA_PORT
{0x2510, 0xBB12}, // SEQ_DATA_PORT
{0x2510, 0x1A12}, // SEQ_DATA_PORT
{0x2510, 0x1008}, // SEQ_DATA_PORT
{0x2510, 0x1250}, // SEQ_DATA_PORT
{0x2510, 0x1076}, // SEQ_DATA_PORT
{0x2510, 0x10E6}, // SEQ_DATA_PORT
{0x2510, 0x1461}, // SEQ_DATA_PORT
{0x2510, 0x0906}, // SEQ_DATA_PORT
{0x2510, 0x1240}, // SEQ_DATA_PORT
{0x2510, 0x1260}, // SEQ_DATA_PORT
{0x2510, 0x091C}, // SEQ_DATA_PORT
{0x2510, 0x1460}, // SEQ_DATA_PORT
{0x2510, 0x090C}, // SEQ_DATA_PORT
{0x2510, 0x0B09}, // SEQ_DATA_PORT
{0x2510, 0x0515}, // SEQ_DATA_PORT
{0x2510, 0xC813}, // SEQ_DATA_PORT
{0x2510, 0xC808}, // SEQ_DATA_PORT
{0x2510, 0x1066}, // SEQ_DATA_PORT
{0x2510, 0x090B}, // SEQ_DATA_PORT
{0x2510, 0x1588}, // SEQ_DATA_PORT
{0x2510, 0x1388}, // SEQ_DATA_PORT
{0x2510, 0x0913}, // SEQ_DATA_PORT
{0x2510, 0x0C14}, // SEQ_DATA_PORT
{0x2510, 0x4009}, // SEQ_DATA_PORT
{0x2510, 0x0310}, // SEQ_DATA_PORT
{0x2510, 0xE611}, // SEQ_DATA_PORT
{0x2510, 0xFB12}, // SEQ_DATA_PORT
{0x2510, 0x6212}, // SEQ_DATA_PORT
{0x2510, 0x6011}, // SEQ_DATA_PORT
{0x2510, 0xFF11}, // SEQ_DATA_PORT
{0x2510, 0xFB14}, // SEQ_DATA_PORT
{0x2510, 0x4109}, // SEQ_DATA_PORT
{0x2510, 0x0210}, // SEQ_DATA_PORT
{0x2510, 0x6609}, // SEQ_DATA_PORT
{0x2510, 0x1211}, // SEQ_DATA_PORT
{0x2510, 0xBB12}, // SEQ_DATA_PORT
{0x2510, 0x6312}, // SEQ_DATA_PORT
{0x2510, 0x6014}, // SEQ_DATA_PORT
{0x2510, 0x0015}, // SEQ_DATA_PORT
{0x2510, 0x1811}, // SEQ_DATA_PORT
{0x2510, 0xB812}, // SEQ_DATA_PORT
{0x2510, 0xA012}, // SEQ_DATA_PORT
{0x2510, 0x0010}, // SEQ_DATA_PORT
{0x2510, 0x2610}, // SEQ_DATA_PORT
{0x2510, 0x0013}, // SEQ_DATA_PORT
{0x2510, 0x0011}, // SEQ_DATA_PORT
{0x2510, 0x8030}, // SEQ_DATA_PORT
{0x2510, 0x5342}, // SEQ_DATA_PORT
{0x2510, 0x1100}, // SEQ_DATA_PORT
{0x2510, 0x1002}, // SEQ_DATA_PORT
{0x2510, 0x1016}, // SEQ_DATA_PORT
{0x2510, 0x1101}, // SEQ_DATA_PORT
{0x2510, 0x1109}, // SEQ_DATA_PORT
{0x2510, 0x1056}, // SEQ_DATA_PORT
{0x2510, 0x1210}, // SEQ_DATA_PORT
{0x2510, 0x0D09}, // SEQ_DATA_PORT
{0x2510, 0x0614}, // SEQ_DATA_PORT
{0x2510, 0x4009}, // SEQ_DATA_PORT
{0x2510, 0x0214}, // SEQ_DATA_PORT
{0x2510, 0x6009}, // SEQ_DATA_PORT
{0x2510, 0x0615}, // SEQ_DATA_PORT
{0x2510, 0x4C13}, // SEQ_DATA_PORT
{0x2510, 0x0C09}, // SEQ_DATA_PORT
{0x2510, 0x0713}, // SEQ_DATA_PORT
{0x2510, 0x4C09}, // SEQ_DATA_PORT
{0x2510, 0x0715}, // SEQ_DATA_PORT
{0x2510, 0xCC09}, // SEQ_DATA_PORT
{0x2510, 0x0211}, // SEQ_DATA_PORT
{0x2510, 0x4908}, // SEQ_DATA_PORT
{0x2510, 0x1461}, // SEQ_DATA_PORT
{0x2510, 0x1460}, // SEQ_DATA_PORT
{0x2510, 0x0903}, // SEQ_DATA_PORT
{0x2510, 0x1588}, // SEQ_DATA_PORT
{0x2510, 0x1308}, // SEQ_DATA_PORT
{0x2510, 0x0905}, // SEQ_DATA_PORT
{0x2510, 0x1388}, // SEQ_DATA_PORT
{0x2510, 0x0913}, // SEQ_DATA_PORT
{0x2510, 0x1159}, // SEQ_DATA_PORT
{0x2510, 0x090B}, // SEQ_DATA_PORT
{0x2510, 0x1214}, // SEQ_DATA_PORT
{0x2510, 0x0901}, // SEQ_DATA_PORT
{0x2510, 0x1210}, // SEQ_DATA_PORT
{0x2510, 0x10D6}, // SEQ_DATA_PORT
{0x2510, 0x1212}, // SEQ_DATA_PORT
{0x2510, 0x1210}, // SEQ_DATA_PORT
{0x2510, 0x115D}, // SEQ_DATA_PORT
{0x2510, 0x1159}, // SEQ_DATA_PORT
{0x2510, 0x1056}, // SEQ_DATA_PORT
{0x2510, 0x0903}, // SEQ_DATA_PORT
{0x2510, 0x115B}, // SEQ_DATA_PORT
{0x2510, 0x0913}, // SEQ_DATA_PORT
{0x2510, 0x111B}, // SEQ_DATA_PORT
{0x2510, 0x113B}, // SEQ_DATA_PORT
{0x2510, 0x121A}, // SEQ_DATA_PORT
{0x2510, 0x1210}, // SEQ_DATA_PORT
{0x2510, 0x0901}, // SEQ_DATA_PORT
{0x2510, 0x1250}, // SEQ_DATA_PORT
{0x2510, 0x10F6}, // SEQ_DATA_PORT
{0x2510, 0x10E6}, // SEQ_DATA_PORT
{0x2510, 0x0903}, // SEQ_DATA_PORT
{0x2510, 0x15AB}, // SEQ_DATA_PORT
{0x2510, 0x13AB}, // SEQ_DATA_PORT
{0x2510, 0x1240}, // SEQ_DATA_PORT
{0x2510, 0x1260}, // SEQ_DATA_PORT
{0x2510, 0x0964}, // SEQ_DATA_PORT
{0x2510, 0x1588}, // SEQ_DATA_PORT
{0x2510, 0x0903}, // SEQ_DATA_PORT
{0x2510, 0x0B08}, // SEQ_DATA_PORT
{0x2510, 0x0813}, // SEQ_DATA_PORT
{0x2510, 0x8809}, // SEQ_DATA_PORT
{0x2510, 0x0715}, // SEQ_DATA_PORT
{0x2510, 0x8D13}, // SEQ_DATA_PORT
{0x2510, 0x8D09}, // SEQ_DATA_PORT
{0x2510, 0x0D15}, // SEQ_DATA_PORT
{0x2510, 0x8813}, // SEQ_DATA_PORT
{0x2510, 0x8809}, // SEQ_DATA_PORT
{0x2510, 0x0310}, // SEQ_DATA_PORT
{0x2510, 0x6609}, // SEQ_DATA_PORT
{0x2510, 0x030C}, // SEQ_DATA_PORT
{0x2510, 0x0914}, // SEQ_DATA_PORT
{0x2510, 0x10E6}, // SEQ_DATA_PORT
{0x2510, 0x1262}, // SEQ_DATA_PORT
{0x2510, 0x1260}, // SEQ_DATA_PORT
{0x2510, 0x113F}, // SEQ_DATA_PORT
{0x2510, 0x113B}, // SEQ_DATA_PORT
{0x2510, 0x1066}, // SEQ_DATA_PORT
{0x2510, 0x117B}, // SEQ_DATA_PORT
{0x2510, 0x0927}, // SEQ_DATA_PORT
{0x2510, 0x113B}, // SEQ_DATA_PORT
{0x2510, 0x1263}, // SEQ_DATA_PORT
{0x2510, 0x1260}, // SEQ_DATA_PORT
{0x2510, 0x1400}, // SEQ_DATA_PORT
{0x2510, 0x155A}, // SEQ_DATA_PORT
{0x2510, 0x1138}, // SEQ_DATA_PORT
{0x2510, 0x12A0}, // SEQ_DATA_PORT
{0x2510, 0x1200}, // SEQ_DATA_PORT
{0x2510, 0x1026}, // SEQ_DATA_PORT
{0x2510, 0x1000}, // SEQ_DATA_PORT
{0x2510, 0x1342}, // SEQ_DATA_PORT
{0x2510, 0x1100}, // SEQ_DATA_PORT
{0x2510, 0x437A}, // SEQ_DATA_PORT
{0x2510, 0x0605}, // SEQ_DATA_PORT
{0x2510, 0x0807}, // SEQ_DATA_PORT
{0x2510, 0x4137}, // SEQ_DATA_PORT
{0x2510, 0x502C}, // SEQ_DATA_PORT
{0x2510, 0x2CFE}, // SEQ_DATA_PORT
{0x2510, 0x16FE}, // SEQ_DATA_PORT
{0x2510, 0x0C2C}, // SEQ_DATA_PORT
{0x1008, 0x0338}, // FINE_INTEGRATION_TIME_MIN
{0x100C, 0x051B}, // FINE_INTEGRATION_TIME2_MIN
{0x100E, 0x06FE}, // FINE_INTEGRATION_TIME3_MIN
{0x1010, 0x0155}, // FINE_INTEGRATION_TIME4_MIN
{0x3230, 0x02D6}, // FINE_CORRECTION
{0x3232, 0x04B9}, // FINE_CORRECTION2
{0x3234, 0x069C}, // FINE_CORRECTION3
{0x3236, 0x00F3}, // FINE_CORRECTION4
{0x32E6, 0x00DA}, // RESERVED_MFR_32E6
{0x350C, 0x035F}, // RESERVED_MFR_350C
{0x32D0, 0x3A02}, // RESERVED_MFR_32D0
{0x32D2, 0x3508}, // RESERVED_MFR_32D2
{0x32D4, 0x3702}, // RESERVED_MFR_32D4
{0x32D6, 0x3C04}, // RESERVED_MFR_32D6
{0x32DC, 0x370A}, // RESERVED_MFR_32DC
{0x302A, 0x0008}, // VT_PIX_CLK_DIV
{0x302C, 0x0001}, // VT_SYS_CLK_DIV
{0x302E, 0x0002}, // PRE_PLL_CLK_DIV
{0x3030, 0x0034}, // PLL_MULTIPLIER
{0x3036, 0x0008}, // OP_WORD_CLK_DIV
{0x3038, 0x0001}, // OP_SYS_CLK_DIV
{0x31DC, 0x0030}, // RESERVED_MFR_31DC
{0x30A2, 0x0001}, // X_ODD_INC_
{0x30A6, 0x0001}, // Y_ODD_INC_
{0x3040, 0x0000}, // READ_MODE
{0x3044, 0x0400}, // DARK_CONTROL
{0x3180, 0x0080}, // RESERVED_MFR_3180
{0x33E4, 0x0080}, // RESERVED_MFR_33E4
{0x33E0, 0x0880}, // TEST_ASIL_ROWS
#ifdef AR0143_EMBEDDED_LINE
{0x3064, 0x1982}, // SMIA_TEST
#else
{0x3064, 0x1802}, // SMIA_TEST
#endif
{0x3004, 0x0000}, // X_ADDR_START_
{0x3008, 0x053F}, // X_ADDR_END_
{0x3002, 0x0000}, // Y_ADDR_START_
{0x3006, 0x03C7}, // Y_ADDR_END_
{0x3400, 0x0010}, // RESERVED_MFR_3400
{0x3402, 0x0A80}, // X_OUTPUT_CONTROL
{0x3404, 0x0790}, // Y_OUTPUT_CONTROL
{0x3082, 0x0008}, // OPERATION_MODE_CTRL
{0x30BA, 0x01E2}, // DIGITAL_CTRL
{0x300C, 0x09A0}, // LINE_LENGTH_PCK_
{0x300A, 0x041E}, // FRAME_LENGTH_LINES_
{0x3042, 0x0000}, // EXTRA_DELAY
{0x3238, 0x0333}, // EXPOSURE_RATIO
{0x3012, 0x036E}, // COARSE_INTEGRATION_TIME_
{0x3014, 0x0A7A}, // FINE_INTEGRATION_TIME_
{0x321E, 0x0A7A}, // FINE_INTEGRATION_TIME2
{0x3222, 0x0A7A}, // FINE_INTEGRATION_TIME3
{0x32EA, 0x3C0E}, // RESERVED_MFR_32EA
{0x32EA, 0x3C0E}, // RESERVED_MFR_32EA
{0x32EA, 0x3C0E}, // RESERVED_MFR_32EA
{0x32EC, 0x72A1}, // RESERVED_MFR_32EC
{0x32EC, 0x72A1}, // RESERVED_MFR_32EC
{0x32EC, 0x72A1}, // RESERVED_MFR_32EC
{0x32EC, 0x72A1}, // RESERVED_MFR_32EC
{0x32EC, 0x72A1}, // RESERVED_MFR_32EC
{0x32EC, 0x72A1}, // RESERVED_MFR_32EC
{0x3C06, 0x083C}, // RESERVED_MFR_3C06
{0x3C08, 0x0100}, // RESERVED_MFR_3C08
{0x31D0, 0x0001}, // COMPANDING
{0x31AC, 0x1410}, // DATA_FORMAT_BITS: 2xRAW8
{0x301A, 0x1098}, // RESET_REGISTER
{0x301A, 0x1018}, // RESET_REGISTER
{0x301A, 0x0018}, // RESET_REGISTER
{0x31AE, 0x0204}, // SERIAL_FORMAT
{0x3342, 0x122A}, // MIPI_F1_PDT_EDT
{0x3346, 0x122A}, // MIPI_F2_PDT_EDT
{0x334A, 0x122A}, // MIPI_F3_PDT_EDT
{0x334E, 0x122A}, // MIPI_F4_PDT_EDT
{0x3344, 0x0011}, // MIPI_F1_VDT_VC
{0x3348, 0x0111}, // MIPI_F2_VDT_VC
{0x334C, 0x0211}, // MIPI_F3_VDT_VC
{0x3350, 0x0311}, // MIPI_F4_VDT_VC
{0x31B0, 0x0061}, // FRAME_PREAMBLE
{0x31B2, 0x004C}, // LINE_PREAMBLE
{0x31B4, 0x51C8}, // RESERVED_MFR_31B4
{0x31B6, 0x424B}, // RESERVED_MFR_31B6
{0x31B8, 0x40CF}, // RESERVED_MFR_31B8
{0x31BA, 0x028B}, // RESERVED_MFR_31BA
{0x31BC, 0x0D09}, // RESERVED_MFR_31BC
// end demo init
// start reg wizard WIDTHxHEIGHT@30fps
#define NEW_TBL
#ifdef NEW_TBL
/* PCLK=27Mhz/0x5 *0x5d /1/0xa - MAXIM serializers */
{0x302A, 0x000A}, // VT_PIX_CLK_DIV
{0x302C, 0x0001}, // VT_SYS_CLK_DIV
{0x302E, 0x0005}, // PRE_PLL_CLK_DIV
{0x3030, 0x005d}, // PLL_MULTIPLIER
{0x3036, 0x000A}, // OP_WORD_CLK_DIV
{0x3038, 0x0001}, // OP_SYS_CLK_DIV
#else
/* PCLK=27Mhz/0x9 *134 /1/8 - MAXIM serializers */
{0x302A, 0x0008}, // VT_PIX_CLK_DIV
{0x302C, 0x0001}, // VT_SYS_CLK_DIV
{0x302E, 0x0009}, // PRE_PLL_CLK_DIV
{0x3030, 134}, // PLL_MULTIPLIER
{0x3036, 0x0008}, // OP_WORD_CLK_DIV
{0x3038, 0x0001}, // OP_SYS_CLK_DIV
#endif
{0x31B0, 0x0056}, // FRAME_PREAMBLE
{0x31B2, 0x0045}, // LINE_PREAMBLE
{0x3004, AR0143_X_START}, // X_ADDR_START_
{0x3008, AR0143_X_END}, // X_ADDR_END_
{0x3002, AR0143_Y_START}, // Y_ADDR_START_
{0x3006, AR0143_Y_END}, // Y_ADDR_END_
{0x3402, 0x0000 | AR0143_MAX_WIDTH}, // X_OUTPUT_CONTROL
{0x3404, 0x0000 | AR0143_MAX_HEIGHT}, // Y_OUTPUT_CONTROL
{0x31B4, 0x2207}, // RESERVED_MFR_31B4
{0x31B6, 0x220B}, // RESERVED_MFR_31B6
{0x31B8, 0x404B}, // RESERVED_MFR_31B8
{0x31BA, 0x020A}, // RESERVED_MFR_31BA
{0x31BC, 0x0C08}, // RESERVED_MFR_31BC
{0x3040, 0x0000}, // READ_MODE
{0x30BA, 0x01E2}, // DIGITAL_CTRL
{0x3082, 0x0008}, // OPERATION_MODE_CTRL
{0x3044, 0x0400}, // DARK_CONTROL
{0x33E0, 0x0880}, // TEST_ASIL_ROWS
{0x3180, 0x0080}, // RESERVED_MFR_3180
{0x33E4, 0x0080}, // RESERVED_MFR_33E4
{0x3032, 0x0000}, // RESERVED_MFR_3032
{0x3400, 0x0010}, // RESERVED_MFR_3400
{0x31D0, 0x0001}, // COMPANDING
//{0x31AC, 0x1410}, // DATA_FORMAT_BITS: 2xRAW8
{0x31AC, 0x140C}, // DATA_FORMAT_BITS: RAW12
{0x3C08, 0x0100}, // RESERVED_MFR_3C08
{0x3C0C, 0x0518}, // DELAY_BUFFER_LLPCK_RD_WR_OVERLAP
#ifdef NEW_TBL
//{0x300A, 0x0438}, // FRAME_LENGTH_LINES_
//{0x300C, 0x060e}, // LINE_LENGTH_PCK_
{0x300A, AR0143_SENSOR_HEIGHT + 157}, // FRAME_LENGTH_LINES_
{0x300C, AR0143_SENSOR_WIDTH + 144}, // LINE_LENGTH_PCK_
#else
{0x300A, 0x048A}, // FRAME_LENGTH_LINES_
{0x300C, 0x05BA}, // LINE_LENGTH_PCK_
#endif
{0x3018, 0x0000}, // FINE_INTEGRATION_TIME_CB
{0x1008, 0x0338}, // FINE_INTEGRATION_TIME_MIN
{0x100C, 0x051B}, // FINE_INTEGRATION_TIME2_MIN
{0x100E, 0x06FE}, // FINE_INTEGRATION_TIME3_MIN
{0x1010, 0x0155}, // FINE_INTEGRATION_TIME4_MIN
#ifdef NEW_TBL
{0x3012, 0x0206}, // COARSE_INTEGRATION_TIME_
{0x3014, 0x06e8}, // FINE_INTEGRATION_TIME_
{0x321E, 0x06E8}, // FINE_INTEGRATION_TIME2
{0x3222, 0x06E8}, // FINE_INTEGRATION_TIME3
#else
{0x3012, 0x0332}, // COARSE_INTEGRATION_TIME_
{0x3014, 0x0694}, // FINE_INTEGRATION_TIME_
{0x321E, 0x0694}, // FINE_INTEGRATION_TIME2
{0x3222, 0x0694}, // FINE_INTEGRATION_TIME3
#endif
{0x32EC, 0x72A0}, // RESERVED_MFR_32EC
{0x31C6, 0x0000}, // HISPI_CONTROL
#ifdef NEW_TBL
{0x3082, 0x0000}, // OPERATION_MODE_CTRL: 1 exposure
{0x3238, 0x0222}, // auto exposure time ratio - Fixed!
#else
// patch start
//{0x30BA, 0x01E2}, // DIGITAL_CTRL: 3 exposures
//{0x3082, 0x0008}, // OPERATION_MODE_CTRL: 3 exposures
{0x3082, 0x0000}, // OPERATION_MODE_CTRL: 1 exposure
//{0x30fe, 0x07ff}, // NOISE PEDESTAL
//{0x305e, 0x3333}, // DIGITAL COLOR GLOBAL GAIN
{0x3308, 0x200}, // DIGITAL GLOBAL GAIN: max=0x7ff
//{0x3060, 0x7777}, // ANALOG COLOR GAIN
{0x3366, 0x0666}, // ANALOG_GAIN - Fixed!
//{0x3238, 0x8000}, // manual exposure time
{0x3238, 0x0222}, // auto exposure time ratio - Fixed!
{0x3012, 0x0300}, // T1 exposure - max=0x400
//{0x3212, 0x0004}, // T2 exposure - not used in auto
//{0x3216, 0x0001}, // T3 exposure - not used in auto
#endif
// patch eof
{0x301A, 0x01d8}, // RESET_REGISTER
// enable trigger
{0x340A, 0x0070}, // GPIO_CONTROL1: GPIO3 is trigger
{0x340C, 0x0080}, // GPIO_CONTROL2: GPIO3 is trigger
{0x30CE, 0x0120}, // TRIGGER_MODE
//{0x30DC, 0x0120}, // TRIGGER_DELAY
// end reg wizard WIDTHxHEIGHT@30fps
};
