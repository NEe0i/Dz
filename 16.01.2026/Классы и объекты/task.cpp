#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

class Student {
private:
    string name;
    int grades[5];
    double averageGrade;

public:
    Student(const string& studentName, const int studentGrades[5]) {
        name = studentName;
        for (int i = 0; i < 5; i++) {
            grades[i] = studentGrades[i];
        }
        calculateAverage();}

    void calculateAverage() {
        double sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += grades[i];
        }
        averageGrade = sum / 5.0;
    }

    void printInfo() const {
        cout << "Студент: " << name << endl;
        cout << "Оценки: ";
        for (int i = 0; i < 5; i++) {
            cout << grades[i];
            if (i < 4) cout << ", ";
        }
        cout << endl;
        cout << "Средний балл: " << fixed << setprecision(2) << averageGrade << endl;
        cout << "Отличник: " << (hasExcellentGrades() ? "да" : "нет") << endl;
        cout << "----------------------------------------" << endl;
    }

    bool hasExcellentGrades() const {
        for (int i = 0; i < 5; i++) {
            if (grades[i] < 8) {
                return false;
            }
        }
        return true;
    }

    bool changeGrade(int subjectIndex, int newGrade) {
        if (subjectIndex < 0 || subjectIndex >= 5) {
            cout << "Ошибка: неверный индекс предмета (должен быть от 0 до 4)" << endl;
            return false;
        }
        if (newGrade < 0 || newGrade > 10) {
            cout << "Ошибка: оценка должна быть от 0 до 10" << endl;
            return false;
        }
        
        grades[subjectIndex] = newGrade;
        calculateAverage();
        return true;
    }

    string getName() const { return name; }
    double getAverageGrade() const { return averageGrade; }
    void getGrades(int outputGrades[5]) const {
        for (int i = 0; i < 5; i++) {
            outputGrades[i] = grades[i];
        }
    }
};

const Student* findBestStudent(const vector<Student>& students) {
    if (students.empty()) {
        return nullptr;
    }
    
    const Student* bestStudent = &students[0];
    double maxAverage = students[0].getAverageGrade();
    
    for (size_t i = 1; i < students.size(); i++) {
        if (students[i].getAverageGrade() > maxAverage) {
            maxAverage = students[i].getAverageGrade();
            bestStudent = &students[i];
        }
    }
    
    return bestStudent;
}

int main() {
    int grades1[5] = {8, 9, 7, 10, 9};
    int grades2[5] = {9, 10, 8, 9, 10};
    int grades3[5] = {6, 7, 8, 6, 7};
    int grades4[5] = {10, 10, 10, 10, 9};
    Student student1("Иванов И.И.", grades1);
    Student student2("Петров П.П.", grades2);
    Student student3("Сидоров С.С.", grades3);
    Student student4("Кузнецова А.В.", grades4);

    cout << "ИНФОРМАЦИЯ О СТУДЕНТАХ" << endl;
    student1.printInfo();
    student2.printInfo();
    student3.printInfo();
    student4.printInfo();

    cout << "ТЕСТИРОВАНИЕ ИЗМЕНЕНИЯ ОЦЕНКИ" << endl;
    cout << "Изменяем оценку студента " << student3.getName() << ":" << endl;
    cout << "Попытка изменить оценку по предмету 2 (математика) на 9..." << endl;
    student3.changeGrade(2, 9);
    student3.printInfo();

    cout << "\nПопытка изменить оценку по неверному индексу..." << endl;
    student1.changeGrade(10, 9); 
    student1.changeGrade(2, 15);

    vector<Student> students;
    students.push_back(student1);
    students.push_back(student2);
    students.push_back(student3);
    students.push_back(student4);

    cout << "ПОИСК ЛУЧШЕГО СТУДЕНТА" << endl;
    const Student* bestStudent = findBestStudent(students);
    
    if (bestStudent != nullptr) {
        cout << "Студент с наивысшим средним баллом:" << endl;
        bestStudent->printInfo();
    }

    cout << "АНАЛИЗ УСПЕВАЕМОСТИ" << endl;
    int excellentCount = 0;
    
    for (const auto& student : students) {
        if (student.hasExcellentGrades()) {
            excellentCount++;
        }
    }
    
    cout << "Количество отличников в группе: " << excellentCount << endl;
    cout << "Процент отличников: " << fixed << setprecision(1) 
         << (excellentCount * 100.0 / students.size()) << "%" << endl;

    cout << "ДЕМОНСТРАЦИЯ ПЕРЕСЧЕТА СРЕДНЕГО БАЛЛА" << endl;
    Student testStudent("Тестовый Студент", grades3);
    cout << "До изменения:" << endl;
    testStudent.printInfo();
    
    cout << "После изменения оценки по предмету 0 на 10:" << endl;
    testStudent.changeGrade(0, 10);
    testStudent.printInfo();

    cout << "СРЕДНИЕ БАЛЛЫ ВСЕХ СТУДЕНТОВ" << endl;
    for (size_t i = 0; i < students.size(); i++) {
        cout << students[i].getName() << ": " 
             << fixed << setprecision(2) << students[i].getAverageGrade() << endl;
    }

    return 0;
}