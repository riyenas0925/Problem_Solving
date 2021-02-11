#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[502][502] = { 0, };
bool vis[502][502] = { 0, };
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    int nx = 0;
    int num = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 0 || vis[i][j]) continue;
            queue<pair<int,int> > Q;
            int cnt = 0;
            vis[i][j] = 1;
            Q.push({i,j});
            while(!Q.empty()){
                pair<int,int> cur = Q.front(); Q.pop();
                cnt++;
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(vis[nx][ny] || board[nx][ny] != 1) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
            num = max(num, cnt);
            nx++;
        }
    }
    cout << nx << "\n" << num;
}