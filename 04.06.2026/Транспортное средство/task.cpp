#include <iostream>
#include <vector>
#include <memory>
using namespace std;


class Vehicle {
protected:
    double speed;
public:
    
    Vehicle() : speed(0.0) {}
    virtual ~Vehicle() = default;
    virtual void Move() = 0;
    virtual void Honk() const = 0;
    double GetSpeed() const {
        return speed;
    }

    virtual string GetType() const = 0;
};

class Car : public Vehicle {
public:
    void Move() override {
        speed += 10.0;
    }

    void Honk() const override {
        cout << "Beep-beep!";
    }

    string GetType() const override {
        return "Машина";
    }
};

class Bicycle : public Vehicle {
public:
    void Move() override {
        speed += 2.0;
    }

    void Honk() const override {
        cout << "Ring-ring!";
    }

    string GetType() const override {
        return "Велосипед";
    }
};

class Train : public Vehicle {
public:
    void Move() override {
        speed += 30.0;
    }

    void Honk() const override {
        cout << "Tu-tuuu!";
    }

    string GetType() const override {
        return "Поезд";
    }
};

int main() {
    vector<unique_ptr<Vehicle>> garage;

    garage.push_back(make_unique<Car>());
    garage.push_back(make_unique<Bicycle>());
    garage.push_back(make_unique<Train>());

    cout << "===== НАЧАЛО СИМУЛЯЦИИ ПоЕЗДКИ =====\n\n";

    for (const auto& vehicle : garage) {
        cout << "--- Тестируем: " << vehicle->GetType() << " ---\n";
        
        for (int i = 0; i < 5; ++i) {
            vehicle->Move();
        }
        cout << "Транспорт проехал 5 раз.\n";

        cout << "Сигнал: ";
        vehicle->Honk();
        cout << "\n";

        cout << "Конечная скорость: " << vehicle->GetSpeed() << " км/ч\n\n";
    }

    return 0;
}
