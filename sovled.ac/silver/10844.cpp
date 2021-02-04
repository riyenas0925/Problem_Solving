#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

#define MOD 1000000000

long long dp[101][10] = { 0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    long long ans = 0;

    for(int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= 9; j++) {
            if(j == 0) {
                dp[i][j] = dp[i-1][j+1];
            } else if ((1<=j)&&(j<=8)) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
            } else {
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }

    for(int i = 0; i <= 9; i++) {
        ans += dp[n][i];
    }

    cout << ans % MOD << endl;
}