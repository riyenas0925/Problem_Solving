#include<iostream>
using namespace std;
using ll = long long;

// 12^58 = 4(mod67) -> 4
// 12^116 = 4*4(mod67) -> 16
// 12^117 = 12*4*4(mod67) -> 58
ll func(ll a, ll b, ll c) {
    if(b == 1) return a % c;
    ll val = func(a, b / 2, c);
    val = (val * val) % c;
    if(b % 2 == 0) return val % c;
    else return (val * a) % c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    cout << func(a, b, c);
}