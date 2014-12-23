/**
 * Main entry point for the microcontroller.
 *
 * Copyright (c) 2014 Danilo Bargen
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the “Software”), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include <avr/io.h>
#include <util/delay.h>
#include "colors.h"
#include "usart.h"

// LEDs
#define LED_DDR  DDRD
#define QR1      PD3
#define QG1      PD6
#define QB1      PD5

// POTs
#define POT_DDR  DDRC
#define RV1      PC0
#define RV2      PC1
#define RV3      PC2

// LED bit values
#define RED    (1 << QR1)
#define GREEN  (1 << QG1)
#define BLUE   (1 << QB1)

// LED PWM registers
#define RED_PWM    OCR2B
#define GREEN_PWM  OCR0A
#define BLUE_PWM   OCR0B

// POT bit values
#define POT1  (1 << RV1)
#define POT2  (1 << RV2)
#define POT3  (1 << RV3)

// ADC multiplexing configurations
#define ADC0  0
#define ADC1  (1 << MUX0)
#define ADC2  (1 << MUX1)

// Fading
#define FADE_INTERVAL       1600
#define fadeIn(color_pwm)   i = 0; do { color_pwm = i; _delay_ms(FADE_INTERVAL / 255); } while (i++ != 255);
#define fadeOut(color_pwm)  i = 255; do { color_pwm = i; _delay_ms(FADE_INTERVAL / 255); } while (i--);

// Other useful macros (TODO: Refactor out)
#define bit_is_set(sfr, bit)               (_SFR_BYTE(sfr) & _BV(bit))
#define bit_is_clear(sfr, bit)             (!(_SFR_BYTE(sfr) & _BV(bit)))
#define loop_until_bit_is_set(sfr, bit)    do { } while (bit_is_clear(sfr, bit))
#define loop_until_bit_is_clear(sfr, bit)  do { } while (bit_is_set(sfr, bit))


// TODO: Configure clock, set prescaler, don't forget ADC prescaler


/** Set up I/O **/
static inline void initIO(void) {
    LED_DDR |= RED | GREEN | BLUE; // PD3/5/6 are output (LED)
    POT_DDR &= ~(POT1 | POT2 | POT3); // PC0/1/2 are input (POTs)
}

/** Initialize ADC **/
static inline void initADC() {
    ADMUX = _BV(REFS0); // Ref voltage AVcc, right adjust result, read ADC0
    ADCSRA |= _BV(ADPS0) | _BV(ADPS1) | _BV(ADPS2); // ADC clock prescaler -- 20 MHz / 128 ~= 156 KHz
    ADCSRA |= _BV(ADEN); // Enable ADC
    _delay_ms(1); // Settle time
}

/** Set up timers (PWM) **/
static inline void initTimers(void) {
    // TCCR0: Enable fast 8 bit PWM mode counting up to 0xFF
    TCCR0A |= _BV(WGM00);
    TCCR0A |= _BV(WGM01);
    TCCR0B &= ~_BV(WGM02);

    // TCCR2: Enable fast 8 bit PWM mode counting up to 0xFF
    TCCR2A |= _BV(WGM20);
    TCCR2A |= _BV(WGM21);
    TCCR2B &= ~_BV(WGM22);

    // TCCR0: PWM Frequency: Divide by 256
    TCCR0B &= ~_BV(CS00);
    TCCR0B &= ~_BV(CS01);
    TCCR0B |= _BV(CS02);

    // TCCR2: PWM Frequency: Divide by 256
    TCCR2B &= ~_BV(CS20);
    TCCR2B &= ~_BV(CS21);
    TCCR2B |= _BV(CS22);

    // Non inverted compare output mode on OCR0A (green)
    TCCR0A &= ~_BV(COM0A0);
    TCCR0A |= _BV(COM0A1);

    // Non inverted compare output mode on OCR0B (blue)
    TCCR0A &= ~_BV(COM0B0);
    TCCR0A |= _BV(COM0B1);

    // Non inverted compare output mode on OCR2B (red)
    TCCR2A &= ~_BV(COM2B0);
    TCCR2A |= _BV(COM2B1);
}

/** Analog input pin selection **/
static void selectADC(uint8_t adc_pin) {
    ADMUX = (ADMUX & 0xF0) | (adc_pin & 0x0F);
}

/** Read 16 bit value from ADC **/
static uint16_t readADC(void) {
    ADCSRA |= _BV(ADSC); // Start ADC conversion
    loop_until_bit_is_clear(ADCSRA, ADSC); // Wait until done
    return ADC;
}

void hsiLoop() {
    // Variables
    uint16_t h;
    uint16_t s;
    uint16_t i;
    uint8_t rgb[3];

    selectADC(ADC0);
    h = readADC();
    selectADC(ADC1);
    s = readADC();
    selectADC(ADC2);
    i = readADC();

    hsi2rgb((1023 - h ) / 1023.0f * 360.0f,
            (1023 - s) / 1023.0f,
            (1023 - i) / 1023.0f,
            rgb);

    RED_PWM = rgb[0];
    GREEN_PWM = rgb[1];
    BLUE_PWM = rgb[2];
}

/** Entry point **/
int main(void) {

    // Initialization

    initIO();
    initTimers();
    initADC();
    initUSART();

    printString("Hello colorful world!\r\n");

    // Main loop
    while(1) {
        hsiLoop();
    }

    return(0);
}
