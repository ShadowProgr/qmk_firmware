#include "shadowprogr.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef SSD1306OLED
  if (record->event.pressed) {
    set_keylog(keycode, record);
    // set_timelog();
  }
#endif

  switch (keycode) {
    case KC_P00:
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_KP_0) SS_DELAY(5) SS_TAP(X_KP_0));
      }
      break;

    // Layers
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
