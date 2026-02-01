#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    string choices[] = {"Камень", "Ножницы", "Бумага"};
    int userChoice, computerChoice;

    cout << "Выберите вариант (0 - Камень, 1 - Ножницы, 2 - Бумага): ";
    cin >> userChoice;

    if (userChoice < 0 || userChoice > 2) {
        cout << "Ошибка: выберите число от 0 до 2!" << endl;
        return 1;
    }

    computerChoice = rand() % 3;

    cout << "Вы выбрали: " << choices[userChoice] << endl;
    cout << "Компьютер выбрал: " << choices[computerChoice] << endl;

    if (userChoice == computerChoice) {
        cout << "Результат: Ничья!" << endl;
    } 
    else if ((userChoice == 0 && computerChoice == 1) ||
             (userChoice == 1 && computerChoice == 2) ||
             (userChoice == 2 && computerChoice == 0)) {
        cout << "Вы победили!" << endl;
    } 
    else {
        cout << "Вы проиграли" << endl;
    }

    return 0;
}
