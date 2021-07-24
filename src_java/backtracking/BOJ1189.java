package backtracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ1189 {

    static int board[][] = new int[5][5];
    static int vis[][] = new int[5][5];
    static int dx[] = {0, 1, 0, -1};
    static int dy[] = {1, 0, -1, 0};
    static int r, c, k;

    static class Pair {
        int X;
        int Y;

        Pair(int X, int Y) {
            this.X = X;
            this.Y = Y;
        }
    }

    static int go(int y, int x) {
        if(y == 0 && x == c - 1) {
            if(k == vis[y][x]) return 1;
            return 0;
        }
        int ans = 0;
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(nx >= c || ny >= r || nx < 0 || ny < 0) continue;
            if(board[ny][nx] == 1 || vis[ny][nx] > 0) continue;
            vis[ny][nx] = vis[y][x] + 1;
            ans += go(ny, nx);
            vis[ny][nx] = 0;
        }
        return ans;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        for(int i = 0; i < r; i++) {
            String str = br.readLine();
            for(int j = 0; j < c; j++) {
                if(str.charAt(j) == 'T') board[i][j] = 1;
                else board[i][j] = 0;
            }
        }

        vis[r - 1][0] = 1;
        System.out.println(go(r - 1, 0));
    }
}
