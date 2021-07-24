package dfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class BOJ10026 {
    static char board[][] = new char[101][101];
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
        int ans1 = 0, ans2 = 0;
        for(int i = 0; i < n; i++) {
            String str = br.readLine();
            for(int j = 0; j < n; j++) {
                board[i][j] = str.charAt(j);
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(vis[i][j] == true) continue;
                Queue<Pair> Q = new LinkedList<>();
                char color = board[i][j];
                Q.add(new Pair(j, i));
                vis[i][j] = true;
                ans1++;
                while(!Q.isEmpty()) {
                    Pair cur = Q.peek();
                    Q.remove();
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx >= n || ny >= n || ny < 0 || nx < 0) continue;
                        if(vis[ny][nx] == true || board[ny][nx] != color) continue;
                        Q.add(new Pair(nx, ny));
                        vis[ny][nx] = true;
                    }
                }
            }
        }

        vis = new boolean[101][101];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(vis[i][j] == true) continue;
                Queue<Pair> Q = new LinkedList<>();
                char color = board[i][j];
                Q.add(new Pair(j, i));
                vis[i][j] = true;
                ans2++;
                while(!Q.isEmpty()) {
                    Pair cur = Q.peek();
                    Q.remove();
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx >= n || ny >= n || ny < 0 || nx < 0) continue;
                        if(vis[ny][nx] == true) continue;
                        if((board[ny][nx] == 'G' || board[ny][nx] == 'R') && (color == 'B')) continue;
                        if((board[ny][nx] == 'B') && (color == 'G' || color == 'R')) continue;
                        Q.add(new Pair(nx, ny));
                        vis[ny][nx] = true;
                    }
                }
            }
        }

        System.out.println(ans1 + " " + ans2);
    }
}
