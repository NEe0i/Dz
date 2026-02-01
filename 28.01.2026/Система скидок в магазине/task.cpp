#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    double total;
    bool hasCard, isHoliday;
    int discount = 0;

    cout << "Введите сумму покупки: ";
    cin >> total;
    cout << "Есть карта лояльности? (1 - да, 0 - нет): ";
    cin >> hasCard;
    cout << "Сегодня праздник? (1 - да, 0 - нет): ";
    cin >> isHoliday;

    if (total > 1000) discount += 5;

    if (hasCard) discount += 3;

    if (isHoliday) discount += 2;

    if (discount > 15) discount = 15;

    double finalPrice = total * (1.0 - discount / 100.0);

    cout << "Ваша скидка: " << discount << "%" << endl;
    cout << "Сумма к оплате: " << finalPrice << " руб." << endl;

    return 0;
}
