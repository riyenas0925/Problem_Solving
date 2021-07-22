#include<iostream>

using namespace std;

// 123 -> 한수
// 135 -> 한수 X

int main(){
    int num, cnt = 0;
    cin >> num;

    if(num < 100) {
        cout << num << endl;
    } else {
        for(int i = 100; i <= num; i++) {
            int a = i % 10;
            int b = i / 10 % 10;
            int c = i / 100;

            if((a - b) == (b - c)) {
                cnt++;
            }
        }
        cout << cnt + 99 << endl;
    }
}