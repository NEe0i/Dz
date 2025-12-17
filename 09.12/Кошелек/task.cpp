#include<iostream>
using namespace std;

class Wallet{
    public:
    int rubles;
    int dollars;
    int euros;
    Wallet(int rub = 0, int usd = 0, int eur = 0) {
        rubles = (rub >= 0) ? rub : 0;
        dollars = (usd >= 0) ? usd : 0;
        euros = (eur >= 0) ? eur : 0;
    }
    void addMoney(int rub, int usd, int eur) {
        if (rub > 0) rubles += rub;
        if (usd > 0) dollars += usd;
        if (eur > 0) euros += eur;
        cout << "Баланс пополнен." << endl;
    }
    bool spendMoney(int rub, int usd, int eur) {
        if (rub <= rubles and usd <= dollars and eur <= euros) {
            rubles -= rub;
            dollars -= usd;
            euros -= eur;
            cout << "Оплата прошла успешно." << endl;
            return true;
        } else {
            cout << "Ошибка: недостаточно средств в одной из валют!" << endl;
            return false;
        }
    }

    double convertToRubles(double usdRate, double eurRate) {
        return rubles + (dollars * usdRate) + (euros * eurRate);
    }

    void displayBalance() const {
        cout << "Рубли:   " << rubles << " RUB" << endl;
        cout << "Доллары: " << dollars << " USD" << endl;
        cout << "Евро:    " << euros << " EUR" << endl;
    }
};

int main() {

    Wallet myWallet(5000, 100, 50);
    myWallet.displayBalance();

    myWallet.addMoney(1000, 0, 20);

    myWallet.spendMoney(2000, 150, 10);
    myWallet.spendMoney(2000, 50, 10);

    myWallet.displayBalance();

    double usdRate = 95.5;
    double eurRate = 103.2;
    cout << "Общая сумма в рублях: " << myWallet.convertToRubles(usdRate, eurRate) << " руб." << endl;

    return 0;
}
