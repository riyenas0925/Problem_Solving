#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
bool vis[1002][1002] = { 0, };
int board[1002][1002] = { 0, };
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        string str; cin >> str;
        for(int j = 0; j < n; j++) {
            board[i][j] = str[j] - '0';
        }
    }
    queue<pair<int,int>> Q;
    vector<int> V;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 1 && vis[i][j] != 1) {
                vis[i][j] = 1;
                Q.push({i,j});
                int cnt = 0;
                while(!Q.empty()) {
                    pair<int,int> cur = Q.front(); Q.pop();
                    cnt++;
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if(vis[nx][ny] || board[nx][ny] != 1) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
                V.push_back(cnt);
            }
        }
    }
    sort(V.begin(), V.end());
    cout << V.size() << "\n";
    for(int i = 0; i < V.size(); i++) {
        cout << V[i] << "\n";
    }
}