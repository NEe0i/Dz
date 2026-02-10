#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, string> phoneBook;
    phoneBook["Ivan"] = "123-4567";
    phoneBook["Anna"] = "765-4321";
    phoneBook["Peter"] = "555-1234";
    
    cout << "Номер Anna: " << phoneBook["Anna"] << endl;
    
    if (phoneBook.count("Maria")) {
        cout << "Maria найдена: " << phoneBook["Maria"] << endl;
    } else {
        cout << "Контакт Maria не найден." << endl;
    }

    phoneBook.erase("Peter");
    cout << "Контакт Peter удален." << endl;

    cout << "Всего контактов: " << phoneBook.size() << endl;

    cout << "Список всех контактов:" << endl;
    for (auto const& [name, phone] : phoneBook) {
        cout << name << " -> " << phone << endl;
    }
    
    return 0;
}
