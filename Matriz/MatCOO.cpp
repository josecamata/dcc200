
#include "MatCOO.h"

#include <stdexcept>


MatCOO::MatCOO(int n) : n(n), count(0), capacity(10) {
    data = new Elemento[capacity];
}

MatCOO::~MatCOO() {
    delete[] data;
}

void MatCOO::resize() {
    capacity *= 2;
    Elemento* newData = new Elemento[capacity];
    for (int i = 0; i < count; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}



void MatCOO::set(int i, int j, double value) 
{
    if (!verificaIndice(i, j)) {
        throw std::out_of_range("Indices out of range");
    }

    for (int k = 0; k < count; ++k) {
        if (data[k].row == i && data[k].col == j) {
            data[k].value = value;
            return;
        }
    }

    if (count >= capacity) {
        resize();
    }

    data[count++] = {i, j, value};
}

double MatCOO::get(int i, int j) const {
    if (!verificaIndice(i, j)) {
        throw std::out_of_range("Indices out of range");
    }

    for (int k = 0; k < count; ++k) {
        if (data[k].row == i && data[k].col == j) {
            return data[k].value;
        }
    }
    return 0.0; // Return 0 for non-existent elements
}

bool MatCOO::verificaIndice(int i, int j) const {
    return (i >= 0 && i < n && j >= 0 && j < n);
}

void MatCOO::print() const {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cout << get(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

void MatCOO::print_as_array() const {
    for (int k = 0; k < count; ++k) {
        std::cout << "(" << data[k].row << ", " << data[k].col << ") = " << data[k].value << std::endl;
    }
}

int MatCOO::size() const {
    return n;
}

int MatCOO::non_zero_count() const {
    return count;
}



