
#include <Stepper.h>

const int stepsPerRevolution = 64;

char data;

Stepper small_stepper(stepsPerRevolution, 8, 9, 10, 11);
Stepper small_stepper2(stepsPerRevolution, 3, 4, 5, 6);

void setup() {
  Serial.begin(9600);

  small_stepper.setSpeed(500);   // set first stepper speed
  small_stepper2.setSpeed(500);

} 

void loop() {
  if (Serial.available()) {
      data = Serial.read();
   
  
    if (data == 'L') {
      small_stepper.step(250);  
    } 
    else if (data == 'R') {
      small_stepper.step(-250);  
    }  
    else if (data == 'F') {
      small_stepper2.step(+360);  
    }
    else if (data == 'B') {
      small_stepper2.step(-360);  
    } 
    else {
      small_stepper.step(0); 
      small_stepper2.step(0);
    }
  }
  else {
    small_stepper.step(0); 
    small_stepper2.step(0);  
  }
  }
