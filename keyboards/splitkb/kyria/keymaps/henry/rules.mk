OLED_DRIVER_ENABLE = no   # Enables the use of OLED displays
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
RGBLIGHT_ENABLE = no      # Enable keyboard RGB underglow

TAP_DANCE_ENABLE = yes
CONSOLE_ENABLE = no
KEY_LOCK_ENABLE = no

SRC += encoders.c

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
	SRC += oled_utils.c
endif



