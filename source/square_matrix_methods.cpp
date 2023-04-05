#include "setup.hpp"

//-------------------
// Gauss determinant
//-------------------
    template <typename T>
    int square_matrix<T>::to_up_triangale () {
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

    template <typename T>
    long double square_matrix<T>::mul_diag () {
        long double res = 1;
        for (int i = 0; i < size; ++i) {
            if (data[i*size + i] == 0) return 0;
            res *= data[i*size + i];
        }
        return res;
    }

    template <typename T>
    long double square_matrix<T>::gauss_det () {
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
    template <typename T>
    square_matrix<T> square_matrix<T>::make_addition (int i, int j) {
        long double* numbers = new long double [(size-1)*(size-1)];
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
        delete numbers;

        return addition;
    }

    template <typename T>
    long double square_matrix<T>::minor_det () {
        if (size == 1) return (data[0]);

        square_matrix addition = this -> make_addition(0, 0); 
        long double result = 0;
        int sign = 1;

        for (int j = 0; j < size; ++j) {
            result += (sign)*(data[j])*(addition.minor_det());
            sign *= (-1);
            if((j + 1) != size) {
                square_matrix result = this -> make_addition(0, j + 1);
            }
        }

        return result;
    }