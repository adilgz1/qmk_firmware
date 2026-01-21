

#include QMK_KEYBOARD_H
#include "quantum.h"

// OLED animation
#include "lib/layer_status/layer_status.h"


#ifdef OLED_ENABLE
    bool oled_task_user(void) {
        render_layer_status();

        return true;
    }
#endif


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layer_names {
    _BASE,
    _NAV,
    _NUM,
    _TEXT,
    _TYPE1,
    _TYPE2,
};

enum custom_keycodes {
    BASE_SHIFT = SAFE_RANGE,
    COPY_TYPE,
    PASTE_TEXT,
    NUM_NAV,
    OPEN_IN_TERM,
    COPY_CMDOPT,
    PASTE_SFTOPT,
    BASE_CMDSFT,
    DOT_SLSH,
    SPACE_COMMA,
    LEFT_HOME,
    RIGHT_END,
    QUES_SHIFT,
};



// Define Tap Dance actions using SAFE_RANGE
enum tap_dance_codes {
    BRACKETS,
    CLNQUOTE,
    COMMADOT,
    MNSPLS,
    // ESCCTRL,
    // SPACEALT,
    // BKSPSHIFT,
};



// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_ESC,      KC_SPC,      LGUI(KC_Z),  KC_DEL,      TO(_TYPE1),
        COPY_TYPE,   LGUI(KC_SPC), KC_UP,       KC_TAB,      KC_MUTE,
        PASTE_TEXT,  LEFT_HOME,     KC_DOWN,     RIGHT_END,     KC_MPLY,
        NUM_NAV,     LGUI_T(KC_ENTER),   KC_LSFT,     KC_LALT
    ),

    [_NAV] = LAYOUT(
        LGUI(KC_Q),  LGUI(KC_T),  LSG(KC_T),   KC_F5,       TO(_BASE),
        LGUI(KC_S), LGUI(KC_F), LCTL(KC_PGDN), LGUI(KC_K),   KC_MUTE,
        LSG(KC_NO),  LCTL(LSFT(KC_PGUP)),  LCTL(KC_PGUP), LCTL(LSFT(KC_PGDN)),    KC_MPLY,
        KC_TRNS,     LCTL(KC_LEFT), LCTL(KC_RIGHT), OPEN_IN_TERM
    ),

    [_NUM] = LAYOUT(
        KC_BSPC,     KC_1,        KC_2,        KC_3,        TO(_BASE),
        KC_PPLS,     KC_4,        KC_5,        KC_6,        KC_MUTE,
        KC_MINS,     KC_7,        KC_8,        KC_9,        KC_MPLY,
        BASE_SHIFT,  KC_ENT,      KC_0,        KC_DOT
    ),

    [_TEXT] = LAYOUT(
        LGUI(KC_A), KC_SPC,       LGUI(KC_Z), KC_BSPC,       TO(_BASE),
        COPY_CMDOPT,       LGUI(KC_H), KC_UP,       KC_TAB,         KC_MUTE,
        PASTE_SFTOPT,       KC_LEFT,       KC_DOWN,       KC_RIGHT,         KC_MPLY,
        BASE_CMDSFT,       LCTL_T(KC_ENTER),       KC_LSFT,       KC_LALT
    ),

    [_TYPE1] = LAYOUT(
        KC_BSPC,       KC_A,       KC_B,       KC_C,       TO(_BASE),
        SPACE_COMMA,       KC_D,       KC_E,       KC_F,         KC_MUTE,
        LSFT_T(KC_DOT),       KC_G,       KC_H,       KC_I,         KC_MPLY,
        MO(_TYPE2),       KC_J,       KC_K,       KC_L
    ),

    [_TYPE2] = LAYOUT(
        KC_Y,       KC_M,       KC_N,       KC_O,       TO(_BASE),
        KC_Z,       KC_P,       KC_Q,       KC_R,         KC_MUTE,
        QUES_SHIFT,       KC_S,       KC_T,       KC_U,         KC_MPLY,
        KC_TRNS,       KC_V,       KC_W,       KC_X
    )
};



