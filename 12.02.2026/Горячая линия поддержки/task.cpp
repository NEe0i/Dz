#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    queue<string> supportQueue;
 
    supportQueue.push("Не работает интернет");
    supportQueue.push("Ошибка авторизации");
    supportQueue.push("Запрос на смену тарифa");
    supportQueue.push("Проблема с оплатой");

    cout << "Поступило обращений: " << supportQueue.size() << endl;

    while (!supportQueue.empty()) {
        string currentTask = supportQueue.front();
        
        cout << "Обработка: " << currentTask << endl;

        supportQueue.pop();
    }

    cout << boolalpha; 
    cout << "Очередь пуста? " << supportQueue.empty() << endl;
    cout << "Размер очереди: " << supportQueue.size() << endl;

    return 0;
}
