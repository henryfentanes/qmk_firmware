#include QMK_KEYBOARD_H
#include "layers.h"

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control.
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
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
                    if (clockwise) {
                        tap_code16(KC_PGDN);
                    } else {
                        tap_code16(KC_PGUP);
                    }
                    break;
                case NAV_AND_NUMBERS:
                    if (clockwise) {
                        tap_code16(A(KC_LEFT));
                    } else {
                        tap_code16(A(KC_RIGHT));
                    }
                    break;
            }
    }
}
#endif
