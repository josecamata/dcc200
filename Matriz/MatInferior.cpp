
#include "MatInferior.h"

#include <iostream>
#include <iomanip>

MatInferior::MatInferior(int n) : n(n) {
    _size = n * (n + 1) / 2; // Calculate size for lower triangular part
    // Allocate memory for lower triangular part    
    data = new double[n * (n + 1) / 2](); // Allocate memory for lower triangular part
}

MatInferior::~MatInferior() {
    delete[] data;
}

void MatInferior::set(int i, int j, double value) {
    if (i >= j && verificaIndice(i, j)) {
        data[index(i, j)] = value;
    }
}

double MatInferior::get(int i, int j) const {
    if (i >= j && verificaIndice(i, j)) {
        return data[index(i, j)];
    }
    return 0.0; // Or handle error as appropriate
}

int MatInferior::index(int i, int j) const {
    if (i < j) {
        return -1; // Invalid index for lower triangular matrix
    }
    return (i * (i + 1)) / 2 + j; // Triangular matrix indexing
}

bool MatInferior::verificaIndice(int i, int j) const {
    return (i >= 0 && i < n && j >= 0 && j <= i);
}


void MatInferior::print() const {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i >= j) {
                std::cout << std::setw(5) << std::setprecision(4) << get(i, j) << " ";
            } else {
                std::cout << std::setw(5) << 0 << " "; // Print zero for upper part
            }
        }
        std::cout << std::endl;
    }
}

void MatInferior::print_as_array() const {
    for (int i = 0; i < _size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

