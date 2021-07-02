## 다차원 배열의 BFS, DFS
-   플러드 필 문제는 BFS/DFS 알고리즘으로 해결 가능
-   적당한 난이도의 자료구조와 구현력을 요구하는 문제이기 때문에 코딩테스트에 정말 자주 나오는 유형
-   BFS는 큐로 구현, DFS는 스택으로 구현

## BFS

-   BFS는 다차원 배열에서 각 칸을 방문할 때 너비를 우선으로 방문하는 알고리즘
-   모든 칸이 큐에 1번 씩만 들어감이 보장되므로 시간복잡도는 칸이 N개일 때 O(N)
-   시작점으로부터의 거리를 잴 때, 다차원 배열에서는 DFS보다는 BFS사용 추천

## 구현

1.  시작하는 칸을 큐에 넣고 방문했다는 표시를 남긴다.
2.  큐에서 원소를 꺼내어 그 칸에 상/하/좌/우로 인접한 4개의 칸에 대해 3번 행동을 한다.
3.  해당 칸을 이전에 방문했다면 아무 것도 하지 않고, 처음으로 방문했다면 방문했다는 표시를 남기고 해당 칸을 큐에 넣는다.
4.  큐의 모든 원소가 빌 때 까지 2를 반복한다.

```cpp
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응

bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장
int n = 7, m = 10; // n = 행의 수, m = 열의 수
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향을 의미

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int,int> > Q;
    vis[0][0] = 1; // (0, 0)을 방문했다고 명시
    Q.push({0,0}); // 큐에 시작점인 (0, 0)을 삽입.

    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        cout << '(' << cur.X << ", " << cur.Y << ") -> ";

        for(int dir = 0; dir < 4; dir++){ // 상하좌우 칸을 살펴볼 것이다.
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
            if(vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우

            vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
            Q.push({nx,ny});
        }
    }
}
```

## DFS

-   DFS는 다차원 배열에서 각 칸을 방문할 때 깊이를 우선으로 방문하는 알고리즘
-   BFS와 거의 동일한 흐름이나 큐 대신 스택을 쓴다는 차이점만 있습니다.
-   모든 칸이 큐에 1번 씩만 들어감이 보장되므로 시간복잡도는 칸이 N개일 때 O(N)

## 구현

1.  시작하는 칸을 스택에 넣고 방문했다는 표시를 남긴다.
2.  스택에서 원소를 꺼내 그 칸에 상/하/좌/우로 인접한 4개의 칸에 대해 3번 행동을 한다.
3.  해당 칸을 이전에 방문했다면 아무 것도 하지 않고, 처음으로 방문했다면 방문했다는 표시를 남기고 해당 칸을 스택에 넣는다.
4.  스택의 모든 원소가 빌 때 까지 2를 반복한다.

```cpp
#define X first
#define Y second // pair에서 first, second를 줄여서 쓰기 위해서 사용
int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응

bool vis[502][502]; // 해당 칸을 방문했는지 여부를 저장
int n = 7, m = 10; // n = 행의 수, m = 열의 수
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향을 의미

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int,int> > S;
    vis[0][0] = 1; // (0, 0)을 방문했다고 명시
    S.push({0,0}); // 스택에 시작점인 (0, 0)을 삽입.

    while(!S.empty()){
        pair<int,int> cur = S.top(); S.pop();
        cout << '(' << cur.X << ", " << cur.Y << ") -> ";

        for(int dir = 0; dir < 4; dir++){ // 상하좌우 칸을 살펴볼 것이다.
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // 범위 밖일 경우 넘어감
            if(vis[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우

            vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
            S.push({nx,ny});
        }
    }
}
```

### 1차원 배열의 DFS
```cpp
void dfs(vector<int> nums, int target, int sum, int idx) {
    if(idx == nums.size()) {
        if(sum == target) cnt++;
        return;
    }
    
    dfs(nums, target, sum + nums[idx], idx + 1);
    dfs(nums, target, sum - nums[idx], idx + 1);
}
```

## 참고

-   [\[실전 알고리즘\] 0x05강 - BFS, DFS\_구버전](https://blog.encrypted.gg/729?category=773649)