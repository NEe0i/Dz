#include<iostream>
using namespace std;

struct Student{
    string lastName;
    int grades[5];
    double averageGrade;
};

double calculateAverage(int grades[5]) {
    double sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += grades[i];
    }
    return sum / 5.0;
}
int main(){
    Student students[3];
    for(int i =0; i <3; i++){
        cout << "Введите фамилию студента: ";
        cin >> students[i].lastName;

        cout << "Введите 5 числе ерез пробел: ";
        for (int j = 0; j < 5; j++) {
            cin >> students[i].grades[j];
        }
        students[i].averageGrade = calculateAverage(students[i].grades);
        cout << "Средний балл: " << students[i].averageGrade << endl << endl;
    }
     int bestStudentIndex = 0;
    for (int i = 1; i < 3; i++) {
        if (students[i].averageGrade > students[bestStudentIndex].averageGrade) {
            bestStudentIndex = i;
        }
    }

    cout << "Студент с самым высоким средним баллом: " 
         << students[bestStudentIndex].lastName << endl;
}
