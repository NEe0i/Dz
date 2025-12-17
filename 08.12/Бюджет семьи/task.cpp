#include<iostream>
using namespace std;

struct FamilyMember{
    string name;
    double salary;
};

struct FamilyBudget{
    string surname;
    FamilyMember* members;
    int count;
    double totalIncome;
};

FamilyBudget inputFamily() {
    FamilyBudget fb;
    
    cout << "Введите фамилию семьи: ";
    cin >> fb.surname;
    
    cout << "Введите количество членов семьи: ";
    cin >> fb.count;

    fb.members = new FamilyMember[fb.count];
    
    for (int i = 0; i < fb.count; i++) {
        cout << "Введите имя члена семьи " << i + 1 << ": ";
        cin >> fb.members[i].name;
        cout << "Введите зарплату: ";
        cin >> fb.members[i].salary;
    }
    
    fb.totalIncome = 0;
    return fb;
}

void calculateTotalIncome(FamilyBudget &fb) {
    fb.totalIncome = 0;
    for (int i = 0; i < fb.count; i++) {
        fb.totalIncome += fb.members[i].salary;
    }
}

void printFamilyInfo(const FamilyBudget &fb) {
    cout << "Семья " << fb.surname << endl;
    for (int i = 0; i < fb.count; i++) {
        cout << fb.members[i].name << ": " << fb.members[i].salary << " руб." << endl;
    }
    cout << endl;
    cout << "Общий доход семьи: " << fb.totalIncome << " руб." << endl;
}

int main() {
    FamilyBudget myFamily = inputFamily();
    calculateTotalIncome(myFamily);
    printFamilyInfo(myFamily);
    delete[] myFamily.members;
}