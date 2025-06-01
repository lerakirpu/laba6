#include "SquareMatrix.h"  
#include <iostream>      

// Вызывает конструктор копирования базового класса Matrix
SquareMatrix::SquareMatrix(const SquareMatrix& other) : Matrix(other) { 
}

// Конструктор с параметром размера
SquareMatrix::SquareMatrix(int size) : Matrix(size, size) { 
}

// Метод вычисления определителя матрицы
int SquareMatrix::determinant() const {

    if (rows == 1) return matrix[0][0];  // Для 1x1 матрицы определитель - единственный элемент
    
    if (rows == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    int det = 0;  
     
    for (int k = 0; k < rows; ++k) {     // Разложение по первой строке
        SquareMatrix minorMatrix(rows - 1);
        
        // Заполнение минора
        for (int i = 1; i < rows; ++i) {  // Начинаем со второй строки
            int colIdx = 0;
            for (int j = 0; j < rows; ++j) {
                if (j == k) continue;  // Пропускаем k-й столбец
                minorMatrix.matrix[i - 1][colIdx] = matrix[i][j];
                ++colIdx;
            }
        }
        
        // Вычисление знака для алгебраического дополнения
        int sign = (k % 2 == 0) ? 1 : -1;
        det += sign * matrix[0][k] * minorMatrix.determinant();
    }
    
    return det;
}

// Метод проверки матрицы на симметричность 
bool SquareMatrix::cheak() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rows; ++j) {
            // Если элемент не равен своему транспонированному 
            if (matrix[i][j] != matrix[j][i]) {
                return false;  // Матрица не симметрична
            }
        }
    }
    return true;  // Матрица симметрична
}

// Оператор умножения квадратных матриц
SquareMatrix SquareMatrix::operator*(const SquareMatrix &other) const {
    SquareMatrix result(rows);  // Создаем матрицу для результата
    
    // умножение матриц
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rows; ++j) {
            result.matrix[i][j] = 0;  // Инициализация элемента
            // Вычисление скалярного произведения i-й строки и j-го столбца
            for (int k = 0; k < rows; ++k) {
                result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
            }
        }
    }
    
    return result;
}

// Метод возведения матрицы в степень n
SquareMatrix SquareMatrix::power(int n) {
    // Создаем единичную матрицу для результата
    SquareMatrix result(rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rows; ++j) {
            // Диагональные элементы = 1, остальные = 0
            result.matrix[i][j] = (i == j) ? 1 : 0;
        }
    }

    // Если степень 0, возвращаем единичную матрицу
    if (n == 0) {
        return result;
    }

    SquareMatrix base(*this);  // Создаем копию текущей матрицы
    
    // Алгоритм быстрого возведения в степень
    while (n > 0) {
        if (n % 2 == 1) {  // Если степень нечетная
            result = result * base;  // Умножаем результат на текущую степень
        }
        base = base * base;  // Возводим в квадрат
        n /= 2;              // Делим степень пополам
    }

    return result;
}
