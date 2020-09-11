#include "Vector.h"
#include <iostream>
#include <locale.h>
#include <math.h>

namespace vectName {
    Vector::Vector() {  //инициализация переменных
        this->x = 0; this->y = 0; this->z = 0;
        //std::cout << "Конструктор 1\n";
    }

    /*конструктор, который задаёт координаты*/
    Vector::Vector(double x, double y, double z) {
        this->x = x; this->y = y; this->z = z;
        //std::cout << "Конструктор 2\n";
    }

    /*конструктор копирования*/
    /*Вообще он нужен например если объект ссылается на какую-то память или 
    пемять выделена динамическая, потому что если полностью скопировать объект,
    то будет два объекта, которые ссылаются на одну и ту же память, а это плохо.*/
    Vector::Vector(const Vector& other) {   //это конечно позор, это надо убрать
        //std::cout << "Конструктор копирования\n";
        this->x = other.x; this->y = other.y; this->z = other.z;
    }

    Vector::~Vector() { //деструктор
        //std::cout << "Деструктор\n";
    }

    double Vector::getX() { return(this->x); }    //геттеры
    double Vector::getY() { return(this->y); }
    double Vector::getZ() { return(this->z); }

    void Vector::setX(double x) { this->x = x; }    //сеттеры
    void Vector::setY(double y) { this->y = y; }
    void Vector::setZ(double z) { this->z = z; }

    double Vector::gedModul() { //возвращает модуль вектора 
        return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
    }

    void Vector::printVector() { //печать вектора на экран
        std::cout << "x = " << this->x << "; y = " << this->y << "; z = " << this->z << "\n";
    }

    void Vector::multiplyScalar(double k) { //умножение вектора на скаляр   
        this->x *= k;
        this->y *= k;
        this->z *= k;
    }

    Vector& Vector::normirVector() { //нормировка вектора
        double modul = this->gedModul();
        if (modul != 0) {
            this->x /= modul;
            this->y /= modul;
            this->z /= modul;
        }
        return *this;
    }
}