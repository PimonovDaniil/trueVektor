#pragma once

namespace mathTools {
	class Vector
	{
	private:
		double x, y, z; //���������� ������� 
		static int num; //������� �������� ������
		int numObj; //����� ����������� � �������

	public:
		static bool debug;

		Vector();
		Vector(double x, double y, double z);
		Vector(const Vector& other); 
		~Vector();

		Vector& operator = (Vector other);

		double getX() const; //�������
		double getY() const;
		double getZ() const;

		void setX(double x); //�������
		void setY(double y);
		void setZ(double z);

		double getModul() const;
		void printVector();
		void multiplyScalar(double k);
		Vector& normirVector();
	};
}


