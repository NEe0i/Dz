#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Shape {
public:
    virtual ~Shape() = default; 
    virtual void Draw() const = 0; 
};

class Circle : public Shape {
public:
    void Draw() const override {
            cout << "Рисую круг:\n";
            cout << "   ***   \n"
                  << " *      * \n"
                  << "*        *\n"
                  << " *      * \n"
                  << "   ***   \n\n";
    }
};

class Rectangle : public Shape {
public:
    void Draw() const override {
        cout << "Рисую прямоугольник:\n";
        cout << "**********\n"
                  << "*        *\n"
                  << "**********\n\n";
    }
};

class Triangle : public Shape {
public:
    void Draw() const override {
        cout << "Рисую треугольник:\n";
        cout << "    *    \n"
                  << "   * *   \n"
                  << "  *   *  \n"
                  << " ******* \n\n";
    }
};

int main() {
    vector<std::unique_ptr<Shape>> shapes;

    shapes.push_back(make_unique<Circle>());
    shapes.push_back(make_unique<Rectangle>());
    shapes.push_back(make_unique<Triangle>());

    for (const auto& shape : shapes) {
        shape->Draw();
    }

    return 0;
}
