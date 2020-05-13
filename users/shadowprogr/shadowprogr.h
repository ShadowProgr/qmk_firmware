#pragma once
#include QMK_KEYBOARD_H

#include "process_records.h"
#include "wrappers.h"
#include "my_lt.h"

#if defined(OLED_DRIVER_ENABLE)
#    include "oled.h"
#endif
#if defined(RGBLIGHT_ENABLE)
#    include "rgb_light.h"
#endif
#if defined(RGB_MATRIX_ENABLE)
#    include "rgb_matrix.h"
#endif

/* Layers */
enum layers {
    _QWERTY,
    _DVORAK,
    _COLEMAK,
    _NUMPAD,
    _LOWER,
    _RAISE,
    _ADJUST,
    _RESCUE,
};

/* Layer keys */
#define TG_NUMP TG(_NUMPAD)
#define TG_RESC TG(_RESCUE)

/* Mod-tap keys */
#define MT_CT_E MT(MOD_LCTL, KC_ESC)
#define MT_CT_Q MT(MOD_RCTL, KC_QUOT)
#define MT_CT_S MT(MOD_RCTL, KC_SLSH)
