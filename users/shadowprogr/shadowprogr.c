#include "shadowprogr.h"

layer_state_t layer_state_set_user (layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void keyboard_post_init_user() {
  layer_state_set_user(layer_state);
}
