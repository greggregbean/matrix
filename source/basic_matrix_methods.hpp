#pragma once

#include "setup.hpp"

//--------------
// Construction
//--------------
    template <typename T>
    matrix<T>::matrix (int strs, int clmns, const T* i_data) : 
        num_of_strings(strs), num_of_columns(clmns) {
        // std::cout << "Usual constructor of " << this << std::endl;

        data = new T [num_of_strings * num_of_columns];

        for (int i = 0; i < num_of_strings; ++i) {
            for (int j = 0; j < num_of_columns; ++j) {
                data [i*num_of_columns + j] = i_data [i*num_of_columns + j];
            }
        }
    }

    template <typename T>
    matrix<T>::matrix (const matrix<T>& source) : 
        num_of_strings(source.num_of_strings), num_of_columns(source.num_of_columns) {
        // std::cout << "Copy constructor of " << this << std::endl;

        data = new T [source.num_of_strings * source.num_of_columns];

        for (int i = 0; i < num_of_strings; ++i) {
            for (int j = 0; j < num_of_columns; ++j) {
                data [i*num_of_columns + j] = (source.data) [i*num_of_columns + j];
            }
        }  
    }

    template <typename T>
    matrix<T>::matrix (matrix<T>&& source) :
        num_of_strings(source.num_of_strings), num_of_columns(source.num_of_columns), data(source.data) {
        // std::cout << "Move constructor of " << this << std::endl;

        source.data = nullptr;
    }

    template <typename T>
    matrix<T>::~matrix () {
        // std::cout << "Distructor of " << this << std::endl;

        delete [] data;
    }

//------
// Dump
//------
    template <typename T>
    void matrix<T>::checkout () {

        for (int i = 0; i < num_of_strings; ++i) {
            std::cout << "| ";
            for(int j = 0; j < num_of_columns; ++j) {
                std::cout << std::setw(3u) << data[i * num_of_columns + j] << std::setw(3u) << " ";
            }
            std::cout << "|" << std::endl;
        }

        std::cout << std::endl;
    }

//----------------------------
// Verification for operators
//----------------------------
    template <typename T>
    int matrix<T>::verification (const matrix<T>& A, const matrix<T>& B)  {

        if (A.num_of_columns != B.num_of_columns) {
            std::cout << "Matrix " << &A << " has no the same numers of columns as " << &B << "." << std::endl;
            return NOT_VERIFIED; 
        }

        if (A.num_of_strings != B.num_of_strings) {
            std::cout << "Matrix " << &A << " has no the same number of strings as " << &B << "." << std::endl;
            return NOT_VERIFIED;
        }

        return VERIFIED;
    }

//-----------------
// Unary operators
//-----------------
    template <typename T>
    matrix<T>& matrix<T>::operator= (const matrix<T>& source) {
        // std::cout << "Lvalue& operator =" << std::endl;

        if ((num_of_strings * num_of_columns) != (source.num_of_strings * source.num_of_columns)) {
            delete [] data;
            data = new T [source.num_of_strings * source.num_of_columns];
        }

        num_of_strings = source.num_of_strings;
        num_of_columns = source.num_of_columns;

        for (int i = 0; i < num_of_strings; ++i) {
            for (int j = 0; j < num_of_columns; ++j) {
                data [i * num_of_columns + j] = (source.data) [i * num_of_columns + j];
            }
        }

        return *this;
    }

    template <typename T>
    matrix<T>& matrix<T>::operator= (matrix<T>&& source) {
        // std::cout << "Rvalue& operator =" << std::endl;

        if ((num_of_strings * num_of_columns) != (source.num_of_strings * source.num_of_columns)) {
            delete [] data;
            data = new T [source.num_of_strings * source.num_of_columns];
        }

        num_of_strings = source.num_of_strings;
        num_of_columns = source.num_of_columns;

        std::swap(data, source.data);

        return *this;
    }

    template <typename T>
    matrix<T>& matrix<T>::operator+= (const matrix<T>& source) {

        if (verification(*this, source) == NOT_VERIFIED)
            throw std::invalid_argument("In operator+= invalid dimentions of source.");

        for (int i = 0; i < num_of_strings; ++i) {
            for (int j = 0; j < num_of_columns; ++j) {
                data [i * num_of_columns + j] += (source.data) [i * num_of_columns + j];
            }
        }

        return *this;
    }

    template <typename T>
    matrix<T> matrix<T>::operator- () const {

        matrix<T> neg_cpy = *this;

        for (int i = 0; i < num_of_strings; ++i) {
            for (int j = 0; j < num_of_columns; ++j) {
                neg_cpy.data [i * num_of_columns + j] *= (-1);
            }
        }

        return neg_cpy;
    }

    template <typename T>
    matrix<T>& matrix<T>::operator*= (const T& lambda) {

        for (int i = 0; i < num_of_strings; ++i) {
            for (int j = 0; j < num_of_columns; ++j) {
                data [i * num_of_columns + j] *= lambda;
            }
        }

        return *this;
    }

    template <typename T>
    matrix<T>& matrix<T>::operator*= (const matrix<T>& source) {

        *this = (*this) * source;
        return *this;
    }

