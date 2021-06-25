#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        queue<pair<int,int> > Q;
        int board[502][502] = { 0 };
        bool vis[502][502] = { 0 };
        int m, n, k; cin >> m >> n >> k;
        int cnt = 0;
        for(int j = 0; j < k; j++) {
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }
        for(int height = 0; height < n; height++) {
            for(int width = 0; width < m; width++) {
                if(board[height][width] == 1 && vis[height][width] != 1) {
                    vis[height][width] = 1;
                    Q.push({height,width});
                    cout << '(' << "vis : " << height << ", " << width << ") -> ";
                    cnt++;
                }
                while(!Q.empty()){
                    pair<int,int> cur = Q.front(); Q.pop();
                    //cout << '(' << cur.X << ", " << cur.Y << ") -> ";

                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(vis[nx][ny] || board[nx][ny] != 1) continue;

                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
}