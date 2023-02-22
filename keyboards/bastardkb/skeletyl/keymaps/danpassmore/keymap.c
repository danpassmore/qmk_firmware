/* 
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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



#define NUM_AND_SYMBOLS_SCHEME 4

/* layers */
enum
{
  _DVRK = 0,
  _QWRT,
#if NUM_AND_SYMBOLS_SCHEME == 1 || NUM_AND_SYMBOLS_SCHEME == 2
  _NVSM,  // Navigation and symbols
  _FNNM,  // Function keys and Number Pad
  _MDMS, // Media and Mouse
#elif NUM_AND_SYMBOLS_SCHEME == 3
  _NMSM, // Numbers + Symbols
  _NVMS, // Navigation + mouse
  _FNMD, // function + media
#elif NUM_AND_SYMBOLS_SCHEME == 4
  _NMSM, // Numbers + Symbols
  _FNNV, // Function + Navigation
  _MDMS, // Media and Mouse
#else
#endif
  _RISE,
  _LOWR,
};

#define _____ KC_TRNS
#define __x__ KC_NO

#if 1
#define U_PSTE S(KC_INS)
#define U_COPY C(KC_INS)
#define U_CUT  S(KC_DEL)
#define U_REDO KC_AGIN
#define U_UNDO KC_UNDO

#else
#define U_PSTE LCTRL(KC_V)
#define U_COPY LCTRL(KC_C)
#define U_CUT  LCTRL(KC_X)
#define U_REDO  LCTRL(KC_C)
#define U_UNDO LCTRL(KC_Z)
#endif

#define LPMOD MOD_LGUI
#define LRMOD MOD_LALT
#define LMMOD MOD_LSFT
#define LIMOD MOD_LCTL

#define RIMOD MOD_RCTL
#define RMMOD MOD_RSFT
#define RRMOD MOD_RALT
#define RPMOD MOD_RGUI

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_DVRK] = LAYOUT_split_3x5_3(
    KC_QUOT,           KC_COMM,           KC_DOT,            KC_P,              KC_Y,             /**/  KC_F,              KC_G,              KC_C,              KC_R,              KC_L,              
    MT(LPMOD,KC_A),    MT(LRMOD,KC_O),    MT(LMMOD,KC_E),    MT(LIMOD,KC_U),    KC_I,             /**/  KC_D,              MT(RIMOD,KC_H),    MT(RMMOD,KC_T),    MT(RRMOD,KC_N),    MT(RPMOD,KC_S),   
    KC_SCLN,           KC_Q,              KC_J,              KC_K,              KC_X,             /**/  KC_B,              KC_M,              KC_W,              KC_V,              KC_Z,              
                                          LT(_FNNV,KC_ESC),  LT(_NMSM,KC_TAB),  LT(_MDMS,__x__),  /**/  LT(_MDMS,__x__),   LT(_NMSM,KC_SPC),  LT(_FNNV,KC_ENT)                                        
),

[_NMSM] = LAYOUT_split_3x5_3( // Numbers + Symbols
    KC_PLUS, KC_7,    KC_8,    KC_9,    KC_PERC, /**/ KC_TILD, KC_LCBR, KC_CIRC, KC_PIPE, KC_RCBR, 
    KC_ASTR, KC_4,    KC_5,    KC_6,    KC_MINS, /**/ KC_HASH, KC_LPRN, KC_EQL,  KC_AMPR, KC_RPRN, 
    KC_0,    KC_1,    KC_2,    KC_3,    KC_SLSH, /**/ KC_GRV,  KC_LBRC, KC_AT,   KC_DLR,  KC_RBRC, 
                      KC_BSLS, KC_SLSH, __x__,   /**/ __x__,   KC_UNDS, KC_MINS                   
),
[_FNNV] = LAYOUT_split_3x5_3( // function + navigation
    KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, /**/ KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  
    KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_CAPS, /**/ KC_SCRL, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, 
    KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, /**/ _____,   _____,   KC_WH_D, KC_WH_U, _____,  
                      KC_EXLM, KC_QUES, __x__,   /**/ __x__,   KC_BSPC, KC_DEL                    
),

[_MDMS] = LAYOUT_split_3x5_3( // media-cp + mouse
    KC_VOLD, KC_MUTE, KC_MUTE, KC_VOLU, _____,   /**/ _____,   _____,   _____,   _____,   _____,   
    KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, _____,   /**/ _____,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, 
    U_UNDO,  U_CUT,   U_COPY,  U_PSTE,  U_REDO,  /**/ _____,   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, 
                      __x__,   __x__,   __x__,   /**/ __x__,   KC_BTN1, KC_BTN2                   
),

[_QWRT] = LAYOUT_split_3x5_3(
    KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,             /**/  KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,              
    MT(LPMOD,KC_A),    MT(LRMOD,KC_S),    MT(LMMOD,KC_D),    MT(LIMOD,KC_F),    KC_G,             /**/  KC_H,              MT(RIMOD,KC_J),    MT(RMMOD,KC_K),    MT(RRMOD,KC_L),    MT(RPMOD,KC_SCLN), 
    KC_Z,              KC_X,              KC_C,              KC_V,              KC_B,             /**/  KC_N,              KC_M,              KC_COMM,           KC_DOT,            KC_QUOT,           
                                          LT(_FNNV,KC_ESC),  LT(_NMSM,KC_TAB),  LT(_MDMS,__x__),  /**/  LT(_MDMS,__x__),   LT(_NMSM,KC_SPC),  LT(_FNNV,KC_ENT)                                        
),
};

#if 1
enum combos {
  COMBO_LEFT_THUMBS_AS_DEL,
  COMBO_TOGGLE_LAYOUT,
  COMBO_TEST,
  NUM_COMBOS
};

uint16_t COMBO_LEN = NUM_COMBOS;

const uint16_t PROGMEM del_combo[] = {LT(_FNNV,KC_ESC),  LT(_NMSM,KC_TAB), COMBO_END};
const uint16_t PROGMEM toggle_layout_combo[] = {KC_QUOT,  KC_L, KC_SCLN, KC_Z, COMBO_END};
const uint16_t PROGMEM test_combo[] = {KC_QUOT,  KC_L, COMBO_END};

combo_t key_combos[] = {
  [COMBO_LEFT_THUMBS_AS_DEL] = COMBO(del_combo, KC_DEL),
  [COMBO_TOGGLE_LAYOUT] = COMBO(toggle_layout_combo, TG(_QWRT)),
  [COMBO_TEST] = COMBO(test_combo, KC_C)
};
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
