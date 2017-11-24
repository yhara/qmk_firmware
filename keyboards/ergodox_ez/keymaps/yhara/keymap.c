#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#undef  TAPPING_TERM
#define TAPPING_TERM 100

// Emoji
const uint32_t PROGMEM unicode_map[] = {0x1F363};

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define LOWER 3
#define RAISE 4
#define FN 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        | 1  ! | 2  @ | 3  # | 4  $ | 5  % | 6  ^ |           | 5  % | 6  ^ | 7  & | 8  * | 9  ( | 0  ) |  -  _  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  | `  ~ |           | '  " |   Y  |   U  |   I  |   O  |   P  |  BS    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Ctl/Esc|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  | ;  : |  Enter/MDIA |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | = +  |           |  B   |   N  |   M  | ,  < | .  > | /  ? | RSft/- |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  Fn  | Alt  |  L1  | Cmd  |EISU/L|                                       |KANA/R| Left | Down |  Up  | Right |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        |      |      |       | Left | Right  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |  Up  |        |      |
 *                                 |Space |      |------|       |------|        |Space/L1 |
 *                                 |      |      |  N   |       | Down |        |      |
 *                                 `--------------------'       `----------------------'
 *  N ... For thunderbird
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_NO,          KC_NO,        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_NO,
        CTL_T(KC_ESC),  KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_NO,
        LT(FN,KC_LEFT), ALT_T(KC_DOWN),LT(SYMB, KC_UP), GUI_T(KC_RIGHT), LT(LOWER,KC_LANG2),
                                                       KC_LEFT, KC_RIGHT,
                                                                KC_HOME,
                                                KC_SPC,KC_BSLS, KC_N,
        // right hand
             X(0),        KC_NO,  KC_NO,   KC_NO,  KC_NO,  KC_NO,            KC_NO,
             KC_NO,       KC_Y,   KC_U,    KC_I,   KC_O,   KC_P,             KC_BSPC,
                          KC_H,   KC_J,    KC_K,   KC_L,   KC_SCLN,          LT(MDIA,KC_ENT),
             KC_NO,       KC_N,   KC_M,    KC_COMM,KC_DOT, KC_SLSH,          SFT_T(KC_MINS),
                                  LT(RAISE,KC_LANG1),KC_LEFT, KC_DOWN,KC_UP, KC_RIGHT,
             KC_LEFT,       KC_RIGHT,
             KC_UP,
             KC_DOWN,KC_EQL, LT(SYMB,KC_SPC)
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | End  |      |      |      |           |      |      |      |      |      |      |  BkSp  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Home |      | Del  |PgDn  |      |------|           |------| Left | Down | Up   | Right|      |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      | PgUp |      |           | PgUp |      |      | ^z[  |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,   KC_F5,  KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_END, KC_TRNS, KC_TRNS,KC_TRNS,
       KC_TRNS,KC_HOME,KC_TRNS,KC_DEL, KC_PGDN, KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_PGUP,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS, KC_TRNS,
                                                KC_TRNS,
                               KC_TRNS,KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC,
                KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_TRNS, KC_F12,
       KC_PGUP, KC_TRNS, KC_TRNS, M(0)   , KC_TRNS, KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | RESET  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      | Play |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------| Prev |VolDn |VolUp | Next |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      | Mute |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Rclk | Lclk |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN2, KC_BTN1,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_TRNS,
                 KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MUTE, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

/* LOWER
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |  @   |   #  |  $   |  %   |      |           |      |  ^   |  &   |  (   |   )  |  *   |  BS    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   ~  |  |   |   =  |  \   |  `   |------|           |------|  '   |  {   |  [   |   ]  |  }   | Enter  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |  "   |  +   |  <   |   >  |  ?   |   _    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Space|      |------|       |------|      |Space |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[LOWER] = KEYMAP(
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_NO  ,
       KC_NO  , KC_TILD, KC_PIPE, KC_EQL , KC_BSLS, KC_GRV,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                                           KC_NO  , KC_NO  ,
                                                    KC_NO  ,
                                  KC_TRNS, KC_NO  , KC_NO  ,
    // right hand
       KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  ,  KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_ASTR, KC_TRNS,
                 KC_QUOT, KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, KC_TRNS,
       KC_NO  ,  KC_DQT , KC_PLUS, S(KC_COMM),S(KC_DOT),S(KC_SLSH),S(KC_MINS),
                          KC_NO  , KC_NO,   KC_NO,   KC_NO, KC_NO,
       KC_NO  , KC_NO  ,
       KC_NO  ,
       KC_NO  , KC_NO  , KC_TRNS  
),
/* RAISE
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   1  |  2   |   3  |  4   |  5   |      |           |      |  6   |  7   |  8   |   9  |  0   |  BS    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |  :   | Enter  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |  ,   |   .  |  /   |  -     |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | RESET|      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |Space |      |------|       |------|      |Space |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[RAISE] = KEYMAP(
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       RESET  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                                           KC_NO  , KC_NO  ,
                                                    KC_NO  ,
                                  KC_TRNS, KC_NO  , KC_NO  ,
    // right hand
       KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  ,  KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_TRNS,
                 KC_NO  , KC_NO  , KC_NO  , KC_NO  , S(KC_SCLN), KC_TRNS,
       KC_NO  ,  KC_NO  , KC_NO  , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  ,
       KC_NO  ,
       KC_NO  , KC_NO  , KC_TRNS  
),

/* FN
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |------|           |------|  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |  F12   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[FN] = KEYMAP(
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                                           KC_NO  , KC_NO  ,
                                                    KC_NO  ,
                                  KC_NO  , KC_NO  , KC_NO  ,
    // right hand
       KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO,
                 KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11,
       KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_F12,
                          KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  , KC_NO  ,
       KC_NO  ,
       KC_NO  , KC_NO  , KC_NO  
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          SEND_STRING(SS_LCTRL("z")"[");
          break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
