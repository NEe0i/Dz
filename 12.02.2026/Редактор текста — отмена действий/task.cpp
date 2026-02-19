#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
list<string> lines;
    string input;

    cout << "Мини-редактор (команды: 'exit' - выход, пустая строка - Undo)" << endl;

    while (true) {
        cout << "> ";
        getline(cin, input); 

        if (input == "exit") {
            break;
        }

        if (input.empty()) {
            if (!lines.empty()) {
                lines.pop_back();
                cout << "[Система]: Последняя строка удалена (Undo)." << endl;
            } else {
                cout << "[Система]: Редактор уже пуст!" << endl;
            }
        } else {
            lines.push_back(input);
        }

        if (!lines.empty()) {
            cout << "Содержимое: ";
            for (auto it = lines.begin(); it != lines.end(); ++it) {
                cout << *it;
                if (next(it) != lines.end()) {
                    cout << " | ";
                }
            }
            cout << endl;
        } else {
            cout << "Содержимое пусто." << endl;
        }
    }

    cout << "Редактор закрыт" << endl;
    return 0;
}
