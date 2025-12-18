#include <iostream>
using namespace std;

class Book {
public:
    string title;
    string author;
    int year;
    double price;
    bool isAvailable;

    Book(string t, string a, int y, double p) {
        title = t;
        author = a;
        year = y;
        price = p;
        isAvailable = true;
    }

    void borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Книга \"" << title << "\" успешно выдана." << endl;
        } else {
            cout << "Ошибка: Книга \"" << title << "\" уже на руках." << endl;
        }
    }

    void returnBook() {
        isAvailable = true;
        cout << "Книга \"" << title << "\" возвращена в библиотеку." << endl;
    }

    void applyDiscount(double percent) {
        if (percent > 0 and percent <= 100) {
            price -= price * (percent / 100.0);
            cout << "Применена скидка " << percent << "%. Новая цена: " << price << endl;
        }
    }

    void displayInfo() {
        cout << "Книга: " << title << endl;
        cout << "Автор: " << author << endl;
        cout << "Год:   " << year << endl;
        cout << "Цена:  " << price << " руб." << endl;
        cout << "Статус: " << (isAvailable ? "Доступна" : "Выдана") << endl;
        cout << endl;
    }

    bool isOldBook() {
        const int currentYear = 2025;
        return (currentYear - year) > 50;
    }
};

int main() {
    Book myBook("Властелин колец", "Дж. Р. Р. Толкин", 1954, 1500.0);
    myBook.displayInfo();
    if (myBook.isOldBook()) {
        cout << "Это издание считается старым (более 50 лет)." << endl;
    }
    myBook.borrowBook();

    myBook.applyDiscount(15);
    myBook.returnBook();

    myBook.displayInfo();

}