#include "setup.h"

matrix matrix::make_addition(int i, int j) {
    long double numbers[(size-1)*(size-1)];
    int pos = 0;

    for (int n = 0; n < size; ++n) {
        if (n == i) continue;
        else {
            for (int m = 0; m < size; ++m) {
                if (m == j) continue;
                else {
                    numbers[pos] = data[n*size + m];
                    ++pos;
                }
            }
        }
    }
    matrix addition (size-1, numbers);
    return addition;
}

long double matrix::minor_det() {
    if (size == 1) return (data[0]);

    matrix addition = make_addition(0, 0); 
    long double result = 0;
    int sign = 1;

    for (int j = 0; j < size; ++j) {
        result += (sign)*(data[j])*(addition.minor_det());
        sign *= (-1);
        if((j + 1) != size) {
            addition = make_addition(0, j + 1);
        }
    }

    return result;
}