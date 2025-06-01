#include "Matrix.h"   
#include <cstdlib>   
#include <ctime> 
#include <random>  

// Конструктор (создает 2x2 матрицу с нулями)
Matrix::Matrix() : rows(2), column(2), matrix(2, std::vector<int>(2, 0)) {}

// Конструктор (создает матрицу r на c и заполняет случайными числами)
Matrix::Matrix(int r, int c) : rows(r), column(c), matrix(r, std::vector<int>(c))
{
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            matrix[i][j] = rand() % 10; // Заполнение случайными числами от 0 до 99
}

// Деструктор 
Matrix::~Matrix() {}

// Метод вывода матрицы в консоль
void Matrix::print() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < column; j++) {
            std::cout << matrix[i][j] << " ";  // Вывод элемента
        }
        std::cout << "\n";  // Переход на новую строку после каждой строки матрицы
    }
}

// Оператор сложения матриц
Matrix Matrix::operator+(const Matrix &other) const {
    Matrix result(rows, column);  // Создаем матрицу для результата
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < column; j++) {
            result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        }
    }
    return result;
}

// Оператор вычитания матриц
Matrix Matrix::operator-(const Matrix &other) const {
    Matrix result(rows, column);  // Создаем матрицу для результата
    // Поэлементное вычитание
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < column; j++) {
            result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
        }
    }
    return result;
}

// Оператор умножения матрицы на скаляр
Matrix Matrix::operator*(const int value) const {
    Matrix result(rows, column);  // Создаем матрицу для результата
    // Умножение каждого элемента на скаляр
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < column; j++) {
            result.matrix[i][j] = matrix[i][j] * value;
        }
    }
    return result;
}

// Оператор умножения матриц
Matrix Matrix::operator*(const Matrix &other) const {
    Matrix result(rows, other.column);  // Создаем матрицу для результата
    // Алгоритм умножения матриц
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.column; j++) {
            result.matrix[i][j] = 0;  // Инициализация элемента
            // Вычисление скалярного произведения строки и столбца
            for (int k = 0; k < column; k++) {
                result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
            }
        }
    }
    return result;
}

// Оператор присваивания
Matrix Matrix::operator=(const Matrix &other) {
    // Копирование размеров
    rows = other.rows;
    column = other.column;
    matrix = other.matrix;
    return *this;  // Возвращаем текущий объект
}

// Оператор сравнения матриц
bool Matrix::operator==(const Matrix &other) const {
    // Сравниваем размеры и поэлементно содержимое матриц
    return rows == other.rows && column == other.column && matrix == other.matrix;
}

// Оператор вывода матрицы в поток
std::ostream& operator<<(std::ostream &os, const Matrix &other) {
    for (int i = 0; i < other.rows; i++) {
        for (int j = 0; j < other.column; j++) {
            os << other.matrix[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}

// Оператор ввода матрицы из потока
std::istream& operator>>(std::istream &is, Matrix &other) {
    for (int i = 0; i < other.rows; i++) {
        for (int j = 0; j < other.column; j++) {
            is >> other.matrix[i][j];
        }
    }
    return is;
}

// Метод поиска максимального элемента
int Matrix::maxelement() {
    int result = -10000; 
    // Поиск максимума в матрице
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < column; j++) {
            if (matrix[i][j] > result) {
                result = matrix[i][j];  
            }
        }
    }
    return result;
}
