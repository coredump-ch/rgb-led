/**
 * HSI -> RGB color conversion.
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

#pragma once


struct RGB {
    int r;
    int g;
    int b;
};


/**
 * Function example takes H, S and I. It will return a RGB struct
 * that has three members called r, g and b.
 *
 * The input intervals are the following:
 *
 * H -- [0, 360]
 * S -- [0, 1]
 * I -- [0, 1]
 *
 * Source: http://blog.saikoled.com/post/43693602826/why-every-led-light-should-be-using-hsi
 */
RGB hsi2rgb(float H, float S, float I);
