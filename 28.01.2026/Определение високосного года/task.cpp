#include <iostream>

using namespace std;

int main() {
    int year;
    cout << "Введите год: ";
    cin >> year;

    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
        cout << year << " високосный год." << endl;
    } else {
        cout << year << " 2не високосный год." << endl;
    }

    return 0;
}
