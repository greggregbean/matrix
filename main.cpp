#include "setup.h"

int main(int argc, char* argv[]) {
    size_t n;
    std::cout << "Enter size of matrix: " << std::endl;
    std::cin >> n;

    double numbers[n*n];
    std::cout << "Enter data of matrix: " << std::endl;
    for(int i = 0; i < n; ++i) {
        for(int k = 0; k < n; ++k) {
            std::cin >> numbers[n*i + k];
        }
    }

    matrix A (n, numbers);
    A.checkout();

    matrix A_addition = A.make_addition(1, 1);
    A_addition.checkout();

}