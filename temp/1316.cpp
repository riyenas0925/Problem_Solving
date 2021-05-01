// ccazzzzbb 연속
// kin 연속
// aabbbccb 불연속

#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
int main() {
    ll n; cin >> n;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        string str; cin >> str;
        bool alp[26] = { false }; 
        ll cnt = 0;
        for(int j = 0; j < str.length(); j++) {
            if(str[j] != str[j+1]) {
                ll idx = str[j] - 'a'; 
                if(alp[idx] == true) {
                    cnt++;
                } else {
                    alp[idx] = true;
                }
            }
        }

        if(cnt == 0) {
            ans++;
        }
    }

    cout << ans;
}
