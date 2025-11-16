#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "Выберите блюдо: пицца(1) суши(2) тако(3) паста(4)";
    cin >> a;

    switch(a) {
        case 1: {
            a == 1;
            cout << "Стоит 500";
            break;
        }
        case 2: {
            a == 2;
            cout << "Стоит 600";
            break;
        }
        case 3: {
            a == 3;
            cout << "Стоит 450";
            break;
        }
        case 4: {
            a == 4;
            cout << "250";
            break;
        }
        default: {
            cout << "Ошибка" << endl;
        }
    }

    return 0;
}