# QMK features
CAPS_WORD_ENABLE = yes
EXTRAKEY_ENABLE = yes    # Audio control and System control
OS_DETECTION_ENABLE = yes
COMBO_ENABLE = yes
TAP_DANCE_ENABLE=yes

# For keymap_support.c
VPATH += keyboards/svalboard/keymaps

VPATH += $(USER_PATH)/defs
VPATH += $(USER_PATH)/extensions

SRC += tlvenn.c
SRC += achordion_settings.c
SRC += achordion.c
SRC += select_word.c
SRC += macros.c

CFLAGS += -fcommon
