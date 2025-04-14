/// i have written this code..this code is not exacly similar to what was asked in the question. but i know only how a motor and an IR sensor
/// can work together. like when the IR sensor is detecting something motor is not moving otherwise it is spinning back and forth.

#include <Servo.h>

int servoPin = 9; // define the pin for the servo motor
Servo servo;
int angle = 0;  // servo's initial position in degrees
int IRSensor=2;
void setup() {
  Serial.begin(115200);
  Serial.println("Serial Working");

  pinMode(IRSensor,INPUT);
  servo.attach(servoPin);
  // put your setup code here, to run once:

}

void loop() {
  int sensorStatus=digitalRead(IRSensor);
  if (sensorStatus==1) // if no object detected (IR sensor gives high)
  {
    
    Serial.println("Object not detected");
    for(angle = 0; angle < 180; angle++) { // sweeps servo from 0 to 180
        servo.write(angle);
        delay(3);
    }
    
    // now scan back from 180 to 0 degrees
    for(angle = 180; angle > 0; angle--) { // sweeps the servo back from 180 to 0
        servo.write(angle);
        delay(3);
    }


  }
  else{ // if object detected IR sensor gives low.
  
    Serial.println("Object detected");

  }
  // put your main code here, to run repeatedly:

}
