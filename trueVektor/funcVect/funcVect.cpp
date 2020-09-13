#include <iostream>
#include <locale.h>
#include <math.h>
#include "funcVect.h"
#include "../Vector/Vector.h"
using namespace mathTools;

Vector sumVect(const Vector& a, const Vector& b) { // сложение (C = A + B);
    return(Vector(a.getX() + b.getX(), a.getY() + b.getY(), a.getZ() + b.getZ()));
}

Vector raznostVect(const Vector& a, const Vector& b) { // вычитание (C = A – B);
    return(Vector(a.getX() - b.getX(), a.getY() - b.getY(), a.getZ() - b.getZ()));
}

Vector multiplyVect(const Vector& a, const Vector& b) { // векторное произведение (С = A * B);
    Vector c;
    c.setX((a.getY() * b.getZ()) - (a.getZ() * b.getY()));
    c.setY((a.getZ() * b.getX()) - (a.getX() * b.getZ()));
    c.setZ((a.getX() * b.getY()) - (a.getY() * b.getX()));
    return(c);
}

double scalarMultiply(const Vector& a, const Vector& b) {// скалярное произведение двух векторов
    return(a.getX() * b.getX() + a.getY() * b.getY() + a.getZ() * b.getZ());
}

double getCosVect(const Vector& a, const Vector& b) {// нахождение косинуса угла между двумя векторами;
    return(scalarMultiply(a, b) / (a.getModul() * b.getModul()));
}

double getSinVect(const Vector& a, const Vector& b) {// нахождение синуса угла между двумя векторами;
    //return(sqrt(1 - pow(getCosVect(a, b), 2)));
    return multiplyVect(a, b).getModul() / b.getModul() / a.getModul();
}


double uglVectGrad(const Vector& a, const  Vector& b) { //величины угла в градусах между векторами в пределах[0, 180º].
    return atan2(multiplyVect(a, b).getModul(), scalarMultiply(a, b)) * 180 / 3.14159265358979323846;
}