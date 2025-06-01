#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include "Matrix.h"
#include <iostream>
#include <vector>
class SquareMatrix : public Matrix {
public:
    SquareMatrix(const SquareMatrix& other); // Конструктор копирования
    SquareMatrix(int size); // Конструктор с параметром размера
    
    int determinant() const;
    bool cheak() const;
    SquareMatrix operator*(const SquareMatrix &other) const;
    SquareMatrix power(int n);
};


#endif
