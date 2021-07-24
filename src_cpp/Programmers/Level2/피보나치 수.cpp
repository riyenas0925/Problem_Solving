#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long f[100001] = { 0, 1, };

long long fibo(long long n) {
    if(n == 0) {
        return 0;
    } else if(n == 1){
        return 1;
    } else {
        if(f[n] != 0) {
            return f[n];
        } else {
            f[n] = fibo(n-1) % 1234567 + fibo(n-2) % 1234567; 
            return f[n];
        }
    }
}

int solution(int n) {
    return fibo(n) % 1234567;
}

int main() {
    cout << solution(100000);
}
