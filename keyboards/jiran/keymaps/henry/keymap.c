#include QMK_KEYBOARD_H


#include "tapdance_utils.c"
#include "layers.h"

enum custom_keycodes {
    EMOJIS = SAFE_RANGE,
    CMDSHFTA,
    ZOOM_MUTE,
    PYCHARM_DEBUGGER_TOOL,
    PYCHARM_RUN_TEST,
    PYCHARM_DEBUG_TEST,
    PYCHARM_BACK_TO_EDITOR,
    PYCHARM_BACK_TO_CONSOLE,
    PYCHARM_BACK_TO_TERMINAL,
    PYC_BRANCH,
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

        case CMDSHFTA:
            if (record->event.pressed) {
                SEND_STRING(SS_LCMD(SS_LSFT(SS_TAP(X_A))));
            }
            break;

        case ZOOM_MUTE:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LALT(SS_LCMD(SS_LSFT(SS_TAP(X_A))))));
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
                SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_TAB) SS_DOWN(X_LSFT) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_UP(X_LSFT) SS_UP(X_LCTL));
            }
            break;

        case PYC_BRANCH:
            if (record->event.pressed){
                //  addKeycodeToQueue(LCTL(S(LGUI(KC_K))));
                SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) SS_DOWN(X_LGUI) SS_TAP(X_K) SS_UP(X_LGUI) SS_UP(X_LSFT) SS_UP(X_LCTL));
            }
            break;

        case PRINT_SCREEN:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LCMD(SS_LSFT(SS_TAP(X_4)))));
            }
            break;

        case PRINT_SCREEN_COPY:
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
 * RUN make kyria:henry
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT(
      LT(NAV_AND_NUMBERS,KC_GRV),    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                                                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_MINS,
      MT(MOD_LCTL,KC_TAB),      KC_A,  KC_S,   KC_D,   KC_F,   KC_G,                                                                                KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
      CMDSHFTA,      KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,  LT(SHIFTED_QWERTY,KC_TAB),  PYCHARM_DEBUGGER_TOOL,                      EMOJIS, LALT(KC_BSPC),  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_PIPE,
      ZOOM_MUTE, TD(TAB_ALT_OR_ALTSHIFT), TD(ENTER_CMD_OR_CMDSHIFT), KC_LSFT, LT(PYCHARM_MACROS,KC_DEL),                            MT(MOD_LALT,KC_ENT), MT(MOD_LSFT,KC_SPC), LT(NAV_AND_NUMBERS,KC_SPC),  KC_BSPC, PRINT_SCREEN
    ),
	[SHIFTED_QWERTY] = LAYOUT(
	  PRINT_SCREEN_COPY,    KC_EXLM,   KC_AT,   KC_HASH,  KC_DOLLAR,   KC_PERCENT,                                                                                 KC_CIRCUMFLEX,   KC_AMPERSAND,   KC_ASTERISK,   KC_LEFT_PAREN,   KC_RIGHT_PAREN,   KC_UNDERSCORE,
	  KC_TRNS,   KC_HASH,   KC_MPRV,    KC_MPLY,    KC_MNXT,   KC_GRV,                                                                                  KC_HOME,   KC_PGDN,   KC_PGUP,   KC_END,   KC_LCBR,   KC_RCBR,
	  PRINT_SCREEN,   KC_PERC,   KC_CIRC,   PYCHARM_BACK_TO_CONSOLE,   KC_RBRC,   KC_TILD,  LT(SHIFTED_QWERTY,KC_TAB),   PYCHARM_DEBUG_TEST,         EMOJIS, KC_TRNS,   KC_AMPR,   KC_NO,   KC_COMM,   KC_DOT,   KC_SLSH,   KC_BSLS,
      KC_TRNS, TD(TAB_ALT_OR_ALTSHIFT), TD(ENTER_CMD_OR_CMDSHIFT), KC_LSFT,LT(PYCHARM_MACROS,KC_DEL),                                 MT(MOD_LALT,KC_ENT), KC_TRNS, LT(NAV_AND_NUMBERS,KC_SPC),  KC_TRNS, PRINT_SCREEN
	  ),
	[PYCHARM_MACROS] = LAYOUT(
	  KC_F7,    KC_EXLM,   KC_AT,   PYCHARM_BACK_TO_EDITOR,KC_RCBR,PYCHARM_BACK_TO_TERMINAL,                                                                       KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_LPRN,   KC_RPRN,   KC_PPLS,
	  KC_TRNS,   KC_HASH,   KC_MPRV,    KC_MPLY,    KC_MNXT,   KC_GRV,                                                                                              KC_HOME,   KC_PGDN,   KC_PGUP,   KC_END,   KC_LCBR,   KC_RCBR,
	  KC_TRNS,   KC_PERC,   KC_CIRC,   PYCHARM_BACK_TO_CONSOLE,   KC_RBRC,   PYC_BRANCH,  LT(SHIFTED_QWERTY,KC_TAB),   PYCHARM_DEBUG_TEST,                EMOJIS, KC_TRNS,   KC_AMPR,   KC_NO,   KC_COMM,   KC_DOT,   KC_SLSH,   KC_BSLS,
      KC_TRNS, TD(TAB_ALT_OR_ALTSHIFT), TD(ENTER_CMD_OR_CMDSHIFT), KC_LSFT,LT(PYCHARM_MACROS,KC_DEL),                                        MT(MOD_LALT,KC_ENT), KC_TRNS, LT(NAV_AND_NUMBERS,KC_SPC),  KC_TRNS, PRINT_SCREEN
	  ),
	[NAV_AND_NUMBERS] = LAYOUT(
	  KC_ESC,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                                                                                       KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_EQL,
	  KC_TRNS, KC_TRNS, KC_DLR,   TD(TAPDANCE_LPRN),   TD(TAPDANCE_RPRN),    KC_VOLU,                                                       KC_LEFT,    KC_DOWN,    KC_UP,  KC_RGHT,    KC_LBRC,    KC_RBRC,
	  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, LT(SHIFTED_QWERTY,KC_TAB), KC_BTN2,                                     EMOJIS, KC_TRNS, LALT(KC_LEFT), LALT(KC_DOWN), LALT(KC_UP), LALT(KC_RGHT), KC_NO, KC_BSLS,
      KC_TRNS, TD(TAB_ALT_OR_ALTSHIFT), TD(ENTER_CMD_OR_CMDSHIFT), KC_LSFT,LT(PYCHARM_MACROS,KC_DEL),                     MT(MOD_LALT,KC_ENT), KC_TRNS, LT(NAV_AND_NUMBERS,KC_SPC),  KC_TRNS, PRINT_SCREEN
      )
};
