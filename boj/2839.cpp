/* 
3Kg, 5Kg 설탕 봉지
최소한의 개수로 가져가야함
 */

#include <iostream>
#include <string>

using namespace std;
int main(){
    int n; cin >> n;
    int min = 5000;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(n == (3 * i + 5 * j)){
                if(min > i + j){
                    min = i + j;
                }
            }
        }
    }

    if(min == 5000){
        cout << -1 << endl;
    } else {
        cout << min << endl;
    }
}