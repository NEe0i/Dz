#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    string filename = "numbers.txt";
    ofstream outFile(filename);

    cout << "Введите 10 целых чисел:" << endl;
    for (int i = 0; i < 10; i++) {
        int num;
        cout << "Число " << i + 1 << ": ";
        cin >> num;
        outFile << num << endl;
    }
    outFile.close();
    cout << "\nДанные успешно сохранены в " << filename << endl;

    ifstream inFile(filename);

    int currentNum;
    int sum = 0;
    int count = 0;
    int maxVal = numeric_limits<int>::min();
    int minVal = numeric_limits<int>::max();

    cout << "Числа из файла: ";

    while (inFile >> currentNum) {
        cout << currentNum << " ";
        
        sum += currentNum;
        count++;

        if (currentNum > maxVal) maxVal = currentNum;
        if (currentNum < minVal) minVal = currentNum;
    }
    inFile.close();

    if (count > 0) {
        cout << "Сумма: " << sum << endl;
        cout << "Среднее: " << (double)sum / count << endl;
        cout << "Максимум: " << maxVal << endl;
        cout << "Минимум: " << minVal << endl;
    } else {
        cout << "Файл пуст." << endl;
    }

    return 0;
}
