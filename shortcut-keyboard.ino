#include<Keyboard.h>

const int buttonCount = 3;
int buttonPin[3] = {7,8,9};
int previousButtonState[3] = {HIGH,HIGH,HIGH};

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
  switch(keyId) {
    case 0:
      //Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press(KEY_RETURN);
      Keyboard.release(KEY_RETURN);;
      break;
   case 1:
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('M');
      Keyboard.releaseAll();
      break;
   case 2:
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.releaseAll();
      delay(100);
      Keyboard.print("Terminal");
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_RETURN);
      Keyboard.releaseAll();
      
      break;
   default:
     break;
  }
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