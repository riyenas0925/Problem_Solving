#include<iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    for(int i = 1; i <= 9; i++) {
        cout << n << " * " << i << " = " << n * i << endl;
    }
}