#ifndef MATANTISIMETRICA_H__
#define MATANTISIMETRICA_H__


// Implmentação de uma matriz antissimétrica
class MatAntiSimetrica {
public:
    MatAntiSimetrica(int n);
    ~MatAntiSimetrica();

    void set(int i, int j, double value);
    double get(int i, int j) const;

    int size() const { return n; }
    void print() const;
    void print_as_array() const;
private:
    int n;
    double* data;
    int index(int i, int j) const;
    bool verificaIndice(int i, int j) const;
    int _size;
};

#endif /* MATANTISIMETRICA_H__ */
