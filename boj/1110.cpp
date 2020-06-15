/* 
0 <= n <= 99
n < 10
-> 앞에 0을 붙여 두자리 수로 만듬
 */

#include<iostream>

using namespace std;

int main(){
    int startNumber; cin >> startNumber;
    int tempNumber = startNumber;
    int cnt = 0;

    while(true){
        int newNumber = ((tempNumber % 10) + (tempNumber / 10)) % 10;
        int oldNumber = tempNumber % 10;

        tempNumber = (oldNumber * 10) + newNumber;

        cnt++;

        if(tempNumber == startNumber){
            break;
        }
    }

    cout << cnt << endl;

    return 0;
}