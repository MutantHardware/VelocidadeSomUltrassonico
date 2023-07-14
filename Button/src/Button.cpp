#include "Button.h"
#include "Arduino.h"

Button::Button(int ButtonPin, int debounceTime){
  _ButtonPin = ButtonPin;
  Debounce = debounceTime;
  pinMode(_ButtonPin, INPUT);
}

bool Button::pressed(){
  if (digitalRead(_ButtonPin)){
    currentState = true;
  }
  else{
    currentState = false;
  }
  
  if (currentState != lastFlickerableState) {
    lastDebounceTime = millis();
    lastFlickerableState = currentState;
  }

  if ((millis() - lastDebounceTime) > Debounce) {
    if(lastState == HIGH && currentState == LOW){
      state = true;
    } 
    else{
      state = false;
    }
    lastState = currentState;
  }
  return state;
}