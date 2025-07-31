

#include "MatTriDiag.h"

#include <iostream>
#include <iomanip>

MatTriDiag::MatTriDiag(int n) : n(n) {
    _size = 3 * n - 2; // Size for tridiagonal matrix
    data = new double[_size](); // Allocate memory for tridiagonal matrix
}

MatTriDiag::~MatTriDiag() {
    delete[] data;
}

int MatTriDiag::index(int i, int j) const {
    if (i < 0 || i >= n || j < 0 || j >= n) {
        return -1; // Invalid index
    }
    if (i == j) {
        return i; // Main diagonal
    } else if (j == i + 1) {
        return n + i; // Upper diagonal
    } else if (i == j + 1) {
        return 2 * n - 2 + j; // Lower diagonal
    }
    return -1; // Not a tridiagonal element
}

bool MatTriDiag::verificaIndice(int i, int j) const {
    return index(i, j) != -1;
}

void MatTriDiag::set(int i, int j, double value) {
    int idx = index(i, j);
    if (idx != -1) {
        data[idx] = value;
    }
}

double MatTriDiag::get(int i, int j) const {
    int idx = index(i, j);
    if (idx != -1) {
        return data[idx];
    }
    return 0.0; // Default value for non-existent elements
}

void MatTriDiag::print() const {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (verificaIndice(i, j)) {
                std::cout << std::setw(10) << get(i, j);
            } else {
                std::cout << std::setw(10) << 0.0;
            }
        }
        std::cout << std::endl;
    }
}

void MatTriDiag::print_as_array() const {
    for (int i = 0; i < _size; ++i) {
        std::cout << std::setw(10) << data[i];
    }
    std::cout << std::endl;
}


