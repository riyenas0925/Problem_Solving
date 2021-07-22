#include<iostream>

using namespace std;

// 300, 60, 10 초
int main(){
    int T;
    cin >> T;

    int a = T / 300;

    int b = T % 300 / 60;

    int c = T % 60 / 10;
    
    if(T == (a * 300 + b * 60 + c * 10)) {
        cout << a << " " << b << " " << c <<endl;
    } else {
        cout << -1 << endl;
    }

}