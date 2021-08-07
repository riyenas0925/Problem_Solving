package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ1463 {
    static int[] dp;
    static int n;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        dp = new int[1000001];
    }

    static void pro() {
        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 1;
        for(int i = 4; i <= n; i++) {
            if(i % 6 == 0) {
                dp[i] = Math.min(dp[i / 3] + 1, dp[i / 2] + 1);
                dp[i] = Math.min(dp[i], dp[i - 1] + 1);
            } else if(i % 3 == 0) {
                dp[i] = Math.min(dp[i / 3] + 1, dp[i - 1] + 1);
            } else if(i % 2 == 0) {
                dp[i] = Math.min(dp[i / 2] + 1, dp[i - 1] + 1);
            } else {
                dp[i] = dp[i - 1] + 1;
            }
        }
        System.out.println(dp[n]);
    }

    public static void main(String[] args) throws IOException {
        input();
        pro();
    }
}
