#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _FL 3
#define _CL 4

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: ANSI qwerty */
  [_QWERTY] = LAYOUT_ansi_1u(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_HOME,  KC_END,   KC_INS, \
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,             KC_BSPC,  KC_PAUSE,  \
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGUP,  \
    KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_PGDN, \
    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,    KC_DEL, \
    KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(_FL),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

  /* 1: ANSI colemak */
  [_COLEMAK] = LAYOUT_ansi_1u(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_HOME,  KC_END,   KC_DEL, \
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,             KC_BSPC,  KC_INS,  \
    KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGUP,  \
    KC_CAPS,  KC_A,     KC_R,     KC_S,     KC_T,     KC_D,     KC_H,     KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,            KC_ENT,             KC_PGDN, \
    KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_K,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,    KC_PAUS, \
    KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(_FL),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

  /* 2: ANSI dvorak */
  [_DVORAK] = LAYOUT_ansi_1u(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_HOME,  KC_END,   KC_DEL, \
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_LBRC,  KC_RBRC,            KC_BSPC,  KC_INS, \
    KC_TAB,   KC_QUOT,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,     KC_F,     KC_G,     KC_C,     KC_R,     KC_L,     KC_SLSH,  KC_EQL,   KC_BSLS,            KC_PGUP,  \
    KC_CAPS,  KC_A,     KC_O,     KC_E,     KC_U,     KC_I,     KC_D,     KC_H,     KC_T,     KC_N,     KC_S,     KC_MINS,            KC_ENT,             KC_PGDN, \
    KC_LSFT,            KC_SCLN,  KC_Q,     KC_J,     KC_K,     KC_X,     KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,               KC_RSFT,  KC_UP,    KC_PAUS, \
    KC_LCTL,  KC_LGUI,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(_FL),  KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

  /* 3: ANSI Fn layer */
  [_FL] = LAYOUT_ansi_1u(
    KC_ESC,  RGB_TOG, RGB_VAI, RGB_HUI, RGB_SAI, RGB_MOD, _______, _______, _______, _______, QWERTY,  COLEMAK, DVORAK,  _______, _______, RESET, \
    _______, _______, RGB_VAD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______, _______, MO(_CL), _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, \
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_RSFT, KC_VOLU, KC_INS, \
    _______, _______, _______,                            KC_MPLY,                            KC_APP,  MO(_FL), _______, KC_MPRV, KC_VOLD, KC_MNXT),

  /* 4: ANSI control layer */
  [_CL] = LAYOUT_ansi_1u(
    KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,  KC_NO,   KC_NO,  KC_NO, KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO, \
    KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,  KC_NO,   KC_NO,  KC_NO, KC_NO,   KC_NO,          KC_NO,   RGB_TOG, \
    KC_NO,   KC_NO, KC_NO,   KC_NO, RESET, KC_NO, KC_NO,   QWERTY, COLEMAK, DVORAK, KC_NO, KC_NO,   KC_NO, KC_NO,   RGB_VAI, \
    KC_NO,   KC_NO, MO(_CL), KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,  KC_NO,   KC_NO,  KC_NO, KC_NO,          KC_NO,            RGB_VAD, \
    MO(_FL),        KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,  KC_NO,   KC_NO,  KC_NO, KC_NO,   KC_NO,          KC_VOLU, KC_NO, \
    KC_NO,   KC_NO, KC_NO,                        KC_MPLY,                          KC_NO, MO(_FL), KC_NO, KC_MPRV, KC_VOLD, KC_MNXT),
};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
  }
  return true;
}
