#include<bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n; cin >> n;

    for(int i = 0; i < n; i++) {
        string str; cin >> str;
        stack<char> s;
        ll cnt = 0;

        for(int j = 0; j < str.length(); j++) {
            if(str[j] == '(') {
                s.push(str[j]);
            } else {
                if(!s.empty()) {
                    if(s.top() == '(') {
                        s.pop();
                    }
                } else {
                    s.push(str[j]);
                }
            }
        }

        if(s.empty()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}