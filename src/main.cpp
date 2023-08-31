#include <Arduino.h>

int led = 13;
int count = 0;
int time = 0;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);

  TCCR1A = 0;
  TCCR1B = (1 << WGM12) | (1 << CS10);       // CTC mode, no prescaler
  TCNT1  = 0;
  OCR1A = 62500;                             // 1M / 16 = 62500
  TIMSK1 |= (1 << OCIE1A) | (1 << ICIE1);    // enable timer compare and capture interrupt
  sei();
}

void loop() {
  Serial.println(count);
  if(digitalRead(led)){
    digitalWrite(led,LOW);
  } else {
    digitalWrite(led, HIGH);
  }
  delay(1000);
}

ISR(TIMER1_COMPA_vect){
  count += 1;
}

ISR(TIMER1_CAPT_vect){
  unsigned char sreg = SREG;
  cli();
  time = TCNT1;               // capture timer at pps signal
  SREG = sreg;
}
