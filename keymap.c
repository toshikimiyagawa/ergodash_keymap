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
 KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_DEL, KC_ESC, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS, \
 KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_BSPC, KC_TAB, KC_H, KC_J, KC_K, KC_L, KC_COLN, KC_QUOT, \
 KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, TO(_LOWER) , TO(_RAISE) , KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSPC, \
 KC_LGUI, KC_DEL, KC_LALT, KC_LALT ,CTL_T(KC_F13), LT(_LOWER,KC_SPC), KC_SPC, KC_ENT,LT(_RAISE, KC_ENT),SFT_T(KC_F14), KC_LALT, KC_GRV, KC_BSLS, KC_DEL \
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
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX,                        XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, \
    _______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX ,                        XXXXXXX, KC_6,   KC_7,   KC_8,   KC_9,   KC_0,    KC_DQT,   \
    _______,   KC_BSLS, KC_PLUS, KC_EQL,   KC_LCBR, KC_RCBR, TO(_LOWER) ,TO(_RAISE) , KC_LBRC,   KC_RBRC,   KC_LT,   KC_GT,   KC_QUES,  _______, \
    _______, _______, _______,     _______,_______,LOWER,  TO(_QWERTY),           TO(_QWERTY), RAISE,_______, _______, KC_TILD, KC_PIPE, _______    \
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
 	  _______, XXXXXXX  ,XXXXXXX, KC_MS_UP, XXXXXXX,XXXXXXX, _______,                        _______,  XXXXXXX, XXXXXXX, KC_UP, XXXXXXX,   XXXXXXX,XXXXXXX,\
    _______,LCTL(LSFT(KC_TAB)), KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT , LCTL(KC_TAB) ,_______,                        _______,  KC_HOME, KC_LEFT, KC_DOWN,   KC_RGHT, KC_END, KC_PGUP,\
    _______,  KC_MS_BTN4,    KC_MS_BTN1,    KC_MS_BTN3,    KC_MS_BTN2,    KC_MS_BTN5,_______,                     _______,  LALT(KC_LEFT), LCTL(KC_LEFT), XXXXXXX, LCTL(KC_RGHT),   LALT(KC_RGHT),KC_PGDN, \
   _______, _______, _______,     _______,_______,LOWER,  TO(_QWERTY),           TO(_QWERTY), RAISE,_______, _______, _______, _______,   _______  \
  ),


  [_CAPS] = LAYOUT(
    XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                        XXXXXXX , XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, \
  	XXXXXXX, LCTL(KC_Q),LCTL(KC_W),    KC_END,  LCTL(KC_R), LCTL(KC_T), _______,                       _______,  LCTL(KC_Y), LCTL(KC_U), KC_TAB, LCTL(KC_O), KC_UP,XXXXXXX,\
    XXXXXXX, KC_HOME, LCTL(KC_S),    KC_DEL,    KC_RGHT,   KC_ESC,    _______,                        _______, KC_BSPC, LCTL(KC_J), LCTL(KC_K),   LCTL(KC_L), LALT(KC_RGHT) , XXXXXXX,\
    XXXXXXX, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V),    KC_LEFT,    XXXXXXX ,                        XXXXXXX, KC_DOWN, KC_ENT, XXXXXXX, XXXXXXX,XXXXXXX,XXXXXXX,  \
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
        update_tri_layer(_LOWER, _CAPS, _LOWERCAPS);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
        update_tri_layer(_LOWER, _CAPS, _LOWERCAPS);
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
  }
  return true;
}
