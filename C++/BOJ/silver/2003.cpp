#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
int main() {
    ll n, m, sum, cnt = 0;
    ll sptr = 0, lptr = 0;
    ll arr[100001] = { 0, };   
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    while(sptr < n) {
        if(sum == m) cnt++;
        if(sum >= m) sum -= arr[sptr++];
        else sum += arr[lptr++];
    }
    cout << cnt;
}
