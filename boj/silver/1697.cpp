#include<bits/stdc++.h>
using namespace std;
int vis[100002] = { 0, };
int board[100002] = { 0, };
int n, m;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    fill(vis, vis + 100001, -1);
    queue<int> Q;
    vis[n] = 0;
    Q.push(n);
    while(vis[k] == -1) {
        int cur = Q.front(); Q.pop();
        for(int nxt : {cur + 1, cur - 1, cur * 2}) {
            if(nxt < 0 || nxt > 100000) continue;
            if(vis[nxt] != -1) continue;
            vis[nxt] = vis[cur] + 1;
            Q.push(nxt);
        }
    }
    cout << vis[k];
}