#include QMK_KEYBOARD_H
#include "achordion.h"

bool achordion_eager_mod(uint8_t mod) {
  return true;  // Eagerly apply all mods.
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t *tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t *other_record) {

#ifdef SVALBOARD  // Svalboard flips columns and rows
  // Sval thumb keys should also always be valid
  if ((tap_hold_record->event.key.row == 0) || (other_record->event.key.row == 0) || (tap_hold_record->event.key.row == 5) || (other_record->event.key.row == 5)) {
    return true;
  }
#else
#endif

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}
