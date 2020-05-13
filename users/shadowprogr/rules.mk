# Enable Bootmagic Lite to consistently reset to bootloader and clear EEPROM.
BOOTMAGIC_ENABLE				= lite

# Enable audio control and system control on all keyboards.
EXTRAKEY_ENABLE					= yes

# Enable link-time optimization to reduce binary size.
LINK_TIME_OPTIMIZATION_ENABLE	= no

# Disable unused build options on all keyboards.
COMMAND_ENABLE					= no
CONSOLE_ENABLE					= no
MOUSEKEY_ENABLE					= no
NKRO_ENABLE						= no
TERMINAL_ENABLE					= no

# Disable unused hardware options on all keyboards.
FAUXCLICKY_ENABLE				= no
MIDI_ENABLE						= no
SLEEP_LED_ENABLE				= no

# Disable other unused options.
API_SYSEX_ENABLE				= no
AUTO_SHIFT_ENABLE				= no
COMBO_ENABLE					= no
KEYBOARD_LOCK_ENABLE			= no
KEY_LOCK_ENABLE					= no
SWAP_HANDS_ENABLE				= no
TAP_DANCE_ENABLE				= no
UCIS_ENABLE						= no
UNICODEMAP_ENABLE				= no
UNICODE_ENABLE					= no

SRC += shadowprogr.c \
       process_records.c \
	   my_lt.c

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
    SRC += oled.c
endif

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
    SRC += rgb_light.c
endif

RGB_MATRIX_ENABLE ?= no
ifneq ($(strip $(RGB_MATRIX_ENABLE)), no)
    SRC += rgb_matrix.c
endif
