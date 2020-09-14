#pragma once

namespace mathTools {
	class Vector
	{
	private:
		double x, y, z; //координаты вектора 
		static int num; //счётчик объектов класса
		int numObj; //номер привязанный к объекту

	public:
		static bool debug;

		Vector();
		Vector(double x, double y, double z);
		Vector(const Vector& other); 
		~Vector();

		void operator = (Vector other);

		double getX() const; //геттеры
		double getY() const;
		double getZ() const;

		void setX(double x); //сеттеры
		void setY(double y);
		void setZ(double z);

		double getModul() const;
		void printVector();
		void multiplyScalar(double k);
		void copyFrom(const Vector& v);
		
		void toUnit();
		Vector getUnit() const;
	};

}

using namespace mathTools;

Vector sumVect(const Vector& a, const Vector& b); // сложение (C = A + B);

Vector raznostVect(const Vector& a, const Vector& b); // вычитание (C = A – B);

Vector multiplyVect(const Vector& a, const Vector& b);  // векторное произведение (С = A * B);

double scalarMultiply(const Vector& a, const Vector& b);// скалярное произведение двух векторов

double getCosVect(const Vector& a, const Vector& b); // нахождение косинуса угла между двумя векторами;

double getSinVect(const Vector& a, const Vector& b); // нахождение синуса угла между двумя векторами;

double uglVectGrad(const Vector& a, const  Vector& b); //величины угла в градусах между векторами в пределах[0, 180º].




