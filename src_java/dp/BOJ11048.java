package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ11048 {
    public static int board[][] = new int[1001][1001];
    public static int cache[][] = new int[1001][1001];
    public static int m, n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        for(int i = 1; i <= n; i++) {
            StringTokenizer input = new StringTokenizer(br.readLine());
            for(int j = 1; j <= m; j++) {
                board[i][j] = Integer.parseInt(input.nextToken());
                cache[i][j] = Math.max(cache[i-1][j], Math.max(cache[i][j-1], cache[i-1][j-1])) + board[i][j];
            }
        }

        System.out.println(cache[n][m]);
    }
}
