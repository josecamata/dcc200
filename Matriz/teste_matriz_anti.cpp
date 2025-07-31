
#include "MatAntiSimetrica.h"

#include <iostream>
#include <iomanip>

int main()
{
    try {
        MatAntiSimetrica matriz(4);
        
        std::cout << "=== Teste da Classe MatrizAntissimetrica ===" << std::endl;
            
        // Preenchendo alguns elementos (definindo na triangular inferior)
        matriz.set(1, 0, 2.0);   // matriz(0, 1) automaticamente = -2.0
        matriz.set(2, 0, 3.0);   // matriz(0, 2) automaticamente = -3.0
        matriz.set(3, 0, 1.0);   // matriz(0, 3) automaticamente = -1.0
        matriz.set(2, 1, 4.0);   // matriz(1, 2) automaticamente = -4.0
        matriz.set(3, 1, 5.0);   // matriz(1, 3) automaticamente = -5.0
        matriz.set(3, 2, 6.0);   // matriz(2, 3) automaticamente = -6.0
            
        std::cout << "Matriz preenchida:" << std::endl;
        matriz.print();

        std::cout << "Array da Matriz Antissimétrica:" << std::endl;
        matriz.print_as_array();

        matriz.set(0, 0, 1.0); // Tentativa de definir um elemento da diagonal

    }
    catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }
    std::cout << "=== Fim do Teste da Classe MatrizAntissimetrica ===" << std::endl;

    return 0;
}