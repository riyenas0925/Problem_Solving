#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> adj[50001];
int dist[50001];

void bfs(int v) {
    for(int j = 1; j <= v; j++) dist[j] = -1;
    queue<int> Q;
    Q.push(1);
    dist[1] = 0;
    while(!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for(int i = 0; i < adj[cur].size(); i++) {
            int nxt = adj[cur][i];
            if(dist[nxt] != -1) continue;
            Q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }   
    }   
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0, mx = 0;
    for(int i = 0; i < edge.size(); i++) {
        int from = edge[i][0], to = edge[i][1];
        //cout << edge[i][0] << "->" << edge[i][1] << ", ";
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    bfs(n);

    mx = *max_element(dist, dist + n);

    for(int i = 1; i <= n; i++) if(dist[i] == mx) answer++;

    return answer;
}