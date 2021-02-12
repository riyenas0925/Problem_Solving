#include<iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 0;

    for(int i = 0; i < 5; i++) {
        int n; cin >> n;
        t = t + n * n;
    }

    cout << t % 10 << "\n";
}