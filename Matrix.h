#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

class Matrix {

    public:
        int rows;
        int column;
        std::vector<std::vector<int>> matrix;
        Matrix();
        Matrix(int r,int c);
        ~Matrix();
        void print() const;
        Matrix operator+(const Matrix &other) const;
        Matrix operator-(const Matrix &other) const;
        Matrix operator*(const int value) const;
        Matrix operator*(const Matrix &other) const;
        Matrix operator=(const Matrix &other);
        bool operator==(const Matrix &other) const;
        int maxelement();
        friend std::ostream& operator<<(std::ostream &os, const Matrix &other);
        friend std::istream& operator>>(std::istream &is, Matrix &other);
};


#endif
