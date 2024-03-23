#include QMK_KEYBOARD_H

float song_sonic_ring[][2] = SONG(SONIC_RING);

enum layers {
    _BASE = 0,
    _NUM,
    _NAV,
    _SYM,
    _MOUSE,
    _FN,
    _MEDIA,

};

enum custom_keycodes {
  UPDIR = SAFE_RANGE,
  ELIXIR_PIPE,
  OS_SWITCH,
  SALL,
  COPY,
  PASTE,
  CUT,
  UNDO,
  REDO
};

enum tap_dance {
  TD_VIM_LS = 0
};

enum combos {
  COMMADOT_SEMICOLON = 0
};

const uint16_t PROGMEM commadot_semicolon[]    = {KC_COMM, KC_DOT, COMBO_END};

// clang-format off
combo_t key_combos[] = {
    [COMMADOT_SEMICOLON]= COMBO(commadot_semicolon, KC_SCLN),
};
// clang-format on

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /*
    * COLEMAK_DH
    *
    *
    *                              _____                                                                 _____
    *                       .-----|  E  |-----._____                                         _____.-----|  I  |-----.
    *           .-----|-----|  W  |_____|  R  |  T  |                                       |  Y  |  U  |_____|  O  |-----|-----.
    *           |     |  Q  |-----|  D  |-----|_____|                                       |_____|-----|  K  |-----|  P  |     |
    *           |-----|-----|  S  |_____|  F  |  G  |                                       |  H  |  J  |_____|  L  |-----|-----|
    *           |     |  A  |-----|  C  |-----|_____|                                       |_____|-----| , < |-----| ; : |     |
    *           |-----|-----|  X  |_____|  V  |  B  |                                       |  N  |  M  |_____| . > |-----|-----|
    *           |     |  Z  |-----'     '-----|_____|                                       |_____|-----'     '-----| / ? |     |
    *           '-----'-----'          .-----. _____   .-.._                           _..-.   _____ .-----.        '-----|-----'
    *                    |             | WIN ||CTRL | /     /                         \     \ | BSp || Del |           |
    *                  SHIFT           '-----':_____|/ ENT /                           \ SPC \|_____:'-----'         SHIFT
    *                                     |         '--.._/                             \_..--'  |      |
    *                                    NUM                                                    NAV    SYM
    */


    [_BASE] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------------------------------.                            ,-----------------------------------------------------------------------------.
              KC_NO,        KC_Q,        KC_W,        KC_F,        KC_P,        KC_B,                                     KC_J,        KC_L,       KC_U ,    KC_Y,    KC_QUOTE,       KC_NO,
    //|------------+------------+------------+------------+------------+------------|                            |------------+------------+------------+------------+------------+------------|
              KC_NO,LGUI_T(KC_A),LALT_T(KC_R),LCTL_T(KC_S),LSFT_T(KC_T),        KC_G,                                     KC_M,LSFT_T(KC_N),LCTL_T(KC_E),LALT_T(KC_I),LGUI_T(KC_O),       KC_NO,
    //|------------+------------+------------+------------+------------+------------|                            |------------+------------+------------+------------+------------+------------|
          OS_SWITCH,        KC_Z,        KC_X,        KC_C, ALL_T(KC_D),        KC_V,                                     KC_K, ALL_T(KC_H),    KC_COMMA,      KC_DOT,    KC_SLASH,       KC_NO,
    //|------------+------------+------------+------------+------------+------------+------------|  |------------+------------+------------+------------+------------+------------+------------|
                                          LT(_MEDIA,KC_ESCAPE),LT(_NAV,KC_BSPC),LT(_MOUSE,KC_TAB),   LT(_SYM,KC_ENTER), LT(_NUM,KC_SPACE),  LT(_FN,KC_SPACE)
                                       //`-------------------------------------------------------'  `------------------------------------------------------'
    ),



    [_NUM] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------------------------------.                            ,-----------------------------------------------------------------------------.
              KC_NO,       KC_NO,        KC_7,        KC_6,        KC_5,       KC_NO,                                    KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,
    //|------------+------------+------------+------------+------------+------------|                            |------------+------------+------------+------------+------------+------------|
              KC_NO,       KC_4,         KC_3,        KC_2,        KC_1,       KC_0,                                    KC_NO,     KC_LSFT,     KC_LCTL,     KC_LALT,     KC_LGUI,       KC_NO,
    //|------------+------------+------------+------------+------------+------------|                            |------------+------------+------------+------------+------------+------------|
              KC_NO,       KC_NO,       KC_NO,        KC_9,        KC_8,       KC_NO,                                    KC_NO,       KC_NO,     KC_TRNS,     KC_TRNS,     _______,       KC_NO,
    //|------------+------------+------------+------------+------------+------------+------------|  |------------+------------+------------+------------+------------+------------+------------|
                                                              KC_UP,       KC_TRNS,    KC_DOWN,         KC_NO,      KC_TRNS,       KC_NO
                                       //`-------------------------------------------------------'  `------------------------------------------------------'
    ),


    [_NAV] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------------------------------.                            ,-----------------------------------------------------------------------------.
              KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,                                     REDO,     KC_PGUP,       KC_UP,       SALL,        KC_NO,       KC_NO,
    //|------------+------------+------------+------------+------------+------------|                            |------------+------------+------------+------------+------------+------------|
              KC_NO,     KC_LGUI,     KC_LALT,     KC_LCTL,     KC_LSFT,       KC_NO,                            TD(TD_VIM_LS),     KC_LEFT,     KC_DOWN,    KC_RIGHT,      KC_END,       KC_NO,
    //|------------+------------+------------+------------+------------+------------|                            |------------+------------+------------+------------+------------+------------|
              KC_NO,       KC_NO,     KC_ALGR,       KC_NO,       KC_NO,       KC_NO,                                     UNDO,     KC_PGDN,       KC_NO,       KC_NO,       KC_NO,       KC_NO,
    //|------------+------------+------------+------------+------------+------------+------------|  |------------+------------+------------+------------+------------+------------+------------|
                                                              KC_NO,      KC_TRNS,      KC_NO,          PASTE,        COPY,        CUT
                                       //`-------------------------------------------------------'  `------------------------------------------------------'
    ),


    [_SYM] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------------------------------.                            ,-----------------------------------------------------------------------------.
              KC_NO,       KC_NO,  LSFT(KC_2),  LSFT(KC_3),  LSFT(KC_4),  LSFT(KC_5),                               LSFT(KC_6),  LSFT(KC_7),  LSFT(KC_8),LSFT(KC_SLASH),  KC_QUOTE,       KC_NO,
    //|------------+------------+------------+------------+------------+------------|                            |------------+------------+------------+------------+------------+------------|
              KC_NO,LSFT(KC_EQUAL),  KC_EQUAL,LSFT(KC_MINUS),LSFT(KC_SCLN),LSFT(KC_QUOTE),                          LSFT(KC_1),  LSFT(KC_9),LSFT(KC_LBRC),    KC_LBRC,LSFT(KC_GRAVE),     KC_NO,
    //|------------+------------+------------+------------+------------+------------|                            |------------+------------+------------+------------+------------+------------|
              KC_NO,LSFT(KC_COMMA),LSFT(KC_BSLS), KC_MINUS,LSFT(KC_DOT),     KC_BSLS,                                 KC_GRAVE,  LSFT(KC_0),LSFT(KC_RBRC),    KC_RBRC,     _______,       KC_NO,
    //|------------+------------+------------+------------+------------+------------+------------|  |------------+------------+------------+------------+------------+------------+------------|
                                                            ELIXIR_PIPE,   KC_TRNS,    KC_SCLN,         KC_TRNS,      KC_NO,      KC_NO
                                       //`-------------------------------------------------------'  `------------------------------------------------------'
    ),

    [_MOUSE] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------------------------------.                            ,-----------------------------------------------------------------------------.
            KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                                  KC_TRNS,     KC_TRNS,     KC_MS_U,     KC_TRNS,     KC_TRNS,     KC_TRNS,
    //|------------+------------+------------+------------+------------+------------|                            |------------+------------+------------+------------+------------+------------|
            KC_TRNS,     KC_LGUI,     KC_LALT,     KC_LCTL,     KC_LSFT,     KC_TRNS,                                  KC_TRNS,     KC_MS_L,     KC_MS_D,     KC_MS_R,     KC_TRNS,     KC_TRNS,
    //|------------+------------+------------+------------+------------+------------|                            |------------+------------+------------+------------+------------+------------|
            KC_TRNS,     KC_TRNS,     KC_ALGR,     KC_TRNS,     KC_TRNS,     KC_TRNS,                                  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
    //|------------+------------+------------+------------+------------+------------+------------|  |------------+------------+------------+------------+------------+------------+------------|
                                                              KC_NO,       KC_NO,      KC_TRNS,         KC_BTN1,     KC_BTN2,     KC_BTN3
                                       //`-------------------------------------------------------'  `------------------------------------------------------'
    ),


    [_FN] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------------------------------.                            ,-----------------------------------------------------------------------------.
              KC_NO,       KC_NO,       KC_F7,       KC_F6,       KC_F5,     KC_PSCR,                                  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
    //|------------+------------+------------+------------+------------+------------|                            |------------+------------+------------+------------+------------+------------|
              KC_NO,       KC_F4,       KC_F3,       KC_F2,       KC_F1,       KC_NO,                                  KC_TRNS,     KC_LSFT,     KC_LCTL,     KC_LALT,     KC_LGUI,     KC_TRNS,
    //|------------+------------+------------+------------+------------+------------|                            |------------+------------+------------+------------+------------+------------|
              KC_NO,       KC_NO,       KC_NO,       KC_F9,       KC_F8,    KC_PAUSE,                                  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_ALGR,     KC_TRNS,     KC_TRNS,
    //|------------+------------+------------+------------+------------+------------+------------|  |------------+------------+------------+------------+------------+------------+------------|
                                                             KC_F11,        KC_F10,     CW_TOGG,           KC_NO,       KC_NO,     KC_TRNS
                                       //`-------------------------------------------------------'  `------------------------------------------------------'
    ),


    [_MEDIA] = LAYOUT_split_3x6_3(
    //,-----------------------------------------------------------------------------.                            ,-----------------------------------------------------------------------------.
            KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                                  RGB_TOG,     RGB_MOD,     RGB_HUI,     RGB_SAI,     RGB_VAI,     KC_TRNS,
    //|------------+------------+------------+------------+------------+------------|                            |------------+------------+------------+------------+------------+------------|
            KC_TRNS,     KC_LGUI,     KC_LALT,     KC_LCTL,     KC_LSFT,     KC_TRNS,                                  KC_TRNS,     KC_MPRV,     KC_VOLD,     KC_VOLU,     KC_MNXT,     KC_TRNS,
    //|------------+------------+------------+------------+------------+------------|                            |------------+------------+------------+------------+------------+------------|
            KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                                  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,
    //|------------+------------+------------+------------+------------+------------+------------|  |------------+------------+------------+------------+------------+------------+------------|
                                                              KC_TRNS,      KC_NO,      KC_NO,         KC_MUTE,      KC_MPLY,     KC_MSTP
                                       //`-------------------------------------------------------'  `------------------------------------------------------'
    ),

};
// clang-format on


