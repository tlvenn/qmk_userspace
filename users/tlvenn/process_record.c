#include "tlvenn.h"
#include "achordion.h"
#include "select_word.h"
#include "macros.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if (!process_achordion(keycode, record)) {
    return false;
  }

  if (!process_select_word(keycode, record, SEL_WORD)) {
    return false;
  }

  if (!process_macro_event(keycode, record)) {
    return false;
  }

  return true;
}

uint16_t achordion_streak_timeout(uint16_t tap_hold_keycode) {
  return 100;  // Default of 100 ms.
}

void matrix_scan_user(void) {
  achordion_task();
}
