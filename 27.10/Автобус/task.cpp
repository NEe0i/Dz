#include <iostream>
using namespace std;

int main() {
    int m, k, n;

    cout << "Сколько человек было в автобусе изначально (m): ";
    cin >> m;

    cout << "Сколько человек вошло (k): ";
    cin >> k;

    cout << "Сколько человек вышло (n): ";
    cin >> n;

    int total = m + k - n;

    if (total < 0) {
        cout << "Ошибка: количество людей не может быть отрицательным!" << endl;
        return 0;
    }

    cout << "Теперь в автобусе " << total << " человек." << endl;

    return 0;
}
