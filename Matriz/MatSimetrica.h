#ifndef MATSIMETRICA_H__
#define MATSIMETRICA_H__

// Implementação de uma matriz simétrica
class MatSimetrica {
public:
    MatSimetrica(int n);
    ~MatSimetrica();

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

#endif /* MATSIMETRICA_H__ */
