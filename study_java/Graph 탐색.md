## 그래프

* 자료 구조로써 Graph = 정점(Vertex) + 간선(Edge)
* 간선(Edge) -> 무방향 / 방향
* deg(x) -> 정점 x의 차수(degree), 정점 x에 연결된 간선의 수
* deg(x)의 합 = 모든 정점의 차수의 합 = 간선의 개수의 2배

## 인접 행렬
* 공간 복잡도: O(V^2)
  * 만약 V=10만, E=50만 -> 100억개의 원소 -> 10G의 크기를 가진다.
  * 공간의 활용도가 매우 낮다.(0이 들어간 공간이 많다.)
* 시간 복잡도: 
  * A에서 B로 이동 가능? 가중치 얼마?: O(1)
  * 정점 A에서 갈 수 있는 정점들은?: O(V)

## 인접 리스트
* 공간 복잡도: O(E) 만큼의 공간이 필요
  * 만약 V=10만, E=50만 -> 50만개의 원소
* 시간 복잡도:
  * A에서 B로 이동 가능? 기중치 얼마?: O(min(deg(A), deg(B)))
  * 정점 A에서 갈 수 있는 정점들은?: O(deg(A))

### BFS
```java
static void bfs(int x) {
    Queue<Integer> q = new LinkedList<>();
    q.add(x);
    visit[x] = true;

    while(!q.isEmpty()) {
        x = q.poll();
        sb.append(x).append(' ');

        for(int y : adj[x]) {
            if(visit[y] == true) continue;
            q.add(y);
            visit[y] = true;
        }
    }
}
```

### DFS
```java
static void dfs(int x) {
    visit[x] = true;
    sb.append(x).append(' ');

    for(int y : adj[x]) {
        if(visit[y] == true) continue;
        dfs(y);
    }
}
```

## 격자형 그래프 유형
### BFS
```java
static void dfs(int x, int y) {
    visit[x][y] = true;

    for (int k = 0; k < 4; k++) {
        int nx = x + dir[k][0];
        int ny = y + dir[k][1];
        if(nx < 0 || ny < 0 || ny >= n || nx >= n) continue;
        if(arr[nx].charAt(ny) == '0') continue;
        if(visit[nx][ny]) continue;
        dfs(nx, ny);
    }
}
```

### DFS
```java
static void bfs(int x, int y) {
    Queue<Integer> q = new LinkedList<>();
    q.add(x);
    q.add(y);
    visit[x][y] = true;

    while(!q.isEmpty()) {
        x = q.poll();
        y = q.poll();

        for(int k = 0; k < 4; k++) {
            int nx = x + dir[k][0];
            int ny = y + dir[k][1];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visit[nx][ny] == true) continue;
            if(arr[nx].charAt(ny) == '0') continue;

            visit[nx][ny] = true;
            q.add(nx);
            q.add(ny);
        }
    }
}
```