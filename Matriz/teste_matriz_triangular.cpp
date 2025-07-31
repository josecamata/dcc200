

#include "MatInferior.h"
#include "MatSuperior.h"

#include <iostream>



int main()
{
    MatInferior matInferior(5);
    MatSuperior matSuperior(5);
    int count1 = 0;
    int count2 = 0;
    for(int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (i >= j) {
                matInferior.set(i, j, static_cast<double>(count1++));
            }
            if (i <= j) {
                matSuperior.set(i, j, static_cast<double>(count2++));
            }
        }
    }
    std::cout << "Matriz Triangular Inferior:" << std::endl;
    matInferior.print();

    std::cout << "Array da Matriz Inferior:" << std::endl;
    matInferior.print_as_array();

    std::cout << std::endl;

    std::cout << "Matriz Triangular Superior:" << std::endl;
    matSuperior.print();

    std::cout << "Array da Matriz Superior:" << std::endl;
    matSuperior.print_as_array();   

    return 0;

}