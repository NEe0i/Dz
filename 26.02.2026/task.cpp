#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Engine {
public:
    string country;
    int year;
    int power;
};

struct Car {
    string name;
    int year;
    Engine engine; 
};

struct Shop {
    string name;
    int year;
    string description;
    vector<Car> cars; 
};

vector<Engine> engines;
vector<Car> cars;
vector<Shop> shops;

void add_engine() {
    Engine e;
    cout << "\n[Добавление двигателя]\n";
    cout << "Страна производства: ";
    cin >> e.country;
    cout << "Год выпуска: ";
    cin >> e.year;
    cout << "Мощность (л.с.): ";
    cin >> e.power;
    engines.push_back(e);
    cout << "Двигатель успешно добавлен!\n";
}

void add_car() {
    if (engines.empty()) {
        cout << "\nОшибка: Сначала добавьте хотя бы один двигатель!\n";
        return;
    }
    Car c;
    cout << "\n[Добавление машины]\n";
    cout << "Название: ";
    cin >> c.name;
    cout << "Год выпуска: ";
    cin >> c.year;

    cout << "Выберите номер двигателя для машины:\n";
    for (size_t i = 0; i < engines.size(); ++i) {
        cout << i << ". " << engines[i].country << " (" << engines[i].power << " л.с.)\n";
    }
    size_t eng_idx;
    cin >> eng_idx;
    if (eng_idx < engines.size()) {
        c.engine = engines[eng_idx];
        cars.push_back(c);
        cout << "Машина успешно добавлена!\n";
    } else {
        cout << "Неверный индекс двигателя.\n";
    }
}

void add_shop() {
    Shop s;
    cout << "\n[Добавление магазина]\n";
    cout << "Название магазина: ";
    cin >> s.name;
    cout << "Год основания: ";
    cin >> s.year;
    cout << "Описание: ";
    cin.ignore();
    getline(cin, s.description);
    shops.push_back(s);
    cout << "Магазин успешно добавлен!\n";
}

void ref_engine(size_t idx) {
    if (idx >= engines.size()) {
        cout << "Двигатель не найден!\n";
        return;
    }
    cout << "\n[Редактирование двигателя " << idx << "]\n";
    cout << "Новая страна (" << engines[idx].country << "): ";
    cin >> engines[idx].country;
    cout << "Новый год (" << engines[idx].year << "): ";
    cin >> engines[idx].year;
    cout << "Новая мощность (" << engines[idx].power << "): ";
    cin >> engines[idx].power;
}

void ref_car(size_t idx) {
    if (idx >= cars.size()) {
        cout << "Машина не найдена!\n";
        return;
    }
    cout << "\n[Редактирование машины " << idx << "]\n";
    cout << "Новое название (" << cars[idx].name << "): ";
    cin >> cars[idx].name;
    cout << "Новый год (" << cars[idx].year << "): ";
    cin >> cars[idx].year;
}

void ref_shop(size_t idx) {
    if (idx >= shops.size()) {
        cout << "Магазин не найден!\n";
        return;
    }
    cout << "\n[Редактирование магазина " << idx << "]\n";
    cout << "Новое название (" << shops[idx].name << "): ";
    cin >> shops[idx].name;
    cout << "Новый год (" << shops[idx].year << "): ";
    cin >> shops[idx].year;
    cout << "Новое описание: ";
    cin.ignore();
    getline(cin, shops[idx].description);
}

void del_engine(size_t idx) {
    if (idx < engines.size()) {
        engines.erase(engines.begin() + idx);
        cout << "Двигатель удален.\n";
    }
}

void del_car(size_t idx) {
    if (idx < cars.size()) {
        cars.erase(cars.begin() + idx);
        cout << "Машина удалена.\n";
    }
}

void del_shop(size_t idx) {
    if (idx < shops.size()) {
        shops.erase(shops.begin() + idx);
        cout << "Магазин удален.\n";
    }
}

int main() {

    add_engine();
    add_car();
    add_shop();

    if (!engines.empty()) {
        ref_engine(0);
    }

    if (!cars.empty()) {
        del_car(0);
    }

    return 0;
}
