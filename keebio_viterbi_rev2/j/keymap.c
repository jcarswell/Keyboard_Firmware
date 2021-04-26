#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLMAK 1
#define _DVORAK 2
#define _LOWER 10
#define _RAISE 11
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLMAK,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
  CKC_1_12,
  CKC_2_13
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |  ESC |   `  |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |  -   | BSPC |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | PGUP | Tab  |   Q  |   W  |   E  |   R  |   T  |      |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | PGDN | CAPS |   A  |   S  |   D  |   F  |   G  |      |   H  |   J  |   K  |   L  |   ;  |   "  |Enter |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |  ALT |SHIFT |   Z  |   X  |   C  |   V  |   B  |      |   N  |   M  |   ,  |   .  |   /  |SHIFT | DEL  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * | CTRL | WIN  | LEFT | DOWN |LOWER |    Space    |      |    Space    |Raise |  UP  |RIGHT | ALT  | CTRL |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_QWERTY] = LAYOUT_ortho_5x14(
    KC_ESC , KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_BSPC,
    KC_PGUP, KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC, KC_BSLS,
    KC_PGDN, KC_CAPS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT, KC_ENT ,
    KC_INS,  KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,     KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, KC_DEL ,
    KC_LCTL, KC_LGUI, KC_LEFT, KC_DOWN, LOWER  , KC_SPC , KC_SPC ,     KC_SPC , KC_SPC , RAISE  , KC_UP,   KC_RGHT, KC_RALT, KC_RCTL
  ),
  [_COLMAK] = LAYOUT_ortho_5x14(
    KC_ESC , KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_BSPC,
    KC_PGUP, KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_G   ,     KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_LBRC, KC_BSLS,
    KC_PGDN, KC_CAPS, KC_A   , KC_R   , KC_S   , KC_T   , KC_D   ,     KC_H   , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUOT, KC_ENT ,
    KC_INS,  KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,     KC_K   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT, KC_DEL ,
    KC_LCTL, KC_LGUI, KC_LEFT, KC_DOWN, LOWER  , KC_SPC , KC_SPC ,     KC_SPC , KC_SPC , RAISE  , KC_UP  , KC_RGHT, KC_RALT, KC_RCTL
  ),
  [_DVORAK] = LAYOUT_ortho_5x14(
    KC_ESC , KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_LBRC, KC_BSPC,
    KC_PGUP, KC_TAB , KC_QUOT, KC_COMM, KC_DOT , KC_P   , KC_Y   ,     KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , KC_SLSH, KC_BSLS,
    KC_PGDN, KC_CAPS, KC_A   , KC_O   , KC_E   , KC_U   , KC_I   ,     KC_D   , KC_H   , KC_T   , KC_N   , KC_S   , KC_MINS , KC_ENT ,
    KC_INS,  KC_LSFT, KC_SCLN, KC_Q   , KC_J   , KC_K   , KC_X   ,     KC_B   , KC_M   , KC_W   , KC_V   , KC_X   , KC_RSFT, KC_DEL ,
    KC_LCTL, KC_LGUI, KC_LEFT, KC_DOWN, LOWER  , KC_SPC , KC_SPC ,     KC_SPC , KC_SPC , RAISE  , KC_UP  , KC_RGHT, KC_RALT, KC_RCTL
  ),



/* Lower
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |   ~  |  F1  |  F3  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   _  |      |   !  |   @  |   #  |   $  |   %  |      |   ^  |   &  |   *  |   (  |   )  |   {  |   }  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   +  |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |   _  |   +  |   {  |   }  |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |  F12 |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |      |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_LOWER] = LAYOUT_ortho_5x14(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
    _______, _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, KC_INS,
    _______, KC_LALT,  KC_VOLD, KC_MPRV, _______, KC_MPLY, KC_MPLY,     KC_MPLY, KC_MPLY, _______, KC_VOLU, KC_MNXT, _______, _______
  ),

/* Raise
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |   ~  |  F1  |  F3  |  F3  |  F4  |  F5  |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   _  |      |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  |   {  |   }  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |   +  |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |   -  |   =  |   [  |   ]  |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |  F12 |ISO # |ISO / |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |      |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_RAISE] = LAYOUT_ortho_5x14(
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, KC_EQL, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, KC_RBRC,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, KC_INS,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______
  ),

  [_ADJUST] = LAYOUT_ortho_5x14(
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, QWERTY,  _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, RESET,
    _______, _______, _______, _______, DVORAK,  _______, _______,     _______, _______, _______, _______, _______, _______, EEP_RST,
    _______, _______, _______, _______, COLMAK,  _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______
  )

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    //case CKC_1_12:
    //  switch(get_highest_layer(state)) {
    //    case DVORAK:
    //      register_code(KC_RBRC); //is this the right function ???
    //      break;
    //    default :
    //      register_code(KC_MINS);
    //      break;

    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

