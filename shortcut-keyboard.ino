#include<Keyboard.h>
#include "KeyboardApplicationShortcuts.h"

const int buttonCount = 3;
int buttonPin[3] = {7,8,9};
int previousButtonState[3] = {HIGH,HIGH,HIGH};
int buttonAction[3] = {
  SHORTCUT_DEFAULTS_GUI,
  SHORTCUT_MSTEAMS_TOGGLE_MUTE,
  SHORTCUT_MSTEAMS_GO_TO_SHARING_TOOLBAR
};

/*
initialize the buttons and start acting as a keyboard
*/
void setup() {
  for (int i = 0; i< buttonCount; i++) {
    pinMode(buttonPin[i], INPUT_PULLUP);
    digitalWrite(buttonPin[i], HIGH);
  }

  // initialize control over the keyboard:
  Keyboard.begin();
}

/*
press some buttons based on the 
*/
void pressButtons(int keyId) {
  int action = buttonAction[keyId];
  KeyboardApplicationShortcuts::pressShortcut(action);
}

/*
detect pressed buttons and run pressButtons
*/
void loop() {
  for ( int i = 0; i< buttonCount; i++) {
      int buttonState = digitalRead(buttonPin[i]);
      if ((buttonState != previousButtonState[i])  && (buttonState = HIGH)) {
        pressButtons(i);
        delay(200);
      }
      previousButtonState[i] = buttonState;
  }
}