bool is_mac_the_default(void) { return keymap_config.swap_lctl_lgui; }

void send_mac_or_win(uint16_t mac_code, uint16_t win_code, bool is_pressed) {
    uint16_t code = is_mac_the_default() ? mac_code : win_code;
    if (is_pressed) {
        register_code16(code);
    } else {
        unregister_code16(code);
    }
}

void tap_mac_or_win(uint16_t mac_code, uint16_t win_code) {
    uint16_t code = is_mac_the_default() ? mac_code : win_code;
    tap_code16(code);
}

bool is_shift_held(void) { return (get_mods() & MOD_BIT(KC_LSFT)) || (get_mods() & MOD_BIT(KC_RSFT)); }
bool is_ctrl_held(void) { return get_mods() & MOD_BIT(KC_LCTL); }
bool is_gui_held(void) { return get_mods() & MOD_BIT(KC_LGUI); }
bool is_alt_held(void) { return get_mods() & MOD_BIT(KC_LALT); }

void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}

void dance_vim_ls_finished (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_HOME);
  } else {
    register_code (KC_LSFT);
    register_code (KC_6);
  }
}

void dance_vim_ls_reset (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_HOME);
  } else {
    unregister_code (KC_LSFT);
    unregister_code (KC_6);
  }
}

tap_dance_action_t tap_dance_actions[] = {
  [TD_VIM_LS] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_vim_ls_finished, dance_vim_ls_reset)
};

