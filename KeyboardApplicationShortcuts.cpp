#include "KeyboardApplicationShortcuts.h"
#include "Arduino.h"
#include "Keyboard.h"

void KeyboardApplicationShortcuts::pressShortcut(int shortcutName)
{
	switch (shortcutName) {
		case SHORTCUT_DEFAULTS_GUI:
			KeyboardApplicationShortcuts::pressShortcutDefaults(shortcutName);
			break;

		case SHORTCUT_MSTEAMS_ACCEPT_AUDIO_CALL:
		case SHORTCUT_MSTEAMS_ACCEPT_VIDEO_CALL:
		case SHORTCUT_MSTEAMS_DECLINE_CALL:
		case SHORTCUT_MSTEAMS_FILTER_CURRENT_LIST:
		case SHORTCUT_MSTEAMS_GO_TO_SHARING_TOOLBAR:
		case SHORTCUT_MSTEAMS_START_AUDIO_CALL:
		case SHORTCUT_MSTEAMS_START_VIDEO_CALL:
		case SHORTCUT_MSTEAMS_TOGGLE_MUTE:
		case SHORTCUT_MSTEAMS_TOGGLE_VIDEO:
			KeyboardApplicationShortcuts::pressShortcutMSTeams(shortcutName);
			break;

		default:
			break;
	}
}

void KeyboardApplicationShortcuts::pressShortcutDefaults(int shortcutName)
{
	switch (shortcutName) {
		case SHORTCUT_DEFAULTS_GUI:
			Keyboard.press(KEY_LEFT_GUI);
			Keyboard.release(KEY_LEFT_GUI);
			break;

		default:
			break;
	}
}

void KeyboardApplicationShortcuts::pressShortcutMSTeams(int shortcutName)
{
	bool pressed = true;
	switch (shortcutName) {
		case SHORTCUT_MSTEAMS_ACCEPT_AUDIO_CALL:
			Keyboard.press(KEY_LEFT_CTRL);
			Keyboard.press(KEY_LEFT_SHIFT);
			Keyboard.press('A');
			break;
		case SHORTCUT_MSTEAMS_ACCEPT_VIDEO_CALL:
			Keyboard.press(KEY_LEFT_CTRL);
			Keyboard.press(KEY_LEFT_SHIFT);
			Keyboard.press('S');
			break;
		case SHORTCUT_MSTEAMS_DECLINE_CALL:
			Keyboard.press(KEY_LEFT_CTRL);
			Keyboard.press(KEY_LEFT_SHIFT);
			Keyboard.press('D');
			break;
		case SHORTCUT_MSTEAMS_FILTER_CURRENT_LIST:
			Keyboard.press(KEY_LEFT_CTRL);
			Keyboard.press(KEY_LEFT_SHIFT);
			Keyboard.press('F');
			break;
		case SHORTCUT_MSTEAMS_GO_TO_SHARING_TOOLBAR:
			Keyboard.press(KEY_LEFT_CTRL);
			Keyboard.press(KEY_LEFT_SHIFT);
			Keyboard.press(' ');
			break;
		case SHORTCUT_MSTEAMS_START_AUDIO_CALL:
			Keyboard.press(KEY_LEFT_CTRL);
			Keyboard.press(KEY_LEFT_SHIFT);
			Keyboard.press('C');
			break;
		case SHORTCUT_MSTEAMS_START_VIDEO_CALL:
			Keyboard.press(KEY_LEFT_CTRL);
			Keyboard.press(KEY_LEFT_SHIFT);
			Keyboard.press('U');
			break;
		case SHORTCUT_MSTEAMS_TOGGLE_MUTE:
			Keyboard.press(KEY_LEFT_CTRL);
			Keyboard.press(KEY_LEFT_SHIFT);
			Keyboard.press('M');
			break;
		case SHORTCUT_MSTEAMS_TOGGLE_VIDEO:
			Keyboard.press(KEY_LEFT_CTRL);
			Keyboard.press(KEY_LEFT_SHIFT);
			Keyboard.press('O');
			break;
		default:
			pressed = false;
			break;
	}
	if (pressed)
		Keyboard.releaseAll();
}