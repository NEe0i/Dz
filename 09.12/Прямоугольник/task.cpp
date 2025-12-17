#include<iostream>
using namespace std;

class Rectangle{
    public:
    double width, height;
    Rectangle(double w, double h){
        width = (w > 0)? w : 1.0;
        height = (h > 0)? h : 1.0;
    }
    double getWidth() const { return width; }
    double getHeight() const { return height; }

    void setWidth(double w) {
        if (w > 0) width = w;
    }

    void setHeight(double h) {
        if (h > 0) height = h;
    }

    double calculateArea() const {
        return width * height;
    }

    double calculatePerimeter() const {
        return 2 * (width + height);
    }

    bool isSquare() const {
        return width == height;
    }
};

int main() {
    double x, y;
    cout << "Введите шиирену: ";
    cin >> x;
    cout << "Введите длину: ";
    cin >> y;
    Rectangle rect(x, y);

    cout << "Ширина: " << rect.getWidth() << ", Высота: " << rect.getHeight() << endl;
    cout << "Площадь: " << rect.calculateArea() << endl;
    cout << "Периметр: " << rect.calculatePerimeter() <<endl;
    cout << "Это квадрат? " << (rect.isSquare() ? "Да" : "Нет") << endl;

    return 0;
};