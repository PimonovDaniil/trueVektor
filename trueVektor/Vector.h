#pragma once

namespace vectName {
	class Vector
	{
	private:
		double x, y, z; //���������� ������� 

	public:
		static bool debug;

		Vector();
		Vector(double x, double y, double z);
		Vector(const Vector& other); //��� ������� �����, ��� ���� ������
		~Vector();

		double getX(); //�������
		double getY();
		double getZ();

		void setX(double x); //�������
		void setY(double y);
		void setZ(double z);

		double getModul();
		void printVector();
		void multiplyScalar(double k);
		Vector& normirVector();
	};
}


