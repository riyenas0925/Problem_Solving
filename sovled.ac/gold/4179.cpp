#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int vis[1002][1002] = { 0, };
int fire[1002][1002] = { 0, };
int board[1002][1002] = { 0, };
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string str; cin >> str;
        for(int j = 0; j < m; j++) {
            board[i][j] = str[j];
        }
    }
    queue<pair<int,int>> Q1;
    queue<pair<int,int>> Q2;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'F') {
                fire[i][j] = 1;
                Q1.push({i,j});
            }
            if(board[i][j] == 'J') {
                vis[i][j] = 1;
                Q2.push({i,j});
            }
        }
    }
    while(!Q1.empty()) {
        pair<int,int> cur = Q1.front(); Q1.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(fire[nx][ny] > 0 || board[nx][ny] == '#') continue;
            fire[nx][ny] = fire[cur.X][cur.Y] + 1;
            Q1.push({nx,ny});
        }
    }
    while(!Q2.empty()) {
        pair<int,int> cur = Q2.front(); Q2.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) {
                cout << vis[cur.X][cur.Y];
                return 0; 
            }
            if(vis[nx][ny] > 0 || board[nx][ny] == '#') continue;
            if(fire[nx][ny] != 0 && fire[nx][ny] <= vis[cur.X][cur.Y] + 1) continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            Q2.push({nx,ny});
        }
    }
    cout << "IMPOSSIBLE" << endl;
}