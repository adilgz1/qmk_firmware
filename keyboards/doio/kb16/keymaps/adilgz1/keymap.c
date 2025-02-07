

#include QMK_KEYBOARD_H
#include "quantum.h"

// OLED animation
#include "lib/layer_status/layer_status.h"







// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layer_names {
    _BASE,
    _CODE,
    _NUM,
    _RGB
};

// enum layer_keycodes { };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(CTL_T(KC_ESC), SFT_T(KC_TAB), LCTL(KC_Z), LCTL(KC_X),             KC_MUTE, 
                    LALT_T(KC_SPC), LCTL(KC_S), LCTL(KC_Y), LCTL(KC_C),                TO(_CODE), 
                    TD(TD_UP), TD(TD_LEFT), KC_DEL, LCTL(KC_V),                        LAG(KC_P),
                    TD(TD_DOWN), TD(TD_RIGHT), KC_F13, LCA_T(KC_ENT)),
    
    [_CODE] = LAYOUT(CTL_T(KC_ESC), SFT_T(KC_TAB), LCTL(KC_Z), KC_TRNS,             KC_MUTE, 
                    LALT_T(KC_SPC), LCTL(KC_S), LCTL(KC_Y), KC_TRNS,                TO(_NUM), 
                    TD(TD_UP), TD(TD_LEFT), KC_BSPC, KC_TRNS,                       LAG(KC_P),
                    TD(TD_DOWN), TD(TD_RIGHT), KC_F13, SFT_T(KC_ENT)),

    [_NUM] = LAYOUT(KC_1, KC_2, KC_3, KC_TRNS,                                           KC_TRNS, 
                    KC_4, KC_5, KC_6, KC_TRNS,                                           TO(_RGB), 
                    KC_7, KC_8, KC_9, KC_TRNS,                                           KC_TRNS, 
                    KC_DEL, KC_0, TG(_NUM), SFT_T(KC_ENT)),

    [_RGB] = LAYOUT(RM_TOGG, KC_TRNS, KC_TRNS, QK_BOOT,                                 KC_TRNS, 
                    RM_NEXT, KC_TRNS, KC_TRNS, KC_TRNS,                                 TO(_BASE), 
                    RM_VALU, RM_HUEU, RM_SATU, KC_TRNS,                                 KC_TRNS,
                     RM_VALD, RM_HUED, RM_SATD, KC_TRNS)
                     
                    };      
#ifdef OLED_ENABLE
    bool oled_task_user(void) {
        render_layer_status();

        return true;
    }
#endif



const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(LAG(KC_MPRV), LAG(KC_MNXT)), ENCODER_CCW_CW(LCTL(KC_MINS), LCTL(KC_EQL)), ENCODER_CCW_CW(LAG(KC_DOWN), LAG(KC_UP)) },
    [_CODE] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_NUM]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [_RGB]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};






#define LAYER_TOGGLE_KEY KC_F13  // Assign your key (e.g., F1)


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t key_timer;

    switch (keycode) {
        case LAYER_TOGGLE_KEY:  
            if (record->event.pressed) {
                key_timer = timer_read();

                // Short press, toggle Layer _NUM
                layer_on(_NUM);
                register_code(KC_LSFT);
           
                    
                
            } else {
                if (timer_elapsed(key_timer) < 300) {
                    unregister_code(KC_LSFT);
                } else {
                    layer_off(_NUM);
                    unregister_code(KC_LSFT);
                }
                
            }
            return false; 

        
    }
    return true;
}








// Tap Dance declarations

enum {
    TD_LEFT,   // Left Arrow / Home
    TD_RIGHT,  // Right Arrow / End
    TD_UP,     // Up Arrow / Page Up
    TD_DOWN    // Down Arrow / Page Down
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LEFT]  = ACTION_TAP_DANCE_DOUBLE(KC_LEFT, KC_HOME),
    [TD_RIGHT] = ACTION_TAP_DANCE_DOUBLE(KC_RIGHT, KC_END),
    [TD_UP]    = ACTION_TAP_DANCE_DOUBLE(KC_UP, KC_PGUP),
    [TD_DOWN]  = ACTION_TAP_DANCE_DOUBLE(KC_DOWN, KC_PGDN)
};











// RGB EFFECTS
uint32_t base_mode = RGBLIGHT_MODE_STATIC_LIGHT; // Solid color mode

void keyboard_post_init_user(void) {
    rgblight_enable();  // Enable RGB by default
    rgblight_mode(base_mode); // Set to solid color mode
    rgblight_sethsv(135, 255, 255); // Default color: Cyan
}

uint32_t layer_state_set_user(uint32_t state) {
    uint8_t layer = biton32(state); // Get the highest active layer
    xprintf("Active Layer: %d\n", layer); // Debugging output

    switch (layer) {
        case _BASE:
            rgblight_sethsv_noeeprom(135, 255, 255); // Purple
            break;
        case _CODE:
            rgblight_sethsv_noeeprom(85, 255, 255); // Green
            break;
        case _NUM:
            rgblight_sethsv_noeeprom(180, 255, 255); // Blue
            break;
        case _RGB:
            rgblight_sethsv_noeeprom(0, 255, 255); // Red
            break;
    }
    return state;
}
