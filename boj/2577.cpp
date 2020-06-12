#include<iostream>

using namespace std;

int main(){
    int numCount[100] = {0};
    int a, b, c, result;

    cin >> a >> b >> c;
    result = a * b * c;

    while(result != 0){
        int num = result % 10;
        numCount[num] = numCount[num] + 1; 
        result = result / 10;
    }

    for(int i = 0; i < 10; i++){
        cout << numCount[i] << endl;
    }

    return 0;
}