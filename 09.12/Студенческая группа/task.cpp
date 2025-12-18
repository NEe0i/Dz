#include <iostream>
#include <algorithm>
using namespace std;

class StudentGroup {
public:
    string groupName;
    static const int maxSize = 25;
    string students[maxSize];
    int studentCount;

    StudentGroup(string name) {
        groupName = name;
        studentCount = 0;
    }

    void addStudent(string name) {
        if (studentCount < maxSize) {
            students[studentCount] = name;
            studentCount++;
            cout << "Студент " << name << " добавлен в группу " << groupName << "." << endl;
        } else {
            cout << "Ошибка: Группа переполнена (макс. " << maxSize << " чел.)" << endl;
        }
    }

    int findStudent(string name) {
        for (int i = 0; i < studentCount; i++) {
            if (students[i] == name) {
                return i;
            }
        }
        return -1;
    }

    void removeStudent(string name) {
        int index = findStudent(name);
        if (index != -1) {
            for (int i = index; i < studentCount - 1; i++) {
                students[i] = students[i + 1];
            }
            studentCount--;
            cout << "Студент " << name << " удален." << endl;
        } else {
            cout << "Студент " << name << " не найден." << endl;
        }
    }
    void sortStudents() {
        if (studentCount > 1) {
            sort(students, students + studentCount);
            cout << "Список студентов отсортирован." << endl;
        }
    }

    void displayGroup() {
        cout << "Группа: " << groupName << " (Всего: " << studentCount << ")" << endl;
        if (studentCount == 0) {
            cout << "Группа пуста." << endl;
        } else {
            for (int i = 0; i < studentCount; i++) {
                cout << i + 1 << ". " << students[i] << endl;
            }
        }
        cout << endl;
    }

    double getAverageNameLength() {
        if (studentCount == 0) return 0.0;
        
        double totalLength = 0;
        for (int i = 0; i < studentCount; i++) {
            totalLength += students[i].length();
        }
        return totalLength / studentCount;
    }
};

int main() {
    StudentGroup group("ИСП-2025");
    group.addStudent("Иванов");
    group.addStudent("Алексеев");
    group.addStudent("Сидоров");
    group.addStudent("Борисов");

    group.displayGroup();

    string searchName = "Сидоров";
    cout << "Поиск " << searchName << ": индекс " << group.findStudent(searchName) << endl;

    group.sortStudents();
    group.displayGroup();

    group.removeStudent("Иванов");
    group.displayGroup();
    cout << "Средняя длина имени в группе: " << group.getAverageNameLength() << " символов." << endl;

    return 0;
}