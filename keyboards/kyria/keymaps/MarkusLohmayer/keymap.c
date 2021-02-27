#include QMK_KEYBOARD_H

#define _L_TAB   LT(_L, KC_TAB)
#define GUI_A    LGUI_T(KC_A)
#define ALT_S    LALT_T(KC_S)
#define CTL_D    LCTL_T(KC_D)
#define SFT_F    LSFT_T(KC_F)
#define _R_G     LT(_R, KC_G)

#define _R_H     LT(_R, KC_H)
#define SFT_J    RSFT_T(KC_J)
#define CTL_K    RCTL_T(KC_K)
#define ALT_L    LALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)
#define _L_ENT   LT(_L, KC_ENT)

enum layers {
  _B = 0,
  _L,
  _R,
  _A
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_B] = LAYOUT(
  KC_ESC  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    ,                                         KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_BSPC ,
  _L_TAB  , GUI_A   , ALT_S   , CTL_D   , SFT_F   , _R_G    ,                                         _R_H    , SFT_J   , CTL_K   , ALT_L   , GUI_SCLN, _L_ENT  ,
  KC_NO   , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , TT(_A)  , KC_LEFT , KC_RGHT , KC_NO   , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_UP   ,
                                KC_LEAD , KC_NO   , KC_SPC  , TT(_R)  , KC_DOWN , KC_UP   , TT(_L)  , KC_SPC  , KC_NO   , KC_MUTE
),
[_L] = LAYOUT(
  KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,                                         KC_6    , KC_7,     KC_8    , KC_9    , KC_0    , KC_DEL  ,
  KC_CAPS , _______ , _______ , _______ , _______ , _______ ,                                         KC_LBRC , KC_RBRC , KC_BSLS , KC_QUOT , _______ , _______ ,
  KC_RALT , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_MINS , KC_EQUAL, _______ , _______ , _______ , KC_VOLU ,
                                _______ , KC_RCTL , _______ , _______ , _______ , _______ , _______ , KC_VOLD , KC_RGUI , _______
),
[_R] = LAYOUT(
  _______ , _______ , _______ , _______ , _______ , _______ ,                                         _______ , KC_LBRC , KC_RBRC , KC_LPRN , KC_RPRN , _______ ,
  _______ , _______ , _______ , _______ , _______ , _______ ,                                         KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , _______ , _______ ,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_MS_L , KC_MS_D , KC_MS_U , KC_MS_R , _______ , _______ ,
                                _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
),
[_A] = LAYOUT(
  _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   ,                                         KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , _______ ,
  _______ , _______ , _______ , _______ , _______ , _______ ,                                         _______ , _______ , _______ , KC_F11  , KC_F12  , _______ ,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
                                _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
),
};

/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*     return update_tri_layer_state(state, _L, _R, _A); */
/* } */

void encoder_update_user(uint8_t index, bool direction) {
    if (index == 0) { // left encoder
        if (direction) {
            tap_code(KC_PGUP);
        } else {
            tap_code(KC_PGDN);
        }
    }
    else if (index == 1) { // right encoder
        if (direction) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
}
