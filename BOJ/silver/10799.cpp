#include<bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str; cin >> str;
    stack<char> s;
    ll ans = 0;
    ll dep = 0;

    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(') {
            dep++;
            s.push(str[i]);
        } else {
            if(!s.empty()) {
                if(s.top() == '(') {
                    dep--;
                    ans = ans + dep;
                    s.push(str[i]);
                } else {
                    dep--;
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}