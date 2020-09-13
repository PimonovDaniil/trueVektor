// trueVektor.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale.h>
#include <math.h>
#include "Vector.h"
using namespace vectName;

Vector sumVect(Vector &a, Vector &b) { // сложение (C = A + B);
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
    return(scalarMultiply(a, b) / (a.getModul() * b.getModul()));
}

double getSinVect(Vector &a, Vector &b) {// нахождение синуса угла между двумя векторами;
    return(sqrt(1 - pow(getCosVect(a, b), 2)));
    //return multiplyVect(a, b).getModul() / b.getModul() / a.getModul();
}


double uglVectGrad(Vector &a, Vector &b) { //величины угла в градусах между векторами в пределах[0, 180º].
    return atan2(multiplyVect(a, b).getModul(), scalarMultiply(a, b)) * 180 / 3.14159265358979323846;
}

int main()
{
    setlocale(LC_CTYPE, "RUSSIAN");
    Vector::debug = true; //переменная позволяет включить отображение конструкторов/деструкторов

    Vector v1, v2, v3;
    v3 = sumVect(v1, v2);


    /*Vector::debug = false; //переменная позволяет включить отображение конструкторов/деструкторов

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
    printf("\t\tмодуль вектора А равен: %lf\n", a.getModul());
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

    printf("\nII. C помощью внешних функций обеспечить двуместные операции над векторами A и B:\n");
    printf("есть вектор A: ");
    Vector A(5, 0, 1);
    A.printVector();
    printf("есть вектор B: ");
    Vector B(1, 2, 1);
    B.printVector();
    printf("a) с получением нового вектора C:\n");
    printf("\t1) сложение (C = A + B);\n\t\tвектор С: ");
    Vector C = sumVect(A, B);
    C.printVector();
    printf("\t2) вычитание (C = A – B);\n\t\tвектор С: ");
    C = raznostVect(A, B);
    C.printVector();
    printf("\t3) векторное произведение (С = A * B);\n\t\tвектор С: ");
    C = multiplyVect(A, B);
    C.printVector();
    printf("б) с получением скалярных величин:\n");
    printf("\t1) скалярного произведения двух векторов;\n");
    printf("\t\tскалярное произведение A и B: %lf:\n", scalarMultiply(A, B));
    printf("\t2) косинуса и синуса угла между двумя векторами;\n");
    printf("\t\tcos между A и B: %lf рад.\n", getCosVect(A, B));
    printf("\t\tsin между A и B: %lf рад.\n", getSinVect(A, B));
    printf("\t3) величины угла в градусах между векторами впределах[0, 180].\n");
    printf("\t\tугол между A и B: %lf градусов", uglVectGrad(A, B));*/
}

/*Конструкторы могут вызываться автоматически например при передачу объекта
в функцию типа void F(Vector a){}. В данном случае вызывается конструктор копирования.
Деструктор вызывается при удалении объекта, например при его удалении в конце функции.*/

/*Спасибо за просмотр. Подписывайтесь на канал:) https://github.com/PimonovDaniil/trueVektor */