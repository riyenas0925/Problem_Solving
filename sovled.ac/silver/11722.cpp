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
        int maxn = 0;

        for(int j = 0; j < i; j++) {
            if(arr[j] > arr[i]) {
                maxn = max(maxn, dp[j]);
            }
        }
        dp[i] = maxn + 1;
        ans = max(dp[i], ans);
    }

    cout << ans << endl;
}