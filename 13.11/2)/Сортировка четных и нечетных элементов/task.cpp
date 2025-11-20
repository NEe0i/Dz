#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main(){
    srand(time(NULL));
    int n = 10, a[n];
    for(int i = 0;i < n; i++){
        a[i]=rand() % (1 - 50);
        cout << a[i] << " ";
   }

   cout << endl;

    for(int i = 0;i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] % 2 == 0 and a[j] % 2 == 0){
                if(a[i] > a[j]){
                    swap(a[i], a[j]);
                }
            }
            else if(a[i] % 2 != 0 and a[j] % 2 != 0){
                if(a[i] < a[j]){
                    swap(a[j], a[i]);
                }                
            }
        }
   }

   for(int i = 0; i < n; i++){
    cout << a[i] << " ";
   }
   return 0;
}