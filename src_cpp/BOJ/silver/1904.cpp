#include <iostream>
#include <string>

using namespace std;

#define MAX 1000000

long long cache[MAX];

long long tile(int n){
    if(n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else if(cache[n] != 0) {
        return cache[n];
    } else {
        return cache[n] = (tile(n-2) + tile(n-1)) % 15746;
    }
}

int main(){
    int n; cin >> n;
    cout << tile(n) << endl;
    return 0;
}

/* 
원래 O, X 하나
동주가 OO, X 로 만들어버림
-> N인 2진 수열을 만들수 없게 되었음

N=1 1
N=2 00, 11
N=3 001, 100, 111
N=4 0011, 1100, 0000, 1111, 1001
 */