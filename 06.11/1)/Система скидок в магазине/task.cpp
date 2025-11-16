#include <iostream>
using namespace std;

int main() {
    double sum, prochent;

    cout << "Введите сумму покупки: ";
    cin >> sum;

    if (sum < 1000)
        prochent = 0.0;
    else if (sum < 5000)
        prochent = 0.05;
    else if (sum < 10000)
        prochent = 0.10;
    else
        prochent = 0.15;

    double finalSum = sum * (1 - prochent);

    cout << "Скидка: " << prochent * 100 << "%" << endl;
    cout << "Итоговая сумма к оплате: " << finalSum << " руб" << endl;

    return 0;
}
