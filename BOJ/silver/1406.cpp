#include<bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    list<char> L;
    list<char>::iterator t = L.begin();
    string str; cin >> str;
    for(char c : str) L.insert(t, c);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        char c; cin >> c;
        if(c == 'P') {
            char val; cin >> val;
            L.insert(t, val);
        }
        if(c == 'L' && t != L.begin()) t--;
        if(c == 'D' && t != L.end()) t++;
        if(c == 'B' && t != L.begin()) t = L.erase(--t);
    }

    for(auto i : L) cout << i;
}