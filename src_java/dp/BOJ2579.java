package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ2579 {
    static int[] dp;
    static int[] stair;
    static int n;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        stair = new int[301];
        dp = new int[301];
        for(int i = 1; i <= n; i++) {
            stair[i] = Integer.parseInt(br.readLine());
        }
    }

    // 연속 3번 X
    //   O X O(마지막)
    // O X O O(마지막)

    static void pro() {
        dp[1] = stair[1];
        dp[2] = stair[1] + stair[2];
        for(int i = 3; i <= n; i++) {
            dp[i] = Math.max(dp[i - 2] + stair[i], dp[i-3] + stair[i-1] + stair[i]);
        }
        System.out.println(dp[n]);
    }

    public static void main(String[] args) throws IOException {
        input();
        pro();
    }
}
