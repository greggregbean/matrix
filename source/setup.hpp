#ifndef SETUP_H
#define SETUP_H

#include <iostream>
#include <iomanip>

#define VERIFIED     1
#define NOT_VERIFIED 0

//--------
// MATRIX
//--------
    template <typename T> class matrix {
        protected:
            int num_of_strings;
            int num_of_columns;                            
            T* data;

        public:
            matrix  (int strs, int clmns, T* numbers);  // Usual constructor
            matrix  (const matrix<T>& source);          // Copy constructor
            ~matrix ();                                 // Distructor

     friend int verification  (const matrix<T>& A, const matrix<T>& B); // Verifies if number of columns and 
                                                                        // number of strings in A & B are correct

            matrix<T>& operator=  (const matrix<T>& source);                // Operator =
            matrix<T>& operator+= (const matrix<T>& source);                // Operator +=
            matrix<T>  operator-  () const;                                 // Unary operator -
     friend matrix<T>  operator*  (const matrix<T>& A, const matrix<T>& B); // Binary operator*
            matrix<T>& operator*= (const long double& lambda);              // Unary operator* by lamda
            matrix<T>& operator*= (const matrix<T>& source);                // Unary operator* by another matrix

            void checkout ();  // Simple dump

            void str_sub     (int a, int b, long double lambda); // Makes string (a) - lambda * string(b)
            void switch_str  (int a, int b);                     // Switches string (a) with string (b)
            matrix transpose ();                                 // Transpose matrix
    }; 

    template <typename T> matrix<T> operator+ (const matrix<T>& A, const matrix<T>& B);       // Binary operator+
    template <typename T> matrix<T> operator- (const matrix<T>& A, const matrix<T>& B);       // Binary operator-
    template <typename T> matrix<T> operator* (const matrix<T>& A, const long double& lambda);// Binary operator* by lambda
    template <typename T> matrix<T> operator* (const long double& lambda, const matrix<T>& A);// Binary operator* by lambda
                                                             
//---------------                                             
// SQUARE MATRIX                                              
//---------------                                                                                                        
    template <typename T> class square_matrix : public matrix<T> {                         
        private:                                                  
            int size = this -> num_of_strings;                                             
                                                                
        public: 
            square_matrix(int strs, int clmns, long double* numbers):    // Usual constructor
                matrix(strs, clmns, numbers) {}             
            // square_matrix(const square_matrix& source):               // Copy constructor
            //     matrix(source) {}          

            int   to_up_triangale ();                                    // Turns matrix with simple operations to upper triangular type
            long double  mul_diag ();                                    // Multiplies diagonal elements
            long double gauss_det ();                                    // Counts the determinant by the Gauss method
            
            square_matrix make_addition (int i, int j);                  // Makes addition to [i,j] element
            long double   minor_det ();                                  // Counts the determinant by the method with minors
    };


#endif