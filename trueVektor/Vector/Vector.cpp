#include "Vector.h"
#include <iostream>
#include <locale.h>
#include <math.h>

namespace mathTools {

    bool Vector::debug = false;
    int Vector::num = 0; //начальное кол-во объектов класса

    Vector::Vector() {  //инициализация переменных
        this->x = 0; this->y = 0; this->z = 0;
        this->num++;
        this->numObj = this->num;
        if(debug) std::cout << "(вектор " << this->numObj << ", конструктор 1)\n";
    }

    /*конструктор, который задаёт координаты*/
    Vector::Vector(const double x, const double y, const double z) {
        this->x = x; this->y = y; this->z = z;
        this->num++;
        this->numObj = this->num;
        if (debug) std::cout << "(вектор " << this->numObj << ", конструктор 2)\n";
    }

    /*конструктор копирования*/
    /*Вообще он нужен например если объект ссылается на какую-то память или 
    пемять выделена динамическая, потому что если полностью скопировать объект,
    то будет два объекта, которые ссылаются на одну и ту же память, а это плохо.*/
    Vector::Vector(const Vector& other) {
        this->num++;
        this->numObj = this->num;
        if (debug) std::cout << "(вектор " << this->numObj << ", конструктор копирования)\n";
        this->x = other.x; this->y = other.y; this->z = other.z;
    }

    Vector::~Vector() { //деструктор
        if (debug) std::cout << "(вектор " << this->numObj << ", деструктор)\n";
    }

    /*подмена понятий (перегрузка)*/
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

    void Vector::multiplyScalar(const double k) { //умножение вектора на скаляр   
        this->x *= k;
        this->y *= k;
        this->z *= k;
    }

    /*Vector& Vector::normirVector() { //нормировка вектора
        double modul = this->getModul();
        if (modul != 0) {
            this->x /= modul;
            this->y /= modul;
            this->z /= modul;
        }
        return *this;
    }*/

    void Vector::toUnit() { //нормировка вектора
        double modul = this->getModul();
        if (modul != 0) {
            this->x /= modul;
            this->y /= modul;
            this->z /= modul;
        }
        else {
            throw "Модуль вектора равен 0. (деление на 0)";
        }
    }

    Vector Vector::getUnit() const {
        double modul = this->getModul();
        if (modul != 0) {
            Vector a(this->x / modul, this->y / modul, this->z / modul);
            return a;
        }
        else {
            throw "Модуль вектора равен 0. (деление на 0)";
        }
        
    }
}