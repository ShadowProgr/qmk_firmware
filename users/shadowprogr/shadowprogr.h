#pragma once
#include QMK_KEYBOARD_H

#include "process_records.h"

#if defined(KEYBOARD_lily58_rev1) & defined(PROTOCOL_LUFA)
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

// Layers
enum layers {
    _QWERTY,
    _DVORAK,
    _COLEMAK,
    _NUMPAD,
    _LOWER,
    _RAISE,
    _ADJUST,
};

// Layer keys
#define NUMPAD TG(_NUMPAD)
#define LOWER LT(_LOWER, KC_ENT)
#define RAISE LT(_RAISE, KC_ENT)

// Mod-tap keys
#define CTL_ESC MT(MOD_LCTL, KC_ESC)
