#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, string> phonebook;

    auto add = [&](string name, string phone) {
        phonebook[name] = phone;
    };

    auto remove = [&](string name) {
        phonebook.erase(name);
    };

    auto find = [&](string name) {
        if (phonebook.count(name)) {
            return phonebook[name];
        }
        return string("Контакт не найден");
    };

    add("Ivan", "+7123456789");
    add("Alice", "+79995554422");
    
    cout << "Поиск Alice: " << find("Alice") <<endl;
    
    remove("Alice");
    cout << find("Alice") << endl;
    return 0;
}
