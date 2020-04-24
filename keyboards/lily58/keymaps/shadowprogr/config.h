#pragma once



/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define SSD1306OLED
#define USE_SERIAL_PD2

#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM
    #define RGBLED_NUM 35
    #define RGBLIGHT_ANIMATIONS
#endif

#ifdef RGB_MATRIX_ENABLE
    #define DRIVER_LED_TOTAL 70
    // #define RGB_MATRIX_KEYPRESSES
    // #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#endif

/* Keyboard info */
#undef VENDOR_ID
#undef PRODUCT_ID
#undef DEVICE_VER
#undef MANUFACTURER
#undef PRODUCT
#undef DESCRIPTION
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x1337
#define DEVICE_VER      0x0100
#define MANUFACTURER    Ape
#define PRODUCT         ShadowProgr Lily58 Keyboard
#define DESCRIPTION     Ergonomic split keyboard
