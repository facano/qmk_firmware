#include QMK_KEYBOARD_H

#include "quantum.h"
#include "keymap_us_international.h"

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes{
  TD_ENHE,
  TD_LSHT_CLOCK,
  _ENHE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT( \
  KC_ESC,            KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,        KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL, \
  KC_TAB,            KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,        KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
  KC_LCTRL,          KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,        KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  TD(TD_LSHT_CLOCK), KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  TD(TD_ENHE), KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_GRV, \
                        KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC,  KC_ENT, MO(_RAISE), KC_BSPC, KC_RALT \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |Pg Up | Home |  Up  | End  |Insert|      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|Pg Dn | Left | Down | Right|      |      |
 * |------+------+------+------+------+------|   (   |    |    )  |------+------+------+------+------+------|
 * |KC_CAPS|  ¡  |  ¿  |      |      |      |-------|    |-------|  Ñ  |   _  |   +  |      |   |   |   ´  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,        KC_F4,     KC_F5,   KC_F6,                       KC_F7,     KC_F8,   KC_F9,   KC_F10,  KC_F11,     KC_F12, \
  _______, _______, _______,      _______,   _______, _______,                     KC_PGUP,   KC_HOME, KC_UP,   KC_END,  KC_INSERT,  _______,\
  KC_GRV,  KC_EXLM, KC_AT,        KC_HASH,   KC_DLR,  KC_PERC,                     KC_PGDOWN, KC_LEFT, KC_DOWN, KC_RGHT, KC_RPRN,    KC_TILD, \
  KC_CAPS, US_IEXL, LSA(KC_SLSH), _______,   _______, _______,  KC_LPRN, KC_RPRN,  _ENHE,     KC_UNDS, KC_PLUS, _______, KC_PIPE,    ALGR(KC_E), \
                                  _______,   _______, _______,  _______, _______,  _______, _______, _______\
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |  8   |   9  |   0  |Numlock|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |Pg Up | Home |  Up  | End  |Insert|      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|Pg Dn | Left | Down | Right|     |  °   |
 * |------+------+------+------+------+------|   <   |    |    >  |------+------+------+------+------+------|
 * |RShift|  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   *  |  \  |  %   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE | DEL  | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT( \
  _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_4, KC_KP_5,                     KC_KP_6,   KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0,   KC_NLCK,\
  _______, _______, _______, _______, _______, _______,                     KC_PGUP,   KC_HOME, KC_UP,   KC_END,  KC_INSERT, _______, \
  KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_PGDOWN, KC_LEFT, KC_DOWN, KC_RGHT, _______,   LSA(KC_8), \
  KC_RSFT, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_LT,     KC_GT,  KC_PLUS,  KC_MINS,  KC_EQL,  KC_ASTR, KC_BSLS,   KC_PERC, \
                             _______, _______, _______,  _______, _______,  _______,  KC_DEL, _______ \
),
/* ADJUST
 * reference of media keys from https://github.com/qmk/qmk_firmware/blob/master/keyboards/minidox/keymaps/dustypomerleau/keymap.c#L141,L157

 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Reset | Debug|      |      |      |      |                    |      |      |      |      |      | Power|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |  B-  | Vol+ |  B+  |      | Sleep|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      | Prev | Vol- | Next |      | Wake |
 * |------+------+------+------+------+------|Play/Pause| | Stop  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |  Mute |     |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT( \
  RESET,   DEBUG,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_POWER, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_BRID, KC_VOLU, KC_BRIU, XXXXXXX, KC_SLEP, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_MPRV, KC_VOLD, KC_MNXT, XXXXXXX, KC_WAKE, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, KC_MSTP, XXXXXXX, XXXXXXX, KC__MUTE, XXXXXXX, XXXXXXX, XXXXXXX,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  )
};

// Works with ABC extended layout in OSX
void td_enhe(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    tap_code(KC_N);
    break;
  case 2:
    add_mods(MOD_MASK_ALT);
    register_code(US_N);
    del_mods(MOD_MASK_ALT);

    tap_code(KC_N);

    break;
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    // Works with ABC extended layout in OSX
    [TD_ENHE] = ACTION_TAP_DANCE_FN(td_enhe),

    // Tap once for Esc, twice for Caps Lock
    [TD_LSHT_CLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    // Other declarations would go here, separated by commas, if you have them
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    #ifdef OLED_DRIVER_ENABLE
      set_keylog(keycode, record);
    #endif
    // set_timelog();
  }

  // Works with ABC extended layout in OSX
  switch (keycode) {
    case _ENHE:
      if (record->event.pressed) {
        add_mods(MOD_MASK_ALT);
        register_code(US_N);
        del_mods(MOD_MASK_ALT);

        tap_code(KC_N);
      }
      break;
     }
  return true;
}
