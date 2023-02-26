#ifndef SETUP_H
#define SETUP_H

#include <iostream>
#include <iomanip>

#define VERIFIED     1
#define NOT_VERIFIED 0

//--------
// MATRIX
//--------
    class matrix {
        protected:
            int num_of_strings;
            int num_of_columns;                            
            long double* data;

        public:
            matrix  (int strs, int clmns, long double* numbers);                    // Usual constructor
            matrix  (const matrix& source);                                         // Copy constructor
            ~matrix ();                                                             // Distructor

            friend int verification  (const matrix& A, const matrix& B);            // Verifies if number of columns and number of strings in A & B are correct

            matrix&       operator=  (const matrix& source);                        // Operator =
            matrix&       operator+= (const matrix& source);                        // Operator +=
            matrix        operator-  () const;                                      // Unary operator -
            friend matrix operator*  (const matrix& A, const matrix& B);            // Binary operator*
            matrix&       operator*= (const long double& lambda);                   // Unary operator* by lamda
            matrix&       operator*= (const matrix& source);                        // Unary operator* by another matrix

            void checkout ();                                                       // Simple dump

            void str_sub     (int a, int b, long double lambda);                    // Makes string (a) - lambda * string(b)
            void switch_str  (int a, int b);                                        // Switches string (a) with string (b)
            matrix transpose ();                                                    // Transpose matrix
    }; 

    matrix operator+ (const matrix& A, const matrix& B);                            // Binary operator+
    matrix operator- (const matrix& A, const matrix& B);                            // Binary operator-
    matrix operator* (const matrix& A, const long double& lambda);                  // Binary operator* by lambda
    matrix operator* (const long double& lambda, const matrix& A);                  // Binary operator* by lambda
                                                             
//---------------                                             
// SQUARE MATRIX                                              
//---------------                                                                                                        
    class square_matrix : public matrix {                         
        private:                                                  
            int size;                                             
                                                                
        public: 
            square_matrix(int strs, int clmns, long double* numbers):    // Usual constructor
                matrix(strs, clmns, numbers), size(strs) {}             
            square_matrix(const square_matrix& source):                  // Copy constructor
                matrix(source), size(source.num_of_strings) {}          

            int   to_up_triangale ();                                    // Turns matrix with simple operations to upper triangular type
            long double  mul_diag ();                                    // Multiplies diagonal elements
            long double gauss_det ();                                    // Counts the determinant by the Gauss method
            
            square_matrix make_addition (int i, int j);                  // Makes addition to [i,j] element
            long double   minor_det ();                                  // Counts the determinant by the method with minors
    };


#endif