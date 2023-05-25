void tapdance_lprn_tap(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case SINGLE_TAP:
            register_code16(KC_LPRN);
            break;
        case SINGLE_HOLD:
            break;
        case DOUBLE_TAP:
            register_code16(KC_LBRC);
            break;
        case DOUBLE_HOLD:
             break;
        case TRIPLE_TAP:
            register_code16(KC_LCBR);
            break;
        case TRIPLE_HOLD:
             break;
    }
}

void tapdance_lprn_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:
            unregister_code16(KC_LPRN);
            break;
        case SINGLE_HOLD:
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_LBRC);
            break;
        case DOUBLE_HOLD:
             break;
        case TRIPLE_TAP:
            unregister_code16(KC_LCBR);
            break;
        case TRIPLE_HOLD:
             break;
    }
}

void tapdance_rprn_tap(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case SINGLE_TAP:
            register_code16(KC_RPRN);
            break;
        case SINGLE_HOLD:
            break;
        case DOUBLE_TAP:
            register_code16(KC_RBRC);
            break;
        case DOUBLE_HOLD:
             break;
        case TRIPLE_TAP:
            register_code16(KC_RCBR);
            break;
        case TRIPLE_HOLD:
             break;
    }
}

void tapdance_rprn_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:
            unregister_code16(KC_RPRN);
            break;
        case SINGLE_HOLD:
            break;
        case DOUBLE_TAP:
            unregister_code16(KC_RBRC);
            break;
        case DOUBLE_HOLD:
             break;
        case TRIPLE_TAP:
            unregister_code16(KC_RCBR);
            break;
        case TRIPLE_HOLD:
             break;
    }
}
