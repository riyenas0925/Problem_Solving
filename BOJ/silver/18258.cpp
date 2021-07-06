#include <bits/stdc++.h>

using namespace std;

queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        string com; cin >> com;

        if(com == "push") {
            int n; cin >> n;
            q.push(n);
        } else if(com == "pop") {
            if(q.empty()) cout << "-1" << "\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        } else if(com == "size") {
            cout << q.size() << "\n";
        } else if(com == "empty") {
            cout << q.empty() << "\n";
        } else if(com == "front") {
            if(q.empty()) cout << "-1" << "\n";
            else cout << q.front() << "\n";
        } else if(com == "back") {
            if(q.empty()) cout << "-1" << "\n";
            else cout << q.back() << "\n";
        }
    }
}