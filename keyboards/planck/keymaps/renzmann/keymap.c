/* Copyright 2015-2017 Jack Humbert
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

#include QMK_KEYBOARD_H

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _QGMLWB,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY,
  COLEMAK,
  DVORAK,
  QGMLWB
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define QWERTY DF(_QWERTY)
#define COLEMAK DF(_COLEMAK)
#define DVORAK DF(_DVORAK)
#define QGMLWB DF(_QGMLWB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Shift| GUI  | Alt  |Lower |    Space    |Raise | Alt  | GUI  |Shift | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, LOWER,   KC_SPC,           RAISE,   KC_RALT, KC_LGUI, KC_RSFT, KC_RCTL, _______
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Shift| GUI  | Alt  |Lower |    Space    |Raise | Alt  | GUI  |Shift | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, LOWER,   KC_SPC,           RAISE,   KC_RALT, KC_LGUI, KC_RSFT, KC_RCTL, _______
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Shift| GUI  | Alt  |Lower |    Space    |Raise | Alt  | GUI  |Shift | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */

[_DVORAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
    KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
    KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT ,
    KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, LOWER,   KC_SPC,           RAISE,   KC_RALT, KC_LGUI, KC_RSFT, KC_RCTL, _______
),

/* QGMLWB
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   G  |   M  |   L  |   W  |   B  |   Y  |   U  |   V  |   ;  | BkSpc|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ESC  |   D  |   S  |   T  |   N  |   R  |   I  |   A  |   E  |   O  |   H  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   F  |   J  |   K  |   P  |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Shift| GUI  | Alt  |Lower |    Space    |Raise | Alt  | GUI  |Shift | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_QGMLWB] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_G,    KC_M,    KC_L,    KC_W,    KC_B,    KC_Y,    KC_U,    KC_V,    KC_SCLN, KC_BSPC,
    KC_ESC,  KC_D,    KC_S,    KC_T,    KC_N,    KC_R,    KC_I,    KC_A,    KC_E,    KC_O,    KC_H,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_F,    KC_J,    KC_K,    KC_P,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, KC_LSFT, KC_LGUI, KC_LALT, LOWER,   KC_SPC,           RAISE,   KC_RALT, KC_LGUI, KC_RSFT, KC_RCTL, _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  ~   |  &   |  *   |  `   |      |      |      |  7   |  8   |  9   |  -   |  =   |
 * |------|------+------+------+------+------+------+------+------+------+------+------|
 * |  _   |  $   |  %   |  ^   |      |      |      |  4   |  5   |  6   |  .   |  +   |
 * |------|------+------+------+------+------+------+------+------+------+------+------|
 * | M-f  |  !   |  @   |  #   |      |      |      |  1   |  2   |  3   |  /   |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |XXXXXX|      0      |Adjust|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_AMPR, KC_ASTR, KC_GRV , _______, _______, _______, KC_7   , KC_8   , KC_9   , KC_MINS, KC_EQL ,
    KC_UNDS, KC_DLR , KC_PERC, KC_CIRC, _______, _______, _______, KC_4   , KC_5   , KC_6   , KC_DOT , KC_PLUS,
    A(KC_F), KC_EXLM, KC_AT  , KC_HASH, _______, _______, _______, KC_1   , KC_2   , KC_3   , KC_SLSH, KC_BSLS,
    _______, _______, _______, _______, _______, KC_0  ,           _______, _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |  {   |  }   |      |      |      | Ins  | Up   |      |      |
 * |------+------+------+------+------+------+------+------|------+------+------+------+
 * |      |      | BkSpc|  (   |  )   | Bkspc|      |      | Left | Down | Right| PgUp |
 * |------+------+------+------+------+------+------+------|------+------+------+------+
 * | Caps |      | Del  |  [   |  ]   | Del  |      |      | Home | End  |      | PgDn |
 * |------+------+------+------+------+------+------+------|------+------+------+------+
 * |      |      |      |      |Adjust|    Space    |XXXXXX|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______, _______, _______, KC_LCBR, KC_RCBR, _______, _______, _______, KC_INS , _______, _______, _______,
    _______, _______, KC_BSPC, KC_LPRN, KC_RPRN, KC_BSPC, _______, _______, KC_HOME, KC_UP  , KC_END , KC_PGUP,
    KC_CAPS, _______, KC_DEL , KC_LBRC, KC_RBRC, KC_DEL , _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
    _______, _______, _______, _______, _______, KC_SPC,           _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | <F9> | <F10>| <F11>| <F12>|Colemk|Dvorak|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | <F5> | <F6> | <F7> | <F8> |Qwerty|Qgmlwb| PvTrk| Play | NxTrk|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | <F1> | <F2> | <F3> | <F4> |      |      | VolDn| Mute | VolUp|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |xxxxxx|             |xxxxxx|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , COLEMAK, DVORAK , _______, _______, _______, _______, _______,
    _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , QWERTY , QGMLWB , KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______, _______, KC_VOLD, KC_MUTE, KC_VOLU, _______, _______,
    _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

