// Including Library
#include "Button.h"

// Defining Button pin
#define ButtonPin 0 // GPIO0

// Ultrasonic Sensor Pinout
#define trigPin 5   // GPIO05
#define echoPin 18  // GPIO18

// Variables and constants
long timeMicro;
float distanceCm;
bool ButtonState = false;
const int DebounceTime = 70; 
const float SOUND_SPEED = 0.0343; // Sound speed in cm/uS

// Creating Button object
Button Button(ButtonPin,DebounceTime);

void setup() {
  // Initialize Serial Communication
  Serial.begin(115200); 

  // Set pins as Input/Output
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
}

void loop() { 
  // Dettect Button Press 
  if(Button.pressed()){
      // Sound wave travel time in microseconds
      timeMicro = ultrasonicTime();
      
      // Calculate the distance
      distanceCm = timeMicro * (SOUND_SPEED/2);

      // Time, in seconds
      Serial.print("Tempo (s): ");
      Serial.print(timeMicro);
      Serial.println(" x 10^-6");
    
      // Distance, in meters
      Serial.print("Distância (m): ");
      Serial.print(distanceCm);
      Serial.println(" x 10^-2");
    
      Serial.println(" ");   
  }
}

// Ultrasonic Sensor Reflection Time
long ultrasonicTime(){
  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  Wait(2);
  
  // Sets the trigger pin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  Wait(10);
  digitalWrite(trigPin, LOW);
  
  return pulseIn(echoPin, HIGH);
}

// Wait Function
void Wait(unsigned long time){
  unsigned long actualTime = micros();
  while(actualTime + time > micros()){}
}
