#include<iostream>
#include<queue>
using namespace std;
#define X first
#define Y second
int board[102][102];
bool vis[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    int mx = 0;
    queue<pair<int, int>> Q;
    for(int k = 0; k <= 100; k++) {
        for(int x = 0; x < n; x++) {
            for(int y = 0; y < n; y++) {
                vis[x][y] = 0;
            }
        }
        int cnt = 0;
        //cout << "k(" << k << ") -> ";                    
        for(int i = 0; i < n; i++) {        
            for(int j = 0; j < n; j++) {
                if(vis[i][j] || board[i][j] <= k) continue;   
                cnt++;
                vis[i][j] = 1;
                Q.push({i, j});
                while(!Q.empty()){
                    pair<int,int> cur = Q.front(); Q.pop();
                    //cout << '(' << cur.X << ", " << cur.Y << ") -> ";

                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(vis[nx][ny] || board[nx][ny] <= k) continue;

                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                } 
            }
        }
        mx = max(cnt, mx);
        //cout << cnt << endl;
        //cout << "cnt(" << cnt << ")" << endl;
    }

    cout << mx;
}
