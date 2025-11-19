#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main(){
for (int i = 10; i != -1;){
    cout << i << endl;
    this_thread::sleep_for(chrono::seconds(1));
    i--;
}
cout << "Старт!";
return 0;
}