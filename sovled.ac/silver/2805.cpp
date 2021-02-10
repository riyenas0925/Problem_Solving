#include<bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m; cin >> n >> m;
    ll arr[1000001] = { 0, };

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    ll low = 0, high = arr[n-1];
    ll target = m;
    ll mid, ans = 0;

    while(low <= high) {
        ll sum = 0;

        mid = (low + high) / 2;

        for(int i = 0; i < n; i++) {
            if(arr[i] > mid) {
                sum = sum + arr[i] - mid;
            }
        }

        if(sum >= target) {
            low = mid + 1;
            ans = max(ans, mid);
        } else {
            high = mid - 1;
        }
    }

    cout << ans << endl;
}