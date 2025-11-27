#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main(){
    srand(time(NULL));
    int arr[4][4];
    for(int i=0; i < 4; i++){
        for(int j=0; j < 4; j++){
            arr[i][j] = 1+rand()% (1-20);
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    int glav_sum = 0, pobov_sum = 0;
    for(int i=0; i < 4; i++){
        for(int j=0; j < 4; j++){
            if(i==j){
            glav_sum += arr[i][j];}
            if(i+j == 4 - 1){
                pobov_sum += arr[i][j];
            }
        }
    }
    for(int j =0; j < 4; j++){
        int tmp;
        tmp = arr[0][j];
        arr[0][j] = arr[3][j];
        arr[3][j] = tmp;
    }
    cout << endl;
    cout << "Сумма чисел в главной диоганале: " << glav_sum << endl;
    cout << "Сумма чисел в побоччной диоганеле: " << pobov_sum << endl;
    for(int i = 0; i < 4; i++){
        for(int j =0; j<4; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}