//------------------
// Binary operators
//------------------
    template <typename T>
    matrix<T> operator+ (const matrix<T>& A, const matrix<T>& B) {

        if (verification(A, B) == NOT_VERIFIED)
            throw std::invalid_argument("In operator+ invalid dimentions.");

        matrix<T> sum = A;
        sum += B;
        return sum;
    }

    template <typename T>
    matrix<T> operator- (const matrix<T>& A, const matrix<T>& B) {

        if (verification(A, B) == NOT_VERIFIED) 
            throw std::invalid_argument("In " << &A << " - " << &B << " invalid dimentions.");

        matrix<T> sub = A;
        sub += -B;
        return sub;
    }

    template <typename T>
    matrix<T> cache_friendly_mul (const matrix<T>& A, const matrix<T>& B) {

        if (A.num_of_columns != B.num_of_strings) {
            throw std::invalid_argument("In cache friendly matrix multiplication \
            number of strings in first is not equal to number of columns in second.");
        }

        T* data = new T [A.num_of_strings * B.num_of_columns] {'\0'};

        int Aik;

        for (int k = 0; k < A.num_of_columns; ++k) {
            for (int i = 0; i < A.num_of_strings; ++i) {
                Aik = A.data[i*A.num_of_columns + k];

                for (int j = 0; j < B.num_of_columns; ++j) {
                    data[i*B.num_of_columns + j] += Aik * B.data[k*B.num_of_columns + j]; 
                }
            }
        }

        matrix<T> C (A.num_of_strings, B.num_of_columns, data);

        delete [] data;

        return C;
    }

    template <typename T>
    matrix<T> operator* (const matrix<T>& A, const matrix<T>& B) {

        if (A.num_of_columns != B.num_of_strings) {
            throw std::invalid_argument("In matrix multiplication \
            number of strings in first is not equal to number of columns in second.");
        }

        T* data = new T [A.num_of_strings * B.num_of_columns];

        for (int m = 0; m < A.num_of_strings; ++m) {
            for (int k = 0; k < B.num_of_columns; ++k) {
                T sum = 0;
                
                for(int i = 0; i < A.num_of_columns; ++i) {
                    sum += (A.data [m * A.num_of_columns + i]) * (B.data [i * B.num_of_columns + k]);
                }

                data [m * B.num_of_columns + k] = sum;
            }
        }
        
        matrix<T> C (A.num_of_strings, B.num_of_columns, data);

        delete [] data;

        return C;
    }

    template <typename T>
    matrix<T> operator* (const matrix<T>& A, const T& lambda) {

        matrix<T> C = A;
        C *= lambda;
        return C;
    }

    template <typename T>
    matrix<T> operator* (const T& lambda, const matrix<T>& A) {

        matrix<T> C = A;
        C *= lambda;
        return C;
    }

//------------------------
// Other matrix functions
//------------------------
    template <typename T>
    void matrix<T>::str_sub (int a, int b, const T& lambda) {

        if (a < 0 || a >= num_of_strings)
            throw std::invalid_argument("Error in str_sub. Invalid number of first string.");
        
        else if (b < 0 || b >= num_of_strings)
            throw std::invalid_argument("Error in str_sub. Invalid number of second string.");
        

        for (int j = 0; j < num_of_columns; ++j) {
            data [a * num_of_columns + j] -= lambda * data [b * num_of_columns + j];
        }
    }

    template <typename T>
    void matrix<T>::switch_str (int a, int b) {

        if (a < 0 || a >= num_of_strings)
            throw std::invalid_argument("Error in switch_str. Invalid number of first string.");

        else if (b < 0 || b >= num_of_strings)
            throw std::invalid_argument("Error in switch_str. Invalid number of second string.");

        for (int j = 0; j < num_of_columns; ++j) {
            std::swap(data[a * num_of_columns + j], data[b * num_of_columns + j]);
        }
    }

    template <typename T>
    matrix<T> matrix<T>::transpose () {

        T* new_data = new T [num_of_strings * num_of_strings];
        int i, j;
        
        for (int n = 0; n < num_of_strings * num_of_columns; ++n) {
            i = n/num_of_strings;
            j = n%num_of_strings;
            new_data [n] = data [num_of_columns * j + i];
        }

        matrix<T> result (num_of_columns, num_of_strings, new_data);
        delete [] new_data;

        return result;
    }
