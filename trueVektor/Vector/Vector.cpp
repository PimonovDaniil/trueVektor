#define _USE_MATH_DEFINES
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
    Vector::Vector(double x, double y, double z) {
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
        this->x = other.x; this->y = other.y; this->z = other.z;
    }

    

    double Vector::getX() const { return(this->x); }    //геттеры
    double Vector::getY() const { return(this->y); }
    double Vector::getZ() const { return(this->z); }

    void Vector::setX(double x) { this->x = x; }    //сеттеры
    void Vector::setY(double y) { this->y = y; }
    void Vector::setZ(double z) { this->z = z; }

    double Vector::getModul() const { //возвращает модуль вектора 
        return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
    }

    void Vector::print() const{ //печать вектора на экран
        std::cout << "x = " << this->x << "; y = " << this->y << "; z = " << this->z << "\n";
    }

    void Vector::multiplyScalar(double k) { //умножение вектора на скаляр   
        this->x *= k;
        this->y *= k;
        this->z *= k;
    }

    void Vector::copyFrom(const Vector& v) //копирования данных из другого вектора
    {
        this->x = v.getX(); this->y = v.getY(); this->z = v.getZ();
    }

    Vector Vector::getUnit() const { //нормировка вектора(возврат значения)
        double modul = this->getModul();
        if (modul != 0) {
            Vector a(this->x / modul, this->y / modul, this->z / modul);
            return a;
        }
        else {
            throw "Модуль вектора равен 0. (деление на 0)";
        }
    }

    void Vector::toUnit() { //нормировка вектора
        this->copyFrom(this->getUnit());
    }
}

Vector sum(const Vector& a, const Vector& b) { // сложение (C = A + B);
    return(Vector(a.getX() + b.getX(), a.getY() + b.getY(), a.getZ() + b.getZ()));
}

Vector difference(const Vector& a, const Vector& b) { // вычитание (C = A – B);
    return(Vector(a.getX() - b.getX(), a.getY() - b.getY(), a.getZ() - b.getZ()));
}

Vector vectMultiply(const Vector& a, const Vector& b) { // векторное произведение (С = A * B);
    Vector c;
    c.setX((a.getY() * b.getZ()) - (a.getZ() * b.getY()));
    c.setY((a.getZ() * b.getX()) - (a.getX() * b.getZ()));
    c.setZ((a.getX() * b.getY()) - (a.getY() * b.getX()));
    return(c);
}

double scalarMultiply(const Vector& a, const Vector& b) {// скалярное произведение двух векторов
    return(a.getX() * b.getX() + a.getY() * b.getY() + a.getZ() * b.getZ());
}

double getCos(const Vector& a, const Vector& b) {// нахождение косинуса угла между двумя векторами;
    return(scalarMultiply(a, b) / (a.getModul() * b.getModul()));
}

double getSin(const Vector& a, const Vector& b) {// нахождение синуса угла между двумя векторами;
    return vectMultiply(a, b).getModul() / b.getModul() / a.getModul();
}

double AngleBetween(const Vector& a, const  Vector& b) { //величины угла в градусах между векторами в пределах[0, 180º].
    return atan2(vectMultiply(a, b).getModul(), scalarMultiply(a, b)) * 180 / M_PI;
}
