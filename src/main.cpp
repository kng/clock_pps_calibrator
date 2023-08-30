#include <Arduino.h>

int led = 13;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("hello");
  if(digitalRead(led)){
    digitalWrite(led,LOW);
  } else {
    digitalWrite(led, HIGH);
  }
  delay(1000);
}
