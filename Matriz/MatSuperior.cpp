
#include "MatSuperior.h"

#include <iostream>
#include <iomanip>

MatSuperior::MatSuperior(int n) : n(n) {
    _size = n*(n + 1) / 2;                    // Calculate size for upper triangular part
    data = new double[_size];                 // Allocate memory for upper triangular part
}

MatSuperior::~MatSuperior() {
    delete[] data;
}

void MatSuperior::set(int i, int j, double value) {
    if (i <= j && verificaIndice(i, j)) {
        data[index(i, j)] = value;
    }
}

double MatSuperior::get(int i, int j) const {
    if (i <= j && verificaIndice(i, j)) {
        return data[index(i, j)];
    }
    return 0.0; // Or handle error as appropriate
}

int MatSuperior::index(int i, int j) const {
    if (i > j) {
        return -1; // Invalid index for upper triangular matrix
    }
    return (j * (j + 1)) / 2 + i; // Triangular matrix indexing
}

bool MatSuperior::verificaIndice(int i, int j) const {
    return (i >= 0 && i < n && j >= 0 && j < n);
}


void MatSuperior::print() const {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i <= j) {
                std::cout << std::setw(5) << std::setprecision(4) << get(i, j) << " ";
            } else {
                std::cout << std::setw(5) << 0 << " "; // Print zero for lower part
            }
        }
        std::cout << std::endl;
    }
}

void MatSuperior::print_as_array() const {
    for (int i = 0; i < _size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}
