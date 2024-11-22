//
// Created by shimo on 21/11/2024.
//

#ifndef MANDELBROTCALC_H
#define MANDELBROTCALC_H
#include <cmath>
#include <vector>
#include <complex>
#define TRESHHOLD 2
#define MAX_ITARATION 1000
#define BEGIN -2.0f
#define END 0.25f

using namespace std;
float calculatZNext(float z, float c);
bool isCon(complex<float> & z);
complex<float> mandelbrot(const complex<float>&c );
float * mandSet();
#endif //MANDELBROTCALC_H
