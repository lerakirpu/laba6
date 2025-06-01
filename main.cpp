#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Matrix.h"
#include "Squarematrix.h"


int main(){
    srand(std::time(0));
    std::cout<<"Матрица 1 с аргументами по умолчанию:\n";
    Matrix m;
    m.print();
    std::cout<<"\nМатрица 2 со случайными значениями:\n";

    Matrix m2(4,4);
    m2.print();
    std::cout<<"\nМатрица 3 со случайными значениями:\n";

    Matrix m3(4,4);
    m3.print();
    std::cout<<"\nСумма Матрицы 2 и 3:\n";

    Matrix Z = m2+m3;
    Z.print();
    std::cout<<"\nРазность Матрицы 2 и 3:\n";

    Matrix X = m2-m3;
    X.print();

    int value;
    std::cout<<"\nВведите число которое желаете умножить на матрицу:";
    std::cin>>value;
    std::cout<<"\nУмножение Матрицы на число "<< value <<":\n";

    Matrix С = m2*value;
    С.print();

    std::cout<<"\nУмножение Матрицы на Матрицу:\n";
    Matrix V = m2*m3;
    V.print();
    
    //для определения равенства матриц (истинно, если они имеют одинаковые размеры и их соответствующие элементы равны)
    std::cout<<"\nПроверка равенства матриц:\n";
    bool N = m2 == m3;
    std::cout << N;
    std::cout<<"\n";

    std::cout<<"\nПрисваивания одной матрице значений другой матрицы:\n";
    Matrix B = m2 = m3;
    std::cout << B;
    

    std::cout<<"\nМаксимальное значение матрицы:\n";
    std::cout << B.maxelement();
    std::cout<<"\n";

    //тест оператора потока ввода
    std::cout<<"\nВведите матрицу:\n";
    Matrix one;
    std::cin >> one;
    std::cout<<"Введенная матрица:\n";
    std::cout<< one;

    //тест детерминатора
    std::cout<< "\nВведите размер квадратной матрицы:\n";
    int size;
    std::cin >> size;
    SquareMatrix mat(size);
    std::cout<< "\nКвадратная матрицы:\n";
    std::cout<< mat<<std::endl;
    std::cout<< "\nДетерминант:\n";
    std::cout<< mat.determinant()<<std::endl;
    
    std::cout<< "\nПроверка на симметричность:\n";
    std::cout<< mat.cheak() <<std::endl;

    std::cout<< "\nПроверка на возведения матрицы в степень:\n";
    int n;
    std::cin>> n;
    std::cout<< mat.power(n);

    return 0;
}
