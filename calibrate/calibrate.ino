/*Calibrate Distance Sensor */

#include <Servo.h>

#define SERVO_PIN 9 // PWM pin
#define SERVO_ANGLE_SETTLE_TIME_MS 100

#define SENSOR_PIN A0

Servo servo;

void setup() {
  Serial.begin(9600);
  servo.attach(SERVO_PIN);
  pinMode(SENSOR_PIN, INPUT);

  for (int angle = 0; angle <= 180; angle++) {
    servo.write(angle);
    delay(SERVO_ANGLE_SETTLE_TIME_MS);
    Serial.print(angle + " ," + read_sensor());
  }
}

int read_sensor() {
    return analogRead(SENSOR_PIN);
}

void loop() {};