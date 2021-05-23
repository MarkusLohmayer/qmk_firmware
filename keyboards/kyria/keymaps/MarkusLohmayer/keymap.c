#include QMK_KEYBOARD_H

enum layers {
  _B = 0,
  _L,
  _R,
  _0,
  _1
};

/* homerow mod */
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
#define _L_QUOT  LT(_L, KC_QUOT)

/* umlaute based on altgr-intl layout */
#define UM_AE    RALT(KC_Q)
#define UM_SS    RALT(KC_S)
#define UM_UE    RALT(KC_Y)
#define UM_OE    RALT(KC_P)
#define EURO     RALT(KC_5)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_B] = LAYOUT(
  KC_GRV  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    ,                                         KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_MINS ,
  _L_TAB  , GUI_A   , ALT_S   , CTL_D   , SFT_F   , _R_G    ,                                         _R_H    , SFT_J   , CTL_K   , ALT_L   , GUI_SCLN, _L_QUOT ,
  KC_LEAD , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , OSL(_0) , KC_LEFT , KC_RGHT , OSL(_1) , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , KC_BSLS ,
                                KC_NO   , TO(_L)  , KC_BSPC , KC_ESC  , KC_DOWN , KC_UP   , KC_ENT  , KC_SPC  , TO(_R)  , KC_MUTE
),
[_L] = LAYOUT(
  _______ , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,                                         KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_EQL  ,
  KC_CAPS , _______ , _______ , _______ , _______ , _______ ,                                         _______ , _______ , _______ , _______ , _______ , _______ ,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_LBRC , KC_RBRC , _______ , _______ ,
                                _______ , TO(_B)  , KC_DEL  , _______ , _______ , _______ , _______ , _______ , TO(_B)  , _______
),
[_R] = LAYOUT(
  _______ , _______ , _______ , _______ , _______ , _______ ,                                         _______ , KC_LBRC , KC_RBRC , KC_LPRN , KC_RPRN , _______ ,
  _______ , _______ , _______ , _______ , _______ , _______ ,                                         KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , _______ , _______ ,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_MS_L , KC_MS_D , KC_MS_U , KC_MS_R , _______ , _______ ,
                                _______ , TO(_B)  , _______ , _______ , KC_BRID , KC_BRIU , KC_BTN1 , KC_BTN3 , TO(_B)  , _______
),
[_0] = LAYOUT(
  _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   ,                                         KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , _______ ,
  _______ , _______ , _______ , _______ , _______ , _______ ,                                         _______ , _______ , _______ , KC_F11  , KC_F12  , _______ ,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_MPRV , KC_MNXT , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
                                _______ , _______ , _______ , _______ , KC_MPLY , KC_MSTP , _______ , _______ , _______ , _______
),
[_1] = LAYOUT(
  _______ , _______ , _______ , EURO    , _______ , _______ ,                                         _______ , UM_UE   , _______ , UM_OE   , _______ , _______ ,
  _______ , UM_AE   , UM_SS   , _______ , _______ , KC_LSFT ,                                         KC_RSFT , _______ , _______ , _______ , _______ , _______ ,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
                                _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______
),
};

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { // left encoder
    switch (get_highest_layer(layer_state)) {
      case _L:
        if (clockwise) {
          tap_code(KC_RBRC);
          tap_code(KC_C);
        } else {
          tap_code(KC_LBRC);
          tap_code(KC_C);
        }
        break;
      default:
        if (clockwise) {
          tap_code(KC_PGDN);
        } else {
          tap_code(KC_PGUP);
        }
        break;
    }
  }
  else if (index == 1) { // right encoder
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
  }
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_TWO_KEYS(KC_M, KC_L) {
      SEND_STRING("Markus Lohmayer");
    }

    SEQ_FOUR_KEYS(KC_C, KC_F, KC_A, KC_U) {
      SEND_STRING("markus.lohmayer@fau.de");
    }

    SEQ_THREE_KEYS(KC_C, KC_M, KC_L) {
      SEND_STRING("markus.lohmayer@gmail.de");
    }

    SEQ_TWO_KEYS(KC_C, KC_P) {
      SEND_STRING("+49 157 789 187 12");
    }

    SEQ_THREE_KEYS(KC_C, KC_M, KC_B) {
      SEND_STRING("Mirdelsberg 1\n84405 Dorfen\nGermany");
    }

    SEQ_THREE_KEYS(KC_MINS, KC_V, KC_G) {
      SEND_STRING("Viele Gr" SS_RALT("y") SS_RALT("s") "e,\nMarkus Lohmayer\n");
    }

    SEQ_THREE_KEYS(KC_MINS, KC_S, KC_G) {
      SEND_STRING("Sch" SS_RALT("p") "ne Gr" SS_RALT("y") SS_RALT("s") "e,\nMarkus Lohmayer\n");
    }

  }
}
