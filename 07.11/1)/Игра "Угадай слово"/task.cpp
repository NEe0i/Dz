#include <iostream>
#include <string>
using namespace std;

int main() {
    string vvod;
    cout << "Введите слово из 5 букв: " << endl;
    cin >> vvod;
    char a0 = vvod[0];
    char a1 = vvod[1];
    char a2 = vvod[2];
    char a3 = vvod[3];
    char a4 = vvod[4];
    string slovo = "slovo";
    char b0 = slovo[0];
    char b1 = slovo[1];
    char b2 = slovo[2];
    char b3 = slovo[3];
    char b4 = slovo[4];
    if(a0 == b0) {
        cout << "Первая буква правильная" << endl;
    }
    if(a1 == b1) {
        cout << "Вторая буква правильная" << endl;
    }
    if(a2 == b2) {
        cout << "Третья буква правильная" << endl;
    }
    if(a3 == b3) {
        cout << "Четвёртая буква правильная" << endl;
    }
    if(a4 == b4) {
        cout << "Пятая буква правильная" << endl;
    }
    if(vvod == slovo) {
        cout << "Вы угадали!" << endl;
    }
    return 0;
}