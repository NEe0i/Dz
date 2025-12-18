#include<iostream>
#include<iomanip>
using namespace std;

class Timer{
    public:
    int hours;
    int minutes;
    int seconds;

    void normalize(){
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }
}
    Timer() : hours(0), minutes(0), seconds(0) {}

    void reset() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    void tick() {
        seconds++;
        normalize();
    }
    void addSeconds(int sec) {
        if (sec > 0) {
            seconds += sec;
            normalize();
        }
    }
    void displayTime() const {
            cout << setfill('0') << setw(2) << hours << ":" << setfill('0') << setw(2) << minutes << ":" << setfill('0') << setw(2) << seconds <<endl;
    }

    int getTotalSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }
};

int main(){
    Timer myTimer;

    cout << "Начальное время: ";
    myTimer.displayTime();

    cout << "Тикаем 5 раз..." << endl;
    for(int i = 0; i < 5; i++) myTimer.tick();
    myTimer.displayTime();

    cout << "Добавляем 55 секунд:" << endl;
    myTimer.addSeconds(55);
    myTimer.displayTime();

    cout << "Добавляем 3661 секунду:" << endl;
    myTimer.addSeconds(3661);
    myTimer.displayTime();

    cout << "Всего секунд в таймере: " << myTimer.getTotalSeconds() << endl;

    myTimer.reset();
    cout << "После сброса: ";
    myTimer.displayTime();
}