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
    std::vector<Employee> employees = {
        {"Alice Johnson", 28, 75000.50, "IT"},
        {"Bob", 35, 82000.0, "HR"},
        {"Charlie Brown", 42, 123456.78, "Management"},
        {"Diana", 31, 67000.25, "IT"}
    };
    std::locale loc("en_US.UTF-8");

    std::cout << std::format("| {:<18} | {:^7} | {:<10} | {:<11} |\n", 
                             "Имя", "Возраст", "Зарплата", "Отдел");
    std::cout << std::format("|{:-<20}|{:-<9}|{:-<12}|{:-<13}|\n", "", "", "", "");
    for (const auto& emp : employees) {
        std::cout << std::format(loc, "| {:<18} | {:^7} | {:>10,.2f} | {:<11} |\n", 
                                 emp.name, emp.age, emp.salary, emp.department);
    }

    return 0;
}
