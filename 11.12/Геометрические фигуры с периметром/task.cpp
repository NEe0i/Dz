#include <iostream>
#include <cmath>

using namespace std;

class Figure {
protected:
    string name;
public:
    Figure(string n) : name(n) {}
    virtual ~Figure() {}

    virtual double area() = 0;
    virtual double perimeter() = 0;

    void printName() {
        cout << "\nФигура: " << name << endl;
    }
};

class Triangle : public Figure {
private:
    double a, b, c;
public:
    Triangle(double sideA, double sideB, double sideC) 
        : Figure("Треугольник"), a(sideA), b(sideB), c(sideC) {}

    double perimeter() override {
        return a + b + c;
    }

    double area() override {

        double p = perimeter() / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

class Square : public Figure {
private:
    double side;
public:
    Square(double s) : Figure("Квадрат"), side(s) {}

    double perimeter() override {
        return 4 * side;
    }

    double area() override {
        return side * side;
    }
};

class Circle : public Figure {
private:
    double radius;
public:
    Circle(double r) : Figure("Круг"), radius(r) {}

    double perimeter() override {
        return 2 * M_PI * radius;
    }

    double area() override {
        return M_PI * radius * radius;
    }
};

int main() {
    Figure* figures[3];

    figures[0] = new Triangle(3, 4, 5);
    figures[1] = new Square(10);
    figures[2] = new Circle(7);

    for (int i = 0; i < 3; i++) {
        figures[i]->printName();
        cout << "Периметр: " << figures[i]->perimeter() << endl;
        cout << "Площадь:  " << figures[i]->area() << endl;
    }
    for (int i = 0; i < 3; i++) {
        delete figures[i];
    }

    return 0;
}
