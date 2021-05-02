#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(char a, char b) {
    return a > b;
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s; 
    ll ans = 0, sum = 0, cnt = 0;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] - '0' == 0) cnt++;
        sum = sum + s[i] - '0';
    }
    if(sum % 3 != 0 || cnt == 0 || sum == 0) {
        cout << -1 << endl;
        return 0;
    }
    sort(s.begin(), s.end(), cmp);
    for(int i = 0; i < s.size(); i++) {
        cout << s[i];
    }
}