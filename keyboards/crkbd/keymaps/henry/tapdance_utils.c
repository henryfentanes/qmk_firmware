#define TAPPING_TERM 100
//
// Tap Dance keycodes
enum td_keycodes {
    TAB_ALT_OR_ALTSHIFT,
    ENTER_CMD_OR_CMDSHIFT,
    TAPDANCE_LPRN,
    TAPDANCE_RPRN
};

// Define a type containing as many tapdance states as you need
typedef enum {
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_TAP,
    TRIPLE_TAP
} td_state_t;

// Create a global instance of the tapdance state type
static td_state_t td_state;

// Declare your tapdance functions:

// Function to determine the current tapdance state
uint8_t cur_dance(qk_tap_dance_state_t *state);

// Determine the tapdance state to return
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    }

    if (state->count == 2){
        return DOUBLE_TAP;
    }
    if (state->count == 3) return TRIPLE_TAP;
    else return 4; // Any number higher than the maximum state value you return above
}

// Define all tap_dances
// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions

#include "tapdance_enter_cmd_cmdshift.c"
#include "tapdance_tab_alt_altshift.c"
#include "tapdance_parenthesis.c"

qk_tap_dance_action_t tap_dance_actions[] = {
    [TAB_ALT_OR_ALTSHIFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tab_alt_altshift_finished, tab_alt_altshift_reset),
    [ENTER_CMD_OR_CMDSHIFT] = ACTION_TAP_DANCE_FN_ADVANCED(enter_cmd_cmdshift_tap, NULL, enter_cmd_cmdshift_reset),
    [TAPDANCE_LPRN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tapdance_lprn_tap, tapdance_lprn_reset),
    [TAPDANCE_RPRN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tapdance_rprn_tap, tapdance_rprn_reset)
};
