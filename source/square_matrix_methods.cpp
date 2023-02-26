#include "setup.h"

//-------------------
// Gauss determinant>
//-------------------
    int square_matrix::to_up_triangale() {
        int count_switch = 0;

        for (int i = 0; i < size; ++i) {
            if (data[i*size + i ] == 0) {
                int n;
                for (n = i+1; n < size; ++n) {
                    if (data[n*size + i] != 0) break;
                }
                if (n == size) continue;
                else {
                    switch_str(n, i);
                    ++count_switch;
                }
            }

            for (int n = i+1; n < size; ++n) {
                if (data[n*size + i] == 0) continue;
                long double lambda = (data[n*size + i]) / (data[i*size + i]);
                std::cout << "lambda = " << lambda << std::endl; 
                this -> str_sub(n, i, lambda);
                this -> checkout();
            }
        }

        return count_switch;
    }

    long double square_matrix::mul_diag() {
        long double res = 1;
        for (int i = 0; i < size; ++i) {
            if (data[i*size + i] == 0) return 0;
            res *= data[i*size + i];
        }
        return res;
    }

    long double square_matrix::gauss_det() {
        square_matrix cpy = *this;

        long double det;
        if ((cpy.to_up_triangale() % 2) == 0) det = 1;
        else det = -1;

        det *= cpy.mul_diag();
        
        return det;
    }

//-------------------
// Minor determinant
//-------------------
    square_matrix square_matrix::make_addition(int i, int j) {
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
        square_matrix addition (size-1, size-1, numbers);
        return addition;
    }

    long double square_matrix::minor_det() {
        if (size == 1) return (data[0]);

        square_matrix addition = make_addition(0, 0); 
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