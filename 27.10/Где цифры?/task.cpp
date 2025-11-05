#include <iostream>
using namespace std;

int main() {
    int X;

    cout << "Введите двузначное число: ";
    cin >> X;

    if (X < 10 || X > 99) {
        cout << "Ошибка: число должно быть двузначным!" << endl;
        return 0;
    }

    int tens = X / 10;
    int ones = X % 10;

    cout << tens << " " << ones << endl;

    return 0;
}
