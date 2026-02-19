#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Browser {
private:
    stack<string> history_back;
    stack<string> history_forward;
    string current_page;

public:
    Browser() {
        current_page = "homepage.com";
        cout << "[Начало] Текущая страница: " << current_page << endl;
    }

    void visit(string url) {
        history_back.push(current_page);
        current_page = url;
        while (!history_forward.empty()) {
            history_forward.pop();
        }
        cout << "[Visit] Переход на: " << current_page << endl;
    }

    void back() {
        if (history_back.empty()) {
            cout << "[Back] Ошибка: Некуда возвращаться!" << endl;
            return;
        }
        history_forward.push(current_page);
        current_page = history_back.top();
        history_back.pop();
        cout << "[Back] Вернулись на: " << current_page << endl;
    }

    void forward() {
        if (history_forward.empty()) {
            cout << "[Forward] Ошибка: Впереди ничего нет!" << endl;
            return;
        }
        history_back.push(current_page);
        current_page = history_forward.top();
        history_forward.pop();
        cout << "[Forward] Перешли вперед на: " << current_page << endl;
    }

    void show_status() {
        cout << "Состояние: [" << current_page << "] (Назад: " 
             << history_back.size() << ", Вперед: " << history_forward.size() << ") ---" << endl;
    }
};

int main() {
    Browser myBrowser;

    myBrowser.visit("google.com");
    myBrowser.visit("github.com");
    myBrowser.visit("stackoverflow.com");
    myBrowser.show_status();

    myBrowser.back();
    myBrowser.back();
    myBrowser.forward();
    myBrowser.show_status();

    myBrowser.visit("youtube.com");
    myBrowser.forward();
    myBrowser.show_status();

    return 0;
}
