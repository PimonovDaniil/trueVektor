#define _USE_MATH_DEFINES
#include "Vector.h"
#include <iostream>
#include <locale.h>
#include <math.h>

namespace mathTools
{

    bool Vector::debug = false;
    int Vector::num = 0; //начальное кол-во объектов класса

	void Vector::init(double x, double y, double z)
	{
		this->setXYZ(x, y, z);
		this->numObj = ++this->num;
	}

	/*конструктор без параметров*/
	Vector::Vector(double xyz) {
		init(xyz, xyz, xyz);
		if (debug) std::cout << "(вектор " << this->numObj << ", конструктор 1)\n";
	}

	/*конструктор, который задаёт координаты*/
	Vector::Vector(double x, double y, double z) {
		init(x, y, z);
		if (debug) std::cout << "(вектор " << this->numObj << ", конструктор 2)\n";
	}

    /*конструктор копирования*/
    Vector::Vector(const Vector& other) {
		init(other.x, other.y, other.z);
        if (debug) std::cout << "(вектор " << this->numObj << ", копия вектора " << other.numObj << ")\n";
    }

	/*деструктор*/
    Vector::~Vector() {
        if (debug) std::cout << "(вектор " << this->numObj << ", деструктор)\n";
    }

    /*подмена понятий (перегрузка)*/
	Vector& Vector::operator=(const Vector& other)
    {
		// Проверка на самоприсваивание
		if (this != &other) this->copyFrom(other);

		return *this;
    }

	int Vector::getNumObj() const { return(this->numObj); }

	int Vector::getNum() { return num; }

    double Vector::getX() const { return(this->x); }    //геттеры
    double Vector::getY() const { return(this->y); }
    double Vector::getZ() const { return(this->z); }
	void Vector::getXYZ(double& x, double& y, double& z) { x = this->x; y = this->y; z = this->z; }

    void Vector::setX(double x) { this->x = x; }    //сеттеры
    void Vector::setY(double y) { this->y = y; }
    void Vector::setZ(double z) { this->z = z; }
	Vector& Vector::setXYZ(double x, double y, double z) {
		this->x = x; this->y = y; this->z = z;

		return *this;
	}

    double Vector::getModul() const { //возвращает модуль вектора 
        return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
    }

    Vector& Vector::multiplyScalar(double k) { //умножение вектора на скаляр   
        this->x *= k; this->y *= k; this->z *= k;

		return *this;
    }

	Vector& Vector::copyFrom(const Vector& other) //копирования данных из другого вектора
    {
		return this->setXYZ(other.x, other.y, other.z);
    }

	Vector& Vector::toUnit() { //нормировка вектора
		double modul = this->getModul();

		if (modul == 0.0) throw "Модуль вектора равен 0. (деление на 0)"; //есть вроде старндартный объект исключения деления на ноль, на будущее лучше всегда стандартными пользоваться

		return this->setXYZ(this->x / modul, this->y / modul, this->z / modul);
	}

    Vector Vector::getUnit() const { //возвращает новый нормированный вектор
		return Vector(*this).toUnit();
    }

	void Vector::print() const { //печать вектора на экран
		std::cout << "x = " << this->x << "; y = " << this->y << "; z = " << this->z << "\n";
	}

	//------------------------------------------------------------------------------------

	Vector sum(const Vector& a, const Vector& b) { // сложение (C = A + B);
		return Vector(
			a.getX() + b.getX(),
			a.getY() + b.getY(),
			a.getZ() + b.getZ());
	}

	Vector difference(const Vector& a, const Vector& b) { // вычитание (C = A – B);
		return Vector(
			a.getX() - b.getX(),
			a.getY() - b.getY(),
			a.getZ() - b.getZ());
	}

	Vector vectMultiply(const Vector& a, const Vector& b) { // векторное произведение (С = A * B);
		return Vector(
			a.getY() * b.getZ() - a.getZ() * b.getY(),
			a.getZ() * b.getX() - a.getX() * b.getZ(),
			a.getX() * b.getY() - a.getY() * b.getX());
	}

	double scalarMultiply(const Vector& a, const Vector& b) {// скалярное произведение двух векторов
		return a.getX() * b.getX() + a.getY() * b.getY() + a.getZ() * b.getZ();
	}

	double getCos(const Vector& a, const Vector& b) {// нахождение косинуса угла между двумя векторами;
		return scalarMultiply(a, b) / (a.getModul() * b.getModul());
	}

	double getSin(const Vector& a, const Vector& b) {// нахождение синуса угла между двумя векторами;
		return vectMultiply(a, b).getModul() / b.getModul() / a.getModul();
	}

	double AngleBetween(const Vector& a, const Vector& b) { //величины угла в градусах между векторами в пределах[0, 180º].
		return atan2(vectMultiply(a, b).getModul(), scalarMultiply(a, b)) * 180 / M_PI;
	}

}
