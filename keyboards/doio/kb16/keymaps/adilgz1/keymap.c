

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
    _NAVIGATION,
    _NUM,
    _HKEYS_MISC,
    _LYRNAV_WEB,
    _TYPING_SYSTEM,
    _FN_LAUNCH,
    _CHARS_A,
    _CHARS_B,
};

enum custom_keycodes {
    NUMP_ACTI_LGUI = SAFE_RANGE,
    SAVE_THEN_TGNAV,
    HKEYS_MISC_ACTIVATOR_ENTER,
    FN_ACTIVATOR_TAB,
    EMAIL_TYPER,
    TELENO_TYPER,
    VAL_LOGIN,
    TEXT_MEENER,
    PC_PASSW,


    SU_EMAIL,
    SU_PASSW,
    GOOGLE_SELECTED,
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
        KC_DOWN, KC_UP, KC_TAB, KC_BSPC, TG(_CHARS_A),
        KC_RIGHT, KC_LEFT, KC_SPC, TG(_NAVIGATION), KC_MUTE,
        LCTL_T(KC_ENT), KC_LSFT, KC_LALT, LCTL(KC_Z), LAG(KC_P),
        NUMP_ACTI_LGUI, LCTL(KC_V), LCTL(KC_C), LCTL(KC_X)
    ),

    [_NAVIGATION] = LAYOUT(
        KC_PGDN, KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_END, KC_HOME, KC_TRNS, SAVE_THEN_TGNAV, KC_TRNS,
        KC_TRNS, KC_TRNS, LCTL(KC_LEFT), KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, LCTL(KC_RIGHT), TG(_NAVIGATION)
    ),

    [_LYRNAV_WEB] = LAYOUT(
        KC_PGDN, KC_PGUP, KC_TAB, KC_ESC, KC_TRNS,
        LCA(KC_R), LCA(KC_F), KC_LALT, LCTL(KC_T), KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, LCTL(KC_W), KC_TRNS,
        KC_TRNS, KC_TRNS, MO(_TYPING_SYSTEM), KC_TRNS
    ),

    [_HKEYS_MISC] = LAYOUT(
        LM(_CHARS_A, MOD_LCTL), TD(COMMADOT), TD(BRACKETS), KC_NO, KC_TRNS,
        LM(_CHARS_B, MOD_LCTL), TD(MNSPLS), TD(CLNQUOTE), TEXT_MEENER, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_SLSH, GOOGLE_SELECTED, KC_TRNS,
        TG(_HKEYS_MISC), KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_NUM] = LAYOUT(
        KC_BSPC, KC_7, KC_4, KC_1, KC_TRNS,
        KC_0, KC_8, KC_5, KC_2, KC_TRNS,
        KC_TRNS, KC_9, KC_6, KC_3, KC_TRNS,
        NUMP_ACTI_LGUI, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_TYPING_SYSTEM] = LAYOUT(
        SU_EMAIL, EMAIL_TYPER, LCAG(KC_F3), LALT(KC_F4), KC_TRNS,
        SU_PASSW, TELENO_TYPER, LGUI(KC_D), LCAG(KC_F6), KC_TRNS,
        PC_PASSW, VAL_LOGIN, LCTL(KC_H), LSG(KC_S), KC_TRNS,
        KC_TRNS, KC_TRNS, LCTL(KC_A), LSG(KC_RIGHT)
    ),

    [_FN_LAUNCH] = LAYOUT(
        LCAG_T(KC_NO), KC_F9, KC_F5, KC_F1, KC_TRNS,
        KC_LCTL, KC_F10, KC_F6, KC_F2, KC_TRNS,
        KC_LALT, KC_F11, KC_F7, KC_F3, KC_TRNS,
        TG(_FN_LAUNCH), KC_F12, KC_F8, KC_F4
    ),

    [_CHARS_A] = LAYOUT(
        KC_SPC, KC_Y, KC_T, KC_Q, TG(_CHARS_A),
        KC_BSPC, KC_I, KC_A, KC_W, KC_TRNS,
        OSM(MOD_LSFT), KC_O, KC_S, KC_E, KC_TRNS,
        TT(_CHARS_B), KC_N, KC_D, KC_R
    ),

    [_CHARS_B] = LAYOUT(
        KC_COMM, KC_U, KC_C, KC_P, TG(_CHARS_B),
        KC_DOT, KC_L, KC_F, KC_B, KC_TRNS,
        KC_TRNS, KC_K, KC_G, KC_M, KC_TRNS,
        TG(_CHARS_B), KC_X, KC_J, KC_V
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
    COMBO(combo_LYRNV_TG, TG(_LYRNAV_WEB)),
    COMBO(combo_HKEYS_TG, TG(_HKEYS_MISC)),
    // COMBO(combo_TYPSYS_TG, TG(_TYPING_SYSTEM)),
    COMBO(combo_FN_TG, TG(_FN_LAUNCH)),
};





                                           
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(TO(_CHARS_B), TO(_NUM)), ENCODER_CCW_CW(LAG(KC_MPRV), LAG(KC_MNXT)), ENCODER_CCW_CW(LAG(KC_PGDN), LAG(KC_PGUP)) },
    [_NAVIGATION] = { ENCODER_CCW_CW(TO(_BASE), TO(_NUM)), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_HKEYS_MISC] = { ENCODER_CCW_CW(TO(_NUM), TO(_LYRNAV_WEB)), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_LYRNAV_WEB] = { ENCODER_CCW_CW(TO(_HKEYS_MISC), TO(_TYPING_SYSTEM)), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_NUM] = { ENCODER_CCW_CW(TO(_BASE), TO(_HKEYS_MISC)), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_TYPING_SYSTEM] = { ENCODER_CCW_CW(TO(_LYRNAV_WEB), TO(_FN_LAUNCH)), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_FN_LAUNCH] = { ENCODER_CCW_CW(TO(_TYPING_SYSTEM), TO(_CHARS_A)), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_CHARS_A] = { ENCODER_CCW_CW(TO(_FN_LAUNCH), TO(_CHARS_B)), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_CHARS_B] = { ENCODER_CCW_CW(TO(_CHARS_A), TO(_BASE)), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
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
    static uint16_t key_timer_NAS;
    // static uint16_t key_timer_HMAE;
    // static uint16_t key_timer_FAT;
    static uint16_t key_timer_VL;
    tap_dance_action_t *action;

    switch (keycode) {
        case NUMP_ACTI_LGUI:  
            if (record->event.pressed) {
                key_timer_NAS = timer_read();
                if (IS_LAYER_ON(_NUM)) {
                    register_code(KC_LSFT);
                } else {
                    layer_on(_NUM);
                }
                
                
            } else {
                
                
                if (get_mods() & MOD_BIT(KC_LSFT)) {
                    unregister_code(KC_LSFT);
                    if (timer_elapsed(key_timer_NAS) < 220) {
                        layer_off(_NUM);
                    }
                    
                } else if (timer_elapsed(key_timer_NAS) > 220 && timer_elapsed(key_timer_NAS) < 800) {
                    layer_off(_NUM);
                    clear_oneshot_mods();
                    set_oneshot_mods(MOD_BIT(KC_LGUI));
                    break;
                } else if (timer_elapsed(key_timer_NAS) > 800) {
                    layer_off(_NUM);
                }
                
            }
            return false;





        case SAVE_THEN_TGNAV:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_S));
                wait_ms(100);
                layer_invert(_NAVIGATION);
            } 
            return false;

        // case FN_ACTIVATOR_TAB:  
        //     if (record->event.pressed) {
        //         key_timer_FAT = timer_read();
                
        //     } else {
        //         if (timer_elapsed(key_timer_FAT) < 200) {
        //             tap_code(KC_TAB);
        //         } else {
        //             layer_invert(_FN_LAUNCH);
        //         }
        //     }
        //     return false;




        // case HKEYS_MISC_ACTIVATOR_ENTER:  
        //     if (record->event.pressed) {
        //         key_timer_HMAE = timer_read();
        //         layer_on(_HKEYS_MISC);

            
        //     } else {
        //         layer_off(_HKEYS_MISC);
        //         if (timer_elapsed(key_timer_HMAE) < 175) {
        //             tap_code(KC_ENTER);
        //         } else if (timer_elapsed(key_timer_HMAE) > 175 && timer_elapsed(key_timer_HMAE) < 800) {
        //             set_oneshot_layer(_TYPING_SYSTEM, ONESHOT_START);
        //             clear_oneshot_layer_state(ONESHOT_PRESSED);
        //         }
        //     }
        //     return false;
        
        
        

        case EMAIL_TYPER:
            if (record->event.pressed) {
                SEND_STRING("adilghaznavi16@gmail.com");
            }
            break;
        case TELENO_TYPER:
            if (record->event.pressed) {
                SEND_STRING("315-572-1752");
            }
            break;

        case PC_PASSW:
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

        case SU_EMAIL:
            if (record->event.pressed) {
                SEND_STRING("sghaznav@syr"SS_TAP(X_DOT)"edu");    
            }
            break;
        case SU_PASSW:
            if (record->event.pressed) {
                SEND_STRING("Dexpoin"SS_TAP(X_DOT)"777");
            }
            break;

        case GOOGLE_SELECTED:
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
        case _NAVIGATION:
        get_hsv_vals(190, 100, 20); // Purple
            break;
        case _LYRNAV_WEB:
            get_hsv_vals(315, 65, 35); // Pink
            break;
        case _HKEYS_MISC:
            get_hsv_vals(125, 100, 45); // Green
            break;
        case _NUM:
            get_hsv_vals(275, 100, 100); // Blue
            break;
        case _TYPING_SYSTEM:
            get_hsv_vals(0, 100, 100); // Red
            break;
        case _FN_LAUNCH:
            get_hsv_vals(60, 100, 40); // Yellow
            break;
        case _CHARS_A:
            get_hsv_vals(255, 100, 100); // Purple
            break;
        case _CHARS_B:
            get_hsv_vals(295, 100, 100); // Blue
            break;
    }
    return state;
}









