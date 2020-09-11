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


double uglVectGrad(Vector &a, Vector &b) { //величины угла в градусах между векторами в пределах[–180º, 180º].
    return atan2(multiplyVect(a, b).gedModul(), scalarMultiply(a, b));
}

int main()
{
    setlocale(LC_CTYPE, "RUSSIAN");
    Vector a(1, 1, 0);
    Vector b(1, 0, 0);
    a.printVector();
    b.printVector();
    printf("угол между a и b %lf\n", uglVectGrad(a, b) * 180 / 3.14159265358979323846);
    printf("угол между b и a %lf\n", uglVectGrad(b, a) * 180 / 3.14159265358979323846);
    a.printVector();
    b.printVector();
}