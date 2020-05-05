#pragma once
#include QMK_KEYBOARD_H

#include "process_records.h"

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
#define NUMPAD TG(_NUMPAD)
#define LOWER LT(_LOWER, KC_ENT)
#define RAISE LT(_RAISE, KC_ENT)
#define RESCUE TG(_RESCUE)

/* Mod-tap keys */
#define CTL_ESC MT(MOD_LCTL, KC_ESC)
#define CTL_QUT MT(MOD_RCTL, KC_QUOT)
#define CTL_SLS MT(MOD_RCTL, KC_SLSH)
