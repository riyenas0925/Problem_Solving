#include<bits/stdc++.h>

using namespace std;

using ll = unsigned long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, k; cin >> n >> k;
    queue<int> q;
    vector<int> v;
    ll cnt = 1;

    while(1){
        if(cnt > n) {
            if(q.empty()) break;

            if(cnt % k == 0) {
                v.push_back(q.front());
                q.pop();
            } else {
                q.push(q.front());
                q.pop();
            }
        } else {
            if(cnt % k == 0) {
                v.push_back(cnt);
            } else {
                q.push(cnt);
            }
        }
        cnt++;
    }

    cout << "<";

    for(int i = 0; i < v.size() - 1; i++) {
        cout << v[i] << ", ";
    }

    cout << v[v.size() - 1] << ">" << endl;
    cout << "";
}