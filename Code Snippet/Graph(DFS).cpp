#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10];
bool vis[10];

// 연결 그래프 (비재귀) -> Flood Fill, 순회에서만!!!!!
void dfs_non_recursion() {
    stack<int> s;
    s.push(1);
    vis[1] = true;
    while(!s.empty()) {
        int cur = s.top();
        s.pop();
        cout << cur << ' ';
        for(int i = 0; i < adj[cur].size(); i++) {
            int nxt = adj[cur][i];
            if(vis[nxt]) continue;
            s.push(nxt);
            vis[nxt] = true;
        }
    }
}

// 연결 그래프 (재귀) -> 관념적으로 생각하는 DFS, 순서 정확
// vis[1] = ture; dfs(1);
void dfs_recursion(int cur) {
    cout << cur << ' ';
    for(int i = 0; i < adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if(vis[nxt]) continue;
        vis[nxt] = true;
        dfs_recursion(nxt);
    }
}

// 비연결 그래프 (비재귀)
void dfs2() {
    stack<int> s;
    int v = 9;
    for(int i = 0; i <= v; i++) {
        if(vis[i]) continue;
        s.push(i);
        vis[i] = true;
        while(!s.empty()) {
            int cur = s.top();
            s.pop();
            cout << cur << ' ';
            for(int i = 0; i < adj[cur].size(); i++) {
                int nxt = adj[cur][i];
                if(vis[nxt]) continue;
                s.push(nxt);
                vis[nxt] = true;
            }
        }
    }
}