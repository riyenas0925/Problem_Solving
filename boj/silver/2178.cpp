#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int vis[502][502] = { 0, };
int board[502][502] = { 0, };
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string str; cin >> str;
        for(int j = 0; j < m; j++) {
            board[i][j] = str[j]-'0';
        }
    }
    queue<pair<int,int> > Q;
    vis[0][0] = 1;
    Q.push({0,0});
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(vis[nx][ny] > 0 || board[nx][ny] != 1) continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
        }
    }

    cout << vis[n-1][m-1] << endl;
}