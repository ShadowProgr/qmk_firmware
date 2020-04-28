#include "shadowprogr.h"

/* Allows usage of _keymap funtions in keymaps since _user funtions are used here. */
__attribute__((weak)) void keyboard_pre_init_keymap(void) {}

__attribute__((weak)) void matrix_init_keymap(void) {}

__attribute__((weak)) void keyboard_post_init_keymap(void) {}

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) { return state; }

/* Global, userspace functions that apply to all my keymaps */
void keyboard_pre_init_user(void) { keyboard_pre_init_keymap(); }

void matrix_init_user(void) { matrix_init_keymap(); }

void keyboard_post_init_user() { keyboard_post_init_keymap(); }

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);

#if defined(RGBLIGHT_ENABLE)
    state = layer_state_set_rgb_light(state);
#endif

    return layer_state_set_keymap(state);
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode) {
    switch (keycode) {
        case CTL_QUT:
            return true;
        case CTL_SLS:
            return true;
        default:
            return false;
    }
}
