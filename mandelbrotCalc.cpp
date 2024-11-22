//
// Created by shimo on 21/11/2024.
//
#include "mandelbrotCalc.h"
#include <stdlib.h>
float calculatZNext(float z, float c) {
    return powf(z,2)+c;
}
bool isCon(complex<float> & z) {
    return fabs(z) < 2.0f;
}
complex<float> mandelbrot(const complex<float>&c ) {
    int i = 0;
    complex<float> z(0,0);
    while(i< MAX_ITARATION && abs(z)<TRESHHOLD) {
        z = z * z +c;
        i++;
    }
    return z ;
}
float * mandSet() {
    float set[3 * MAX_ITARATION];
    float * pSet =&*(set);

    int count = 0;
    int index = 0;
    complex<float> c(-0.7,0.220);
    while(count < MAX_ITARATION) {
        complex<float> z = mandelbrot(c);
        if(isCon(z)) {
            set[index] = c.real();
            set[++index] = c.imag();
            set[++index] = 0.0f;

            count++;
        }

        c.real(c.real()+0.01f);
        c.imag(c.imag());
    }
    return pSet;
}