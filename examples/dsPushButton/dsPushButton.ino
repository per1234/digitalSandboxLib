//dsPushButton.ino example
//Push button cycles the code through a state-machine
//the variable programState is incremented for each
//state.
//
#include "digitalSandbox.h"
digitalSandbox ds;

int programState = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(12) == true)
  {
    programState = programState + 1;
    if (programState > 3)
      programState = 0;
    while (digitalRead(12) == true); //catch to wait for button release
    delay(20); //debounce delay
  }
  switch (programState) {
    case 0:
      ds.setRGB(255, 0, 0); //set to Red
      break;
    case 1:
      ds.setRGB(255, 255, 255); //set to White
      break;
    case 2:
      ds.setRGB(0, 0, 255); //set to Blue
      break;
    case 3:
      ds.setRGB(0, 0, 0); //set to all off
      break;
  }
}