#include "Vector.h"
#include <iostream>
#include <locale.h>
#include <math.h>

namespace vectName {
    Vector::Vector() {  //инициализаци€ переменных
        this->x = 0; this->y = 0; this->z = 0;
        //std::cout << " онструктор 1\n";
    }

    /*конструктор, который задаЄт координаты*/
    Vector::Vector(double x, double y, double z) {
        this->x = x; this->y = y; this->z = z;
        //std::cout << " онструктор 2\n";
    }

    /*конструктор копировани€*/
    Vector::Vector(const Vector& other) {   //это конечно позор, это надо убрать
        //std::cout << " онструктор копировани€\n";
        this->x = other.x; this->y = other.y; this->z = other.z;
    }

    Vector::~Vector() { //деструктор
        //std::cout << "ƒеструктор\n";
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

    void Vector::printVector() {
        std::cout << "x = " << this->x << "; y = " << this->y << "; z = " << this->z << "\n";
    }

    void Vector::multiplyScalar(double k) { //умножение вектора на скал€р   
        this->x *= k;
        this->y *= k;
        this->z *= k;
    }

    void Vector::normirVector() { //нормировка вектора
        double modul = this->gedModul();
        if (modul != 0) {
            this->x /= modul;
            this->y /= modul;
            this->z /= modul;
        }
    }
}