#include <iostream>
#include <vector>
#include <string>
#include <format>
#include <locale>

struct Employee {
    std::string name;
    int age;
    double salary;
    std::string department;
};

int main() {
    std::locale::global(std::locale("en_US.UTF-8"));

    std::vector<Employee> employees = {
        {"Alice Johnson", 28, 75000.50, "IT"},
        {"Bob", 35, 82000.0, "HR"},
        {"Charlie Brown", 42, 123456.78, "Management"},
        {"Diana", 31, 67000.25, "IT"}
    };

    std::cout << std::format("| {:<18} | {:^7} | {:>10} | {:<11} |", 
                             "Имя", "Возраст", "Зарплата", "Отдел") << std::endl;

    std::cout << "|--------------------|---------|------------|-------------|" << std::endl;

    for (const auto& emp : employees) {
        std::cout << std::format("| {:<18} | {:^7} | {:>10.2Lf} | {:<11} |", 
                                 emp.name, 
                                 emp.age, 
                                 emp.salary,
                                 emp.department) << std::endl;
    }

    return 0;
}
