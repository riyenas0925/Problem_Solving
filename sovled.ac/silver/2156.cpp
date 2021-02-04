#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int dp[10001] = { 0, };
int arr[10001] = { 0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];

    for(int i = 3; i <= n; i++) {
        dp[i] = max(dp[i], arr[i] + dp[i-2]);
        dp[i] = max(dp[i], arr[i] + arr[i-1] + dp[i-3]);
        dp[i] = max(dp[i], dp[i-1]);
    }

    cout << dp[n] << endl;
}