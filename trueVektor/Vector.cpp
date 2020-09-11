#include "Vector.h"
#include <iostream>
#include <locale.h>
#include <math.h>

namespace vectName {
    Vector::Vector() {  //������������� ����������
        this->x = 0; this->y = 0; this->z = 0;
        //std::cout << "����������� 1\n";
    }

    /*�����������, ������� ����� ����������*/
    Vector::Vector(double x, double y, double z) {
        this->x = x; this->y = y; this->z = z;
        //std::cout << "����������� 2\n";
    }

    /*����������� �����������*/
    /*������ �� ����� �������� ���� ������ ��������� �� �����-�� ������ ��� 
    ������ �������� ������������, ������ ��� ���� ��������� ����������� ������,
    �� ����� ��� �������, ������� ��������� �� ���� � �� �� ������, � ��� �����.*/
    Vector::Vector(const Vector& other) {   //��� ������� �����, ��� ���� ������
        //std::cout << "����������� �����������\n";
        this->x = other.x; this->y = other.y; this->z = other.z;
    }

    Vector::~Vector() { //����������
        //std::cout << "����������\n";
    }

    double Vector::getX() { return(this->x); }    //�������
    double Vector::getY() { return(this->y); }
    double Vector::getZ() { return(this->z); }

    void Vector::setX(double x) { this->x = x; }    //�������
    void Vector::setY(double y) { this->y = y; }
    void Vector::setZ(double z) { this->z = z; }

    double Vector::gedModul() { //���������� ������ ������� 
        return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
    }

    void Vector::printVector() { //������ ������� �� �����
        std::cout << "x = " << this->x << "; y = " << this->y << "; z = " << this->z << "\n";
    }

    void Vector::multiplyScalar(double k) { //��������� ������� �� ������   
        this->x *= k;
        this->y *= k;
        this->z *= k;
    }

    Vector& Vector::normirVector() { //���������� �������
        double modul = this->gedModul();
        if (modul != 0) {
            this->x /= modul;
            this->y /= modul;
            this->z /= modul;
        }
        return *this;
    }
}