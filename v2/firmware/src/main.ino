/**
 * Main entry point for the microcontroller.
 *
 * Copyright (c) 2014--2015 Coredump Rapperswil
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


// LEDs
const int led_r = 3;
const int led_g = 6;
const int led_b = 5;

// Pots
const int pot_1 = 14;
const int pot_2 = 15;
const int pot_3 = 16;

// Global state
int val_r = 0;
int val_g = 0;
int val_b = 0;
int step_r = 1;
int step_g = 1;
int step_b = 1;


// Initialize GPIO pins
void setup() {

    // Set LED pins as output
    pinMode(led_r, OUTPUT);
    pinMode(led_g, OUTPUT);
    pinMode(led_b, OUTPUT);

    // Set pot pins as input
    pinMode(pot_1, INPUT);
    pinMode(pot_2, INPUT);
    pinMode(pot_3, INPUT);

}

// Main loop
void loop() {

    // Check limits and fade direction
    if (val_r == 0) {
        step_r = 1;
    } else if (val_r == 255) {
        step_r = -1;
    }
    if (val_g == 0) {
        step_g = 1;
    } else if (val_g == 255) {
        step_g = -1;
    }
    if (val_b == 0) {
        step_b = 1;
    } else if (val_b == 255) {
        step_b = -1;
    }

    // Set colors
    analogWrite(led_r, val_r);
    analogWrite(led_g, val_g);
    analogWrite(led_b, val_b);

    // Update colors
    val_b += step_b;

    // Get delay
    int milliseconds = analogRead(pot_1) / 16;

    // Sleep
    delay(milliseconds);

}
