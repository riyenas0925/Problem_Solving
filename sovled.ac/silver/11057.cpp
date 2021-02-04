#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

#define MOD 10007

long long dp[1001][10] = { 1, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    long long ans = 0;

    for(int i = 0; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= 9; j++) {
            for(int k = j; k <= 9; k++) {
                dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
            }
        }
    }

    for(int i = 0; i <= 9; i++) {
        ans += dp[n][i];
    }

    cout << ans % MOD << endl;
}