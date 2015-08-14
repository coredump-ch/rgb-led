/**
 * Main entry point for RGB LED controller.
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

// Get pin definitions
#include "pins.h"

// Include effects
#include "effects/colorwheel.h"
#include "effects/rgb_control.h"


// List of available effects
enum Effect {
    Colorwheel,
    RGBControl,
};

// Choose your effect
static const Effect effect = Colorwheel;


// Initialize GPIO pins
void setup() {
    // Set LED pins as output
    pinMode(LED_R, OUTPUT);
    pinMode(LED_G, OUTPUT);
    pinMode(LED_B, OUTPUT);

    // Set pot pins as input
    pinMode(POT_1, INPUT);
    pinMode(POT_2, INPUT);
    pinMode(POT_3, INPUT);
}


// Main loop
void loop() {

    switch (effect) {
        case Colorwheel:
            effect_colorwheel(); 
            break;
        case RGBControl:
            effect_rgb_control(); 
            break;
    }

}
