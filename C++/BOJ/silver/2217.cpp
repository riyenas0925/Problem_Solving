#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[100001] = { 0, };
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    for(int i = 1; i <= n; i++) {
        ans = max(ans, arr[n-i] * i);
    }
    cout << ans;
}