#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int dp[1001][3] = { 0, };
int arr[1001][3] = { 0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        dp[i][0] = min(dp[i-1][1] + arr[i][1], dp[i-1][2] + arr[i][2]);
        dp[i][1] = min(dp[i-1][0] + arr[i][0], dp[i-1][2] + arr[i][2]);
        dp[i][2] = min(dp[i-1][0] + arr[i][0], dp[i-1][1] + arr[i][1]);
    }

    cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << endl;
}