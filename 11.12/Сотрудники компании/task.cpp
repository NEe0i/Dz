#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
    double baseSalary;

public:
    Employee(string name, double baseSalary) : name(name), baseSalary(baseSalary) {}
    virtual double calculateSalary() const {
        return baseSalary;
    }
};

class Manager : public Employee {
private:
    double bonus;

public:
    Manager(string name, double baseSalary, double bonus) : Employee(name, baseSalary), bonus(bonus) {}
    double calculateSalary() const override {
        return baseSalary + bonus;
    }
};


class Developer : public Employee {
private:
    double overtimePay;

public:

    Developer(string name, double baseSalary, double overtimePay): Employee(name, baseSalary), overtimePay(overtimePay) {}

    double calculateSalary() const override {
        return baseSalary + overtimePay;
    }
};

int main() {

    Manager manager("Иван", 50000, 15000);
    Developer developer("Алексей", 60000, 20000);

    cout << "Зарплата менеджера: " << manager.calculateSalary() << endl;
    cout << "Зарплата разработчика: " << developer.calculateSalary() << endl;

    return 0;
}
