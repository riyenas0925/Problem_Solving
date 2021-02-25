#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(const pair<ll,ll> &a, const pair<ll,ll> &b) {
    if(a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, ans = 0, pos = 0;
    pair<ll,ll> v[100001];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v, v + n, cmp);
    for(int i = 0; i < n; i++) {
        if(pos > v[i].first) continue;
        pos = v[i].second;
        ans++;
    }
    cout << ans;
}