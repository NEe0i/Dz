#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <iomanip>
#include <limits>
using namespace std;

class Figure {
public:
    virtual ~Figure() = default;
    virtual double GetArea() const = 0;
    virtual double GetPerimeter() const = 0;
    virtual string GetType() const = 0;
};

class Circle : public Figure {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double GetArea() const override { return M_PI * radius * radius; }
    double GetPerimeter() const override { return 2 * M_PI * radius; }
    string GetType() const override { return "Круг"; }
};


class Rectangle : public Figure {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double GetArea() const override { return width * height; }
    double GetPerimeter() const override { return 2 * (width + height); }
    string GetType() const override { return "Прямоугольник"; }
};

class RightTriangle : public Figure {
private:
    double legA, legB;
public:
    RightTriangle(double a, double b) : legA(a), legB(b) {}
    double GetArea() const override { return 0.5 * legA * legB; }
    double GetPerimeter() const override { 
        double hypotenuse = sqrt(legA * legA + legB * legB);
        return legA + legB + hypotenuse; 
    }
    string GetType() const override { return "Прямоугольный треугольник"; }
};


double GetPositiveDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value && value > 0) {
            return value;
        }
        cout << "Ошибка! Введите положительное число.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Функция вывода информации о фигурах
void PrintFiguresInfo(const vector<unique_ptr<Figure>>& figures) {
    if (figures.empty()) {
        cout << "\nСписок фигур пуст.\n";
        return;
    }
    
    cout << fixed << setprecision(2);
    cout << "\n===== РЕЗУЛЬТАТЫ РАСЧЕТОВ =====\n";
    for (size_t i = 0; i < figures.size(); ++i) {
        cout << i + 1 << ". Тип: " << figures[i]->GetType() << "\n"
                  << "   Площадь: " << figures[i]->GetArea() << "\n"
                  << "   Периметр: " << figures[i]->GetPerimeter() << "\n"
                  << "---------------------------\n";
    }
}

int main() {
    vector<unique_ptr<Figure>> figures;
    
    int choice = 0;
    while (true) {
        cout << "\nВыберите фигуру для добавления:\n"
                  << "1. Круг\n"
                  << "2. Прямоугольник\n"
                  << "3. Прямоугольный треугольник\n"
                  << "4. Завершить ввод и показать результат\n"
                  << "Ваш выбор: ";
                  
        if (!(cin >> choice)) {
            cout << "Некорректный выбор. Попробуйте еще раз.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 4) {
            break; 
        }

        switch (choice) {
            case 1: {
                double r = GetPositiveDouble("Введите радиус круга: ");
                figures.push_back(make_unique<Circle>(r));
                break;
            }
            case 2: {
                double w = GetPositiveDouble("Введите ширину прямоугольника: ");
                double h = GetPositiveDouble("Введите высоту прямоугольника: ");
                figures.push_back(make_unique<Rectangle>(w, h));
                break;
            }
            case 3: {
                double a = GetPositiveDouble("Введите первый катет треугольника: ");
                double b = GetPositiveDouble("Введите второй катет треугольника: ");
                figures.push_back(make_unique<RightTriangle>(a, b));
                break;
            }
            default:
                cout << "Такого пункта нет в меню. Введите число от 1 до 4.\n";
                break;
        }
    }

    PrintFiguresInfo(figures);

    return 0;
}
