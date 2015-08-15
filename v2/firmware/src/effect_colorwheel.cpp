/**
 * Effect: Controllable color wheel.
 *
 * The goal is to have a "color wheel" cycling through all the colors. The
 * three pots are used the following way:
 *
 *  - Pot 1: Change the saturation
 *  - Pot 2: Change the intensity
 *  - Pot 3: Change the speed of change
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

// HSI -> RGB conversion
#include "hsi.h"

// Hue / Saturation / Intensity
static float val_h = 0.0; // Range: 0-360
static float val_s = 1.0; // Range: 0-1
static float val_i = 1.0; // Range: 0-1

// Delay and step for changing the hue
static int delay_ms = 20;
static float hue_step = 0.5;

// Main loop
void effect_colorwheel(void) {

    // Loop colors
    if (val_h > 360.0f) {
        val_h = 0.0f;
    }

    // Get saturation from potentiometer
    val_s = 1.0f - (analogRead(POT_1) / 1023.0f);

    // Get intensity from potentiometer
    val_i = 1.0f - (analogRead(POT_2) / 1023.0f);

    // Set colors
    RGB rgb = hsi2rgb(val_h, val_s, val_i); 
    analogWrite(LED_R, rgb.r);
    analogWrite(LED_G, rgb.g);
    analogWrite(LED_B, rgb.b);

    // Update hue
    val_h += hue_step;

    // Get delay from potentiometer
    delay_ms = analogRead(POT_3) / 32;

    // Sleep
    delay(delay_ms);

}
