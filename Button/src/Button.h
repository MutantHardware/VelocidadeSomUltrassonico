#ifndef Button_h
#define Button_h
#include "Arduino.h"

class Button{
  private:
    int _ButtonPin, Debounce;
    int lastState = LOW;           
    int lastFlickerableState = LOW;      
    int currentState;                    
    unsigned long lastDebounceTime = 0;  
    bool state = false;
  public:
    Button(int ButtonPin, int debounceTime);
    bool pressed();
};

#endif