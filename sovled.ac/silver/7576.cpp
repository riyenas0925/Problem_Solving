#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int vis[1002][1002] = { 0, };
int board[1002][1002] = { 0, };
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    int ans = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    queue<pair<int,int> > Q;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 1) {
                vis[i][j] = 1;
                Q.push({i,j});
            }
        }
    }
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] > 0 || board[nx][ny] != 0) continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            ans = max(vis[nx][ny], ans);
            Q.push({nx,ny});
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j] == 0 && board[i][j] != -1) ans = 0;
        }
    }
    cout << ans - 1 << endl;
}