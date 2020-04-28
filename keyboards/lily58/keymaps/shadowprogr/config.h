#pragma once

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define SSD1306OLED
#define USE_SERIAL_PD2

#ifdef RGBLIGHT_ENABLE
#    undef RGBLED_NUM
#    define RGBLED_NUM 35
#    define RGBLIGHT_ANIMATIONS
#endif

#ifdef RGB_MATRIX_ENABLE
#    define DRIVER_LED_TOTAL 70
// #define RGB_MATRIX_KEYPRESSES
// #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#endif

/* Keyboard info */
#undef PRODUCT
#define PRODUCT ShadowProgr Lily58 Keyboard
