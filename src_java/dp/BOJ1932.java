package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ1932 {
    static int[][] dp;
    static int[][] tri;
    static int n;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        dp = new int[n + 1][n + 1];
        tri = new int[n + 1][n + 1];
        for(int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 1; j <= i; j++) {
                tri[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }

    static void pro() {
        dp[1][1] = tri[1][1];
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                dp[i][j] = Math.max(dp[i - 1][j - 1] + tri[i][j], dp[i - 1][j] + tri[i][j]);
            }
        }
        int ans = 0;

        for(int i = 1; i <= n; i++) {
            ans = Math.max(ans, dp[n][i]);
        }
        System.out.println(ans);
    }

    public static void main(String[] args) throws IOException {
        input();
        pro();
    }
}
