/*
1(1)            n * 6
2~7(6)
8~19(12)
20~37(18)
38~61(24)
*/

#include<iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int ans = 1;
    int i;

    for(i = 1; i <= n; i++) {
        ans += (i - 1) * 6;

        if(ans >= n) {
            break;
        }
    }

    cout << i << endl;
} 