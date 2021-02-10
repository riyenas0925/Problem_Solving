#include<bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n; cin >> n;
    deque<ll> dq;

    for(int i = 0; i < n; i++) {
        string com; cin >> com;

        if(com == "push_front") {
            ll num; cin >> num;
            dq.push_front(num);
        } else if(com == "push_back") {
            ll num; cin >> num;
            dq.push_back(num);
        } else if(com == "pop_front") {
            if(!dq.empty()) {
                cout << dq.front() << endl;
                dq.pop_front();   
            } else {
                cout << -1 << endl;
            }
        } else if(com == "pop_back") {
            if(!dq.empty()) {
                cout << dq.back() << endl;
                dq.pop_back();   
            } else {
                cout << -1 << endl;
            }
        } else if(com == "size") {
            cout << dq.size() << endl;
        } else if(com == "empty") {
            cout << dq.empty() << endl;
        } else if(com == "front") {
            if(!dq.empty()) {
                cout << dq.front() << endl;
            } else {
                cout << -1 << endl;
            }
        } else if(com == "back") {
            if(!dq.empty()) {
                cout << dq.back() << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
}