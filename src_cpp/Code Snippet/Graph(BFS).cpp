#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10];
bool vis[10];
int dist[10];

// 연결 그래프일 경우
void bfs1() {
    queue<int> q;
    q.push(1);
    vis[1] = true;
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

// 연결 그래프가 아닐경우
void bfs2() {
    int v = 9;
    queue<int> q;
    for(int i = 1; i <= v; i++) {
        if(vis[i]) continue;
        q.push(i);
        vis[i] = true;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            cout << cur << ' ';
            for(int j = 0; j < adj[cur].size(); j++) {
                int nxt = adj[cur][j];
                if(vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = true;
            }
        }
    }
}

void bfs_dist() {
    for(int i = 1; i < 10; i++) dist[i] = -1;
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i = 0; i < adj[cur].size(); i++) {
            int nxt = adj[cur][i];
            if(dist[nxt] != -1) continue;
            q.push(nxt);
            dist[nxt] = dist[cur]+1;
        }
    }
}