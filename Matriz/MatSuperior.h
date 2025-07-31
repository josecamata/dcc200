#ifndef MATSUPERIOR_H__
#define MATSUPERIOR_H__

class MatSuperior
{
public:
    MatSuperior(int n);
    ~MatSuperior();

    void set(int i, int j, double value);
    double get(int i, int j) const;

    int size() const { return n; }

    void print() const;

    void print_as_array() const; 

private:
    int        n;
    double* data;
    int index(int i, int j) const;
    bool verificaIndice(int i, int j) const;
    int _size;
};


#endif /* MATSUPERIOR_H__ */
