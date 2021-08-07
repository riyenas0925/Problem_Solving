package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ10844 {
    static int[][] dp;
    static int n;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        dp = new int[10][n + 1];
    }

    static void pro() {
        dp[1][1] = 1; dp[2][1] = 1; dp[3][1] = 1;
        dp[4][1] = 1; dp[5][1] = 1; dp[6][1] = 1;
        dp[7][1] = 1; dp[8][1] = 1; dp[9][1] = 1;

        for(int i = 2; i <= n; i++) {
            for(int j = 0; j <= 9; j++) {
                if(j == 0) {
                    dp[0][i] = dp[1][i-1];
                } else if(j == 9) {
                    dp[9][i] = dp[8][i-1];
                } else {
                    dp[j][i] = (dp[j-1][i-1] + dp[j+1][i-1]) % 1000000000;
                }
            }
        }
        long ans = 0;
        for(int i = 0; i <= 9; i++) {
            ans += dp[i][n];
        }
        System.out.println(ans % 1000000000);
    }

    public static void main(String[] args) throws IOException {
        input();
        pro();
    }
}
