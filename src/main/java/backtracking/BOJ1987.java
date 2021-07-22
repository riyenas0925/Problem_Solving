package backtracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ1987 {
    static char board[][] = new char[20][20];
    static int dx[] = {1, 0, -1, 0};
    static int dy[] = {0, 1, 0, -1};
    static boolean alp[] = new boolean[26];
    static int r, c, ans;

    static void go(int y, int x, int cnt) {
        ans = Math.max(cnt, ans);

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= r || nx >= c || ny < 0 || nx < 0) continue;
            if(alp[board[ny][nx] - 'A']) continue;
            alp[board[ny][nx] - 'A'] = true;
            go(ny, nx, cnt+1);
            alp[board[ny][nx] - 'A'] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        r = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());

        for(int i = 0; i < r; i++) {
            String str = br.readLine();
            for(int j = 0; j < c; j++) {
                board[i][j] = str.charAt(j);
            }
        }

        alp[board[0][0] - 'A'] = true;
        go(0, 0, 1);
        System.out.println(ans);
    }
}
