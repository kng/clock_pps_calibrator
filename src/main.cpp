#include <Arduino.h>
#define LED 13
#define DIV 62500           // 1M / 16 = 62500

int count, time, time_old, count_old;
long freq;
bool trig = true;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("freq timer");
  TCCR1A = 0;
  TCCR1B = (1 << WGM12)     // CTC mode
         | (1 << CS10)      // no prescaler
         | (1 << ICES1)     // timer capture input
         | (1 << ICNC1);    // rising edge
  OCR1A = DIV - 1;          // set timer top
  TIMSK1 = (1 << OCIE1A)    // enable timer compare interrupt
         | (1 << ICIE1);    // enable capture interrupt on PB0 (arduino pin 8)
  sei();
}

void loop() {
  if(trig){
    trig = false;
    Serial.print(freq);
    Serial.print(" ");
    Serial.println(time);
    if(digitalRead(LED)){
      digitalWrite(LED,LOW);
    } else {
      digitalWrite(LED, HIGH);
    }
  }
}

ISR(TIMER1_COMPA_vect){   // count 16 per MHz
  count += 1;
}

ISR(TIMER1_CAPT_vect){    // capture timer at pps signal
  cli();
  time_old = time;
  time = ICR1;
  freq = (count - count_old) * DIV - (time_old - time);
  count_old = count;
  trig = true;
  sei();
}
