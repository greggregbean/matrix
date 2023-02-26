#include "setup.h"

//--------------
// Construction
//--------------
    matrix::matrix (int strs, int clmns, long double* numbers) : 
        num_of_strings(strs), num_of_columns(clmns) {
            // std::cout << "Usual constructor of " << this << std::endl;

            data = new long double [num_of_strings * num_of_columns];

            for (int i = 0; i < num_of_strings; ++i) {
                for (int j = 0; j < num_of_columns; ++j) {
                    data [i*num_of_columns + j] = numbers [i*num_of_columns + j];
                }
            }
        }

    matrix::matrix (const matrix& source) : 
        num_of_strings(source.num_of_strings), num_of_columns(source.num_of_columns) {
            //std::cout << "Copy constructor of " << this << std::endl;

            data = new long double[source.num_of_strings * source.num_of_columns];

            for (int i = 0; i < num_of_strings; ++i) {
                for (int j = 0; j < num_of_columns; ++j) {
                    data [i*num_of_columns + j] = (source.data) [i*num_of_columns + j];
                }
            }  
        }

    matrix::~matrix () {
        //std::cout << "Distructor of " << this << std::endl;
        delete data;
    }

//------
// Dump
//------
    void matrix::checkout () {
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
    int verification (const matrix& A, const matrix& B) {
        if (A.num_of_columns != B.num_of_columns) {
            std::cout << "Matrix " << &A << " has no the same numers of columns as " << &B << "!!!" << std::endl;
            return NOT_VERIFIED; 
        }

        if (A.num_of_strings != B.num_of_strings) {
            std::cout << "Matrix " << &A << " has no the same number of strings as " << &B << "!!!" << std::endl;
            return NOT_VERIFIED;
        }

        return VERIFIED;
    }

//-----------------
// Unary operators
//-----------------
    matrix& matrix::operator= (const matrix& source) {
        if ((num_of_strings * num_of_columns) != (source.num_of_strings * source.num_of_columns)) {
            delete data;
            data = new long double [source.num_of_strings * source.num_of_columns];
            num_of_strings = source.num_of_strings;
            num_of_columns = source.num_of_columns;
        }

        for (int i = 0; i < num_of_strings; ++i) {
            for (int j = 0; j < num_of_columns; ++j) {
                data [i * num_of_columns + j] = (source.data) [i * num_of_columns + j];
            }
        }

        return *this;
    }

    matrix& matrix::operator+= (const matrix& source) {
        if (verification(*this, source) == NOT_VERIFIED) {
            std::cout << "Error in operator+= !!!" << std::endl;
            return *this;
        }

        for (int i = 0; i < num_of_strings; ++i) {
            for (int j = 0; j < num_of_columns; ++j) {
                data [i * num_of_columns + j] += (source.data) [i * num_of_columns + j];
            }
        }

        return *this;
    }

    matrix matrix::operator- () const {
        matrix neg_cpy = *this;

        for (int i = 0; i < num_of_strings; ++i) {
            for (int j = 0; j < num_of_columns; ++j) {
                neg_cpy.data [i * num_of_columns + j] *= (-1);
            }
        }

        return neg_cpy;
    }

    matrix& matrix::operator*= (const long double& lambda) {
        for (int i = 0; i < num_of_strings; ++i) {
            for (int j = 0; j < num_of_columns; ++j) {
                data [i * num_of_columns + j] *= lambda;
            }
        }

        return *this;
    }

    matrix& matrix::operator*= (const matrix& source) {
        *this = (*this) * source;
        return *this;
    }

//------------------
// Binary operators
//------------------
    matrix operator+ (const matrix &A, const matrix& B)
    {
        if (verification(A, B) == NOT_VERIFIED) {
            std::cout << "Error in binary operator+ !!!" << std::endl;
            return A;
        }

        matrix sum = A;
        sum += B;
        return sum;
    }

    matrix operator- (const matrix &A, const matrix& B) {
        if (verification(A, B) == NOT_VERIFIED) {
            std::cout << "Error in binary operator- !!!" << std::endl;
            return A;
        }

        matrix sub = A;
        sub += -B;
        return sub;
    }

    matrix operator* (const matrix& A, const matrix& B) {
        if (A.num_of_columns != B.num_of_strings) {
            std::cout << "Number of strings in matrix " << &A << " is not equal to number of columns in " << &B << "!!!" << std::endl;
            return A;
        }

        long double data [A.num_of_strings * B.num_of_columns];

        for (int m = 0; m < A.num_of_strings; ++m) {
            for (int k = 0; k < B.num_of_columns; ++k) {
                long double sum = 0;
                
                for(int i = 0; i < A.num_of_columns; ++i) {
                    sum += (A.data [m * A.num_of_columns + i]) * (B.data [i * B.num_of_columns + k]);
                }

                data [m * B.num_of_columns + k] = sum;
            }
        }
        
        matrix C (A.num_of_strings, B.num_of_columns, data);

        return C;
    }

    matrix operator* (const matrix& A, const long double& lambda) {
        matrix C = A;
        C *= lambda;
        return C;
    }

    matrix operator* (const long double& lambda, const matrix& A) {
        matrix C = A;
        C *= lambda;
        return C;
    }

//------------------------
// Other matrix functions
//------------------------
    void matrix::str_sub (int a, int b, long double lambda) {
        for (int j = 0; j < num_of_columns; ++j) {
            data [a * num_of_columns + j] -= lambda * data [b * num_of_columns + j];
        }
    }

    void matrix::switch_str (int a, int b) {
        long double tmp;
        for (int j = 0; j < num_of_columns; ++j) {
            tmp = data[a * num_of_columns + j];
            data[a * num_of_columns + j] = data[b * num_of_columns + j];
            data[b * num_of_columns + j] = tmp;
        }
    }

    matrix matrix::transpose () {
        long double new_data [num_of_strings * num_of_strings];
        int i, j;
        
        for (int n = 0; n < num_of_strings * num_of_columns; ++n) {
            i = n/num_of_strings;
            j = n%num_of_strings;
            new_data [n] = data [num_of_columns * j + i];
        }

        return matrix (num_of_columns, num_of_strings, new_data);
    }
