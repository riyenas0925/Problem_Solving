#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int dp[100001];
int arr[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    dp[1] = 1;

    for(int i = 2; i <= n; i++) {        
        dp[i] = i;
        for(int j = 0; j*j <= i; j++) {
            dp[i] = min(dp[i], dp[i-j*j] + 1);
        }
    }

    cout << dp[n] << endl;
}