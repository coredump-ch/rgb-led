/**
 * Effect: Controllable color wheel.
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

// Get arduino headers
#include "Arduino.h"

// Get pin definitions
#include "pins.h"

// Global state: Color values (0-255)
static int val_r = 0;
static int val_g = 0;
static int val_b = 0;

// Global state: Fading step per color (1 or -1)
static int step_r = 1;
static int step_g = 1;
static int step_b = 1;

// Main loop
void effect_colorwheel(void) {

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
    analogWrite(LED_R, val_r);
    analogWrite(LED_G, val_g);
    analogWrite(LED_B, val_b);

    // Update colors
    val_b += step_b;

    // Get delay
    int milliseconds = analogRead(POT_1) / 16;

    // Sleep
    delay(milliseconds);

}
