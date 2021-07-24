#include<iostream>
#include<algorithm>

using namespace std;

int dp[1001];
int arr[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = 1;

    dp[0] = 1;

    for(int i = 1; i < n; i++) {
        dp[i] = 1;

        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
}