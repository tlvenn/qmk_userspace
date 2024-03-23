/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

// Unicorne LP
#undef ANALOG_JOYSTICK_Y_AXIS_PIN
#define ANALOG_JOYSTICK_Y_AXIS_PIN GP27
#undef ANALOG_JOYSTICK_X_AXIS_PIN
#define ANALOG_JOYSTICK_X_AXIS_PIN GP26
#define POINTING_DEVICE_INVERT_Y
#undef POINTING_DEVICE_INVERT_X

#define SPLIT_POINTING_ENABLE = yes
#define POINTING_DEVICE_RIGHT = yes
#define ANALOG_JOYSTICK_SPEED_REGULATOR 10

// QMK
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 4
#define CAPS_WORD_IDLE_TIMEOUT 5000
#define TAPPING_TERM 200

#undef STARTUP_SONG
#define STARTUP_SONG SONG(PLANCK_SOUND)
#define CG_SWAP_SONG SONG(PREONIC_SOUND)

/* Miryoku */
#define BILATERAL_COMBINATIONS
#define BILATERAL_COMBINATIONS_LIMIT_CHORD_TO_N_KEYS 4 /* GUI, Alt, Ctrl, Shift */
#define BILATERAL_COMBINATIONS_DELAY_MODS_THAT_MATCH MOD_MASK_GUI
#define BILATERAL_COMBINATIONS_DELAY_MATCHED_MODS_BY 120  /* ms */
#define BILATERAL_COMBINATIONS_ALLOW_CROSSOVER_AFTER 80  /* ms */
#define BILATERAL_COMBINATIONS_ALLOW_SAMESIDED_AFTER 3000 /* ms */
#define BILATERAL_COMBINATIONS_TYPING_STREAK_TIMEOUT 160 /* ms */
#define BILATERAL_COMBINATIONS_TYPING_STREAK_MODMASK (~MOD_MASK_SHIFT)