bool handle_macro_presses(uint16_t keycode, keyrecord_t *record);
bool handle_os_custom_keys_presses(uint16_t keycode, keyrecord_t *record);

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!handle_macro_presses(keycode, record)) { return false; }
  if (!handle_os_custom_keys_presses(keycode, record)) { return false; }

  return true;
}

bool handle_macro_presses(uint16_t keycode, keyrecord_t* record) {
  if (record->event.pressed) {
    switch (keycode) {
      case UPDIR:
        SEND_STRING("../");
        return false;
      case ELIXIR_PIPE:
        SEND_STRING("|>");
        return false;
    }
  }

  return true;
}

bool handle_os_custom_keys_presses(uint16_t keycode, keyrecord_t* record) {
  if (record->event.pressed) {
    switch (keycode) {
      case OS_SWITCH:
        keymap_config.swap_lctl_lgui = !keymap_config.swap_lctl_lgui;
        PLAY_SONG(song_sonic_ring);
        return false;
      case COPY:
        tap_mac_or_win(G(KC_C), C(KC_C));
        return false;
      case PASTE:
        tap_mac_or_win(G(KC_V), C(KC_V));
        return false;
      case CUT:
        tap_mac_or_win(G(KC_X), C(KC_X));
        return false;
      case UNDO:
        tap_mac_or_win(G(KC_Z), C(KC_Z));
        return false;
      case REDO:
        tap_mac_or_win(G(KC_Y), C(KC_Y));
        return false;
      case SALL:
        tap_mac_or_win(G(KC_A), C(KC_A));
        return false;
    }
  }

  return true;
}

void matrix_scan_user(void) {
}

bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            keymap_config.swap_lctl_lgui = true;
            break;
        case OS_WINDOWS:
        case OS_LINUX:
        case OS_UNSURE:
            keymap_config.swap_lctl_lgui = false;
            break;
    }

    return true;
}
