#pragma once

namespace vectName {
	class Vector
	{
	private:
		double x, y, z; //координаты вектора 

	public:
		static bool debug;

		Vector();
		Vector(double x, double y, double z);
		Vector(const Vector& other); //это конечно позор, это надо убрать
		~Vector();

		double getX(); //геттеры
		double getY();
		double getZ();

		void setX(double x); //сеттеры
		void setY(double y);
		void setZ(double z);

		double getModul();
		void printVector();
		void multiplyScalar(double k);
		Vector& normirVector();
	};
}


