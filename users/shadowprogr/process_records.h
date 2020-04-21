#pragma once
#include "shadowprogr.h"

enum custom_keycodes {
  // Layers
  QWERTY = SAFE_RANGE,
  DVORAK,
  COLEMAK,

  // Macros
  KC_P00
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
#ifdef OLED_DRIVER_ENABLE
bool process_record_oled(uint16_t keycode, keyrecord_t *record);
#endif
