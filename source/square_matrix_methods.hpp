#pragma once

#include "setup.hpp"

//--------------
// Construction
//--------------
    template <typename T>
    square_matrix<T>::square_matrix (const matrix<T>& source) :
        matrix<T>(source), size(source.get_num_of_strings()) 
    {
        // std::cout << "Square copy constructor of " << this << std::endl;
        if(source.num_of_columns() != source.num_of_strings()) 
            throw std::invalid_argument("In square_matrix ctor num_of_strings != num_of_columns.");
    }

    template <typename T>
    square_matrix<T>::square_matrix (square_matrix<T>&& rhs) : 
        matrix<T>(std::move(rhs)), size(rhs.size) 
    {   
        // std::cout << "Square move constructor of " << this << std::endl;
        rhs.size = 0;
    }

//-----------------
// Unary operators
//-----------------
    template <typename T>
    square_matrix<T>& square_matrix<T>::operator= (const square_matrix<T>& source) {
        
        matrix<T>::operator= (source);
        size = source.size;
        return *this;
    }

    template <typename T>
    square_matrix<T>& square_matrix<T>::operator= (square_matrix<T>&& source) {
        
        matrix<T>::operator= (source);
        size = source.size;
        return *this;
    }

    template <typename T>
    square_matrix<T>& square_matrix<T>::operator+= (const square_matrix<T>& source) {

        matrix<T>::operator+= (source);
        return *this;
    }

    template <typename T>
    square_matrix<T> square_matrix<T>::operator- () const {

        matrix<T> neg_cpy = this -> matrix<T>::operator-();
        square_matrix<T> sq_neg_cpy (neg_cpy);
        return sq_neg_cpy;
    }

    template <typename T>
    square_matrix<T>& square_matrix<T>::operator*= (const T& lambda) {

        matrix<T>::operator*= (lambda);
        return *this;
    }

//------------------
// Binary operators
//------------------
    template <typename T>
    square_matrix<T> operator+ (const square_matrix<T>& A, const square_matrix<T>& B) {

        square_matrix<T> sq_sum (static_cast< matrix<T> > (A) + static_cast< matrix<T> >(B));
        return sq_sum;
    }


//-------------------
// Gauss determinant
//-------------------
    template <typename T>
    int square_matrix<T>::to_up_triangale () {
        int count_switch = 0;

        for (int i = 0; i < size; ++i) {
            if ((this -> data)[i * size + i ] == 0) {
                int n;
                for (n = i + 1; n < size; ++n) {
                    if ((this -> data)[n * size + i] != 0) break;
                }
                if (n == size) continue;
                else {
                    this -> switch_str(n, i);
                    ++count_switch;
                }
            }

            for (int n = i + 1; n < size; ++n) {
                if ((this -> data)[n * size + i] == 0) continue;
                T lambda = ((this -> data)[n * size + i]) / ((this -> data)[i * size + i]);
                // std::cout << "lambda = " << lambda << std::endl; 
                this -> str_sub(n, i, lambda);
                // this -> checkout();
            }
        }

        return count_switch;
    }

    template <typename T>
    T square_matrix<T>::mul_diag () {
        T res = 1;
        for (int i = 0; i < size; ++i) {
            if ((this -> data)[i * size + i] == 0) return 0;
            res *= (this -> data)[i * size + i];
        }
        return res;
    }

    template <typename T>
    T square_matrix<T>::gauss_det () {
        square_matrix<T> cpy = *this;

        T det;
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
        T* new_data = new T [(size - 1) * (size - 1)];
        int pos = 0;

        for (int n = 0; n < size; ++n) {
            if (n == i) continue;
            else {
                for (int m = 0; m < size; ++m) {
                    if (m == j) continue;
                    else {
                        new_data[pos] = (this -> data)[n * size + m];
                        ++pos;
                    }
                }
            }
        }
        square_matrix<T> addition (size-1, new_data);
        delete new_data;

        return addition;
    }

    template <typename T>
    T square_matrix<T>::minor_det () {
        if (size == 1) return ((this -> data)[0]);

        square_matrix<T> addition = this -> make_addition(0, 0); 
        T result = 0;
        int sign = 1;

        for (int j = 0; j < size; ++j) {
            result += (sign) * ((this -> data)[j]) * (addition.minor_det());
            sign *= (-1);
            if((j + 1) != size) {
                addition = this -> make_addition(0, j + 1);
            }
        }

        return result;
    }