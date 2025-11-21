#include<iostream>
using namespace std;

int main(){
    int arr[5][5];
    for (int i = 0; i < 5; i++) { 
        for (int j = 0; j < 5; j++) {
            if(i > j){
                arr[i][j] = 0;
            }
            if(i < j){
                arr[i][j] = 1;
            }
            if(i == j){
                arr[i][j] = 2;
            }
        }
    }

    for (int i= 0; i < 5; i++){
        for(int j =0; j < 5; j++){
            
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}