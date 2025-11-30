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
};



// Define Tap Dance actions using SAFE_RANGE
enum tap_dance_codes {
    END_SELECT,
    HOME_SELECT,
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
                KC_ESC,     OSL(_SYSTEM),    OSL(_MACROS),    KC_BSPC,         TO(_BASE),
                KC_TAB,     LCTL(KC_T),    LCTL(KC_Z),    LCTL(KC_C),                           KC_MUTE,
                LCTL(KC_LSFT),     KC_UP,    KC_SPC,   KC_ENT,                       LAG(KC_P),
                KC_LEFT, KC_DOWN, KC_RIGHT, LCA(KC_F11)
            ),


    [_TEXTEDIT] = LAYOUT(
                _______, _______, _______, _______, _______,
                _______, _______, _______, _______, TO(_LATEX1),
                _______, _______, _______, _______, _______,
                _______, _______, _______, _______
            ),


    [_NUMPAD] = LAYOUT(
                _______, _______, _______, _______, _______,
                _______, _______, _______, _______, TO(_LATEX2),
                _______, _______, _______, _______, _______,
                _______, _______, _______, _______
            ),


    [_BROWSER] = LAYOUT(
                RM_SPDU, RM_SPDD, _______, QK_BOOT, _______,
                RM_SATU, RM_SATD, _______, _______, TO(_BASE),
                RM_TOGG, RM_NEXT, RM_HUEU, _______, _______,
                _______, RM_VALU, RM_HUED, RM_VALD
            ),


    [_SYSTEM] = LAYOUT(
                RM_SPDU, RM_SPDD, _______, QK_BOOT, _______,
                RM_SATU, RM_SATD, _______, _______, TO(_BASE),
                RM_TOGG, RM_NEXT, RM_HUEU, _______, _______,
                _______, RM_VALU, RM_HUED, RM_VALD
            ),


    [_MACROS] = LAYOUT(
                RM_SPDU, RM_SPDD, _______, QK_BOOT, _______,
                RM_SATU, RM_SATD, _______, _______, TO(_BASE),
                RM_TOGG, RM_NEXT, RM_HUEU, _______, _______,
                _______, RM_VALU, RM_HUED, RM_VALD
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







// // Combos for missing letters & functions
// const uint16_t PROGMEM BASE_2TEXT[] = {LCA(KC_F11), KC_ESC, COMBO_END};   // H = T + A
// const uint16_t PROGMEM BASE_2BROWSING[] = {LCA(KC_F11), OSL(_SYSTEM), COMBO_END};   // Z = S + D
// const uint16_t PROGMEM BASE_2LATEX[] = {LCA(KC_F11), OSL(_MACROS), COMBO_END}; // ? = , + .
// const uint16_t PROGMEM BASE_DEL[] = {LCA(KC_F11), KC_BSPC, COMBO_END}; // Enter = Space + Backspace
// const uint16_t PROGMEM BASE_ALTTAB[] = {LCA(KC_F11), KC_TAB, COMBO_END}; // Esc = Space + Shift
// const uint16_t PROGMEM BASE_TABOPEN[] = {LCA(KC_F11), LCTL(KC_T), COMBO_END}; // Delete = Backspace + Shift
// const uint16_t PROGMEM BASE_REDO[] = {LCA(KC_F11), LCTL(KC_Z),  COMBO_END}; // Redo = Alt + Ctrl + Z
// const uint16_t PROGMEM BASE_NEXTTAB[] = {LCA(KC_F11), KC_UP,  COMBO_END}; // Ctrl+F2
// const uint16_t PROGMEM BASE_PREVTAB[] = {LCA(KC_F11), KC_DOWN,     COMBO_END}; // Toggle LYRNAV Layer = Shift + Ctrl + V 
// const uint16_t PROGMEM BASE_BACK[] = {LCA(KC_F11), KC_LEFT,    COMBO_END}; // Toggle HKEYS Layer = Alt + Ctrl + C
// const uint16_t PROGMEM BASE_FORWARD[] = {LCA(KC_F11), KC_RIGHT,    COMBO_END}; // Toggle FN Layer = Ctrl + L + C
// const uint16_t PROGMEM BASE_PCLOCK[] = {LCA(KC_F11), KC_ENT,    COMBO_END}; // Toggle TYPING SYSTEM Layer = Ctrl + W + X
// const uint16_t PROGMEM BASE_ENDSELECT[] = {LCTL(KC_LSFT), KC_RIGHT,    COMBO_END}; // Toggle FN Layer = Ctrl + L + C
// const uint16_t PROGMEM BASE_HOMESELECT[] = {LCTL(KC_LSFT), KC_LEFT,    COMBO_END}; // Toggle TYPING SYSTEM Layer = Ctrl + W + X

// combo_t key_combos[] = {
//     COMBO(BASE_2TEXT, TO(_TEXTEDIT)),      
//     COMBO(BASE_2BROWSING, TO(_BROWSER)),       
//     COMBO(BASE_2LATEX, TO(_LATEX1)),        
//     COMBO(BASE_DEL, KC_DEL),            
//     COMBO(BASE_ALTTAB, LALT(KC_TAB)),       
//     COMBO(BASE_TABOPEN, LSFT(KC_T)),         
//     COMBO(BASE_REDO, LCTL(KC_Y)),         
//     COMBO(BASE_NEXTTAB, LCTL(KC_PGDN)),      
//     COMBO(BASE_PREVTAB, LCTL(KC_PGUP)),      
//     COMBO(BASE_BACK, KC_WBAK),           
//     COMBO(BASE_FORWARD, KC_WFWD),           
//     COMBO(BASE_PCLOCK, LGUI(KC_L)),         
//     COMBO(BASE_ENDSELECT, TD(END_SELECT)),     
//     COMBO(BASE_HOMESELECT,TD(HOME_SELECT)),     
// };








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