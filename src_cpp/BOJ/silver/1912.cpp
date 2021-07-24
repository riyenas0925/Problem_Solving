#include<iostream>
#include<algorithm>

using namespace std;

int dp[100001];
int arr[100001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0] = arr[0];
    int ans = arr[0];

    for(int i = 1; i < n; i++) {
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
        ans = max(dp[i], ans);
    }

    cout << ans << endl;
}