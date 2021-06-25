#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<int> adj[10];
    int v, e;   // 정점(Vertex), 간선(Edge)  
    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);    // Directed Graph
        //adj[to].push_back(from);  // Undirected Graph
    }
}