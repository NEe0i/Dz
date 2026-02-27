#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const string FILE_NAME = "contacts.txt";

void addContact() {
    ofstream outFile(FILE_NAME, ios::app);
    string name, phone;
    cout << "Введите имя контакта: ";
    cin.ignore();
    getline(cin, name);
    cout << "Введите номер телефона: ";
    getline(cin, phone);

    outFile << name << ": " << phone << endl;
    outFile.close();
    cout << "Контакт успешно добавлен!" << endl;
}

void showAllContacts() {
    ifstream inFile(FILE_NAME);
    if (!inFile) {
        cout << "Список контактов пуст или файл не найден." << endl;
        return;
    }

    string line;
    cout << "Список контактов" << endl;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}

void findContact(string name) {
    ifstream inFile(FILE_NAME);
    string line;
    bool found = false;

    while (getline(inFile, line)) {
        if (line.find(name + ":") != string::npos) {
            cout << "Найдено: " << line << endl;
            found = true;
        }
    }
    if (!found) cout << "Контакт с именем '" << name << "' не найден." << endl;
    inFile.close();
}

void deleteContact(string name) {
    ifstream inFile(FILE_NAME);
    if (!inFile) return;

    vector<string> buffer;
    string line;
    bool deleted = false;
    while (getline(inFile, line)) {
        if (line.find(name + ":") == string::npos) {
            buffer.push_back(line);
        } else {
            deleted = true;
        }
    }
    inFile.close();

    if (deleted) {
        ofstream outFile(FILE_NAME);
        for (const string& s : buffer) {
            outFile << s << endl;
        }
        cout << "Контакт '" << name << "' успешно удален." << endl;
    } else {
        cout << "Контакт не найден." << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n--- ТЕЛЕФОННАЯ КНИГА ---" << endl;
        cout << "1. Добавить контакт" << endl;
        cout << "2. Показать все" << endl;
        cout << "3. Найти по имени" << endl;
        cout << "4. Удалить контакт" << endl;
        cout << "5. Выход" << endl;
        cout << "Ваш выбор: ";
        cin >> choice;

        if (choice == 5) break;

        string name;
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                showAllContacts();
                break;
            case 3:
                cout << "Введите имя для поиска: ";
                cin.ignore();
                getline(cin, name);
                findContact(name);
                break;
            case 4:
                cout << "Введите имя для удаления: ";
                cin.ignore();
                getline(cin, name);
                deleteContact(name);
                break;
            default:
                cout << "Неверный ввод!" << endl;
        }
    }

    return 0;
}
