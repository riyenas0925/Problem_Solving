package dfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class BOJ2468 {
    static int board[][] = new int[101][101];
    static boolean vis[][] = new boolean[101][101];
    static int dx[] = {1, 0, -1, 0};
    static int dy[] = {0, 1, 0, -1};

    static class Pair {
        int X;
        int Y;

        Pair(int X, int Y) {
            this.X = X;
            this.Y = Y;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int ans = 0;

        for(int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for(int h = 0; h <= 100; h++) {
            vis = new boolean[101][101];
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(vis[i][j] == true || board[i][j] - h <= 0) continue;
                    Stack<Pair> S = new Stack<>();
                    S.push(new Pair(j, i));
                    vis[i][j] = true;
                    cnt++;

                    while (!S.empty()) {
                        Pair cur = S.peek(); S.pop();
                        for(int dir = 0; dir < 4; dir++) {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if(nx >= n || ny >= n || ny < 0 || nx < 0) continue;
                            if(vis[ny][nx] == true || board[ny][nx] - h <= 0) continue;
                            S.push(new Pair(nx, ny));
                            vis[ny][nx] = true;
                        }
                    }
                }
            }
            if(cnt == 0) break;
            ans = Math.max(ans, cnt);
        }

        System.out.println(ans);
    }
}
