#ifndef SETUP_H
#define SETUP_H

#include <iostream>
#include <iomanip>

//--------
// MATRIX
//--------

class matrix {
    private:
        int num_of_strings;
        int num_of_columns;                            
        long double* data;

    public:
        matrix(int strs, int clmns, long double* numbers);   // Usual constructor
        matrix(const matrix& source);                        // Copy constructor
        ~matrix();                                           // Distructor
        matrix& operator= (const matrix& source);            // Operator =

        int get_size() const;                                // Size getter
        void checkout();                                     // Simple dump

        void str_sub(int a, int b, long double lambda);      // Makes string (a) - lambda * string(b)
        void switch_str(int a, int b);                       // Switches string (a) with string (b)
};                                                           
                                                             
//---------------                                             
// SQUARE MATRIX                                              
//---------------                                             
                                                              
class square_matrix : public matrix {                         
    private:                                                  
        int size;                                             
                                                              
    public:                                                   
        int to_up_triangale();                               // Turns matrix with simple operations to upper triangular type
        long double mul_diag();                              // Multiplies diagonal elements
        long double gauss_det();                             // Counts the determinant by the Gauss method
        
        square_matrix make_addition(int i, int j);           // Makes addition to [i,j] element
        long double minor_det();                             // Counts the determinant by the method with minors
};


#endif