SHELL := /bin/bash

SKETCHBOOK := shortcut-keyboard.ino

BOARD_FAMILY := arduino:avr
FULLY_QUALIFIED_BOARD_NAME := arduino:avr:leonardo
PORT := /dev/ttyACM0

list-boards:
	arduino-cli board list

prepare-compile:
	arduino-cli core install $(BOARD_FAMILY)
	arduino-cli lib install Keyboard

compile:
	arduino-cli compile --fqbn $(FULLY_QUALIFIED_BOARD_NAME) $(SKETCHBOOK)

upload: compile
	arduino-cli upload -p $(PORT) --fqbn $(FULLY_QUALIFIED_BOARD_NAME) $(SKETCHBOOK)
