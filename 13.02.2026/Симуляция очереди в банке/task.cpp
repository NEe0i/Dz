#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Customer {
    int arrivalTime;
    int serviceDuration;
};

int main() {
    int numWindows, numCustomers;
    cout << "Введите количество окон: ";
    cin >> numWindows;
    cout << "Введите количество клиентов: ";
    cin >> numCustomers;

    queue<Customer> bankQueue;
    priority_queue<int, vector<int>, greater<int>> windows;
    for (int i = 0; i < numWindows; ++i) {
        windows.push(0);
    }
    for (int i = 0; i < numCustomers; ++i) {
        bankQueue.push({i * 2, 5 + rand() % 11}); 
    }

    long long totalWaitTime = 0;
    int maxQueueLength = 0;
    int currentTime = 0;

    cout << "Симуляция началась" << endl;

    while (!bankQueue.empty()) {
        Customer c = bankQueue.front();
        bankQueue.pop();


        int windowFreeTime = windows.top();
        windows.pop();

        int waitTime = 0;
        if (windowFreeTime > c.arrivalTime) {
            waitTime = windowFreeTime - c.arrivalTime;
            currentTime = windowFreeTime;
        } else {
            currentTime = c.arrivalTime;
        }

        totalWaitTime += waitTime;
        int nextFreeTime = currentTime + c.serviceDuration;
        windows.push(nextFreeTime);

        if (waitTime > 0) maxQueueLength++; 
    }

    cout << fixed << setprecision(2);
    cout << "Среднее время ожидания: " << (double)totalWaitTime / numCustomers << " мин." << endl;
    cout << "Общее время работы банка: " << currentTime << " мин." << endl;
    cout << "Максимальное количество ожидавших (оценка): " << maxQueueLength << endl;

    return 0;
}