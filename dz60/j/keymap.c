#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _COLMAK 1
#define _DVORAK 2
#define _MOD0 3
#define _MOD1 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
		[_QWERTY] = LAYOUT_60_ansi_arrow( /* Base QWERTY */
			KC_GESC,         KC_1,    KC_2,            KC_3,    KC_4,    KC_5,   KC_6,     KC_7,    KC_8,    KC_9,    KC_0,            KC_MINS, KC_EQL,  KC_BSPC,
		    KC_TAB,          KC_Q,    KC_W,            KC_E,    KC_R,    KC_T,   KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,            KC_LBRC, KC_RBRC, KC_BSLASH,
			CTL_T(KC_CAPS),  KC_A,    KC_S,            KC_D,    KC_F,    KC_G,   KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN,         KC_QUOT,          KC_ENT,
		    KC_LSFT,         KC_Z,    KC_X,            KC_C,    KC_V,    KC_B,   KC_N,     KC_M,    KC_COMM, KC_DOT,  RSFT_T(KC_SLSH), KC_UP,            KC_DEL,
		    KC_LCTL,        KC_LGUI,  KC_LALT,                   KC_SPC,                    MO(_MOD0),   KC_RCTL, KC_LEFT,         KC_DOWN,          KC_RIGHT),
		[_COLMAK] = LAYOUT_60_ansi_arrow( /* Base COLMAK*/
			KC_GRV,          KC_1,    KC_2,            KC_3,    KC_4,    KC_5,   KC_6,     KC_7,    KC_8,    KC_9,    KC_0,            KC_MINS, KC_EQL,  KC_BSPC,
		    KC_TAB,          KC_Q,    KC_W,            KC_F,    KC_P,    KC_G,   KC_J,     KC_L,    KC_U,    KC_Y,    KC_SCLN,         KC_LBRC, KC_RBRC, KC_BSLASH,
			CTL_T(KC_CAPS),  KC_A,    KC_R,            KC_S,    KC_T,    KC_D,   KC_H,     KC_N,    KC_E,    KC_I,    KC_O,            KC_QUOT,          KC_ENT,
		    KC_LSFT,         KC_Z,    KC_X,            KC_C,    KC_V,    KC_B,   KC_K,     KC_M,    KC_COMM, KC_DOT,  RSFT_T(KC_SLSH), KC_UP,            KC_DEL,
		    KC_LCTL,        KC_LGUI,  KC_LALT,                   KC_SPC,                    MO(_MOD0),   KC_RCTL, KC_LEFT,         KC_DOWN,          KC_RIGHT),
		[_DVORAK] = LAYOUT_60_ansi_arrow( /* Base DVORAK */
			KC_GESC,         KC_1,    KC_2,            KC_3,    KC_4,    KC_5,   KC_6,     KC_7,    KC_8,    KC_9,    KC_0,            KC_LBRC, KC_RBRC, KC_BSPC,
		    KC_TAB,          KC_QUOT, KC_COMM,         KC_DOT,  KC_P,    KC_Y,   KC_F,     KC_G,    KC_C,    KC_R,    KC_L,            KC_SLSH, KC_EQL,  KC_BSLASH,
			CTL_T(KC_CAPS),  KC_A,    KC_O,            KC_E,    KC_U,    KC_I,   KC_D,     KC_H,    KC_T,    KC_N,    KC_S,            KC_MINS,          KC_ENT,
		    KC_LSFT,         KC_SCLN, KC_Q,            KC_J,    KC_K,    KC_X,   KC_B,     KC_M,    KC_W,    KC_V,    KC_Z,            KC_UP,            KC_RSFT,
		    KC_LCTL,        KC_LGUI,  KC_LALT,                  KC_SPC,                    MO(_MOD0),   KC_RCTL, KC_LEFT,         KC_DOWN,          KC_RIGHT),
		[_MOD0] = LAYOUT_60_ansi_arrow( /* FN */
		    KC_GRV,          KC_F1,   KC_F2,           KC_F3,   KC_F4,   KC_F5,  KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,          KC_F11,  KC_F12, _______,
		    _______,         _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,         KC_PGDN, KC_PGUP, RESET,
		    _______,         _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,         TO(_MOD1),        EEP_RST,
		    _______,         _______, _______,         _______, _______, _______, _______, _______, KC_HOME, KC_END,  _______,         KC_VOLU,          KC_INS,
			_______,         _______, _______,                           KC_MPLY,                   _______, _______, KC_MPRV,         KC_VOLD,          KC_MNXT),
		[_MOD1] = LAYOUT_60_ansi_arrow( /* CONTROL */
			_______,         KC_F1,       KC_F2,       KC_F3,       KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,          KC_F11,  KC_F12, _______,
			_______,         TO(_QWERTY), _______,     _______,     _______, _______, _______, _______, _______, _______, _______,         _______, _______, RESET,
			_______,         _______,     TO(_DVORAK), _______,     _______, _______, _______, _______, _______, _______, _______,         _______,          EEP_RST,
			_______,         _______,     _______,     TO(_COLMAK), _______, _______, _______, _______, _______, _______, _______,         _______,          _______,
			_______,         _______,     _______,                           _______,                   _______, _______, _______,         _______,          _______),
		};

