#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Job {
    int id;
    string user;
    int pages;
};

int main() {

    queue<Job> printerQueue;
    int toner = 30;

    printerQueue.push({1, "Иванов", 10});
    printerQueue.push({2, "Петров", 15});
    printerQueue.push({3, "Сидоров", 25});
    printerQueue.push({4, "Смирнова", 5});
    printerQueue.push({5, "Кузнецов", 12});

    cout << "Принтер готов к работе. Тонер: " << toner << " стр. " << endl;

    while (!printerQueue.empty()) {
        Job& currentJob = printerQueue.front();

        cout << "Проверка задания ID: " << currentJob.id << " (" << currentJob.user 
             << "), страниц: " << currentJob.pages << endl;

        if (toner >= currentJob.pages) {

            toner -= currentJob.pages;
            cout << ">> ПЕЧАТЬ ЗАВЕРШЕНА. Остаток тонера: " << toner << " стр." << endl;
            printerQueue.pop(); 
        } 
        else {
    
            cout << "!! ОШИБКА: Не хватает тонера для задания ID: " << currentJob.id << endl;
            cout << "Требуется: " << currentJob.pages << ", в наличии: " << toner << endl;

            cout << "Нажмите '1' для заправки картриджа (+20 стр) или любое число для ожидания: ";
            int action;
            cin >> action;
            if (action == 1) {
                toner += 20;
                cout << ">> КАРТРИДЖ ЗАПРАВЛЕН. Текущий тонер: " << toner << " стр." << endl;
            } else {
                cout << ">> Печать приостановлена..." << endl;
                break;
            }
        }
    }

    if (printerQueue.empty()) {
        cout << "Все задания напечатаны!" << endl;
    } else {
        cout << "В очереди осталось заданий: " << printerQueue.size() << " ---" << endl;
    }

    return 0;
}
