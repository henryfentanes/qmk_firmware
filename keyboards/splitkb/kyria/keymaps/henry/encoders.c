#include QMK_KEYBOARD_H
#include "layers.h"

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
            // Volume control.
            case QWERTY:
                if (clockwise) {
                    tap_code(KC_VOLD);
                } else {
                    tap_code(KC_VOLU);
                }
                break;
            case NAV_AND_NUMBERS:
                if (clockwise) {
                    tap_code16(A(S(KC_VOLD)));
                } else {
                    tap_code16(A(S(KC_VOLU)));
                }
                break;
        }
    }
    else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
                case QWERTY:
                // Move the mouse scroll up and down
//                    if (clockwise) {
//                        tap_code16(KC_WH_U);
//                    } else {
//                        tap_code16(KC_WH_D);
//                    }
//                    break;
//                    if (clockwise) {
//                        tap_code16(KC_PGDN);
//                    } else {
//                        tap_code16(KC_PGUP);
//                    }
//                    break;
                    if (clockwise) {
                        tap_code16(A(S(KC_VOLU)));
                    } else {
                        tap_code16(A(S(KC_VOLD)));
                    }
                    break;
                case SHIFTED_QWERTY:
                    if (clockwise) {
                        tap_code16(KC_MEDIA_NEXT_TRACK);
                    } else {
                        tap_code16(KC_MEDIA_PREV_TRACK);
                    }
                    break;
            }
    }
}
#endif
