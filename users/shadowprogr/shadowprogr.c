#include "shadowprogr.h"

LEADER_EXTERNS();

/* Allows usage of _keymap funtions in keymaps since _user funtions are used here. */
__attribute__((weak)) void keyboard_pre_init_keymap(void) {}

__attribute__((weak)) void matrix_init_keymap(void) {}

__attribute__((weak)) void keyboard_post_init_keymap(void) {}

__attribute__((weak)) void matrix_scan_keymap(void) {}

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) { return state; }

/* Global, userspace functions that apply to all my keymaps */
void keyboard_pre_init_user(void) { keyboard_pre_init_keymap(); }

void matrix_init_user(void) { matrix_init_keymap(); }

void keyboard_post_init_user() { keyboard_post_init_keymap(); }

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_T) {
            // Start terminal in Linux (Ctrl+Alt+T)
            register_code(KC_LCTL);
            register_code(KC_LALT);
            tap_code(KC_T);
            unregister_code(KC_LCTL);
            unregister_code(KC_LALT);
        }

        SEQ_ONE_KEY(KC_LEAD) {
            // Toggle numpad layer
            layer_invert(_NUMPAD);
        }
    }
    matrix_scan_keymap();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    return layer_state_set_keymap(state);
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode) {
    switch (keycode) {
        case MT_CT_Q:
            return true;
        case MT_CT_S:
            return true;
        default:
            return false;
    }
}
