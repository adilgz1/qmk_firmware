

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









