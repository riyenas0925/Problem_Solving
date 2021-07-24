#include<bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    queue<int> q;

    for(int i = 1; i <= n; i++) q.push(i);

    for(int i = 0; i < n; i++) {
        if(q.size() == 1) break;
        q.pop();
        int num = q.front();
        q.pop();
        q.push(num);
    }

    cout << q.back();

    return 0;
}