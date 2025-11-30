/* Copyright 2022 DOIO
 * Copyright 2022 HorrorTroll <https://github.com/HorrorTroll>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */



// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.



enum layer_names {
    _BASE,
    _TEXTEDIT,
    _NUMPAD,
    _BROWSER,
    _SYSTEM,
    _MACROS,
    _LATEX1,
    _LATEX2,
    _LATEX3,
};



enum custom_keycodes {
    EMAIL,
    PHONE,
    VAL_LOGIN,
    TEXT_MEENER,
    PC_PASS,
    EMAIL_SU,
    SU_PASS,
    GOOGLE_SELECTION,
    FIND_SELECTION,
    FIND_REPLACE,
};



// Define Tap Dance actions using SAFE_RANGE
enum tap_dance_codes {
    END_SELECT,
    HOME_SELECT,
    COPY_PASTE,
};






#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"
#include "quantum.h"

// OLED animation
#include "lib/layer_status/layer_status.h"



#ifdef OLED_ENABLE
    bool oled_task_user(void) {
        render_layer_status();

        return true;
    }
#endif










// enum layer_keycodes { };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    [_BASE] = LAYOUT(
                KC_ESC,     OSL(_SYSTEM),    OSL(_MACROS),    KC_BSPC,         TO(_NUMPAD),
                KC_TAB,     LCTL(KC_T),    LCTL(KC_Z),    TD(COPY_PASTE),                           KC_MUTE,
                LCTL(KC_LSFT),     KC_UP,    KC_SPC,   KC_ENT,                       LAG(KC_P),
                KC_LEFT, KC_DOWN, KC_RIGHT, LCA(KC_F11)
            ),


    [_TEXTEDIT] = LAYOUT(
                KC_ESC,     LGUI(KC_V),    FIND_SELECTION,    KC_BSPC,         TO(_BASE),
                KC_TAB,     LCTL(KC_S),    LCTL(KC_Z),    KC_TRNS,                           KC_TRNS,
                LCTL(KC_LSFT),     KC_UP,    KC_SPC,   KC_ENT,                       KC_TRNS,
                KC_LEFT, KC_DOWN, KC_RIGHT, LCA(KC_F12)
            ),


    [_NUMPAD] = LAYOUT(
                KC_1, KC_2, KC_3, KC_TRNS,          TO(_BASE),
                KC_4, KC_5, KC_6, KC_EQL,             KC_TRNS,
                KC_7, KC_8, KC_9, KC_MINS,          KC_TRNS,
                KC_DOT, KC_0, KC_SLSH, LSFT_T(KC_ENT)
            ),


    [_BROWSER] = LAYOUT(
                KC_ESC,     LCTL(KC_N),    FIND_SELECTION,    KC_TRNS,         TO(_BASE),
                KC_TRNS,     LCTL(KC_T),    LCTL(KC_M),    KC_TRNS,                           KC_TRNS,
                LCTL(LSFT(KC_EQL)),     KC_UP,    KC_SPC,   KC_ENT,                       KC_TRNS,
                KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS
            ),


    [_SYSTEM] = LAYOUT(
                LGUI(KC_R), RM_SPDD, _______, QK_BOOT, TO(_BASE),
                LSG(KC_RIGHT), LGUI(KC_LEFT), LGUI(KC_RIGHT), LGUI(KC_D), KC_TRNS,
                RM_TOGG, LSG(KC_S), RM_HUEU, _______, KC_TRNS,
                _______, RM_VALU, LCS(KC_ESC), KC_NO
            ),


    [_MACROS] = LAYOUT(
                LSFT(KC_F3), RM_SPDD, KC_NO, VAL_LOGIN, _______,
                TEXT_MEENER, RM_SATD, _______, _______, TO(_BASE),
                PHONE, PHONE, PC_PASS, SU_PASS, _______,
                EMAIL, SU_PASS, SU_EMAIL, SU_PASS
            ),


    [_LATEX1] = LAYOUT(
                RM_SPDU, RM_SPDD, _______, QK_BOOT, _______,
                RM_SATU, RM_SATD, _______, _______, TO(_BASE),
                RM_TOGG, RM_NEXT, RM_HUEU, _______, _______,
                _______, RM_VALU, RM_HUED, RM_VALD
            ),


    [_LATEX2] = LAYOUT(
                RM_SPDU, RM_SPDD, _______, QK_BOOT, _______,
                RM_SATU, RM_SATD, _______, _______, TO(_BASE),
                RM_TOGG, RM_NEXT, RM_HUEU, _______, _______,
                _______, RM_VALU, RM_HUED, RM_VALD
            ),


    [_LATEX3] = LAYOUT(
                RM_SPDU, RM_SPDD, _______, QK_BOOT, _______,
                RM_SATU, RM_SATD, _______, _______, TO(_BASE),
                RM_TOGG, RM_NEXT, RM_HUEU, _______, _______,
                _______, RM_VALU, RM_HUED, RM_VALD
            )
};















