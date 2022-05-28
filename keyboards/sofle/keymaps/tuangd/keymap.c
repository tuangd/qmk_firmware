#include QMK_KEYBOARD_H




enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _DVORAK,
    _FUNC,
    _MOUSE,
    _QWRTY,
    _ARROW,
};

/* enum custom_keycodes {
   
}; */
// Tap Dance declarations
enum {
    TD_5_ESC,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for 5, twice for ESC
    [TD_5_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_ESC),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * DVORAK 0
 * As I set my Windows to use dvorak layout the keymap here actually is a normal qwerty layout. (so the Windows knows how to change it to Dvorak)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |5(ESC)|                    |   6  |   7  |   8  |   9  |   0  | BSpc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Enter|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |F13   |   A  |   S  |   D  |LT4,F |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|PrnScrn|    |  TG3  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LGUI | LALT |Space | /DEL    /       \ TG2  \  |LT2, ]|   -  | =    | [    |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_DVORAK] = LAYOUT(
  KC_F14,   KC_1,   KC_2,    KC_3,    KC_4,TD(TD_5_ESC),                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_ENT,
  KC_F13,   KC_A,   KC_S,    KC_D,LT(_ARROW,KC_F),  KC_G,                KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_PSCR,      TG(_QWRTY), KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
	        KC_LCTRL, KC_LGUI, KC_LALT,  KC_SPC, LT(_FUNC,KC_DEL), TT(_FUNC),LT(_MOUSE,KC_RBRC), KC_MINS, KC_EQL, KC_LBRC 
),
/* _FUNC (1)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |   F7 |   F8 |  F9  |  F10 |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   _  |   +  |   {  |                    | NumL |   N7 |   N8 |  N9  |   N* |  F11 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   #  |   $  |   (  |   )  |   `  |-------.    ,-------|   \  |   N4 |   N5 |  N6  |   N+ |   N- |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   %  |   ^  |   -  |   =  |   ~  |-------|    |-------|   &  |   N1 |   N2 |  N3  |  N/  |  F12 |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      | N.   |  N0  |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_FUNC] = LAYOUT(
  _______, KC_F1,  KC_F2,   KC_F3,   KC_F4, KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
  _______, KC_EXLM,KC_AT, KC_UNDS, KC_PLUS, KC_LCBR,                   KC_NLCK,   KC_P7,   KC_P8,   KC_P9, KC_PAST,  KC_F11,
  _______, KC_HASH,KC_DLR,KC_LPRN, KC_RPRN, KC_GRV,                    KC_BSLS,   KC_P4,   KC_P5,   KC_P6, KC_PPLS, KC_PMNS,
  _______, KC_PERC,KC_CIRC,KC_MINS, KC_EQL, KC_TILD, _______,  _______,KC_AMPR,   KC_P1,   KC_P2,   KC_P3, KC_PSLS,  KC_F12,
                 _______,_______,_______,_______, _______,      _______,_______,  KC_P0, KC_PDOT,  _______
),

/* Mouse 2
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | M-L  | M-UP | M-R  |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | M-DWN|      |      |      |-------.    ,-------|      |M-BTN1|M-BTN2|M-BTN3|      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |WHL-U |WHL-D |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_MOUSE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                          _______,  _______, _______,  _______,  _______,_______,
  _______, _______, _______, KC_MS_U, _______, _______,                          _______,  _______, _______,  _______,  _______,_______,
  _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,                          _______,  KC_BTN1, KC_BTN2,  KC_BTN3,  _______,_______,
  _______, _______, _______, _______, _______, _______,  _______,      _______,  _______,  KC_WH_U, KC_WH_D,  _______,  _______,_______,
                    _______, _______, _______,  _______, _______,      _______, _______,   _______, _______, _______
),

/*
 * DVORAK to QWERTY 3
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   X  |   ,  |   D  |   O  |   K  |                    |   T  |   F  |   G  |   S  |   R  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   A  |   ;  |   H  |   Y  |   U  |-------.    ,-------|   J  |   C  |   V  |   P  |   Z  |   Q  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   /  |   B  |   I  |   .  |   N  |-------|    |-------|   L  |   M  |   W  |   E  |   [  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |  '   |   ]  |  -   |  =   |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_QWRTY] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
  _______,    KC_X, KC_COMM,    KC_D,    KC_O,    KC_K,                       KC_T,    KC_F,    KC_G,    KC_S,    KC_R, _______,
  _______,    KC_A, KC_SCLN,    KC_H,    KC_Y,    KC_U,                       KC_J,    KC_C,    KC_V,    KC_P,    KC_Z,    KC_Q,
  _______, KC_SLSH,    KC_B,    KC_I,  KC_DOT,    KC_N, _______,  _______,    KC_L,    KC_M,    KC_W,    KC_E, KC_LBRC, _______,
                    _______, _______, _______, _______, _______,  _______, KC_QUOT, KC_RBRC, KC_MINS,  KC_EQL
),

/* VIM ARROW 4
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |Ctrl-L|HOME  |END   |CTRL-R|      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|Arr-L |Arr-D |Arr-U |Arr-R |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|C+S+L |      |      |C+S+R |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ARROW] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                         _______,  _______ , _______,     _______ ,  _______ ,_______,
  _______, _______ , _______ , _______ , _______ , _______,                      C(KC_LEFT),  KC_HOME ,  KC_END,   C(KC_RGHT),  _______ ,_______,
  _______, _______ , _______ , _______ , _______ , _______,                         KC_LEFT,   KC_DOWN,   KC_UP,      KC_RGHT,  _______ ,_______,
  _______, _______ , _______ , _______ , _______ , _______,_______,   _______, RCS(KC_LEFT),   _______, _______, RCS(KC_RGHT),  _______ ,_______,
                    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
  )
};

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR("----"), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _DVORAK:
            oled_write_ln_P(PSTR("DVRK"), false);
            break;
        case _QWRTY:
            oled_write_ln_P(PSTR("QWRTY"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_ln_P(PSTR("----"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _DVORAK:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _FUNC:
            oled_write_P(PSTR("Num\n"), false);
            break;
		case _QWRTY:
			oled_write_P(PSTR("QWRTY") , false);
			break;
        case _MOUSE:
            oled_write_P(PSTR("Mouse"), false);
            break;
        case _ARROW:
            oled_write_P(PSTR("Arrow"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_ln_P(PSTR("----"), false);
    led_t led_usb_state = host_keyboard_led_state();
    //// oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
	oled_write_ln_P(led_usb_state.num_lock ? PSTR("NUMLK ") : PSTR("    "), false);
	oled_write_ln_P(led_usb_state.caps_lock ? PSTR("CAPLK ") : PSTR("    "), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif


#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGUP);
        } else {
            tap_code(KC_PGDN);
        }
    }
    return true;
}

#endif



