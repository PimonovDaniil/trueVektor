// trueVektor.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale.h>
#include <math.h>

class Vector { //3д реализация
private:
    //static int number;  //нумеровка вектора, чтобы знать
    //int localNumber;    //где какой вектор когда создался/уничтожился
    double x, y, z; //координаты вектора 

public:
    Vector() {  //инициализация переменных
        this->x = 0; this->y = 0; this->z = 0;
        /*this->number++;
        this->localNumber = this->number;
        std::cout << "Вектор " << this->number<< "; ";*/
        std::cout << "Конструктор 1\n";
    }

    /*конструктор, который задаёт координаты*/
    Vector(double x, double y, double z) { 
        this->x = x; this->y = y; this->z = z;
        /*this->number++;
        this->localNumber = this->number;
        std::cout << "Вектор " << this->number << "; ";*/
        std::cout << "Конструктор 2\n";
    }

    ~Vector() { //деструктор
        //std::cout << "Вектор " << this->localNumber << "; ";
        //std::cout << "Деструктор\n";
    }

    double getX() { return(this->x); }    //геттеры
    double getY() { return(this->y); }
    double getZ() { return(this->z); }

    void setX(double x) { this->x = x; }    //сеттеры
    void setY(double y) { this->y = y; }
    void setZ(double z) { this->z = z; }

    double gedModul() { //возвращает модуль вектора 
        return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
    }

    void printVector() {
        std::cout << "x = " << this->x << "; y = " << this->y << "; z = " << this->z << "\n";
    }

    Vector getCopy() { //возвращает копию вектора
        return(Vector(this->x, this->y, this->z));
    }

    void multiplyScalar(double k) { //умножение вектора на скаляр   
        this->x *= k;
        this->y *= k;
        this->z *= k;
    }

    void normirVector() { //нормировка вектора
        double modul = this->gedModul();
        if (modul != 0) {
            this->x /= modul;
            this->y /= modul;
            this->z /= modul;
        }
    }
};

//int Vector::number = 0;

Vector sumVect(Vector a, Vector b) { // сложение (C = A + B);
    return(Vector(a.getX()+ b.getX(), a.getY() + b.getY(), a.getZ() + b.getZ()));
}

Vector raznostVect(Vector &a, Vector &b) { // вычитание (C = A – B);
    return(Vector(a.getX() - b.getX(), a.getY() - b.getY(), a.getZ() - b.getZ()));
}   

Vector multiplyVect(Vector &a, Vector &b) { // векторное произведение (С = A * B);
    Vector c;
    c.setX((a.getY() * b.getZ()) - (a.getZ() * b.getY()));
    c.setY((a.getZ() * b.getX()) - (a.getX() * b.getZ()));
    c.setZ((a.getX() * b.getY()) - (a.getY() * b.getX()));
    return(c);
}

double scalarMultiply(Vector &a, Vector &b) {// скалярное произведение двух векторов
    return((a.getX() * b.getX()) + (a.getY() * b.getY()) + (a.getZ() * b.getZ()));
}

double getCosVect(Vector &a, Vector &b) {// нахождение косинуса угла между двумя векторами;
    return(scalarMultiply(a, b) / (a.gedModul() * b.gedModul()));
}

double getSinVect(Vector &a, Vector &b) {// нахождение синуса угла между двумя векторами;
    return(sqrt(1 - pow(getCosVect(a, b), 2)));
}

double uglVectGrad(Vector a, Vector b) { //величины угла в градусах между векторами в пределах[–180º, 180º].
    /*double dot = (a.getX() * b.getX()) + (a.getY() * b.getY());      //dot product
    double det = (a.getX() * b.getY()) - (a.getY() * b.getX());      // determinant
    double angle = atan2(det, dot);  // atan2(y, x) or atan2(sin, cos)
    return(angle * 180 / 3.14159265358979323846);*/
    //return(atan2(getSinVect(a, b), getCosVect(a, b)) /** 180 / 3.14159265358979323846*/);
    Vector c(1, 1, 1);
    double x = scalarMultiply(a, c);
    Vector y = multiplyVect(a, c);
    double ang1 = atan2(y.gedModul(), x) * 180 / 3.14159265358979323846;
    x = scalarMultiply(b, c);
    y = multiplyVect(b, c);
    double ang2 = atan2(y.gedModul(), x) * 180 / 3.14159265358979323846;
    int k = 1;
    if (ang1 - ang2 <= 0) {
        k = -1;
    }
    std::cout << "ang1 " << ang1<< "\n";
    std::cout << "ang2 " << ang2 << "\n";
    x = scalarMultiply(a, b);
    y = multiplyVect(a, b);
    return(atan2(y.gedModul(), x) * 180 / 3.14159265358979323846 *k);
}

int main()
{
    setlocale(LC_CTYPE, "RUSSIAN");
    Vector a(1, 0, 0);
    Vector b(-1, 0, 1);
    Vector c = multiplyVect(a, b);
    a.printVector();
    b.printVector();
    std::cout << getCosVect(a,b) << "\n";
    //c.printVector();
    //std::cout << sumVect() << "\n";
    //std::cout << getCosVect(a, b)<< "\n";
    //std::cout <<"градусы между векторами " << uglVectGrad(a, b) <<"\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"
//https://switch-case.ru/70020050

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
