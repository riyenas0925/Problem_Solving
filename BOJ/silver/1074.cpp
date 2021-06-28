#include<iostream>
#include<cmath>
using namespace std;
int n, r, c;

int func(int n, int r, int c) {
    if(n == 0) return 0;
    int half = pow(2, n - 1);   // int half = 1<<(n-1);
    if(half > r && half > c) return func(n - 1, r, c);
    if(half > r && half <= c) return half*half + func(n, r, c - half);
    if(half <= r && half > c) return 2*half*half + func(n, r - half, c);
    if(half <= r && half <= c) return 3*half*half + func(n, r - half, c - half);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> r >> c;
    cout << func(n, r, c);
}