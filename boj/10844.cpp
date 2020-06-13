#include <iostream>
#include <string>

using namespace std;

#define MAX 101
#define MOD 1000000000

long long cache[MAX][10];

long long stepNum(int n, int m){
    if(n == 1){
        return m == 0 ? 0 : 1;
    } else if(cache[n][m] != 0){
        return cache[n][m];  
    } else if(m == 0) {
        return cache[n][m] = stepNum(n - 1, m + 1) % MOD;
    } else if(m == 9) {
        return cache[n][m] = stepNum(n - 1, m - 1) % MOD;
    } else {
        return cache[n][m] = (stepNum(n - 1, m - 1) + stepNum(n - 1, m + 1)) % MOD;
    }
}

int main(){
    int n; cin >> n;
    long long total = 0;

    for(int m = 0; m < 10; m++){   
        total = (total + stepNum(n, m)) % MOD;
    }

    cout << total % MOD<< endl;
    return 0;
}