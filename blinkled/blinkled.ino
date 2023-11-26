#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <avr/wdt.h>
#include <avr/adc.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void) {
  ADCSRA &= ~ bit(ADEN); // disable the ADC
  power_all_disable();
  wdt_enable(WDTO_4S);

  DDRB = 0xff;
  PORTB = 0xff;
  _delay_ms(2);
  PORTB = 0x00;

  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_mode();
}
