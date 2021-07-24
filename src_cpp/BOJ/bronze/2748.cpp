#include<iostream>

using namespace std;

#define MAX 91

long long cache[MAX];

long long fib(int n){
    if(n <= 1) {
        return n;
    } else if(cache[n] != -1) {
        return cache[n];
    } else {
        return cache[n] = fib(n - 1) + fib(n - 2);
    }
}

int main(){
    for(int i = 0; i < MAX; i++){
        cache[i] = -1;
    }

    int n; cin >> n;
    cout << fib(n) << endl;
    return 0;
}