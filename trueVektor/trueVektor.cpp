// trueVektor.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale.h>
#include <math.h>
#include "Vector/Vector.h"
using namespace mathTools;

int main()
{
    setlocale(LC_CTYPE, "RUSSIAN");
    /*Vector::debug = true; //переменная позволяет включить отображение конструкторов/деструкторов

    Vector v1, v2, v3;
    v3 = sum(v1, v2);*/
    

    Vector::debug = false; //переменная позволяет включить отображение конструкторов/деструкторов

    printf("I. С помощью функций-элементов класса обеспечить:\n");
    printf("\tесть вектор А: ");
    Vector a(1, 5, 2);
    a.print();
    printf("\t1) доступ к элементам вектора (чтение/запись);\n");
    printf("\t\tзапишим 5 в X\n\t\t");
    a.setX(5);
    a.print();
    printf("\t\tсчитаем Z: %lf\n",a.getZ());
    printf("\t2) вычисление модуля вектора;\n");
    printf("\t\tмодуль вектора А равен: %lf\n", a.getModul());
    printf("\t3) копирование вектора;\n\t\tкопируем вектор А в вектор B\n\t\tВектор B: ");
    Vector b(a);
    b.print();
    printf("\t4) умножение вектора на скаляр;\n");
    printf("\t\tумножаем вектор А на 3: ");
    a.multiplyScalar(3);
    a.print();
    printf("\t5) нормировку вектора (получение вектора единичной длины)\n\t\tнормированный вектор А: ");
    a.toUnit();
    a.print();

    printf("\nII. C помощью внешних функций обеспечить двуместные операции над векторами A и B:\n");
    printf("есть вектор A: ");
    Vector A(5, 0, 1);
    A.print();
    printf("есть вектор B: ");
    Vector B(1, 2, 1);
    B.print();
    printf("a) с получением нового вектора C:\n");
    printf("\t1) сложение (C = A + B);\n\t\tвектор С: ");
    Vector C = sum(A, B);
    C.print();
    printf("\t2) вычитание (C = A – B);\n\t\tвектор С: ");
    C = difference(A, B);
    C.print();
    printf("\t3) векторное произведение (С = A * B);\n\t\tвектор С: ");
    C = vectMultiply(A, B);
    C.print();
    printf("б) с получением скалярных величин:\n");
    printf("\t1) скалярного произведения двух векторов;\n");
    printf("\t\tскалярное произведение A и B: %lf:\n", scalarMultiply(A, B));
    printf("\t2) косинуса и синуса угла между двумя векторами;\n");
    printf("\t\tcos между A и B: %lf рад.\n", getCos(A, B));
    printf("\t\tsin между A и B: %lf рад.\n", getSin(A, B));
    printf("\t3) величины угла в градусах между векторами впределах[0, 180].\n");
    printf("\t\tугол между A и B: %lf градусов", AngleBetween(A, B));
}

/*Конструкторы могут вызываться автоматически например при передачу объекта
в функцию типа void F(Vector a){}. В данном случае вызывается конструктор копирования.
Деструктор вызывается при удалении объекта, например при его удалении в конце функции.*/

/*Спасибо за просмотр. Ставьте лайки. Подписывайтесь на канал:) https://github.com/PimonovDaniil/trueVektor */