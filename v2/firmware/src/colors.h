/**
 * Various color space related functions.
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

#ifndef COLORS_H
#define COLORS_H

#include <math.h>
#include <inttypes.h> 

/**
 * Function example takes H, S, I, and a pointer to the 
 * returned RGB colorspace converted vector. It should
 * be initialized with:
 *
 * int rgb[3];
 *
 * in the calling function. After calling hsi2rgb
 * the vector rgb will contain red, green, and blue
 * calculated values.
 *
 * The input intervals are the following:
 *
 * H -- [0, 360]
 * S -- [0, 1]
 * I -- [0, 1]
 *
 * Source: http://blog.saikoled.com/post/43693602826/why-every-led-light-should-be-using-hsi
 */
extern void hsi2rgb(float H, float S, float I, uint8_t* rgb);

#endif
