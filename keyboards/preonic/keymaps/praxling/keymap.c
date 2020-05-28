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
// #include "muse.h"

//** Custom keycodes **//
// Layer-switching //
#define L3_TAB LT(_NUMPAD, KC_TAB)
#define L4_SPACE LT(_MOUSEKEYS, KC_SPC)
#define TG_NUM TG(_NUMPAD)
#define LT_RAISE LT(_NUMRAISE, KC_0)

// Custom keys //
#define HYPER MO(_HYPER)
#define AGUI_R RGUI(RALT(KC_RIGHT))
#define AGUI_L RGUI(RALT(KC_LEFT))
#define GO_BCK RGUI(KC_LBRC)
#define GO_FWD RGUI(KC_RBRC)
#define UC_EMOJI RGUI(RCTL(KC_SPC))
#define CMD_SFT RGUI(KC_RSFT)
#define CMD_ALT RGUI(KC_RALT)
#define CMD_CTL RGUI(KC_RCTL)

//** Custom layers **//
enum preonic_layers {
  _DVORAK,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUMPAD,
  _HYPER,
  _MOUSEKEYS,
  _NUMRAISE
};

enum preonic_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  LOWER,
  RAISE,
  BACKLIT,
  OPT_CTL,

  // shortcuts
  UC_LOCK,
  UC_COPY,
  UC_PASTE,
  UC_CUT,
  UC_UNDO,
  UC_COMMENT,
  SLCT_ALL,
  UC_SAVE,
  UC_SAVEAS,
  UC_STRIKE,

  // mouse
  UC_SCRL_UP,
  UC_SCRL_DWN  
};

bool curr_os_is_mac = true;


//Tap Dance Declarations
enum tapdance_id {
    TD_SCLN = 0,
    TD_COMM,
    TD_DOT,
    TD_MINS,
    TD_QUOT,
};

 
// Start keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   ;  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   "  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  |  GUI | Hyp  |Lower |    Space    |Raise |GUIsft|GUIalt|GUIctl|Space |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_preonic_grid( \
  KC_GRV,         KC_1,           KC_2,        KC_3,        KC_4,        KC_5,       KC_6,     KC_7,         KC_8,         KC_9,         KC_0,         KC_DEL, \
  KC_ESC,         TD(TD_SCLN),    TD(TD_COMM), KC_DOT,      KC_P,        KC_Y,       KC_F,     KC_G,         KC_C,         KC_R,         KC_L,         KC_BSPC,  \
  L3_TAB,         LSFT_T(KC_A),   CTL_T(KC_O), ALT_T(KC_E), GUI_T(KC_U), KC_I,       KC_D,     GUI_T(KC_H),  ALT_T(KC_T),  CTL_T(KC_N),  SFT_T(KC_S),  TD(TD_MINS), \
  OSM(MOD_LSFT),  TD(TD_QUOT),    KC_Q,        KC_J,        KC_K,        KC_X,       KC_B,     KC_M,         KC_W,         KC_V,         KC_Z,         KC_SFTENT,  \
  KC_LCTL,        KC_LALT,        KC_LGUI,     HYPER,       LOWER,       L4_SPACE,   L4_SPACE, RAISE,        CMD_SFT,      CMD_ALT,      CMD_CTL,      KC_SPC  \
),


