/* Shamelessly copied @sigprof code */
#include "shadowprogr.h"

void process_my_lt(uint16_t keycode, keyrecord_t *record, uint16_t lt_kc, uint8_t layer, uint16_t tap_kc, my_lt_data_t *data) {
    if (keycode == lt_kc) {
        // The event is for the layer tap key.

        if (record->event.pressed) {
            // The layer tap key was pressed.

            // Store the timestamp to measure the hold duration.
            data->timer = timer_read();

            // Reset the interrupted flag to its initial state.
            data->interrupted = false;

            // Snapshot the modifier state at the press time (similar to what
            // the tap dance implementation does).  The LT() implementation
            // delays the key release events for modifiers instead, which
            // provides a nicer looking event stream to the host (no extra
            // release and press events for modifiers), but implementing that
            // is much more complicated.
            data->mods = get_oneshot_mods();
            data->mods |= get_mods();
            data->mods |= get_weak_mods();

            // Do the layer switch immediately (even if the action is later
            // resolved to be a tap, this would be harmless).
            layer_on(layer);
        } else {
            // The layer tap key was released.

            // Check for interruptions (if another key was pressed while the
            // layer tap key was down, this was not a tap).
            if (!data->interrupted) {
                // Check for timeout (a long press of the layer tap key should
                // not be handled as a tap).
                if (timer_elapsed(data->timer) < TAPPING_TERM) {
                    // This was really a tap, so we need to do the tap action
                    // with the saved modifiers active.
                    uint8_t saved_weak_mods = get_weak_mods();
                    add_weak_mods(data->mods);
                    tap_code16(tap_kc);
                    set_weak_mods(saved_weak_mods);
                }
            }

            // Undo the momentary layer switch which was done on press.
            layer_off(layer);
        }
    } else {
        // The event is for some other key.

        if (record->event.pressed) {
            // Another key was pressed; set the interrupted flag, so that the
            // subsequent release of the layer tap key will not be handled as a
            // tap.
            data->interrupted = true;
        }
    }
}
