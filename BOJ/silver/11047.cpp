#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, k, ans = 0;
    ll coin[10];
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    for(int i = n - 1; i >= 0; i--) {
        if(k == 0) break;
        if(coin[i] > k) continue;
        else {
            ans += k / coin[i];
            k = k % coin[i];
        }
    }
    cout << ans;
}