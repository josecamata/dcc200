#include "MatCOO.h"

#include <iostream>
using namespace std;


int main() {
    MatCOO mat(5);
    
    mat.set(0, 0, 1.0);
    mat.set(1, 2, 2.0);
    mat.set(3, 4, 3.0);

    cout << "Tamanho da matriz: " << mat.size() << endl;
    cout << "Elemento (0, 0): " << mat.get(0, 0) << endl;
    cout << "Elemento (1, 2): " << mat.get(1, 2) << endl;
    cout << "Elemento (3, 4): " << mat.get(3, 4) << endl;
    cout << "Elemento (2, 2): " << mat.get(2, 2) << endl; // Should return 0.0

    mat.print();

    mat.print_as_array();

    cout << "Quantidade de não zeros: " << mat.non_zero_count() << endl;

    return 0;
}

