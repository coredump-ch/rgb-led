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

// LEDs
#define LED_DDR DDRD
#define QR1 PD3
#define QG1 PD6
#define QB1 PD5

// POTs
#define POT_DDR DDRC
#define RV1 PC0
#define RV2 PC1
#define RV3 PC2

// LED bit values
#define RED (1 << QR1)
#define GREEN (1 << QG1)
#define BLUE (1 << QB1)

// LED PWM registers
#define RED_PWM OCR2B
#define GREEN_PWM OCR0A
#define BLUE_PWM OCR0B

// POT bit values
#define POT1 (1 << RV1)
#define POT2 (1 << RV2)
#define POT3 (1 << RV3)

// Fading
#define FADE_INTERVAL 1600
#define fadeIn(color_pwm) i = 0; do { color_pwm = i; _delay_ms(FADE_INTERVAL / 255); } while (i++ != 255);
#define fadeOut(color_pwm) i = 255; do { color_pwm = i; _delay_ms(FADE_INTERVAL / 255); } while (i--);


/** Set up I/O **/
static inline void initIO(void) {
    LED_DDR |= RED | GREEN | BLUE; // PD3/5/6 are output (LED)
    POT_DDR &= ~(POT1 | POT2 | POT3); // PC0/1/2 are input (POTs)
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

/** Entry point **/
int main(void) {

    initIO();
    initTimers();

    uint8_t i = 0;

    while(1) {
        fadeIn(RED_PWM);
        fadeIn(GREEN_PWM);
        fadeIn(BLUE_PWM);
        fadeOut(RED_PWM);
        fadeOut(GREEN_PWM);
        fadeOut(BLUE_PWM);
    }
    return(0);
}
