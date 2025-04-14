
#include <Servo.h>

int servoPin = 9;
Servo servo;
int angle = 0;  // servo position in degrees
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
  if (sensorStatus==1)
  {
    
    Serial.println("Object not detected");
    for(angle = 0; angle < 180; angle++) {
        servo.write(angle);
        delay(3);
    }
    
    // now scan back from 180 to 0 degrees
    for(angle = 180; angle > 0; angle--) {
        servo.write(angle);
        delay(3);
    }


  }
  else{
  
    Serial.println("Object detected");

  }
  // put your main code here, to run repeatedly:

}