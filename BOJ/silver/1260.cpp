#include<bits/stdc++.h>

using namespace std;

vector<int> adj[1001];
bool vis[1001];

void bfs(int st) {
    queue<int> q;
    q.push(st);
    vis[st] = true;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for(int i = 0; i < adj[cur].size(); i++) {
            int nxt = adj[cur][i];
            if(vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = true;
        }
    }
}

void dfs(int cur) {
    vis[cur] = true;
    cout << cur << ' ';
    for(int i = 0; i < adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        if(vis[nxt]) continue;
        vis[nxt] = true;
        dfs(nxt);
    }
}

int main() {
    int n, m, v;
    cin >> n >> m >> v;
    for(int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    for(int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end(), less<int>());
    }
    dfs(v);
    cout << endl;   
    fill(vis, vis+n+1,false);
    bfs(v);
}