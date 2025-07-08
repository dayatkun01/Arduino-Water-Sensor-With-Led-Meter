#include <Arduino.h>

int waterSensorPinAnalog = 0;int LEDgreenPin = 9;int LEDyellowPin = 10;
int LEDredPin = 11;

void setup() {
  pinMode(LEDgreenPin, OUTPUT);pinMode(LEDyellowPin, OUTPUT);pinMode(LEDredPin, OUTPUT);
  Serial.begin(250000);
}

void loop() {
  int waterSensorValue = analogRead(waterSensorPinAnalog);
  Serial.println(analogRead(waterSensorPinAnalog));
  
  if(waterSensorValue > 15) {
    analogWrite(LEDgreenPin, constrain(map(waterSensorValue, 15, 150, 0, 255), 0, 255));
    Serial.println("green acitve");
  } else {
    analogWrite(LEDgreenPin, 0);
  }
  if(waterSensorValue > 150) {
    analogWrite(LEDyellowPin, constrain(map(waterSensorValue, 151, 300, 0, 255), 0, 255));
    Serial.println("yellow acitve");
  } else {
    analogWrite(LEDyellowPin, 0);
  }
  if(waterSensorValue > 300) {
    analogWrite(LEDredPin, constrain(map(waterSensorValue, 301, 600, 0, 255), 0, 255));
    Serial.println("red acitve");
  } else {
    analogWrite(LEDredPin, 0);
  }
}