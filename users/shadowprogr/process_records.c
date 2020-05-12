#include "shadowprogr.h"

/* Allows usage of _keymap funtions in keymaps since _user funtions are used here. */
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

/* Global, userspace functions that apply to all my keymaps */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static my_lt_data_t lwr_data;
    static my_lt_data_t rse_data;

    process_my_lt(keycode, record, LT_LWR, _LOWER, KC_ENT, &lwr_data);
    process_my_lt(keycode, record, LT_RSE, _RAISE, KC_DEL, &rse_data);

    switch (keycode) {
        /* Macros */
        case KC_P00:  // Send 2 KC_P0 in a row
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_KP_0) SS_DELAY(5) SS_TAP(X_KP_0));
            }
            break;

        /* Layers */
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            break;
        case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            break;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            break;
    }
    return process_record_keymap(keycode, record);
}
