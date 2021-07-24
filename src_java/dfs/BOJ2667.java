package dfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;

public class BOJ2667 {
    static int board[][] = new int[26][26];
    static boolean vis[][] = new boolean[26][26];
    static int dx[] = {1, 0, -1, 0};
    static int dy[] = {0, 1, 0, -1};

    static class Pair {
        int X;
        int Y;

        public Pair(int x, int y) {
            X = x;
            Y = y;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int ans = 0;
        ArrayList ar = new ArrayList<>();

        for(int i = 0; i < n; i++) {
            String str = br.readLine();
            for(int j = 0; j < n; j++) {
                board[i][j] = str.charAt(j) - '0';
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(vis[i][j] == true || board[i][j] == 0) continue;
                Queue<Pair> Q = new LinkedList<>();
                Q.add(new Pair(j, i));
                vis[i][j] = true;
                int space = 0;
                ans++;
                while (!Q.isEmpty()) {
                    Pair cur = Q.peek();
                    Q.remove();
                    space++;
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                        if (vis[ny][nx] || board[ny][nx] != 1) continue;
                        vis[ny][nx] = true;
                        Q.add(new Pair(nx, ny));
                    }
                }
                ar.add(space);
            }
        }
        Collections.sort(ar);
        System.out.println(ans);
        for(int i = 0; i < ar.size(); i++) {
            System.out.println(ar.get(i));
        }
    }
}
