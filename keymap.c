#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _CAPS 3
#define _ADJUST 16
#define _LOWERCAPS 17

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  CAPS,
  ADJUST,
  LOWERCAPS,
  CTRL,
};

// Tap danceの設定
enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
};

enum {
  COLN,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [COLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN)
};

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |   [  |                    |   ]  |   6  |   7  |   8  |   9  |   0  |Pscree|
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  `   |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |  Del |                    | Bksp |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | Space|                    | Enter|   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space|  Del |||||||| Bksp | Enter| Raise|||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( 
 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
 KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_LCBR , KC_RCBR, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS, \
 KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_LBRC, KC_RBRC, KC_H, KC_J, KC_K, KC_L, TD(COLN), KC_QUOT, \
 KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, TO(_LOWER) , TO(_RAISE) , KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_EQL, \
 KC_LCTL, KC_LGUI, KC_LALT,  KC_LALT, CTL_T(KC_F13),LT(_LOWER,KC_SPC),  KC_SPC, KC_ENT,LT(_RAISE,KC_ENT), SFT_T(KC_F14), KC_LALT, KC_GRV, KC_BSLS, KC_DEL \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |   }  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  ~   |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   1  |   2  |   3  |   4  |   5  |  Del |                    | Bksp |   H  |   J  |   K  |   L  |   :  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  | Space|                    | Enter|   N  |   M  |   <  |   >  |   ?  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space|  Del |||||||| Bksp | Enter| Raise|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------. 
   */
  [_LOWER] = LAYOUT(
    XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                        XXXXXXX , XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
  	XXXXXXX, XXXXXXX,XXXXXXX, LSFT(KC_UP),  XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX,  XXXXXXX, LCTL(KC_LEFT), KC_UP, LCTL(KC_RIGHT), XXXXXXX, XXXXXXX,\
    XXXXXXX, XXXXXXX, LSFT(KC_LEFT), LSFT(KC_DOWN), LSFT(KC_RIGHT), KC_ESC, XXXXXXX, XXXXXXX, KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,\
    _______, LGUI(KC_S),XXXXXXX, KC_DEL, XXXXXXX, XXXXXXX,    XXXXXXX ,                        XXXXXXX, KC_TAB, KC_ENT, KC_HOME, KC_END,XXXXXXX,XXXXXXX,  \
   _______, _______, _______,     _______,_______,LOWER,  _______,           TO(_QWERTY), RAISE,_______, _______, _______, _______,   _______  \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |   }  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  ~   |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   1  |   2  |   3  |   4  |   5  |  Del |                    | Bksp |   H  |   J  |   K  |   L  |   :  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  | Space|                    | Enter|   N  |   M  |   <  |   >  |   ?  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space|  Del |||||||| Bksp | Enter| Raise|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
     XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                        XXXXXXX , XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, TO(_QWERTY),                        XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, \
    _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX ,                        XXXXXXX, KC_6,   KC_7,   KC_8,   KC_9,   KC_0,    KC_DQT,   \
    _______,   KC_LCBR, KC_RCBR, KC_LBRC,   KC_RBRC, KC_SCLN, TO(_LOWER) ,TO(_RAISE) , KC_PIPE,   KC_BSLS,   KC_LT,   KC_GT,   KC_QUES,  KC_PLUS, \
    _______, _______, _______,     _______,_______,LOWER,  _______,           TO(_QWERTY), RAISE,_______, _______, KC_TILD, KC_PIPE, _______    \
  ),


  [_CAPS] = LAYOUT(
   XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                        XXXXXXX , XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
 	  _______, XXXXXXX  ,XXXXXXX, KC_MS_UP, XXXXXXX,XXXXXXX, _______,                        TO(_QWERTY),  XXXXXXX, XXXXXXX, KC_UP, XXXXXXX,   XXXXXXX,XXXXXXX,\
    _______,LCTL(LSFT(KC_TAB)), KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT , LCTL(KC_TAB) ,_______,                        _______,  LCTL(KC_LEFT), KC_LEFT, KC_DOWN,   KC_RGHT, LCTL(KC_RGHT), KC_PGUP,\
    _______,  KC_MS_BTN4,    KC_MS_BTN1,    KC_MS_BTN3,    KC_MS_BTN2,    KC_MS_BTN5,_______,                     _______,  LALT(KC_LEFT), KC_HOME, XXXXXXX, KC_END,   LALT(KC_RGHT),KC_PGDN, \
  	XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX  ,XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX  \
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      | BL ON|  BRTG|  INC|   DEC|      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                        XXXXXXX , XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
  	KC_CAPS, XXXXXXX,XXXXXXX,    KC_MS_WH_UP,  XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, LGUI(KC_T),LGUI(LCTL(KC_F4)),    LGUI(KC_TAB),  LGUI(LCTL(KC_D)),XXXXXXX,XXXXXXX,\
    KC_PSCREEN, XXXXXXX, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_RIGHT,    XXXXXXX,    XXXXXXX,                        XXXXXXX, XXXXXXX, LGUI(LCTL(KC_LEFT)),    LGUI(KC_D),    LGUI(LCTL(KC_RGHT)),  XXXXXXX, XXXXXXX,\
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,XXXXXXX,                       XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12, \
  	XXXXXXX, KC_APP, XXXXXXX,   XXXXXXX, XXXXXXX  ,XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX  \
  ),
	
	  [_LOWERCAPS] = LAYOUT(
    XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                        XXXXXXX , XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
  	_______, _______,KC_7,    KC_8,  KC_9, KC_PLUS, _______,                       _______,  LALT(KC_LEFT), LCTL(KC_PGUP), LCTL(KC_PGDN), LALT(KC_RGHT), KC_ESC,KC_DEL,\
    _______, _______, KC_4,    KC_5,    KC_6,   KC_ENT,    _______,                        _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  KC_TAB, KC_ENT,\
    _______, _______,    KC_1,    KC_2,    KC_3,    KC_ENT,    _______ ,                        _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,_______,KC_BSPC,  \
    _______, _______, _______,     _______,LOWER,_______, _______,          _______, _______,RAISE, _______, _______, _______,   _______  \
  )


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// static bool ctrl_pressed = false;
// static uint16_t ctrl_pressed_time = 0;
// static bool raise_pressed = false;
// static uint16_t raise_pressed_time = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  #ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
    uprintf("ctrl %d\n", ctrl_pressed);
  #endif 
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        // update_tri_layer(_LOWER, _CAPS, _LOWERCAPS);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        // update_tri_layer(_LOWER, _CAPS, _LOWERCAPS);
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
      // if (record->event.pressed) {
      //   raise_pressed = true;
      //   raise_pressed_time = record->event.time;
      //   if (ctrl_pressed) {
      //     layer_on(_ADJUST);
      //   } else {
      //     layer_on(_RAISE);
      //   }
      // } else {
      //   layer_off(_RAISE);
      //   layer_off(_ADJUST);
      //   if (ctrl_pressed) {
      //     register_code(KC_LCTL);
      //   }
      //   if (raise_pressed && (TIMER_DIFF_16(record->event.time, raise_pressed_time) < TAPPING_TERM)) {
      //     register_code(KC_ENT);
      //     unregister_code(KC_ENT);
      //   }
      //   raise_pressed = false;
      // }
      return false;
      break;
    case CAPS:
      if (record->event.pressed) {
        layer_on(_CAPS);
        update_tri_layer(_LOWER, _CAPS, _LOWERCAPS);
      } else {
        layer_off(_CAPS);
        update_tri_layer(_LOWER, _CAPS, _LOWERCAPS);
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
    case LOWERCAPS:
      if (record->event.pressed) {
        layer_on(_LOWERCAPS);
      } else {
        layer_off(_LOWERCAPS);
      }
      return false;
      break;
    // case CTRL:
    //   if (record->event.pressed) {
    //     ctrl_pressed = true;
    //     ctrl_pressed_time = record->event.time;
    //     if (raise_pressed) {
    //       layer_on(_ADJUST);
    //     } else {
    //       register_code(KC_LCTL);
    //     }
    //   } else {
    //     layer_off(_ADJUST);
    //     unregister_code(KC_LCTL);
    //     if (raise_pressed) {
    //       layer_on(_RAISE);
    //     }
    //     if (ctrl_pressed && (TIMER_DIFF_16(record->event.time, ctrl_pressed_time) < TAPPING_TERM)) {
    //       register_code(KC_SPC);
    //       unregister_code(KC_SPC);
    //     }
    //     ctrl_pressed = false;
    //   }
    //   return false;
    //   break;
  }
  return true;
}

void keyboard_post_init_user(void) {
  #ifdef CONSOLE_ENABLE
  // Customise these values to desired behaviour
  debug_enable=true;
  // debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
  #endif 
}