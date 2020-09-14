#pragma once

namespace mathTools
{

	class Vector
	{
	private:
		double x, y, z; //координаты вектора 
		static int num; //счётчик объектов класса
		int numObj; //номер привязанный к объекту

		void init(double x, double y, double z);
	public:
		static bool debug;

		Vector(double xyz = 0.0);
		Vector(double x, double y, double z);
		Vector(const Vector& other); 
		~Vector();

		Vector& operator=(const Vector& other);

		int getNumObj() const;
		static int getNum();

		double getX() const; //геттеры
		double getY() const;
		double getZ() const;
		void getXYZ(double& x, double& y, double& z);

		void setX(double x); //сеттеры
		void setY(double y);
		void setZ(double z);
		Vector& setXYZ(double x, double y, double z);

		Vector& copyFrom(const Vector& other);

		double getModul() const;
		
		Vector& multiplyScalar(double k);
		
		Vector& toUnit();
		Vector getUnit() const;

		void print() const;
	};

	//------------------------------------------------------------------------------------

	Vector sum(const Vector& a, const Vector& b); // сложение (C = A + B);

	Vector difference(const Vector& a, const Vector& b); // вычитание (C = A – B);

	Vector vectMultiply(const Vector& a, const Vector& b);  // векторное произведение (С = A * B);

	double scalarMultiply(const Vector& a, const Vector& b);// скалярное произведение двух векторов

	double getCos(const Vector& a, const Vector& b); // нахождение косинуса угла между двумя векторами;

	double getSin(const Vector& a, const Vector& b); // нахождение синуса угла между двумя векторами;

	double AngleBetween(const Vector& a, const  Vector& b); //величины угла в градусах между векторами в пределах[0, 180º].

}
