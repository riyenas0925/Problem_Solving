#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> adj[201];
bool vis[201];

int bfs(int v) {
    int cnt = 0;
    queue<int> q;
    for(int i = 1; i <= v; i++) {
        if(vis[i]) continue;
        cnt++;
        q.push(i);
        vis[i] = true;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(int j = 0; j < adj[cur].size(); j++) {
                int nxt = adj[cur][j];
                if(vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    for(int i = 0; i < computers.size(); i++) {
        for(int j = 0; j < computers[i].size(); j++) {
            if(i == j) continue;
            if(computers[i][j] == 1) {
                cout << i+1 << "->" << j+1 << ", ";
                adj[i+1].push_back(j+1);
            }
        }
    }

    return bfs(n);
}

int main() {
    cout << solution(3, {{1,1,0},{1,1,0},{0,0,1}});
}