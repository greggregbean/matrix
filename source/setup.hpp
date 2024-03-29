#pragma once

#include <iostream>
#include <iomanip>
#include <vector>  // not for my class, but for main.cpp

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
            // Costruction:
            matrix (int strs, int clmns, const T* i_data);  // usual
            matrix (const matrix<T>& source);               // copy
            matrix (matrix<T>&& rhs);                       // move 
            virtual ~matrix() noexcept; 

            // Getters:
            int get_num_of_strings() const {return num_of_strings;}    
            int get_num_of_columns() const {return num_of_columns;}   

            // Simple dump:
            void checkout ();   

            // Verifies if number of columns and number of strings in A & B are correct:
            static int verification (const matrix<T>& A, const matrix<T>& B); 

            // Unary operstors:
            matrix<T>& operator=  (const matrix<T>& source);
            matrix<T>& operator=  (matrix<T>&& source);                
            matrix<T>& operator+= (const matrix<T>&  source);                
            matrix<T>  operator-  () const;                                 
            matrix<T>& operator*= (const T& lambda);              
            matrix<T>& operator*= (const matrix<T>& source);  

            // Binary operator*:
            template <typename T1>
            friend matrix<T1> operator* (const matrix<T1>& A, const matrix<T1>& B);

            template <typename T1>
            friend matrix<T1> cache_friendly_mul (const matrix<T1>& A, const matrix<T1>& B);               

            // Other matrix functions:
            void str_sub     (int a, int b, const T& lambda); 
            void switch_str  (int a, int b);                     
            matrix<T> transpose ();                                 
    }; 

    // Binary operators:
    template <typename T> matrix<T> operator+ (const matrix<T>& A, const matrix<T>& B);       
    template <typename T> matrix<T> operator- (const matrix<T>& A, const matrix<T>& B);       
    template <typename T> matrix<T> operator* (const matrix<T>& A, const T& lambda);
    template <typename T> matrix<T> operator* (const T& lambda, const matrix<T>& A);
                                                             
//---------------                                             
// SQUARE MATRIX                                              
//---------------                                                                                                        
    template <typename T> class square_matrix final : public matrix<T>  {                         
        private:                                                  
            int size;                                             
                                                                
        public:
            // Construction:
            square_matrix(int i_size, const T* i_data) :
                matrix<T>(i_size, i_size, i_data), size(i_size) {
                    // std::cout << "Squre usual constructor of " << this << std::endl;
                }      
            square_matrix(const square_matrix<T>& source) :               
                matrix<T>(source), size(source.size) {
                    // std::cout << "Square copy constructor of " << this << std::endl;
                }             
            square_matrix (const matrix<T>& source);
            square_matrix (square_matrix<T>&& rhs);
            ~square_matrix() noexcept {}


            // Getter:
            int get_size() const {return size;}

            // Unary operators:
            square_matrix<T>& operator=  (const square_matrix<T>& source);
            square_matrix<T>& operator=  (square_matrix<T>&& source);
            square_matrix<T>& operator+= (const square_matrix<T>& source);
            square_matrix<T>  operator-  () const;
            square_matrix<T>& operator*= (const T& lambda);              

            // Gauss determinant:
            int to_up_triangale ();                                    
            T mul_diag ();                                    
            T gauss_det ();  

            // Minor determinant:
            square_matrix<T> make_addition (int i, int j);
            T minor_det ();   
    };

    // Binary operators:
    template <typename T> square_matrix<T> operator+ (const square_matrix<T>& A, const square_matrix<T>& B);       
    template <typename T> square_matrix<T> operator- (const square_matrix<T>& A, const square_matrix<T>& B); 




