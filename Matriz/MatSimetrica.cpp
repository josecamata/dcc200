
#include "MatSimetrica.h"

#include <iostream>
#include <iomanip>

MatSimetrica::MatSimetrica(int n) : n(n) {
    _size = n * (n + 1) / 2; // Calculate size for symmetric matrix
    data = new double[_size](); // Allocate memory for symmetric matrix
}

MatSimetrica::~MatSimetrica() {
    delete[] data;
}

void MatSimetrica::set(int i, int j, double value) {
    if (verificaIndice(i, j)) 
    {
        int idx = index(i, j);
        data[idx] = value;
    }
    else {
        throw std::out_of_range("Invalid matrix indices");
    }
}

double MatSimetrica::get(int i, int j) const {
    if (verificaIndice(i, j)) {
        return data[index(i, j)];
    }
    throw std::out_of_range("Invalid matrix indices");
}

int MatSimetrica::index(int i, int j) const {
    if (i < j) {
        return (j * (j + 1)) / 2 + i; // Upper triangular part
    } else {
        return (i * (i + 1)) / 2 + j; // Lower triangular part
    }
}

bool MatSimetrica::verificaIndice(int i, int j) const {
    return (i >= 0 && i < n && j >= 0 && j < n);
}

void MatSimetrica::print() const {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(5) << std::setprecision(4) << get(i, j) << " ";
        }
        std::cout << std::endl;
    }
}
