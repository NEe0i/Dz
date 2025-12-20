#include <iostream>

using namespace std;

class Animal {
protected:
    string name;
    double weight;

public:
    Animal(string n, double w) : name(n), weight(w) {}

    virtual void showInfo() {
        cout << "Животное: " << name << "  Вес: " << weight << " кг";
    }

    virtual ~Animal() {}
};


class Predator : public Animal {
private:
    int huntingHours;

public:
    Predator(string n, double w, int hours) : Animal(n, w), huntingHours(hours) {}

    void showInfo() override {
        Animal::showInfo();
        cout << " Тип: Хищник | Время охоты: " << huntingHours << " ч/сут" << endl;
    }
};

class Herbivore : public Animal {
private:
    string favoritePlant;

public:
    Herbivore(string n, double w, string plant) : Animal(n, w), favoritePlant(plant) {}

    void showInfo() override {
        Animal::showInfo();
        cout << " | Тип: Травоядное | Любимая еда: " << favoritePlant << endl;
    }
};

int main() {

    Predator lion("Лев", 190.5, 8);
    Herbivore elephant("Слон", 5000, "Акация");

    cout << "Информация о животных:" << endl;
    
    lion.showInfo();
    elephant.showInfo();

    return 0;
}
