#pragma once

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
            // Costruction:
            matrix  (int strs, int clmns, const T* i_data);  
            matrix  (const matrix<T>& source);   
            matrix  (matrix<T>&& rhs);       
            virtual ~matrix (); 

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
                matrix<T>(i_size, i_size, i_data), size(i_size) {}  
             
            square_matrix(const square_matrix<T>& source) :               
                matrix<T>(source), size(source.size) {}  
            
            square_matrix(const matrix<T>& source) :
                matrix<T>(source), size(source.get_num_of_strings()) {
                    if(source.get_num_of_columns() != source.get_num_of_strings()) 
                        throw std::invalid_argument("In square_matrix ctor num_of_strings != num_of_columns.");
                }
            ~square_matrix() {}


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
            T   mul_diag ();                                    
            T   gauss_det ();  

            // Minor determinant:
            square_matrix<T> make_addition (int i, int j);
            T   minor_det ();   
    };

    // Binary operators:
    template <typename T> square_matrix<T> operator+ (const square_matrix<T>& A, const square_matrix<T>& B);       
    template <typename T> square_matrix<T> operator- (const square_matrix<T>& A, const square_matrix<T>& B); 




