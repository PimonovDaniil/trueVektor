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

double determenant(Vector a, Vector b, Vector c) {
    return 0.0;
}

double uglVectGrad(Vector a, Vector b) { //величины угла в градусах между векторами в пределах[–180º, 180º].
    //return atan2(norm(cross(a, b)), dot(a, b));
    return atan(getSinVect(a, b)/getCosVect(a, b));
}

int main()
{
    setlocale(LC_CTYPE, "RUSSIAN");
    Vector a(1, 0, 0);
    Vector b(0, 1, 1);
    a.printVector();
    b.printVector();
    printf("угол между a и b %lf\n", uglVectGrad(a, b) * 180 / 3.14159265358979323846);
    printf("угол между b и a %lf\n", uglVectGrad(b, a) * 180 / 3.14159265358979323846);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"
//https://switch-case.ru/70020050

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
