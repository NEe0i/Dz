#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main() {
    map<string, vector<int>> studentGrades;
    
    studentGrades["Ivan"] = {5, 4, 3};
    studentGrades["Anna"] = {4, 5, 5};
    studentGrades["Peter"] = {3, 4, 2};

    cout << "Средние баллы студентов:" << endl;

    for (auto const& [name, grades] : studentGrades) {
        double sum = 0;

        for (int grade : grades) {
            sum += grade;
        }

        double average = sum / grades.size();
        
        cout << name << ": " << average << endl;
    }
    
    return 0;
}
