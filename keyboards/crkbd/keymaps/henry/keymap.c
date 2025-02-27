#include QMK_KEYBOARD_H


#include "tapdance_utils.c"
#include "layers.h"

enum custom_keycodes {
    EMOJIS = SAFE_RANGE,
    ZOOM_MUTE_UNMUTE,
    PYCHARM_DEBUGGER_TOOL,
    PYCHARM_RUN_TEST,
    PYCHARM_DEBUG_TEST,
    PYCHARM_BACK_TO_EDITOR,
    PYCHARM_BACK_TO_CONSOLE,
    PYCHARM_BACK_TO_TERMINAL,
    PRINT_SCREEN,
    PRINT_SCREEN_COPY,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case EMOJIS:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LCMD(SS_TAP(X_SPC))));
            }
            break;

        case ZOOM_MUTE_UNMUTE:
            if (record->event.pressed) {
                SEND_STRING(SS_LCMD(SS_LSFT(SS_TAP(X_A))));
            }
            break;

        case PYCHARM_DEBUGGER_TOOL:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT(SS_TAP(X_F8)));
            }
            break;

        case PYCHARM_RUN_TEST:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_R))));
            }
            break;

        case PYCHARM_DEBUG_TEST:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_D))));
            }
            break;

        case PYCHARM_BACK_TO_EDITOR:
            if (record->event.pressed){
                // Hold ctrl, tap Tab, hold shift down, tap tab again --> From Console or Terminal back to Editor
                SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_TAB) SS_DOWN(X_LSFT) SS_TAP(X_TAB) SS_UP(X_LSFT) SS_UP(X_LCTL));
            }
            break;

        case PYCHARM_BACK_TO_CONSOLE:
            if (record->event.pressed){
                // Hold ctrl, tap Tab, tap C --> Python Console
                SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_TAB) SS_TAP(X_C) SS_UP(X_LCTL));
            }
            break;

        case PYCHARM_BACK_TO_TERMINAL:
            if (record->event.pressed){
                // Hold ctrl, tap Tab, tap T --> Terminal
                SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_TAB) SS_TAP(X_T) SS_UP(X_LCTL));
            }
            break;

        case PRINT_SCREEN_COPY:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LCMD(SS_LSFT(SS_TAP(X_4)))));
            }
            break;

        case PRINT_SCREEN:
            if (record->event.pressed) {
               SEND_STRING(SS_LCMD(SS_LSFT(SS_TAP(X_4))));
            }
            break;
    }
    return true;
};



/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 * RUN make crkbd:henry
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWERTY] = LAYOUT( \
  //,-----------------------------------------------------.                                                                                         ,-----------------------------------------------------.
      LT(1, KC_ESC),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                                                      KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  LT(1,KC_MINS),\
  //|--------+--------+--------+--------+--------+--------|                                                                                         |--------+--------+--------+--------+--------+--------|
      MT(MOD_LCTL,KC_TAB),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                                                               KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                                                                                         |--------+--------+--------+--------+--------+--------|
      ZOOM_MUTE_UNMUTE,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                                                                  KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_PIPE,\
  //|--------+--------+--------+--------+--------+--------+--------|                                                                            |--------+--------+--------+--------+--------+--------+--------|
       TD(TAB_ALT_OR_ALTSHIFT),TD(CMD_OR_CMDSHIFT_OR_CMDALT), MT(MOD_LSFT, KC_ENT),                                                               MT(MOD_LSFT,KC_ENT), LT(2,KC_SPC), MT(MOD_LALT,KC_BSPC)\
                                                    //`--------------------------'                                                            `--------------------------'
  ),

  [MYMACROS] = LAYOUT( \
  //,-----------------------------------------------------.                                                                                          ,-----------------------------------------------------.
      EMOJIS,    KC_EXLM,   KC_AT,   PYCHARM_BACK_TO_EDITOR,  KC_RCBR,   PYCHARM_BACK_TO_TERMINAL,                                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_LPRN, KC_RPRN, KC_PPLS,\
  //|--------+--------+--------+--------+--------+--------|                                                                                          |--------+--------+--------+--------+--------+--------|
      PRINT_SCREEN,   KC_HASH,   KC_MPRV,    PYCHARM_DEBUGGER_TOOL,    KC_MNXT,   KC_VOLU,                                                             KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_LCBR, KC_RCBR,\
  //|--------+--------+--------+--------+--------+--------|                                                                                          |--------+--------+--------+--------+--------+--------|
      PRINT_SCREEN_COPY,   KC_PERC,   KC_CIRC,   PYCHARM_BACK_TO_CONSOLE,   KC_MUTE,   KC_VOLD,                                                        KC_AMPR,  KC_NO,  KC_COMM,  KC_DOT,  KC_SLSH,  KC_BSLS,\
  //|--------+--------+--------+--------+--------+--------+--------|                                                                           |--------+--------+--------+--------+--------+--------+--------|
                                        KC_TRNS,KC_TRNS, KC_TRNS,                                                                               KC_TRNS, KC_TRNS, KC_TRNS\
                                         //`--------------------------'                                                                     `--------------------------'
    ),

  [NAV_AND_NUMBERS] = LAYOUT( \
  //,-----------------------------------------------------.                                                                                           ,-----------------------------------------------------.
      KC_GRV,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                                                                                                  KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_EQL,\
  //|--------+--------+--------+--------+--------+--------|                                                                                           |--------+--------+--------+--------+--------+--------|
      KC_TRNS,KC_TRNS, KC_DLR,TD(TAPDANCE_LPRN),TD(TAPDANCE_RPRN),KC_VOLU,                                                                             KC_LEFT,  KC_DOWN,  KC_UP,  KC_RGHT,  KC_LBRC,  KC_RBRC,\
  //|--------+--------+--------+--------+--------+--------|                                                                                           |--------+--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD,                                                                                            KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO, KC_BSLS,\
  //|--------+--------+--------+--------+--------+--------+--------|                                                                                |--------+--------+--------+--------+--------+--------+--------|
                                       KC_TRNS,KC_TRNS, KC_TRNS,                                                                                     KC_TRNS, KC_TRNS, KC_TRNS\
                                       //`--------------------------'                                                                             `--------------------------'
  )
};