/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  |  GUI | Hyp  |Lower |    Space    |Raise |GUIsft|GUIalt|GUIctl|Space |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_GRV,         KC_1,         KC_2,         KC_3,         KC_4,         KC_5,       KC_6,     KC_7,         KC_8,         KC_9,         KC_0,         KC_DEL, \
  KC_ESC,         KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,       KC_Y,     KC_U,         KC_I,         KC_O,         KC_P,         KC_BSPC,  \
  L3_TAB,         LSFT_T(KC_A), CTL_T(KC_S),  ALT_T(KC_D),  GUI_T(KC_F),  KC_G,       KC_H,     GUI_T(KC_J),  ALT_T(KC_K),  CTL_T(KC_L),  TD(TD_SCLN),  TD(TD_QUOT), \
  OSM(MOD_LSFT),  KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,       KC_N,     KC_M,         TD(TD_COMM),  KC_DOT,       KC_SLSH,      KC_SFTENT,  \
  KC_LCTL,        KC_LALT,      KC_LGUI,      HYPER,        LOWER,        L4_SPACE,   L4_SPACE, RAISE,        CMD_SFT,      CMD_ALT,      CMD_CTL,      KC_SPC  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   %  |   &  |   #  |   ~  |      |   -  |   $  |   |  |   `  |      | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   [  |   {  |   (  |   =  |      |   +  |   ^  |   )  |   }  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Alt  |  F10 |  F11 |  F12 |  F13 |  F14 |  F15 |ISO ~ |ISO | |ISO # |ISO / |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,     KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_DEL, \
  KC_ESC,  KC_PERC, KC_AMPR, KC_HASH, KC_TILD, KC_NO,   KC_PMNS, KC_DLR,      KC_PIPE,    KC_GRV,     KC_NO,      KC_DEL,   \
  KC_TRNS, KC_LBRC, KC_LCBR, KC_LPRN, KC_EQL,  KC_NO,   KC_PPLS, KC_CIRC,     KC_RPRN,    KC_RCBR,    KC_RBRC,    KC_BSLS, \
  KC_LALT, KC_F10,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  S(KC_NUHS),  S(KC_NUBS), KC_NUHS,    KC_NUBS,    _______, \
  _______, _______, _______, _______, _______, _______, _______, _______,     KC_MNXT,    KC_VOLD,    KC_VOLU,    KC_MPLY \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | Save |SaveAs| Emoji|Strike| Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Capsl| Play |  Prv | Next |      |      | Gui+L| Gui+/|   @  |   !  |   ?  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Mute | Vol -| Vol +|      |      |TG_num| Copy | Paste|  Cut | Undo |SLCT_A|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid( \
  KC_GRV,  KC_1,      KC_2,     KC_3,     KC_4,    KC_5,    KC_6,    KC_7,       KC_8,       KC_9,        KC_0,         KC_DEL, \
  KC_TRNS, KC_F1,     KC_F2,    KC_F3,    KC_F4,   KC_F5,   KC_F6,   UC_SAVE,    UC_SAVEAS,  UC_EMOJI,    UC_STRIKE,    KC_BSPC,  \
  KC_CAPS, KC_MPLY,   KC_MRWD,  KC_MFFD,  KC_F4,   KC_NO,   UC_LOCK, UC_COMMENT, KC_AT,      KC_EXLM,     KC_QUES,      KC_PSLS, \
  _______, KC_MUTE,   KC_VOLD,  KC_VOLU,  KC_NO,   KC_NO,   TG_NUM,  UC_COPY,    UC_PASTE,   UC_CUT,      UC_UNDO,      SLCT_ALL, \
  _______, _______,   _______,  _______,  _______, _______, _______, XXXXXXX,    KC_MNXT,    KC_VOLD,     KC_VOLU,      KC_MPLY  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |Dvorak|Qwerty|      |      |      |      |      |      |      |      | Debug|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Reset|      |      |      |      |      |      |      |      |      |TMNL 1|TMNL 0|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |LCGswp|LCGnrm|      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid( \
  XXXXXXX, DVORAK,  QWERTY,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  DEBUG,  \
  RESET,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  TERM_ON,  TERM_OFF,  \
  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  LCG_SWP,  LCG_NRM,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX  \
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      | Close| Esc  |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   :  |   ,  |      |      |      |   -  |   7  |   8  |   9  |   /  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |Shift | Ctrl |  Alt | Gui  |      |   +  |   4  |   5  |   6  |   *  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |   .  |   1  |   2  |   3  |   =  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Dvorak|             |Raise0|GUIsft|GUIalt|GUIctl|Space |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_preonic_grid( \
  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      RGUI(KC_R),     RGUI(KC_W),     KC_ESC,         KC_DEL,  \
  KC_ESC,   KC_COLN, KC_COMM, XXXXXXX, XXXXXXX, XXXXXXX, KC_PMNS, KC_7,         KC_8,           KC_9,           KC_PSLS,        KC_BSPC, \
  _______,  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, KC_PPLS, GUI_T(KC_4),  ALT_T(KC_5),    CTL_T(KC_6),    SFT_T(KC_PAST), _______, \
  _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DOT,  KC_1,         KC_2,           KC_3,           KC_PEQL,        KC_ENT,  \
  _______,  _______, _______, _______, TG_NUM,  _______, _______, LT_RAISE,     CMD_SFT,        CMD_ALT,        CMD_CTL,        KC_SPC  \
),


/* Raise layer for numpad
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Save |SaveAs| Emoji|Strike|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |TG_num| Copy | Paste|  Cut | Undo |SLCT_A|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMRAISE] = LAYOUT_preonic_grid( \
  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    UC_SAVE,    UC_SAVEAS,  UC_EMOJI,   UC_STRIKE,  XXXXXXX,  \
  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  TG_NUM,     UC_COPY,    UC_PASTE,   UC_CUT,     UC_UNDO,    SLCT_ALL, \
  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX  \
),

/* Mousekeys
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |MouseL|MouseD|MouseU|MouseR| Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |      |ScrlDn|ScrlUp|Mouse1|Mouse2|      | Home | End  |      |      | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |Shift | Ctrl |  Alt | Gui  |      |      | Left | Down |  Up  | Right| Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Left | Right| Back | Fwd  | Ent  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSEKEYS] = LAYOUT_preonic_grid( \
  _______,  _______, _______,       _______,      _______, _______,  _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,   KC_DEL,  \
  KC_ESC,   _______, UC_SCRL_DWN,   UC_SCRL_UP,   KC_BTN1, KC_BTN2,  _______, KC_HOME, KC_END,  _______,  _______,  KC_BSPC, \
  _______,  KC_LSFT, KC_LCTL,       OPT_CTL,      KC_LGUI, _______,  _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,  KC_DEL, \
  _______, _______, _______,        _______,      _______, _______,  _______, AGUI_L,  AGUI_R , GO_BCK,  GO_FWD,    KC_ENT,  \
  _______, _______, _______,        _______,      _______, _______,  _______, _______, _______, _______, _______, _______   \
),

/* Hyper layer (for switching virtual desktops)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |      |      |      |      |      |      |      |      |      |      | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_HYPER] = LAYOUT_preonic_grid( \
  _______,  _______,     _______,      _______,      _______,      _______,      _______,      _______,      HYPR(KC_LEFT), HYPR(KC_RIGHT), _______,        KC_DEL,  \
  KC_ESC,   _______,     _______,      _______,      _______,      _______,      _______,      _______,      _______,       _______,        _______,        KC_BSPC, \
  _______,  HYPR(KC_P1), HYPR(KC_P2),  HYPR(KC_P3),  HYPR(KC_P4),  HYPR(KC_P5),  HYPR(KC_P6),  HYPR(KC_P7),  HYPR(KC_P8),   HYPR(KC_P9),    HYPR(KC_P0),    _______, \
  _______,  _______,     _______,      _______,      _______,      _______,      _______,      _______,      _______,       _______,        _______,        _______,  \
  _______,  _______,     _______,      _______,      _______,      _______,      _______,      _______,      _______,       _______,        _______,        _______   \
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Layers
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;

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

    case LCG_SWP:
    case LCG_NRM:
      if (record->event.pressed) {
        curr_os_is_mac = keymap_config.swap_lctl_lgui;
      }
      break;

    // Keeb shortcuts
    case UC_LOCK:
      if (record->event.pressed) {
        if (curr_os_is_mac) {
          SEND_STRING(SS_LCTRL(SS_LGUI("q")));
        } else {
          SEND_STRING(SS_LGUI("l"));
        }
      }
      return false;
      break;      

    case UC_COPY:
      if (record->event.pressed) {
        register_mods(mod_config(MOD_BIT(KC_LGUI)));
        tap_code(KC_C);
        unregister_mods(mod_config(MOD_BIT(KC_LGUI)));
      }
      return false;
      break;

    case UC_PASTE:
      if (record->event.pressed) {
        register_mods(mod_config(MOD_BIT(KC_LGUI)));
        tap_code(KC_V);
        unregister_mods(mod_config(MOD_BIT(KC_LGUI)));
      }
      return false;
      break;

    case UC_CUT:
      if (record->event.pressed) {
        register_mods(mod_config(MOD_BIT(KC_LGUI)));
        tap_code(KC_X);
        unregister_mods(mod_config(MOD_BIT(KC_LGUI)));
      }
      return false;
      break;

    case UC_UNDO:
      if (record->event.pressed) {
        register_mods(mod_config(MOD_BIT(KC_LGUI)));
        tap_code(KC_Z);
        unregister_mods(mod_config(MOD_BIT(KC_LGUI)));
      }
      return false;
      break;

    case UC_COMMENT:
      if (record->event.pressed) {
        register_mods(mod_config(MOD_BIT(KC_LGUI)));
        tap_code(KC_PSLS);
        unregister_mods(mod_config(MOD_BIT(KC_LGUI)));
      }
      return false;
      break; 

    case SLCT_ALL:
      if (record->event.pressed) {
        register_mods(mod_config(MOD_BIT(KC_LGUI)));
        tap_code(KC_A);
        unregister_mods(mod_config(MOD_BIT(KC_LGUI)));
      }
      return false;
      break;

    case UC_SAVE:
      if (record->event.pressed) {
        register_mods(mod_config(MOD_BIT(KC_LGUI)));
        tap_code(KC_S);
        unregister_mods(mod_config(MOD_BIT(KC_LGUI)));
      }
      return false;
      break;  

    case UC_SAVEAS:
      if (record->event.pressed) {
        register_mods(mod_config(MOD_BIT(KC_LGUI)));
        register_code(KC_LSFT);
        tap_code(KC_S);
        unregister_code(KC_LSFT);
        unregister_mods(mod_config(MOD_BIT(KC_LGUI)));
      }
      return false;
      break; 

    case UC_STRIKE:
      if (record->event.pressed) {
        register_mods(mod_config(MOD_BIT(KC_LGUI)));
        register_code(KC_LSFT);
        tap_code(KC_X);
        unregister_code(KC_LSFT);
        unregister_mods(mod_config(MOD_BIT(KC_LGUI)));
      }
      return false;
      break; 

// Mouse navigation
    case UC_SCRL_UP:
      if (record->event.pressed) {
        if (curr_os_is_mac) {
          register_code(KC_WH_D);
        } else {
          register_code(KC_WH_U);
        }
      } else {
        if (curr_os_is_mac) {
          unregister_code(KC_WH_D);
        } else {
          unregister_code(KC_WH_U);
        }            
      }
      return false;
      break;

    case UC_SCRL_DWN:
      if (record->event.pressed) {
        if (curr_os_is_mac) {
          register_code(KC_WH_U);
        } else {
          register_code(KC_WH_D);
        }
      } else {
        if (curr_os_is_mac) {
          unregister_code(KC_WH_U);
        } else {
          unregister_code(KC_WH_D);
        }            
      }
      return false;
      break;

    case OPT_CTL:
      if (record->event.pressed) {
        if (curr_os_is_mac) {
          register_code(KC_LALT);
        } else {
          register_code(KC_LCTL);
        }
      } else {
        if (curr_os_is_mac) {
          unregister_code(KC_LALT);
        } else {
          unregister_code(KC_LCTL);
        }            
      }
      return false;
      break;
    }
  return true;
};



//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {

  //Tap once for semicolon, twice for colon
  [TD_SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),

  //Tap once for comma, twice for <
  [TD_COMM] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_LT),

  //Tap once for period, twice for >
  [TD_DOT] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_GT),

  //Tap once for hyphen/minuse, twice for underscore
  [TD_MINS] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_UNDS),

  //Tap once for single quote, twice for double quote
  [TD_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),

};
