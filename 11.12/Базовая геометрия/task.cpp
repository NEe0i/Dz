#include <iostream>
using namespace std;

class Shape {
protected:
    string color;

public:

    Shape(string c) : color(c) {}

    void printColor() {
        cout << "Цвет фигуры: " << color << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:

    Circle(string c, double r) : Shape(c), radius(r) {}

    double area() {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:

    Rectangle(string c, double w, double h) : Shape(c), width(w), height(h) {}

    double area() {
        return width * height;
    }
};

int main() {

    Circle myCircle("Красный", 5.0);
    myCircle.printColor();
    cout << "Площадь круга: " << myCircle.area() << endl;

    cout << endl;

    Rectangle myRect("Синий", 4.0, 6.0);
    myRect.printColor();
    cout << "Площадь прямоугольника: " << myRect.area() << endl;

    return 0;
}
