#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int memo[102][102][102];

int w(int a, int b, int c) {

    if(memo[a + 51][b + 51][c + 51] != 0) {
        return memo[a + 51][b + 51][c + 51];
    }

    if(a <= 0 || b <= 0 || c <= 0) {
        return 1;
    } else if (a > 20 || b > 20 || c > 20) {
        memo[a + 51][b + 51][c + 51] = w(20, 20, 20);
        return  memo[a + 51][b + 51][c + 51];
    } else if (a < b && b < c) {
         memo[a + 51][b + 51][c + 51] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
        return  memo[a + 51][b + 51][c + 51];
    } else {
         memo[a + 51][b + 51][c + 51] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
        return  memo[a + 51][b + 51][c + 51];
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(1) {
        int a, b, c; cin >> a >> b >> c;
        
        if(a == -1 && b == -1 && c == -1) {
            break;
        }

        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
    }
}