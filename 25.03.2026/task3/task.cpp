#include <iostream>
#include <string>
#include <vector>
using namespace std;

class vozrast {
private:
    int age;
    friend class stud; 
};

class stud {
private:
    string lastName;
    string university;
    string group;
    vozrast v;

public:
    void enter() {
        cout << "Фамилия: "; cin >> lastName;
        cout << "Вуз: "; cin >> university;
        cout << "Группа: "; cin >> group;
        cout << "Возраст: "; cin >> v.age;
    }

    void show() {
        if (v.age < 18) {
            cout << lastName << " (" << university << ", гр. " << group 
                      << ") — " << v.age << " лет" << endl;
        }
    }
};

int main() {
    stud s;
    s.enter();
    cout << "Результат" << std::endl;
    s.show();
    return 0;
}
