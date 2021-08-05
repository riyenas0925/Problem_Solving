package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ9461 {
    static long[] dp;
    static int t, n;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static void input() throws IOException {
        t = Integer.parseInt(br.readLine());
        dp = new long[102];
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 1;
        dp[4] = 2;
        dp[5] = 2;

        for(int i = 0; i < t; i++) {
            n = Integer.parseInt(br.readLine());

            for(int j = 6; j <= n; j++) {
                dp[j] = dp[j - 1] + dp[j - 5];
            }

            System.out.println(dp[n]);
        }
    }

    public static void main(String[] args) throws IOException {
        input();
    }
}