// Combos for missing letters & functions
const uint16_t PROGMEM combo_h[] = {KC_T, KC_A, COMBO_END};   // H = T + A
const uint16_t PROGMEM combo_z[] = {KC_S, KC_D, COMBO_END};   // Z = S + D
const uint16_t PROGMEM combo_qm[] = {KC_COMM, KC_DOT, COMBO_END}; // ? = , + .
const uint16_t PROGMEM combo_ent[] = {KC_SPC, KC_BSPC, COMBO_END}; // Enter = Space + Backspace
const uint16_t PROGMEM combo_esc[] = {KC_SPC, KC_LSFT, COMBO_END}; // Esc = Space + Shift
const uint16_t PROGMEM combo_del[] = {KC_BSPC, KC_LSFT, COMBO_END}; // Delete = Backspace + Shift
const uint16_t PROGMEM combo_REDO[] = {KC_LALT, LCTL(KC_Z), COMBO_END}; // Redo = Alt + Ctrl + Z
const uint16_t PROGMEM combo_ctrl_f2[] = {KC_SPC, KC_TAB,  COMBO_END}; // Ctrl+F2
const uint16_t PROGMEM combo_LYRNV_TG[] = {KC_LSFT,   LCTL(KC_V),  COMBO_END}; // Toggle LYRNAV Layer = Shift + Ctrl + V 
const uint16_t PROGMEM combo_HKEYS_TG[] = { KC_LALT, LCTL(KC_C),  COMBO_END}; // Toggle HKEYS Layer = Alt + Ctrl + C
const uint16_t PROGMEM combo_FN_TG[] = { LCTL(KC_L), LCTL(KC_C),  COMBO_END}; // Toggle FN Layer = Ctrl + L + C
const uint16_t PROGMEM combo_TYPSYS_TG[] = { LCTL(KC_W), LCTL(KC_X),  COMBO_END}; // Toggle TYPING SYSTEM Layer = Ctrl + W + X

combo_t key_combos[] = {
    COMBO(combo_h, KC_H),   
    COMBO(combo_z, KC_Z),
    COMBO(combo_qm, KC_QUES),
    COMBO(combo_ent, KC_ENT),
    COMBO(combo_esc, KC_ESC),
    COMBO(combo_del, KC_DEL),
    COMBO(combo_REDO, LCTL(KC_Y)),
    COMBO(combo_ctrl_f2, LCTL(KC_F2)),
    COMBO(combo_LYRNV_TG, TG(_BASE)),
    COMBO(combo_HKEYS_TG, TG(_BASE)),
    // COMBO(combo_TYPSYS_TG, TG(_TYPING_SYSTEM)),
    COMBO(combo_FN_TG, TG(_BASE)),
};





                                           
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = {   ENCODER_CCW_CW(KC_NO, KC_NO),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_NUM] = {   ENCODER_CCW_CW(KC_NO, KC_NO),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_MPRV, KC_MNXT)  },
    [_NAV] = {   ENCODER_CCW_CW(KC_NO, KC_NO),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_MPRV, KC_MNXT)  },
    [_TEXT] = {   ENCODER_CCW_CW(KC_NO, KC_NO),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_MPRV, KC_MNXT)  },
    [_TYPE1] = {   ENCODER_CCW_CW(KC_NO, KC_NO),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_MPRV, KC_MNXT)  },
    [_TYPE2] = {   ENCODER_CCW_CW(KC_NO, KC_NO),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_MPRV, KC_MNXT)  },
};










/// Tap Dance Definitions

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;



void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            tap_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            tap_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }


