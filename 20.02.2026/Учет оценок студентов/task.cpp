#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    vector<int> grades;

    double getAverage() const {
        if (grades.empty()) return 0;
        double sum = 0;
        for (int g : grades) sum += g;
        return sum / grades.size();
    }
};

const string FILENAME = "grades.txt";

Student parseLine(string line) {
    Student s;
    size_t colonPos = line.find(':');
    if (colonPos != string::npos) {
        s.name = line.substr(0, colonPos);
        string gradesPart = line.substr(colonPos + 1);
        stringstream ss(gradesPart);
        int grade;
        while (ss >> grade) {
            s.grades.push_back(grade);
        }
    }
    return s;
}

vector<Student> readAllStudents() {
    vector<Student> students;
    ifstream inFile(FILENAME);
    string line;
    while (getline(inFile, line)) {
        if (!line.empty()) {
            students.push_back(parseLine(line));
        }
    }
    inFile.close();
    return students;
}

void saveAllStudents(const vector<Student>& students) {
    ofstream outFile(FILENAME);
    for (const auto& s : students) {
        outFile << s.name << ":";
        for (int g : s.grades) outFile << " " << g;
        outFile << endl;
    }
    outFile.close();
}

void addStudent() {
    string name;
    cout << "Введите фамилию студента: ";
    cin.ignore();
    getline(cin, name);
    
    ofstream outFile(FILENAME, ios::app);
    outFile << name << ":" << endl;
    outFile.close();
    cout << "Студент добавлен." << endl;
}

void addGrade() {
    string targetName;
    int newGrade;
    cout << "Кому добавить оценку? (Фамилия): ";
    cin.ignore();
    getline(cin, targetName);
    cout << "Введите оценку: ";
    cin >> newGrade;

    vector<Student> students = readAllStudents();
    bool found = false;
    for (auto& s : students) {
        if (s.name == targetName) {
            s.grades.push_back(newGrade);
            found = true;
            break;
        }
    }

    if (found) {
        saveAllStudents(students);
        cout << "Оценка добавлена." << endl;
    } else {
        cout << "Студент не найден." << endl;
    }
}

void showStatistics() {
    vector<Student> students = readAllStudents();
    if (students.empty()) {
        cout << "Журнал пуст." << endl;
        return;
    }

    double totalSum = 0;
    Student* best = &students[0];
    Student* worst = &students[0];

    cout << "Успеваемость" << endl;
    for (auto& s : students) {
        double avg = s.getAverage();
        cout << left << setw(15) << s.name << " | Средний балл: " << fixed << setprecision(2) << avg << endl;
        
        totalSum += avg;
        if (avg > best->getAverage()) best = &s;
        if (avg < worst->getAverage()) worst = &s;
    }

    cout << "Общая статистика" << endl;
    cout << "Всего студентов: " << students.size() << endl;
    cout << "Средний балл группы: " << totalSum / students.size() << endl;
    cout << "Лучший (по ср. баллу): " << best->name << endl;
    cout << "Худший (по ср. баллу): " << worst->name << endl;
}

int main() {
    int choice;

    while (true) {
        cout << "\n1. Новый студент\n2. Поставить оценку\n3. Список и статистика\n4. Выход\nВыбор: ";
        cin >> choice;

        if (choice == 4) break;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: addGrade(); break;
            case 3: showStatistics(); break;
            default: cout << "Ошибка ввода." << endl;
        }
    }
    return 0;
}
