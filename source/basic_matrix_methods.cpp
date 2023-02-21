#include "setup.h"

matrix::matrix (int strs, int clmns, long double* numbers) : num_of_strings(strs), num_of_columns(clmns) {
    //std::cout << "Usual constructor of " << this << std::endl;

    data = new long double [num_of_strings * num_of_columns];

    for (int i = 0; i < num_of_strings; ++i) {
        for (int j = 0; j < num_of_columns; ++j) {
            data [i*num_of_columns + j] = numbers [i*num_of_columns + j];
        }
    }
}

matrix::matrix (const matrix& source) {
    //std::cout << "Copy constructor of " << this << std::endl;
    
    num_of_strings = source.num_of_strings;
    num_of_columns = source.num_of_columns;

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

matrix& matrix::operator= (const matrix& source) {
    //std::cout << "Operator= of " << this << std::endl;

    for (int i = 0; i < num_of_strings; ++i) {
        for (int j = 0; j < num_of_columns; ++j) {
            data [i * num_of_columns + j] = (source.data) [i*num_of_columns + j];
        }
    }

    return *this;
}

void matrix::str_sub(int a, int b, long double lambda) {
    for (int j = 0; j < num_of_columns; ++j) {
        data [a * num_of_columns + j] -= lambda * data [b * num_of_columns + j];
    }
}

void matrix::switch_str(int a, int b) {
    long double tmp;
    for (int j = 0; j < num_of_columns; ++j) {
        tmp = data[a * num_of_columns + j];
        data[a * num_of_columns + j] = data[b * num_of_columns + j];
        data[b * num_of_columns + j] = tmp;
    }
}
