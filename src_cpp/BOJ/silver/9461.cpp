#include<iostream>
#include<algorithm>

using namespace std;

unsigned long long cache[101] = { 0, };

unsigned long long pado(int n) {
    if(cache[n] != 0) {
        return cache[n];
    }

    if(n == 1) {
        return 1;
    } else if(n == 2) {
        return 1;
    } else if(n == 3) {
        return 1;
    } else if(n == 4) {
        return 2;
    } else if(n == 5) {
        return 2;
    } else {
        cache[n] = pado(n - 1) + pado(n - 5);
        return cache[n];
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    for(int i = 0; i < t; i++) {
        int n; cin >> n;
        cout << pado(n) << endl;
    }
}