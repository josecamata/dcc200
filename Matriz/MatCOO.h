#ifndef MATCOO_H__
#define MATCOO_H__

// Implementacao de Matriz esparsa em formato COO (Coordinate List)

#include <iostream>

typedef struct {
    int row;
    int col;
    double value;
} Elemento;

class MatCOO {
public:
    MatCOO(int n);
    ~MatCOO();

    void set(int i, int j, double value);
    double get(int i, int j) const;

    int size() const ;
    void print() const;
    void print_as_array() const;
    int non_zero_count() const;

private:
    int n;
    Elemento* data;
    int count;
    int capacity;
    void resize();
    bool verificaIndice(int i, int j) const;
};



#endif /* MATCOO_H__ */
