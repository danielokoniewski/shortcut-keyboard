#ifndef KeyboardApplicationShortcuts_h
#define KeyboardApplicationShortcuts_h

const int SHORTCUT_DEFAULTS_GUI		 			= 1;

// https://support.microsoft.com/en-us/office/keyboard-shortcuts-for-microsoft-teams-2e8e2a70-e8d8-4a19-949b-4c36dd5292d2
//#define SHORTCUT_MSTEAMS_.... -> Windows + Linux
const int SHORTCUT_MSTEAMS_ACCEPT_AUDIO_CALL 	= 1001;
const int SHORTCUT_MSTEAMS_ACCEPT_VIDEO_CALL 	= 1002;
const int SHORTCUT_MSTEAMS_DECLINE_CALL 			= 1003;
const int SHORTCUT_MSTEAMS_FILTER_CURRENT_LIST 	= 1004;
const int SHORTCUT_MSTEAMS_GO_TO_SHARING_TOOLBAR = 1005;
const int SHORTCUT_MSTEAMS_START_AUDIO_CALL 		= 1006;
const int SHORTCUT_MSTEAMS_START_VIDEO_CALL 		= 1007;
const int SHORTCUT_MSTEAMS_TOGGLE_MUTE 			= 1008;
const int SHORTCUT_MSTEAMS_TOGGLE_VIDEO 			= 1009;



class KeyboardApplicationShortcuts
{
	public:
		static void pressShortcut(int shortcutName);
	private:
		static void pressShortcutDefaults(int shortcutName);
		static void pressShortcutMSTeams(int shortcutName);
};

#endif