
#include "MatSimetrica.h"

#include <iostream>
#include <iomanip>


int main() {
    MatSimetrica matSimetrica(5);
    int count = 0;

    // Fill the symmetric matrix
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            matSimetrica.set(i, j, static_cast<double>(count++));
        }
    }

    std::cout << "Matriz Simétrica:" << std::endl;
    matSimetrica.print();

    

    return 0;
}