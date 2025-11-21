#include<iostream>
using namespace std;

int main(){
    int arr[6][7];
    int daystart;
    cout << "Введите день недели с которго начнеться месяц от 1 до 7: ";

    int day = 1;

    cin >> daystart;
    if(daystart > 7){
        cout << "Ошибка число должно быть не больше 7";
        return 0;
    }

    for(int i=0; i<6; i++){
        for(int j=0; j<7; j++){
            if(i == 0 and daystart -1 > j){
                arr[i][j] = 0;
            }
            else if(day < 31){
                arr[i][j] = day;
                day++;
            }
            else{
                arr[i][j] = 0;
            }
        }
    }

    for(int i =0; i < 6; i++){
        for(int j=0; j <7; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}