#pragma once
#include "shadowprogr.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

// clang-format off
/* Base layout blocks */
/* QWERTY */
#define _________________QWERTY_L1_________________ KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________ KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________ KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________ KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________ KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________ KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

/* DVORAK */
// TODO: Add programmer dvorak
#define _________________DVORAK_L1_________________ KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y
#define _________________DVORAK_L2_________________ KC_A,    KC_O,    KC_E,    KC_U,    KC_I
#define _________________DVORAK_L3_________________ KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X

#define _________________DVORAK_R1_________________ KC_F,    KC_G,    KC_C,    KC_R,    KC_L
#define _________________DVORAK_R2_________________ KC_D,    KC_H,    KC_T,    KC_N,    KC_S
#define _________________DVORAK_R3_________________ KC_B,    KC_M,    KC_W,    KC_V,    KC_Z

/* COLEMAK and COLEMAK mod DH */
#define _________________COLEMAK_L1________________ KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
#define _________________COLEMAK_L2________________ KC_A,    KC_R,    KC_S,    KC_T,    KC_D
#define _________________COLEMAK_L3________________ KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________COLEMAK_R1________________ KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________COLEMAK_R2________________ KC_H,    KC_N,    KC_E,    KC_I,    KC_O
#define _________________COLEMAK_R3________________ KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define ________________COLEMAK_DH_L1______________ KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define ________________COLEMAK_DH_L2______________ KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define ________________COLEMAK_DH_L3______________ KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define ________________COLEMAK_DH_R1______________ KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define ________________COLEMAK_DH_R2______________ KC_M,    KC_N,    KC_E,    KC_I,    KC_O
#define ________________COLEMAK_DH_R3______________ KC_K,    KC_H,    KC_COMM,  KC_DOT, KC_SLASH

/* Number and F row blocks */
#define _________________FUNC_LEFT_________________ KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________ KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10
#define ________________NUMBER_LEFT________________ KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________ KC_6,    KC_7,    KC_8,    KC_9,    KC_0

/* Layer blocks */
/* Numpad blocks */
#define ____________NUMPAD_R0_____________ KC_P7,   KC_P8,   KC_P9,   KC_PSLS
#define ____________NUMPAD_R1_____________ KC_P4,   KC_P5,   KC_P6,   KC_PAST
#define ____________NUMPAD_R2_____________ KC_P1,   KC_P2,   KC_P3,   KC_PMNS
#define ____________NUMPAD_R3_____________ KC_P0,   KC_P00,  KC_PDOT, KC_PPLS

/* Lower blocks */
#define _________________LOWER_L1__________________ KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________LOWER_L2__________________ ___________________________________________
#define _________________LOWER_L3__________________ ___________________________________________

#define _________________LOWER_R1__________________ KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN
#define _________________LOWER_R2__________________ _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR
#define _________________LOWER_R3__________________ _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC

/* Raise blocks */
#define _________________RAISE_L1__________________ ________________NUMBER_LEFT________________
#define _________________RAISE_L2__________________ _______, KC_INS,  KC_HOME, KC_PGUP, _______
#define _________________RAISE_L3__________________ _______, KC_DEL,  KC_END,  KC_PGDN, _______

#define _________________RAISE_R1__________________ ________________NUMBER_RIGHT_______________
#define _________________RAISE_R2__________________ KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______
#define _________________RAISE_R3__________________ ___________________________________________

/* Adjust blocks */
#define _________________ADJUST_L1_________________ QWERTY,  DVORAK,  COLEMAK, XXXXXXX, XXXXXXX
#define _________________ADJUST_L2_________________ XXXXXXX, KC_VOLU, KC_MNXT, KC_MPLY, XXXXXXX
#define _________________ADJUST_L3_________________ XXXXXXX, KC_VOLD, KC_MPRV, KC_MUTE, XXXXXXX

#define _________________ADJUST_R1_________________ RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI
#define _________________ADJUST_R2_________________ RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD
#define _________________ADJUST_R3_________________ _________________DISABLED__________________

/* QoL blocks */
#define _________________________                            _______, _______, _______
#define __________________________________                   _______, _______, _______, _______
#define ___________________________________________          _______, _______, _______, _______, _______
#define ____________________________________________________ _______, _______, _______, _______, _______, _______

#define _______DISABLED__________                            XXXXXXX, XXXXXXX, XXXXXXX
#define ____________DISABLED______________                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define _________________DISABLED__________________          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define _____________________DISABLED_______________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
// clang-format on
