#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;


int GetStudentCount() {
    int n;
    while (true) {
        cout << "Введите количество студентов: ";
        if (cin >> n && n > 0) {
            return n;
        }
        cout << "Ошибка! Введите целое положительное число.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void FillGrades(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 4 + 2;
    }
}

double CalculateAverage(const int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size;
}

int CountExcellentStudents(const int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == 5) {
            count++;
        }
    }
    return count;
}

int CountFailingStudents(const int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] == 2) {
            count++;
        }
    }
    return count;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int n = GetStudentCount();
    int* grades = new int[n];
    FillGrades(grades, n);
    cout << "Сгенерированные оценки: ";
    for (int i = 0; i < n; ++i) {
        cout << grades[i] << " ";
    }
    cout << "\n\n";

    cout << "Средний балл: " << CalculateAverage(grades, n) << "\n";
    cout << "Отличников: " << CountExcellentStudents(grades, n) << "\n";
    cout << "Неуспевающих: " << CountFailingStudents(grades, n) << "\n";

    delete[] grades;

    return 0;
}
