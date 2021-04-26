/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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
#define _BASE 0
#define _TOGGLE 1
#define _RGB 2
#define _MOUSE 3

/* enum custom_keycodes {
 *   BASE = SAFE_RANGE,
 *   TOGGLE,
 *   RGBC,
 *   MOUSE
 * };
 */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_MPLY, RGB_TOG, KC_MUTE,
        KC_LCTL, KC_UP,   TO(_TOGGLE),
        KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [_TOGGLE] = LAYOUT(
        KC_NO,       KC_NO,    KC_NO,
        RCS(KC_ESC), KC_NO,    TO(_BASE),
        TO(_MOUSE),  TO(_RGB), TO(_BASE)
    ),
    [_RGB] = LAYOUT(
        RGB_M_T,  RGB_TOG, RGB_M_R,
        RGB_M_P,  RGB_VAI, TO(_TOGGLE),
        RGB_RMOD, RGB_VAD, RGB_MOD
    ),
    [_MOUSE] = LAYOUT(
        KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN2,
        KC_MS_BTN5, KC_MS_UP,   TO(_TOGGLE),
        KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (IS_LAYER_ON(_MOUSE)) {
        switch (index) {
            case 0:
                if (clockwise) {
                    tap_code(KC_WH_R);
                } else {
                    tap_code(KC_WH_L);
                }
                break;
            case 1: 
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
            case 2:
                if (clockwise) {
                    tap_code(KC_WH_U);
                } else {
                    tap_code(KC_WH_D);
                }
                break;
        }
    } else if (IS_LAYER_ON(_RGB)) {
        switch (index) {
            case 0:
                if (clockwise) {
                    rgblight_increase_hue();
                } else {
                    rgblight_decrease_hue();
                }
                break;
            case 1: 
                if (clockwise) {
                    rgblight_increase_sat();
                } else {
                    rgblight_decrease_sat();
                }
                break;
            case 2:
                if (clockwise) {
                    rgblight_increase_speed();
                } else {
                    rgblight_decrease_speed();
                }
                break;
        }
    } else {
        switch (index) {
            case 0:
                if (clockwise) {
                    tap_code(KC_MNXT);
                } else {
                    tap_code(KC_MPRV);
                }
                break;
            case 1: 
                if (clockwise) {
                    rgblight_increase_val();
                } else {
                    rgblight_decrease_val();
                }
                break;
            case 2:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
        }
    }
}
