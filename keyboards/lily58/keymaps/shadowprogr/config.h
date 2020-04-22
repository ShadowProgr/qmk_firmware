#pragma once

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define SSD1306OLED

#define USE_SERIAL_PD2

#ifdef TAPPING_TERM
  #undef TAPPING_TERM
  #define TAPPING_TERM 200
#endif

#ifdef RGBLIGHT_ENABLE
  #undef RGBLED_NUM
  #define RGBLIGHT_ANIMATIONS
  #define RGBLED_NUM 35
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 5
  #define RGBLIGHT_LIMIT_VAL 120
#endif
