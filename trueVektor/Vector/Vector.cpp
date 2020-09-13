#include "Vector.h"
#include <iostream>
#include <locale.h>
#include <math.h>

namespace mathTools {

    bool Vector::debug = false;
    int Vector::num = 0; //начальное кол-во объектов класса

    Vector::Vector() {  //инициализаци€ переменных
        this->x = 0; this->y = 0; this->z = 0;
        this->num++;
        this->numObj = this->num;
        if(debug) std::cout << "(вектор " << this->numObj << ", конструктор 1)\n";
    }

    /*конструктор, который задаЄт координаты*/
    Vector::Vector(const double x, const double y, const double z) {
        this->x = x; this->y = y; this->z = z;
        this->num++;
        this->numObj = this->num;
        if (debug) std::cout << "(вектор " << this->numObj << ", конструктор 2)\n";
    }

    /*конструктор копировани€*/
    /*¬ообще он нужен например если объект ссылаетс€ на какую-то пам€ть или 
    пем€ть выделена динамическа€, потому что если полностью скопировать объект,
    то будет два объекта, которые ссылаютс€ на одну и ту же пам€ть, а это плохо.*/
    Vector::Vector(const Vector& other) {
        this->num++;
        this->numObj = this->num;
        if (debug) std::cout << "(вектор " << this->numObj << ", конструктор копировани€)\n";
        this->x = other.x; this->y = other.y; this->z = other.z;
    }

    Vector::~Vector() { //деструктор
        if (debug) std::cout << "(вектор " << this->numObj << ", деструктор)\n";
    }

    /*подмена пон€тий (перегрузка)*/
    void Vector::operator=(Vector other)
    {
        this->x = other.getX(); this->y = other.getY(); this->z = other.getZ();
    }

    

    double Vector::getX() const { return(this->x); }    //геттеры
    double Vector::getY() const { return(this->y); }
    double Vector::getZ() const { return(this->z); }

    void Vector::setX(const double x) { this->x = x; }    //сеттеры
    void Vector::setY(const double y) { this->y = y; }
    void Vector::setZ(const double z) { this->z = z; }

    double Vector::getModul() const { //возвращает модуль вектора 
        return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
    }

    void Vector::printVector() { //печать вектора на экран
        std::cout << "x = " << this->x << "; y = " << this->y << "; z = " << this->z << "\n";
    }

    void Vector::multiplyScalar(const double k) { //умножение вектора на скал€р   
        this->x *= k;
        this->y *= k;
        this->z *= k;
    }


    void Vector::toUnit() { //нормировка вектора
        double modul = this->getModul();
        if (modul != 0) {
            this->x /= modul;
            this->y /= modul;
            this->z /= modul;
        }
        else {
            throw "ћодуль вектора равен 0. (деление на 0)";
        }
    }

    Vector Vector::getUnit() const { //нормировка вектора(возврат значени€)
        double modul = this->getModul();
        if (modul != 0) {
            Vector a(this->x / modul, this->y / modul, this->z / modul);
            return a;
        }
        else {
            throw "ћодуль вектора равен 0. (деление на 0)";
        }
        
    }
}