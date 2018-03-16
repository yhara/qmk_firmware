#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _CURSOR 1
#define _MEDIA 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Macros
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Ctl/Esc|  A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter/MDIA|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Fn   | Alt  |CURSOR| Cmd  |Eisu/L|Space |Sp/CUR|Kana/R| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
CTL_T(KC_ESC),KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, LT(_MEDIA, KC_ENT), \
  KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS , \
  LT(_ADJUST,KC_LEFT),ALT_T(KC_DOWN),LT(_CURSOR,KC_UP),GUI_T(KC_RIGHT),LT(_LOWER,KC_LANG2),KC_SPC, LT(_CURSOR,KC_SPC),LT(_RAISE,KC_LANG1),KC_LEFT,KC_DOWN,KC_UP,KC_RGHT \
),

/* CURSOR
 * ,-----------------------------------------.    ,------------------------------------------.
 * |      |      |      | End  |      |      |    |      |      |      |      |      | BkSp  |
 * |------+------+------+------+------+------|    |------+------+------+------+------+-------|
 * |      | Home |      | Del  |PgDn  |      |    | Left | Down | Up   | Right|      |       |
 * |------+------+------+------+------+------|    |------+------+------+------+------+-------|
 * |      |      |      |      |      | PgUp |    |      |      | ^z[  |      |      |       |
 * |------+------+------+------+------+------|    |------+------+------+------+------+-------|
 * |      |      |CURSOR|      |      |      |    |CURSOR|      |      |      |      |       |
 * `------+------+------+------+------+------'    `------+------+------+------+------+-------'
 */
[_CURSOR] = KEYMAP( \
  KC_NO  ,KC_NO  ,KC_NO  ,KC_END, KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_BSPC, \
  KC_NO  ,KC_HOME,KC_NO  ,KC_DEL, KC_PGDN, KC_NO  ,  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_NO  , KC_NO, \
  KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO  , KC_PGUP,  KC_NO  , KC_NO  , M(0)   , KC_NO  , KC_NO  , KC_NO,  \
  KC_NO  ,KC_NO  ,KC_TRNS,KC_NO  ,KC_NO  , KC_NO  ,  KC_TRNS, KC_NO  , KC_NO   , KC_NO  , KC_NO  , KC_NO
),

/* MEDIA
 * ,-----------------------------------------.    ,------------------------------------------.
 * |      |      |      | MsUp |      |      |    |      |      |      |      | Play |       |
 * |------+------+------+------+------+------|    |------+------+------+------+------+-------|
 * |      |      |MsLeft|MsDown|MsRght|      |    | Prev |VolDn |VolUp | Next |      | MEDIA |
 * |------+------+------+------+------+------|    |------+------+------+------+------+-------|
 * |      |      |      |      |      |      |    |      |VolDn_|VolUp_| Mute |      |       |
 * |------+------+------+------+------+------|    |------+------+------+------+------+-------|
 * |      |      |      |      |      |      |    |      |      |      |      |      |       |
 * `------+------+------+------+------+------'    `------+------+------+------+------+-------'
 */
[_MEDIA] = KEYMAP( \
  KC_NO  , KC_NO  , KC_NO  , KC_MS_U, KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_MPLY, KC_NO, \
  KC_NO  , KC_NO  , KC_MS_L, KC_MS_D, KC_MS_R, KC_NO  ,  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO  , KC_TRNS  , \
  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , S(LALT(KC_VOLD)), S(LALT(KC_VOLU)), KC_MUTE, KC_NO  , KC_NO,  \
  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO 
),

/* Lower
 * ,-----------------------------------------.     ,-----------------------------------------.
 * |      |   !  |  @   |   #  |  $   |  %   |     |  ^   |  &   |  (   |   )  |  *   |  BS  |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |   ~  |  |   |   =  |  \   |  `   |     |  '   |  {   |  [   |   ]  |  :   |   }  |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |      |      |      |      |      |      |     |  "   |  +   |  <   |   >  |  ?   |   _  |
 * |------+------+------+------+------+------|     |------+------+------+------+------+------|
 * |RESET |      |      |      |LOWER |      |     |      |      |      |      |      |      |
 * `------+------+------+------+------+------'     `------+------+------+------+------+------'
 */
[_LOWER] = KEYMAP( \
  KC_NO  , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,  KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_ASTR, KC_TRNS,
  KC_NO  , KC_TILD, KC_PIPE, KC_EQL , KC_BSLS, KC_GRV,   KC_QUOT, KC_LCBR, KC_LBRC, KC_RBRC, S(KC_SCLN), KC_RCBR,
  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_DQT , KC_PLUS, S(KC_COMM),S(KC_DOT),S(KC_SLSH),S(KC_MINS),
  RESET  , KC_NO  , KC_NO  , KC_NO  , KC_TRNS, KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | BS   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |   :  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   ,  |   .  |   /  |   -  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RESET |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = KEYMAP( \
  KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_DEL, \
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  S(KC_SCLN), KC_TRNS, \
  _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS,   KC_TRNS, \
  RESET,   _______, _______, _______, _______, _______, _______, _______, KC_NO,   KC_NO,   KC_NO,     KC_NO \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | RESET|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | F12  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Fn  |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  KEYMAP( \
  RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_F1,   KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F12, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)


};
