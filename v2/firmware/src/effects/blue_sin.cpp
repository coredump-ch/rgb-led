/**
 * Effect: Controllable RGB values
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
#include <Arduino.h>

// Get pin definitions
#include "../pins.h"

float time = 0.0f;
float speed = 0.5f;

// Main loop
void effect_blue_sin(void) {

    // get speed, and filter it (IIR) to avoid noise
    speed = speed*0.5f + analogRead(POT_1)*0.5f/1023.0f;

    // calculate sinus value according to time
    const float sinus_value = sin(PI*time/180.0f);
    // scale sinus to be between 0 and 1
    const float sinus_scaled = (sinus_value +1.0f)/2.0f;
    // by using an exponantial scale we make it more human eye friendly. Then we
    // scale it to x..255
    const int val_b = exp(-3*sinus_scaled)*255.0f+0.5f;

    // Set colors
    analogWrite(LED_R, 0);
    analogWrite(LED_G, 0);
    analogWrite(LED_B, val_b);

    // Sleep
    delay(1);

    time+=speed;
    if(time>=360.0f) {
        time = 0.0f;
    }
}