#ifdef RGB_MATRIX_ENABLE
void rgb_matrix_indicators_user(void) {
	  uint8_t this_led = host_keyboard_leds();
	  if (!g_suspend_state) {
	    switch (biton32(layer_state)) {
        case _MOD0:
          if ( this_led & (1<<USB_LED_NUM_LOCK)) {
            rgb_matrix_set_color(13, 0xFF, 0x00, 0x00);
          } else {
            rgb_matrix_set_color(13, 0x00, 0x00, 0x00);
          }
          rgb_matrix_set_color(0, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(1, 0x00, 0xFF, 0x00);
          rgb_matrix_set_color(2, 0x00, 0xFF, 0x00);
          rgb_matrix_set_color(3, 0x00, 0xFF, 0x00);
          rgb_matrix_set_color(4, 0x00, 0xFF, 0x00);
          rgb_matrix_set_color(5, 0x00, 0xFF, 0x00);
          rgb_matrix_set_color(6, 0x00, 0xFF, 0x00);
          rgb_matrix_set_color(7, 0x00, 0xFF, 0x00);
          rgb_matrix_set_color(8, 0x00, 0xFF, 0x00);
          rgb_matrix_set_color(9, 0x00, 0xFF, 0x00);
          rgb_matrix_set_color(10, 0x00, 0xFF, 0x00);
          rgb_matrix_set_color(11, 0x00, 0xFF, 0x00);
          rgb_matrix_set_color(12, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(14, 0x8F, 0x00, 0x00);
          rgb_matrix_set_color(15, 0xFF, 0xFF, 0x00);
          rgb_matrix_set_color(16, 0x80, 0x80, 0x00);
          rgb_matrix_set_color(17, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(18, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(19, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(20, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(21, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(22, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(23, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(24, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(25, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(26, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(27, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(28, 0x8F, 0x00, 0x00);
          rgb_matrix_set_color(29, 0xC2, 0x50, 0x80);
          rgb_matrix_set_color(30, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(31, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(32, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(33, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(34, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(35, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(36, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(37, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(38, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(39, 0x00, 0xFF, 0xAA);
          rgb_matrix_set_color(40, 0x2F, 0x00, 0x00);
          rgb_matrix_set_color(41, 0xFF, 0xFF, 0xFF);
          rgb_matrix_set_color(42, 0x00, 0x00, 0xFF);
          rgb_matrix_set_color(43, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(44, 0xFF, 0xFF, 0x00);
          rgb_matrix_set_color(45, 0x8F, 0x8F, 0x00);
          rgb_matrix_set_color(46, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(47, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(48, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(49, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(50, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(51, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(52, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(53, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(54, 0xFF, 0x63, 0x47);
          rgb_matrix_set_color(55, 0x00, 0x00, 0x8F);
          rgb_matrix_set_color(56, 0xFF, 0x63, 0x47);
          rgb_matrix_set_color(57, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(58, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(59, 0x4F, 0x4F, 0xFF);
          rgb_matrix_set_color(60, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(61, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(62, 0x00, 0x00, 0x00);
          break;
	    case _MOD1:
          rgb_matrix_set_color(14, 0x8F, 0x00, 0x00);
          rgb_matrix_set_color(15, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(16, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(17, 0x00, 0xFF, 0xFF);
          rgb_matrix_set_color(18, 0xFF, 0xFF, 0x00);
          rgb_matrix_set_color(19, 0x00, 0x00, 0xFF);
          rgb_matrix_set_color(20, 0x00, 0xFF, 0x00);
          rgb_matrix_set_color(21, 0xFF, 0x00, 0x00);
          rgb_matrix_set_color(22, 0xFF, 0xFF, 0xFF);
          rgb_matrix_set_color(23, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(24, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(25, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(26, 0xC2, 0x50, 0x80);
          rgb_matrix_set_color(27, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(28, 0x8F, 0x00, 0x00);
          rgb_matrix_set_color(29, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(37, 0xC2, 0x50, 0x80);
          rgb_matrix_set_color(30, 0x00, 0xA0, 0xA0);
          rgb_matrix_set_color(36, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(35, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(34, 0xA0, 0x00, 0x00);
          rgb_matrix_set_color(33, 0x00, 0xA0, 0x00);
          rgb_matrix_set_color(32, 0x00, 0x00, 0xA0);
          rgb_matrix_set_color(31, 0xA0, 0xA0, 0x00);
          rgb_matrix_set_color(38, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(39, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(40, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(41, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(42, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(43, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(44, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(50, 0xC2, 0x50, 0x80);
          rgb_matrix_set_color(46, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(47, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(48, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(49, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(45, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(51, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(52, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(53, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(54, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(55, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(56, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(57, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(58, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(59, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(60, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(61, 0x00, 0x00, 0x00);
          rgb_matrix_set_color(62, 0x00, 0x00, 0x00);
          break;
      }
    }
    if ( this_led & (1<<USB_LED_CAPS_LOCK)) {
      rgb_matrix_set_color(40, 0xFF, 0xFF, 0xFF);
    }
}

void matrix_init_user(void) {
  //user initialization
}

void matrix_scan_user(void) {
  //user matrix
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	  return true;
	}
