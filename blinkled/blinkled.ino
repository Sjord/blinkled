#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void setup() {
  ADCSRA &= ~ bit(ADEN); // disable the ADC
  power_all_disable();
  wdt_enable(WDTO_4S);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);

  DDRB = 0xff;
}

void loop() {
  WDTCR |= (1 << WDIE);
  sleep_enable();
  sleep_mode();
}

ISR (WDT_vect) {
  // clear the Sleep Enable bit immediately after waking up
  MCUCR &= ~(1 << SE);

  // blink led
  PORTB = 0xff;
  _delay_ms(2);
  PORTB = 0x00;
}