tap_dance_action_t tap_dance_actions[] = {
    [BRACKETS] = ACTION_TAP_DANCE_TAP_HOLD(KC_LBRC, KC_RBRC),
    [CLNQUOTE] = ACTION_TAP_DANCE_TAP_HOLD(KC_SCLN, KC_QUOT),
    [COMMADOT] = ACTION_TAP_DANCE_TAP_HOLD(KC_COMM, KC_DOT),
    [MNSPLS] = ACTION_TAP_DANCE_TAP_HOLD(KC_MINS, KC_EQL),
    // [ESCCTRL] = ACTION_TAP_DANCE_TAP_HOLD(KC_ESC, KC_LCTL),
    // [SPACEALT] = ACTION_TAP_DANCE_TAP_HOLD(KC_SPC, KC_LALT),
    // [BKSPSHIFT] = ACTION_TAP_DANCE_TAP_HOLD(KC_BSPC, KC_LSFT)

};







bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t timer_base_shift;
    static uint16_t timer_copy_type;
    static uint16_t timer_paste_text;
    static uint16_t timer_num_nav;
    static uint16_t timer_copy_cmds;
    static uint16_t timer_paste_sftopt;
    static uint16_t timer_base_cmdsft;
    static uint16_t timer_dot_slsh;
    static uint16_t timer_space_comma;
    static uint16_t timer_left_home;
    static uint16_t timer_right_end;
    static uint16_t timer_ques_shift;
    tap_dance_action_t *action;

    switch (keycode) {
        case BASE_SHIFT:  // TO(BASE) on tap, LShift on hold
            if (record->event.pressed) {
                timer_base_shift = timer_read();
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LSFT);
                if (timer_elapsed(timer_base_shift) < 200) {
                    layer_off(_NUM);
                }
            }
            return false;

        case COPY_TYPE:  // CMD+C on tap, TO(TYPE1) if held
            if (record->event.pressed) {
                timer_copy_type = timer_read();
            } else {
                if (timer_elapsed(timer_copy_type) < 200) {
                    tap_code16(LGUI(KC_C));
                } else {
                    layer_on(_TYPE1);
                }
            }
            return false;

        case PASTE_TEXT:  // CMD+V on tap, TO(TEXT) if held
            if (record->event.pressed) {
                timer_paste_text = timer_read();
            } else {
                if (timer_elapsed(timer_paste_text) < 200) {
                    tap_code16(LGUI(KC_V));
                } else {
                    layer_on(_TEXT);
                }
            }
            return false;



        case NUM_NAV:  // TO(NUM) on tap, MO(NAV) if held
            if (record->event.pressed) {
                timer_num_nav = timer_read();
                layer_on(_NAV);
            } else {
                if (timer_elapsed(timer_num_nav) < 200) {
                    layer_off(_NAV);
                    layer_on(_NUM);
                } else {
                    layer_invert(_NAV);
                }
            }
            return false;

        case OPEN_IN_TERM:  // OPT+RCLICK, wait, N, wait, ENTER
            if (record->event.pressed) {
                register_code(KC_LALT);
                tap_code(KC_BTN2);  // Right click
                unregister_code(KC_LALT);
                wait_ms(50);
                tap_code(KC_N);
                wait_ms(50);
                tap_code(KC_ENT);
            }
            return false;

        case COPY_CMDOPT:  // CMD+C on tap, CMD+OPT on hold
            if (record->event.pressed) {
                timer_copy_cmds = timer_read();
                register_code(KC_LGUI);
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LALT);
                if (timer_elapsed(timer_copy_cmds) < 200) {
                    tap_code16(LGUI(KC_C));
                }
            }
            return false;

        case PASTE_SFTOPT:  // CMD+V on tap, RSHIFT+OPT on hold
            if (record->event.pressed) {
                timer_paste_sftopt = timer_read();
                register_code(KC_RSFT);
                register_code(KC_LALT);
            } else {
                unregister_code(KC_RSFT);
                unregister_code(KC_LALT);
                if (timer_elapsed(timer_paste_sftopt) < 200) {
                    tap_code16(LGUI(KC_V));
                }
            }
            return false;

        case BASE_CMDSFT:  // TO(BASE) on tap, CMD+RSHIFT on hold
            if (record->event.pressed) {
                timer_base_cmdsft = timer_read();
                register_code(KC_LGUI);
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_RSFT);
                if (timer_elapsed(timer_base_cmdsft) < 200) {
                    layer_move(_BASE);
                }
            }
            return false;

        case DOT_SLSH:  
            if (record->event.pressed) {
                timer_base_shift = timer_read();
            } else {
                if (timer_elapsed(timer_dot_slsh) < 200) {
                    register_code(KC_DOT);
                    unregister_code(KC_DOT);
                } else {
                    unregister_code(KC_DOT);
                    register_code(KC_SLSH);
                    unregister_code(KC_SLSH);
                }
            }
            return false;

        case SPACE_COMMA:  
            if (record->event.pressed) {
                timer_space_comma = timer_read();
            } else {
                if (timer_elapsed(timer_space_comma) < 200) {
                    register_code(KC_SPC);
                    unregister_code(KC_SPC);
                } else {
                    unregister_code(KC_SPC);
                    register_code(KC_COMM);
                    unregister_code(KC_COMM);
                }
            }
            return false;

        case LEFT_HOME:  
            if (record->event.pressed) {
                timer_left_home = timer_read();
            } else {
                if (timer_elapsed(timer_left_home) < 200) {
                    register_code(KC_LEFT);
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_LEFT);
                    register_code(KC_HOME);
                    unregister_code(KC_HOME);
                }
            }
            return false;
        
        case RIGHT_END:  
            if (record->event.pressed) {
                timer_right_end = timer_read();
            } else {
                if (timer_elapsed(timer_right_end) < 200) {
                    register_code(KC_RIGHT);
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_RIGHT);
                    register_code(KC_END);
                    unregister_code(KC_END);
                }
            }
            return false;
            
        case QUES_SHIFT:  // Question mark on tap, Left Shift on hold
            if (record->event.pressed) {
                timer_ques_shift = timer_read();
                register_code(KC_LSFT);
            } else {
                unregister_code(KC_LSFT);
                if (timer_elapsed(timer_ques_shift) < 200) {
                    tap_code16(LSFT(KC_SLSH));  // Question mark
                }
            }
            return false;        

        // list all tap dance keycodes with tap-hold configurations
        case TD(BRACKETS): 
        case TD(CLNQUOTE):
        case TD(COMMADOT):
        case TD(MNSPLS):
        // case TD(ESCCTRL):
        // case TD(SPACEALT):
        // case TD(BKSPSHIFT):
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            

   
        
    }
    return true;
}









