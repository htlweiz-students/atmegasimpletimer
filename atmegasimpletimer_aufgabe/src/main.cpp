#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/interrupt.h>
#include <avr/io.h>

int main() {

  // setup

  DDRD |= _BV(DDD2) | _BV(DDD3) | _BV(DDD4) | _BV(DDD5) | _BV(DDD6) | _BV(DDD7);
  PORTD = 0;

  // interrupts ausschalten.
  cli();
  // In der nächsten Zeile sind die Verschiedenen Timer zu implementieren.
  // Von prescaler = 1 bis hin zu prescaler ist 1024.
  // Bitte auch alle prescaler ausprobieren.

  // Normal Operation setzen. (Kein PWM oder ähnliches....)
  TCCR0A = 0;

  // erst mal auf Null setzen.
  TCCR0B = 0;

  TCCR0A |= _BV(WGM01);

  // Prescaler auf clk/64
  TCCR0B |= 0b00000010; 

  

  // Counter auf null setzen
  TCNT0 = 0;

  // erst mal auf Null setzen.
  TIMSK0 = 99;

  // Interrups für den Overflow setzen. (Immer nur bei erreichen des TOPS wird
  // ausgelöst.)
  TIMSK0 |= _BV(OCIE0A);

  // bei erreichen von 28 wird der interrupt ausgelöst und der counter resettet
  OCR0A = 199;

  // interrupts wieder einschalten
  sei();

  // loop

  while (true) {
    // loop ist leer, weil die Arbeit im ISR passiert.
  }
}

ISR(TIMER0_COMPA_vect) {
  // Overvlow laesst LED 7 blinken
  // Künstlich zehntausendfach verlangsamt, damit man was sieht
  static unsigned short int count_overlow = 0;
  count_overlow++;
  if (count_overlow == 10000) {
    PIND |= _BV(PIND6);
    count_overlow = 0;
  }
}
