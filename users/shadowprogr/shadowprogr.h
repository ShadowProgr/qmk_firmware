#pragma once
#include QMK_KEYBOARD_H

#include "process_records.h"

#if defined(KEYBOARD_lily58_rev1) & defined(PROTOCOL_LUFA)
    #include "lufa.h"
    #include "split_util.h"
#endif
#if defined(OLED_DRIVER_ENABLE)
    #include "ssd1306.h"
    #include "oled.h"
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

