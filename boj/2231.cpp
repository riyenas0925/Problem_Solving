/*
자연수 N -> N + N의 각자리수(분해합)
M의 분해합이 N인 경우 M을 N의 생성자라고 말함
245(생성자) -> 256(분해합), 생성자가 없을수도 있다.
 */

#include<iostream>

#define MAX 1000001

using namespace std;

int main(){
    int n; cin >> n;

    for(int i = 1; i < MAX; i++){
        int con = i;
        int sum = 0;

        while(true){
            int num = con % 10;
            sum = sum + num;
            con = con / 10;

            if(con == 0){
                break;
            }  
        }

        if(n == sum + i){
            cout << i << endl;
            return 0;
        }
    }

    cout << 0 << endl;

    return 0;
}