// RGB EFFECTS


// Function to convert standard HSV (0-360, 0-100, 0-100) to QMK HSV (0-360, 0-255, 0-255)

uint32_t base_mode = RGBLIGHT_MODE_STATIC_LIGHT; // Solid color mode

void keyboard_post_init_user(void) {
    rgblight_enable();  // Enable RGB by default
    rgblight_mode(base_mode); // Set to solid color mode
    rgblight_sethsv(135, 255, 255); // Default color: Cyan
}

void get_hsv_vals(uint16_t hue, uint8_t sat, uint8_t val) {
    uint8_t qmk_h = (hue * 255) / 360;  // Hue
    uint8_t qmk_s = (sat * 255) / 100;  // Scale Saturation
    uint8_t qmk_v = (val * 255) / 100;  // Scale Brightness
    rgblight_sethsv_noeeprom(qmk_h, qmk_s, qmk_v);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = biton32(state); // Get the highest active layer
    xprintf("Active Layer: %d\n", layer); // Debugging output

    switch (layer) {
        case _BASE:
            get_hsv_vals(190, 100, 100); // Purple
            break;
        case _NUM:
            get_hsv_vals(275, 100, 100); // Blue
            break;
        case _NAV:
            get_hsv_vals(125, 100, 45); // Green
            break;
        case _TEXT:
            get_hsv_vals(315, 65, 35); // Pink
            break;
        case _TYPE1:
            get_hsv_vals(0, 100, 100); // Red
            break;
        case _TYPE2:
            get_hsv_vals(60, 100, 40); // Yellow
            break;
    }
    return state;
}