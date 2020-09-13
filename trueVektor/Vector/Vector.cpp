#include "Vector.h"
#include <iostream>
#include <locale.h>
#include <math.h>

namespace mathTools {

    bool Vector::debug = false;
    int Vector::num = 0; //��������� ���-�� �������� ������

    Vector::Vector() {  //������������� ����������
        this->x = 0; this->y = 0; this->z = 0;
        this->num++;
        this->numObj = this->num;
        if(debug) std::cout << "(������ " << this->numObj << ", ����������� 1)\n";
    }

    /*�����������, ������� ����� ����������*/
    Vector::Vector(const double x, const double y, const double z) {
        this->x = x; this->y = y; this->z = z;
        this->num++;
        this->numObj = this->num;
        if (debug) std::cout << "(������ " << this->numObj << ", ����������� 2)\n";
    }

    /*����������� �����������*/
    /*������ �� ����� �������� ���� ������ ��������� �� �����-�� ������ ��� 
    ������ �������� ������������, ������ ��� ���� ��������� ����������� ������,
    �� ����� ��� �������, ������� ��������� �� ���� � �� �� ������, � ��� �����.*/
    Vector::Vector(const Vector& other) {
        this->num++;
        this->numObj = this->num;
        if (debug) std::cout << "(������ " << this->numObj << ", ����������� �����������)\n";
        this->x = other.x; this->y = other.y; this->z = other.z;
    }

    Vector::~Vector() { //����������
        if (debug) std::cout << "(������ " << this->numObj << ", ����������)\n";
    }

    /*������� ������� (����������)*/
    void Vector::operator=(Vector other)
    {
        this->x = other.getX(); this->y = other.getY(); this->z = other.getZ();
    }

    

    double Vector::getX() const { return(this->x); }    //�������
    double Vector::getY() const { return(this->y); }
    double Vector::getZ() const { return(this->z); }

    void Vector::setX(const double x) { this->x = x; }    //�������
    void Vector::setY(const double y) { this->y = y; }
    void Vector::setZ(const double z) { this->z = z; }

    double Vector::getModul() const { //���������� ������ ������� 
        return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
    }

    void Vector::printVector() { //������ ������� �� �����
        std::cout << "x = " << this->x << "; y = " << this->y << "; z = " << this->z << "\n";
    }

    void Vector::multiplyScalar(const double k) { //��������� ������� �� ������   
        this->x *= k;
        this->y *= k;
        this->z *= k;
    }

    /*Vector& Vector::normirVector() { //���������� �������
        double modul = this->getModul();
        if (modul != 0) {
            this->x /= modul;
            this->y /= modul;
            this->z /= modul;
        }
        return *this;
    }*/

    void Vector::toUnit() { //���������� �������
        double modul = this->getModul();
        if (modul != 0) {
            this->x /= modul;
            this->y /= modul;
            this->z /= modul;
        }
        else {
            throw "������ ������� ����� 0. (������� �� 0)";
        }
    }

    Vector Vector::getUnit() const {
        double modul = this->getModul();
        if (modul != 0) {
            Vector a(this->x / modul, this->y / modul, this->z / modul);
            return a;
        }
        else {
            throw "������ ������� ����� 0. (������� �� 0)";
        }
        
    }
}