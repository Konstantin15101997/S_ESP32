#include <Arduino.h>
#include <GyverMotor2.h>
GMotor2<DRIVER2WIRE> motor(23,22);
GMotor2<DRIVER2WIRE> motor1(25,26);
GMotor2<DRIVER2WIRE> motor2(27,13);

void setup() {
  motor.setMinDuty(70);   // мин. ШИМ
  motor.reverse(1);     // реверс
  motor.setDeadtime(5); // deadtime
  delay(2500);
}

void loop() {
  motor.setSpeed(100);
  motor1.setSpeed(-100);
  motor2.setSpeed(255);
  delay(3000);
  
  motor.setSpeed(-100);
  motor1.setSpeed(100);
  motor2.setSpeed(-255);
  delay(3000);
}

