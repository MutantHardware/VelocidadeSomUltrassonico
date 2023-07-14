// Including Library
#include "Button.h"

// Variables and constants
bool PlayButtonState = false;
const int DebounceTime = 70;

// Defining Buttons pin
#define PlayButtonPin 0    // GPIO0

// Creating Button object
Button PlayButton(PlayButtonPin,DebounceTime);

void setup() {
  // Initializing Serial 
  Serial.begin(115200);
}
 
void loop() {
  // Dettect Button Press 
  if(PlayButton.pressed()){
    PlayButtonState = !PlayButtonState; 
  }
  
  // Change State
  if (PlayButtonState){
      Serial.println("Play");
  }
  else {
      Serial.println("Pause");
  }  
}