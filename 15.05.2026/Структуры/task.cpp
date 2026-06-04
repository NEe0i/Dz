#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

struct Student {
    string name;
    string group;
    int scores[3];
    double average;
};


void calculate_average(Student &s) {
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        sum += s.scores[i];
    }

    s.average = static_cast<double>(sum) / 3.0;
}

int GetValidatedScore(const string& prompt) {
    int score;
    while (true) {
        cout << prompt;
        if (cin >> score && score >= 2 && score <= 5) {
            return score;
        }
        cout << "Ошибка! Оценка должна быть целым числом от 2 до 5.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    const int STUDENT_COUNT = 5;
    Student students[STUDENT_COUNT];

    cout << "===== ВВОД ДАННЫХ СТУДЕНТОВ =====\n";
    for (int i = 0; i < STUDENT_COUNT; ++i) {
        cout << "\nСтудент #" << i + 1 << ":\n";
        
        cout << "Введите имя (макс. 50 симв.): ";
        getline(cin >> ws, students[i].name);
        if (students[i].name.length() > 50) {
            students[i].name = students[i].name.substr(0, 50);
        }

        cout << "Введите группу (макс. 10 симв.): ";
        getline(cin, students[i].group);
        if (students[i].group.length() > 10) {
            students[i].group = students[i].group.substr(0, 10);
        }

        for (int j = 0; j < 3; ++j) {
            string prompt = "Введите оценку " + to_string(j + 1) + " (2-5): ";
            students[i].scores[j] = GetValidatedScore(prompt);
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        calculate_average(students[i]);
    }

    cout << fixed << setprecision(2);
    cout << "Студенты с отличием";
    
    bool found = false;
    for (int i = 0; i < STUDENT_COUNT; ++i) {
        if (students[i].average > 4.0) {
            cout << students[i].name << ", группа " << students[i].group 
                      << ", ср. балл " << students[i].average << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "Студентов со средним баллом выше 4.0 не найдено.\n";
    }

    return 0;
}
