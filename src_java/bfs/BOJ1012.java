package bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ1012 {
    static int board[][] = new int[51][51];
    static boolean vis[][] = new boolean[51][51];
    static int dx[] = {0, 1, 0, -1};
    static int dy[] = {1, 0, -1, 0};
    static class Pair {
        int X;
        int Y;

        Pair(int Y, int X) {
            this.X = X;
            this.Y = Y;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        for(int i = 0; i < t; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int m = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            board = new int[51][51];
            vis = new boolean[51][51];

            for(int j = 0; j < k; j++) {
                StringTokenizer input = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(input.nextToken());
                int y = Integer.parseInt(input.nextToken());
                board[y][x] = 1;
            }

            int cnt = 0;

            for(int h = 0; h < n; h++) {
                for(int w = 0; w < m; w++) {
                    if(vis[h][w] || board[h][w] == 0) continue;
                    Queue<Pair> Q = new LinkedList<>();
                    Q.add(new Pair(h, w));
                    vis[h][w] = true;
                    cnt++;

                    while(!Q.isEmpty()) {
                        Pair cur = Q.peek(); Q.remove();
                        for(int dir = 0; dir < 4; dir++) {
                            int ny = cur.Y + dy[dir];
                            int nx = cur.X + dx[dir];
                            if(ny >= n || nx >= m || nx < 0 || ny < 0) continue;
                            if(vis[ny][nx] || board[ny][nx] == 0) continue;
                            Q.add(new Pair(ny, nx));
                            vis[ny][nx] = true;
                        }
                    }
                }
            }
            System.out.println(cnt);
        }
    }
}
