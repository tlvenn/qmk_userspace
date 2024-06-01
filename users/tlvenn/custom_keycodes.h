#ifdef SVALBOARD
/*#include "keymap_support.h"*/
/*#define RANGE_START SV_SAFE_RANGE*/
#define RANGE_START SAFE_RANGE
#else
#define RANGE_START SAFE_RANGE
#endif

enum custom_keycodes {
  SEL_WORD = RANGE_START,
};
