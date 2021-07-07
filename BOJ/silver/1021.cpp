#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    deque<int> dq;
    vector<int> vm;
    int cnt = 0;
    for(int i = 1; i <= n; i++) dq.push_back(i);
    for(int i = 0; i < m; i++) {
        int num; cin >> num;
        vm.push_back(num);
    }
    for(int i = 0; i < m; i++) {
        while(1) {
            int pos;
            for(pos = 0; pos < dq.size(); pos++) {
                if(dq[pos] == vm[i]) break;
            }
            if(dq.front() == vm[i]) {
                dq.pop_front();
                break;   
            } else if(pos >= dq.size() - pos) {
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            } else if(pos < dq.size() - pos) {
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
        }
    }
    cout << cnt << endl;
} 