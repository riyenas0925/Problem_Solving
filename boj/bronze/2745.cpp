#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>

using namespace std;

using ll = unsigned long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str; ll b; cin >> str >> b;
    ll ans = 0;

    reverse(str.begin(), str.end());

    for(int i = 0; i < str.length(); i++) {
        if('A' <= str[i] && str[i] <= 'Z') {
            ans = ans + (str[i] - 'A' + 10) * pow(b, i);
        } else {
            ans = ans + (str[i] - '0') * pow(b, i);
        }
    }

    cout << ans << endl;
}