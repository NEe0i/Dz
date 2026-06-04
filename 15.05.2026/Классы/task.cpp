#include <iostream>
using namespace std;

class Counter {
private:
    int count;
    int step;

public:

    Counter() {
        count = 0;
        step = 1;
    }

    Counter(int initial_count, int initial_step) {
            if (initial_count < 0) {
            count = 0;
        } else {
            count = initial_count;
        }

        if (initial_step <= 0) {
            step = 1;
        } else {
            step = initial_step;
        }
    }

    void increment() {
        count += step;
    }

    void decrement() {
        if (count - step < 0) {
            count = 0;
        } else {
            count -= step;
        }
    }
    int get_value() const {
        return count;
    }
    void reset() {
        count = 0;
    }
    void set_step(int new_step) {
        if (new_step > 0) {
            step = new_step;
        } else {
            cout << "[Ошибка]: Шаг должен быть больше 0!" << endl;
        }
    }
};

int main() {
    cout << "Проверка сценария из примера" << endl;
    Counter c(10, 2);
    c.increment();
    c.increment();
    c.decrement();
    cout << "Текущее значение: " << c.get_value() << endl;
    c.reset();
    cout << "После сброса: " << c.get_value() << endl << endl;

    cout << "Проверка защиты от ухода в минус" << endl;
    Counter c2(3, 5);
    cout << "Стартовое значение: " << c2.get_value() << endl;
    c2.decrement();
    cout << "После декремента (ожидается 0): " << c2.get_value() << endl << endl;


    cout << "Проверка работы всех остальных методов" << endl;
    Counter default_counter;
    cout << "Дефолтный счетчик: " << default_counter.get_value() << endl;
    
    default_counter.increment();
    cout << "После инкремента: " << default_counter.get_value() << endl;

    default_counter.set_step(10);
    default_counter.increment();
    cout << "После изменения шага на 10 и инкремента: " << default_counter.get_value() << endl;

    return 0;
}
