#include <iostream>
#include <locale.h>
#include <math.h>
#include "../Vector/Vector.h"
using namespace mathTools; 

Vector sumVect(const Vector& a, const Vector& b); // сложение (C = A + B);

Vector raznostVect(const Vector& a, const Vector& b); // вычитание (C = A – B);

Vector multiplyVect(const Vector& a, const Vector& b);  // векторное произведение (С = A * B);

double scalarMultiply(const Vector& a, const Vector& b);// скалярное произведение двух векторов

double getCosVect(const Vector& a, const Vector& b); // нахождение косинуса угла между двумя векторами;

double getSinVect(const Vector& a, const Vector& b); // нахождение синуса угла между двумя векторами;

double uglVectGrad(const Vector& a, const  Vector& b); //величины угла в градусах между векторами в пределах[0, 180º].
