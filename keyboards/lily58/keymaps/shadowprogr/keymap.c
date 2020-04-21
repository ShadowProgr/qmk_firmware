#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

enum layers {
    _QWERTY,
    _DVORAK,
    _COLEMAK,
    _NUMPAD,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK,
  COLEMAK,
  KC_P00
};

// Layer keys
#define NUMPAD TG(_NUMPAD)
#define LOWER LT(_LOWER, KC_ENT)
#define RAISE LT(_RAISE, KC_ENT)

// Mod-tap keys
#define CTL_ESC MT(MOD_LCTL, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* QWERTY
   * ,-----------------------------------------------.                    ,-----------------------------------------------.
   * | `     |   1   |   2   |   3   |   4   |   5   |                    |   6   |   7   |   8   |   9   |   0   |BSpace |
   * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
   * | Tab   |   Q   |   W   |   E   |   R   |   T   |                    |   Y   |   U   |   I   |   O   |   P   |   \   |
   * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
   * |CtrlEsc|   A   |   S   |   D   |   F   |   G   |-------.    ,-------|   H   |   J   |   K   |   L   |   ;   |   '   |
   * |-------+-------+-------+-------+-------+-------|   -   |    |   =   |-------+-------+-------+-------+-------+-------|
   * | Shift |   Z   |   X   |   C   |   V   |   B   |-------|    |-------|   N   |   M   |   ,   |   .   |   /   | Shift |
   * `-----------------------------------------------/       /    \       \-----------------------------------------------'
   *                     | LAlt  | LGUI  | Space |  / Lower /      \ Raise \  |BSpace | RGUI  |Numpad |
   *                     |       |       |       | /       /        \       \ |       |       |       |
   *                     `-----------------------''-------'          '-------'`-----------------------'
   */
  [_QWERTY] = LAYOUT( \
    KC_GRV , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
    KC_TAB , KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MINS,         KC_EQL,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
                               KC_LALT, KC_LGUI, KC_SPC,  LOWER,           RAISE,   KC_BSPC, KC_RGUI, NUMPAD                              \
  ),

  /* DVORAK
   * ,-----------------------------------------------.                    ,-----------------------------------------------.
   * | `     |   1   |   2   |   3   |   4   |   5   |                    |   6   |   7   |   8   |   9   |   0   |BSpace |
   * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
   * | Tab   |   '   |   ,   |   .   |   P   |   Y   |                    |   F   |   G   |   C   |   R   |   L   |   \   |
   * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
   * |CtrlEsc|   A   |   O   |   E   |   U   |   I   |-------.    ,-------|   D   |   H   |   T   |   N   |   S   |   /   |
   * |-------+-------+-------+-------+-------+-------|   -   |    |   =   |-------+-------+-------+-------+-------+-------|
   * | Shift |   ;   |   Q   |   J   |   K   |   X   |-------|    |-------|   B   |   M   |   W   |   V   |   Z   | Shift |
   * `-----------------------------------------------/       /    \       \-----------------------------------------------'
   *                     | LAlt  | LGUI  | Space |  / Lower /      \ Raise \  |BSpace | RGUI  |Numpad |
   *                     |       |       |       | /       /        \       \ |       |       |       |
   *                     `-----------------------''-------'          '-------'`-----------------------'
   */
  [_DVORAK] = LAYOUT( \
    KC_GRV , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
    KC_TAB , KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                              KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSLS, \
    CTL_ESC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                              KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_MINS,         KC_EQL,  KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT, \
                               KC_LALT, KC_LGUI, KC_SPC,  LOWER,           RAISE,   KC_BSPC, KC_RGUI, NUMPAD                              \
  ),

  /* COLEMAK
   * ,-----------------------------------------------.                    ,-----------------------------------------------.
   * | `     |   1   |   2   |   3   |   4   |   5   |                    |   6   |   7   |   8   |   9   |   0   |BSpace |
   * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
   * | Tab   |   Q   |   W   |   F   |   P   |   G   |                    |   J   |   L   |   U   |   Y   |   ;   |   \   |
   * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
   * |CtrlEsc|   A   |   R   |   S   |   T   |   D   |-------.    ,-------|   H   |   N   |   E   |   I   |   O   |   '   |
   * |-------+-------+-------+-------+-------+-------|   -   |    |   =   |-------+-------+-------+-------+-------+-------|
   * | Shift |   Z   |   X   |   C   |   V   |   B   |-------|    |-------|   K   |   M   |   ,   |   .   |   /   | Shift |
   * `-----------------------------------------------/       /    \       \-----------------------------------------------'
   *                     | LAlt  | LGUI  | Space |  / Lower /      \ Raise \  |BSpace | RGUI  |Numpad |
   *                     |       |       |       | /       /        \       \ |       |       |       |
   *                     `-----------------------''-------'          '-------'`-----------------------'
   */
  [_COLEMAK] = LAYOUT( \
    KC_GRV , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
    KC_TAB , KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                              KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS, \
    CTL_ESC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                              KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_MINS,         KC_EQL,  KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
                               KC_LALT, KC_LGUI, KC_SPC,  LOWER,           RAISE,   KC_BSPC, KC_RGUI, NUMPAD                              \
  ),

  /* Numpad
  * ,-----------------------------------------------.                    ,-----------------------------------------------.
  * |XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|                    |NumLock|   7   |   8   |   9   |   /   |BSpace |
  * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  * |XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|                    |XXXXXXX|   4   |   5   |   6   |   *   |XXXXXXX|
  * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  * |XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|-------.    ,-------|XXXXXXX|   1   |   2   |   3   |   -   |XXXXXXX|
  * |-------+-------+-------+-------+-------+-------|XXXXXXX|    |XXXXXXX|-------+-------+-------+-------+-------+-------|
  * |XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|-------|    |-------|XXXXXXX|   0   |   00  |   .   |   +   | Enter |
  * `-----------------------------------------------/XXXXXXX/    \XXXXXXX\-----------------------------------------------'
  *                     |XXXXXXX|XXXXXXX|XXXXXXX|  /XXXXXXX/      \XXXXXXX\  |XXXXXXX|XXXXXXX|Numpad |
  *                     |XXXXXXX|XXXXXXX|XXXXXXX| /XXXXXXX/        \XXXXXXX\ |XXXXXXX|XXXXXXX|       |
  *                     `-----------------------''-------'          '-------'`-----------------------'
  */

  [_NUMPAD] = LAYOUT( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           KC_NLCK, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, KC_BSPC, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PAST, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, KC_P0,   KC_P00,  KC_PDOT, KC_PPLS, KC_PENT, \
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, NUMPAD                              \
  ),

  /* Lower
  * ,-----------------------------------------------.                    ,-----------------------------------------------.
  * | F11   | F1    | F2    | F3    | F4    | F5    |                    | F6    | F7    | F8    | F9    | F10   | F12   |
  * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  * |       |   !   |   @   |   #   |   $   |   %   |                    |   ^   |   &   |   *   |   (   |   )   |       |
  * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  * |       |       |       |       |       |       |-------.    ,-------|       |       |       |   {   |   }   |       |
  * |-------+-------+-------+-------+-------+-------|       |    |       |-------+-------+-------+-------+-------+-------|
  * | Caps  |       |       |       |       |       |-------|    |-------|       |       |       |   [   |   ]   | Caps  |
  * `-----------------------------------------------/       /    \       \-----------------------------------------------'
  *                     |       |       |       |  / Lower /      \ Raise \  |       |       |       |
  *                     |       |       |       | /       /        \       \ |       |       |       |
  *                     `-----------------------''-------'          '-------'`-----------------------'
  */
  [_LOWER] = LAYOUT( \
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                             KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                           KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
    _______, _______, _______, _______, _______, _______,                           _______, _______, _______, KC_LCBR, KC_RCBR, _______, \
    KC_CAPS, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_CAPS, \
                               _______, _______, _______, LOWER,           RAISE,   _______, _______, _______                             \
  ),

  /* Raise
  * ,-----------------------------------------------.                    ,-----------------------------------------------.
  * | F11   | F1    | F2    | F3    | F4    | F5    |                    | F6    | F7    | F8    | F9    | F10   | F12   |
  * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  * |       | VolUp | Ins   | Home  |PageUp |       |                    |       |       |       |       |       |       |
  * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
  * |       |VolDwn | Del   | End   |PageDwn|       |-------.    ,-------| Left  | Down  | Up    | Right |       |       |
  * |-------+-------+-------+-------+-------+-------|       |    |       |-------+-------+-------+-------+-------+-------|
  * | Caps  |       |       | Next  | Prev  | Play  |-------|    |-------|       |       |       |       |       | Caps  |
  * `-----------------------------------------------/       /    \       \-----------------------------------------------'
  *                     |       |       |       |  / Lower /      \ Raise \  |       |       |       |
  *                     |       |       |       | /       /        \       \ |       |       |       |
  *                     `-----------------------''-------'          '-------'`-----------------------'
  */
  [_RAISE] = LAYOUT( \
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                             KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
    _______, KC_VOLU, KC_INS,  KC_HOME, KC_PGUP, _______,                           _______, _______, _______, _______, _______, _______, \
    _______, KC_VOLD, KC_DEL,  KC_END,  KC_PGDN, _______,                           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
    KC_CAPS, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY, _______,         _______, _______, _______, _______, _______, _______, KC_CAPS, \
                               _______, _______, _______, LOWER,           RAISE,   _______, _______, _______                             \
  ),

