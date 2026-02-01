#include <iostream>
using namespace std;

class Fraction {
  private:
    long long int x, y;

  public:
    Fraction(int x = 0, int y = 1) {
        this->x = x;
        this->y = y;
    }

    void read() {
        char s;
        cin >> x >> s >> y;
    }
    // Перегрузка оператора +
    Fraction operator + (Fraction &b) {
        
        long long int new_x = x * b.y + b.x * y;
        long long int new_y = y * b.y;           
        return *this;          
    }

    // Перегрузка оператора -
    Fraction operator - (const Fraction &b) {
        long long int new_x = x * b.y - b.x * y;
        long long int new_y = y * b.y;
        return Fraction(new_x, new_y);
    }
    
    // Перегрузка оператора *
    Fraction operator * (const Fraction &b) {
        long long int new_x = x * b.x;
        long long int new_y = y * b.y;
        return Fraction(new_x, new_y);
    }
    // Перегрузка оператора /
    Fraction operator / (const Fraction &b) {
        long long int new_x = x * b.y;
        long long int new_y = y * b.x;
        return Fraction(new_x, new_y);
    }
    // Перегрузка оператора ==
    bool operator == (const Fraction& b) {
        return x * b.y == b.x * y;
    }
    Fraction& operator ++ () {
        x = x + y;
        return *this;
    }

    Fraction operator - () const {
        return Fraction(-x, y); 
    }

    void show() {
        cout << x << "/" << y << endl;
    }
};

int main() {
    Fraction a, b, c1, c2, c3, c4;
    cout << "Введите первую дробь x/y: ";
    a.read();
    cout << "Введите вторую дробь x/y: ";
    b.read();
    cout << "Сложение: ";
    c1 = a + b;
    c1.show();

    cout << "Вычитание: ";
    c2 = a - b;
    c2.show();

    cout << "Умножениие: ";
    c3 = a * b;
    c3.show();

    cout << "Деление: ";
    c4 = a / b;
    c4.show();

    cout << "Сравнение: ";
    if (a==b) {
        cout << "Дроби равны" << endl;
    }
    else{
        cout << "Дроби неравные" << endl;
    }

    ++a; 
    cout << "После ++ (увеличение на 1): "; a.show();

    Fraction b = -a;
    cout << "Дробь с обратным знаком: "; b.show();


    return 0;
}
