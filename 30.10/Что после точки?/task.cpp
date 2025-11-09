#include <iostream>
#include <string>
using namespace std;

int main() {
    string x;

    cout << "Введите число x: ";
    cin >> x;

    size_t pos = x.find('.');

    if (pos != string::npos) {

        cout << "Цифры после точки: " << x.substr(pos + 1) << endl;
    } else {
        cout << "В числе нет точки!" << endl;
    }

    return 0;
}