#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_PGDN, KC_PGUP), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_TEXTEDIT] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_NUMPAD] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_BROWSER] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_SYSTEM] = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(KC_PGDN, KC_PGUP), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_MACROS] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_LATEX1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_LATEX2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_LATEX3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },    
};
#endif















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
    [END_SELECT] = ACTION_TAP_DANCE_TAP_HOLD(LCTL(LSFT(KC_RIGHT)), LSFT(KC_END)),
    [HOME_SELECT] = ACTION_TAP_DANCE_TAP_HOLD(LCTL(LSFT(KC_LEFT)), LSFT(KC_HOME)),
    [COPY_PASTE] = ACTION_TAP_DANCE_TAP_HOLD(LCTL(KC_C), LCTL(KC_V)),

};







bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    static uint16_t key_timer_VL;
    tap_dance_action_t *action;

    switch (keycode) {


        case EMAIL:
            if (record->event.pressed) {
                SEND_STRING("adilghaznavi16@gmail.com");
            }
            break;

        case PHONE:
            if (record->event.pressed) {
                SEND_STRING("315-572-1752");
            }
            break;

        case PC_PASS:
            if (record->event.pressed) {
                SEND_STRING("199621");
            }
            break;

        case VAL_LOGIN:
            if (record->event.pressed) {
                key_timer_VL = timer_read();
            } else {
                if (timer_elapsed(key_timer_VL) < 150) {
                    SEND_STRING("adilgzusa");
                } else if (timer_elapsed(key_timer_VL) < 500) {
                    SEND_STRING("NATIIAhggytl253599");
                } else if (timer_elapsed(key_timer_VL) < 1200) {
                    SEND_STRING("musti08asad7");
                }
            }
            return false;
                
        case TEXT_MEENER:
            if (record->event.pressed) {
                
                wait_ms(1000);
                
              
            }
            break;

        case EMAIL_SU:
            if (record->event.pressed) {
                SEND_STRING("sghaznav@syr"SS_TAP(X_DOT)"edu");    
            }
            break;
        case SU_PASS:
            if (record->event.pressed) {
                SEND_STRING("Dexpoin"SS_TAP(X_DOT)"777");
            }
            break;

        case GOOGLE_SELECTION:
            if (record->event.pressed) {
                // copy
                tap_code16(LCTL(KC_C));
                wait_ms(100);
                tap_code16(LCAG(KC_F9));
                wait_ms(200);
                tap_code16(LCTL(KC_T));
                wait_ms(300);
                tap_code16(LCTL(KC_V));
                wait_ms(100);
                tap_code16(LCTL(KC_ENTER));
            }
            break;

            
        case FIND_SELECTION:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_C));
                wait_ms(150);
                tap_code16(LCTL(KC_F));
                wait_ms(100);
                tap_code16(LCTL(KC_V));
                wait_ms(50);
                tap_code16(KC_ENT);
            }
            break;


        case FIND_REPLACE:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_C));
                wait_ms(150);
                tap_code16(LCTL(KC_H));
                wait_ms(100);
                tap_code16(LCTL(KC_V));
                wait_ms(50);
                tap_code16(KC_ENT);
            }
            break;


        // list all tap dance keycodes with tap-hold configurations
        case TD(END_SELECT): 
        case TD(HOME_SELECT):
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            

   
        
    }
    return true;
}