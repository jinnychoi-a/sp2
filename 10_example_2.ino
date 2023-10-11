#include <Servo.h> 

Servo myservo;

void setup() 
{ 
  myservo.attach(7);

} 

void loop() {
  myservo.writeMicroseconds(1500);  // set servo to mid-point
  delay(1000);
  myservo.writeMicroseconds(2000);  // set servo to 180-point
  delay(1000);

  myservo.writeMicroseconds(1500);  // set servo to mid-point
  delay(1000);
    myservo.writeMicroseconds(1000);  // set servo to start-point
  delay(1000);
} 
