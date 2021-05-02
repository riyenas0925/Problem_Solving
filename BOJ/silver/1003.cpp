#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

int cache[41][3] = { 0, };

int fibonacci(int n) {
    if(cache[n][0] != 0) {
        return cache[n][0];
    }

    if (n == 0) {
        cache[n][1] = 1;
        return 0;
    } else if (n == 1) {
        cache[n][2] = 1;
        return 1;
    } else {
        cache[n][0] = fibonacci(n - 1) + fibonacci(n - 2);
        cache[n][1] = cache[n - 1][1] + cache[n - 2][1];
        cache[n][2] = cache[n - 1][2] + cache[n - 2][2];
        return cache[n][0];
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    for(int i = 0; i < t; i++) {
        int n; cin >> n;
        fibonacci(n);
        cout << cache[n][1] << " " << cache[n][2] << endl;
    }
}