#include <iostream>
#include <cmath>
using namespace std;

int main() {
    const int STUDENTS = 5;
    double average;
    int grade;

    for (int i = 1; i <= STUDENTS; i++) {
        cout << "Введите средний балл ученика " << i << ": ";
        cin >> average;

        grade = round(average);

        if (grade < 2) grade = 2;
        if (grade > 5) grade = 5;

        cout << "Итоговая оценка ученика " << i << ": " << grade << endl;
    }

    return 0;
}
