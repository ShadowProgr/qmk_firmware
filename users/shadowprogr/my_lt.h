#pragma once
#include "shadowprogr.h"

typedef struct {
    uint16_t timer;
    uint8_t mods;
    bool interrupted;
} my_lt_data_t;

void process_my_lt(uint16_t keycode, keyrecord_t *record, uint16_t lt_kc, uint8_t layer, uint16_t tap_kc, my_lt_data_t *data);
