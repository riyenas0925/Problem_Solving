#include<bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str; cin >> str;
    ll n; cin >> n;

    list<char> l(str.begin(), str.end());
    auto idx = l.end();
    
    for(int i = 0; i < n; i++) {
        char com; cin >> com;
        
        if(com == 'L') {
            if(idx != l.begin()) idx--;
        }
        if(com == 'D') {
            if(idx != l.end()) idx++;
        }
        if(com == 'B') {
            if(idx != l.begin()) {
                idx--;
                idx = l.erase(idx);
            }
        }
        if(com == 'P') {
            char c; cin >> c;
            l.insert(idx, c);
        }
    }

    for(char c : l) cout << c;
    return 0;
}