/* Adjust
 * ,-----------------------------------------------.                    ,-----------------------------------------------.
 * | Reset |XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|                    |XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |EEP Rst|XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|QWERTY |                    |XXXXXXX|RGBTogg|ChgMode|XXXXXXX|XXXXXXX|XXXXXXX|
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|DVORAK |-------.    ,-------|XXXXXXX|Hue inc|Sat inc|Val inc|XXXXXXX|XXXXXXX|
 * |-------+-------+-------+-------+-------+-------|XXXXXXX|    |XXXXXXX|-------+-------+-------+-------+-------+-------|
 * |XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|XXXXXXX|COLEMAK|-------|    |-------|XXXXXXX|Hue dec|Sat dec|Val dec|XXXXXXX|XXXXXXX|
 * `-----------------------------------------------/       /    \       \-----------------------------------------------'
 *                     |XXXXXXX|XXXXXXX|XXXXXXX|  / Lower /      \ Raise \  |XXXXXXX|XXXXXXX|XXXXXXX|
 *                     |XXXXXXX|XXXXXXX|XXXXXXX| /       /        \       \ |XXXXXXX|XXXXXXX|XXXXXXX|
 *                     `-----------------------''-------'          '-------'`-----------------------'
 */
  [_ADJUST] = LAYOUT( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                               XXXXXXX, XXXXXXX, XXXXXXX, LOWER,           RAISE,   XXXXXXX, XXXXXXX, XXXXXXX                             \
  )

  /* Template
   * ,-----------------------------------------------.                    ,-----------------------------------------------.
   * |       |       |       |       |       |       |                    |       |       |       |       |       |       |
   * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |                    |       |       |       |       |       |       |
   * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |-------.    ,-------|       |       |       |       |       |       |
   * |-------+-------+-------+-------+-------+-------|       |    |       |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |-------|    |-------|       |       |       |       |       |       |
   * `-----------------------------------------------/       /    \       \-----------------------------------------------'
   *                     |       |       |       |  /       /      \       \  |       |       |       |
   *                     |       |       |       | /       /        \       \ |       |       |       |
   *                     `-----------------------''-------'          '-------'`-----------------------'

  [_TEMPLATE] = LAYOUT( \
    _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, \
                               _______, _______, _______, _______,         _______, _______, _______, _______                             \
  )
   */
};

int RGB_current_mode;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case KC_P00:
      if (record->event.pressed) {
        SEND_STRING(SSTAP(X_KP_0) SS_DELAY(5) SSTAP(X_KP_0));
      }

    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
  }
  return true;
}
