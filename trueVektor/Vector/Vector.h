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

		Vector& operator = (Vector other);

		double getX() const; //геттеры
		double getY() const;
		double getZ() const;

		void setX(double x); //сеттеры
		void setY(double y);
		void setZ(double z);

		double getModul() const;
		void printVector();
		void multiplyScalar(double k);
		Vector& normirVector();
	};
}


