#include<iostream>

using namespace std;

int main(){
    int price;
    int minMenuPrice = 2000;
    int minDrinkPrice = 2000;

    for(int i = 0; i < 3; i++){
        cin >> price;
        if(minMenuPrice > price){
            minMenuPrice = price;
        }
    }

    for(int i = 3; i < 5; i++){
        cin >> price;
        if(minDrinkPrice > price){
            minDrinkPrice = price;
        }
    }

    cout << minMenuPrice + minDrinkPrice - 50 << endl;

    return 0;
}