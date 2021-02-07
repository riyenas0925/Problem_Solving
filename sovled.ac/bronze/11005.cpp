#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

using ll = unsigned long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, b; cin >> n >> b;

    vector<char> v;

    while(1) {
        ll mod = n % b;

        if(10 <= mod && mod <= 35) {
            v.push_back('A' - 10 + mod);
        }
        else {
            v.push_back(mod + '0');
        }

        n = n / b;

        if(n == 0) break;
    }

    for(int i = 0; i < v.size(); i++) {
        cout << v[v.size() - i -1];
    }
}