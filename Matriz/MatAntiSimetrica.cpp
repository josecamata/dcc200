

#include "MatAntiSimetrica.h"

#include <iostream>
#include <iomanip>

MatAntiSimetrica::MatAntiSimetrica(int n) : n(n) {
    _size = n * (n - 1) / 2; // Calculate size for anti-symmetric matrix
    data = new double[_size](); // Allocate memory for anti-symmetric matrix
}

MatAntiSimetrica::~MatAntiSimetrica() {
    delete[] data;
}


// Armazenar apenas da matriz antissimétrica como
// matriz triangular inferiror

int MatAntiSimetrica::index(int i, int j) const {
    if (i <= j) {
        return -1; // Invalid index for anti-symmetric matrix
    }
    return (i * (i - 1)) / 2 + j; // Triangular matrix indexing
}

bool MatAntiSimetrica::verificaIndice(int i, int j) const {
    return (i >= 0 && i < n && j >= 0 && j < n);
}

void MatAntiSimetrica::set(int i, int j, double value) {
    if (!verificaIndice(i, j))
    {
        throw std::out_of_range("Indices Invalidos para matriz antissimétrica");
    }

    if( i == j )
    {
        if(value != 0.0)
        {
            throw std::invalid_argument("Elementos da diagonal de uma matriz antissimétrica devem ser zero.");
        }
        return;
    }

    if(i < j) {
        data[index(j, i)] = -value; // Store in upper triangular part
    } else {
        data[index(i, j)] = value; // Store in lower triangular part with negation
    }
    
}

double MatAntiSimetrica::get(int i, int j) const {
    if (!verificaIndice(i, j)) {
        throw std::out_of_range("Indices Invalidos para matriz antissimétrica");
    }

    if (i == j) {
        return 0.0; // Diagonal elements are always zero
    }

    if (i < j) {
        return -data[index(j, i)]; // Return negated value from upper triangular part
    } else {
        return data[index(i, j)]; // Return value from lower triangular part
    }
}

void MatAntiSimetrica::print() const {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i < j) {
                std::cout << std::setw(5) << std::setprecision(4) << -get(j, i) << " "; // Print negated value
            } else if (i > j) {
                std::cout << std::setw(5) << std::setprecision(4) << get(i, j) << " ";
            } else {
                std::cout << std::setw(5) << 0.0 << " "; // Diagonal elements are zero
            }
        }
        std::cout << std::endl;
    }
}

void MatAntiSimetrica::print_as_array() const {
    for (int i = 0; i < _size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

