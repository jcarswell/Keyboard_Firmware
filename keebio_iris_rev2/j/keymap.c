#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16
#define _COLMAK 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  COLMAK,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_GESC, KC_1, KC_2, KC_3, KC_4,    KC_5,                    KC_6,    KC_7,   KC_8,    KC_9,   KC_0,    KC_BSPC,
    KC_TAB,  KC_Q, KC_W, KC_E, KC_R,    KC_T,                    KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,    KC_BSLS,
    KC_LSFT, KC_A, KC_S, KC_D, KC_F,    KC_G,                    KC_H,    KC_J,   KC_K,    KC_L,   KC_QUOT, KC_ENT,
    KC_LCTL, KC_Z, KC_X, KC_C, KC_V,    KC_B,    LOWER,  RAISE,  KC_N,    KC_M,   KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_SCLN),
                               KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_DEL,  KC_LALT
  ),

  [_LOWER] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_INS,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                        KC_VOLD, KC_VOLU, _______, KC_MPLY, KC_MPRV, KC_MNXT
  ),

  [_RAISE] = LAYOUT(
    KC_GRV,  _______, _______, _______, _______, _______,                   _______, _______, _______, KC_MINS, KC_EQL,  KC_DEL,
    _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_INS,                    _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_NO,                     _______, _______, _______, _______, KC_SCLN, KC_QUOT,
    _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   _______, _______, _______, _______, _______, _______, _______, _______,
                                        _______, _______, _______, _______, _______, _______
  ),

  [_ADJUST] = LAYOUT(
    _______, QWERTY,  _______, _______, _______, _______,                   _______, _______, _______, _______, _______, RESET,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, EEP_RST,
    _______, _______, _______, COLMAK,  _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                        _______, _______, _______, _______, _______, _______
  ),

  [_COLMAK] = LAYOUT(
    KC_GESC, KC_1, KC_2, KC_3, KC_4,    KC_5,                    KC_6,   KC_7,   KC_8,    KC_9,   KC_0,    KC_BSPC,
    KC_TAB,  KC_Q, KC_W, KC_F, KC_P,    KC_G,                    KC_J,   KC_L,   KC_U,    KC_Y,   KC_SCLN, KC_BSLS,
    KC_LSFT, KC_A, KC_R, KC_S, KC_T,    KC_D,                    KC_H,   KC_N,   KC_E,    KC_I,   KC_O,    KC_ENT, 
    KC_LCTL, KC_Z, KC_X, KC_C, KC_V,    KC_B,    LOWER,  RAISE,  KC_K,   KC_M,   KC_COMM, KC_DOT, KC_QUOT, RSFT_T(KC_SLSH),
                               KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_DEL, KC_LALT
  ),
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
    case COLMAK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_COLMAK);
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
