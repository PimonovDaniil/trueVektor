// trueVektor.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale.h>
#include <math.h>
#include "Vector.h"
using namespace vectName;



Vector sumVect(Vector a, Vector b) { // сложение (C = A + B);
    return(Vector(a.getX()+ b.getX(), a.getY() + b.getY(), a.getZ() + b.getZ()));
}

Vector raznostVect(Vector &a, Vector &b) { // вычитание (C = A – B);
    return(Vector(a.getX() - b.getX(), a.getY() - b.getY(), a.getZ() - b.getZ()));
}   

Vector multiplyVect(Vector &a, Vector &b) { // векторное произведение (С = A * B);
    Vector c;
    c.setX((a.getY() * b.getZ()) - (a.getZ() * b.getY()));
    c.setY((a.getZ() * b.getX()) - (a.getX() * b.getZ()));
    c.setZ((a.getX() * b.getY()) - (a.getY() * b.getX()));
    return(c);
}

double scalarMultiply(Vector &a, Vector &b) {// скалярное произведение двух векторов
    return(a.getX()*b.getX() + a.getY()*b.getY() + a.getZ()*b.getZ());
}

double getCosVect(Vector &a, Vector &b) {// нахождение косинуса угла между двумя векторами;
    return(scalarMultiply(a, b) / (a.gedModul() * b.gedModul()));
}

double getSinVect(Vector &a, Vector &b) {// нахождение синуса угла между двумя векторами;
    return(sqrt(1 - pow(getCosVect(a, b), 2)));
    //return multiplyVect(a, b).gedModul() / b.gedModul() / a.gedModul();
}


double uglVectGrad(Vector &a, Vector &b) { //величины угла в градусах между векторами в пределах[0, 180º].
    return atan2(multiplyVect(a, b).gedModul(), scalarMultiply(a, b)) * 180 / 3.14159265358979323846;
}

int main()
{
    setlocale(LC_CTYPE, "RUSSIAN");
    printf("I. С помощью функций-элементов класса обеспечить:\n");
    printf("\tесть вектор А: ");
    Vector a(1, 5, 2);
    a.printVector();
    printf("\t1) доступ к элементам вектора (чтение/запись);\n");
    printf("\t\tзапишим 5 в X\n\t\t");
    a.setX(5);
    a.printVector();
    printf("\t\tсчитаем Z: %lf\n",a.getZ());
    printf("\t2) вычисление модуля вектора;\n");
    printf("\t\tмодуль вектора А равен: %lf\n", a.gedModul());
    printf("\t3) копирование вектора;\n\t\tкопируем вектор А в вектор B\n\t\tВектор B: ");
    Vector b(a);
    b.printVector();
    printf("\t4) умножение вектора на скаляр;\n");
    printf("\t\tумножаем вектор А на 3: ");
    a.multiplyScalar(3);
    a.printVector();
    printf("\t5) нормировку вектора (получение вектора единичной длины)\n\t\tнормированный вектор А: ");
    a.normirVector();
    a.printVector();

    printf("\nII. C помощью внешних функций обеспечить двуместные операции над векторами A и B:");

}