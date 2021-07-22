import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ9095 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        /*
        dp[1] = 1 1개
        dp[2] = 2, 1 1 2개
        dp[3] = 2 1, 1 1 1, 1 2, 3 4개
        dp[4] = 1 1 1 1, 1 2 1, 2 1 1, 1 1 2, 3 1, 1 3, 2 2 7개
        dp[5] = dp[2] + dp[3] + dp[4];
         */
        int[] dp = new int[11];
        dp[1] = 1; dp[2] = 2; dp[3] = 4;
        for(int i = 4; i < 11; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        int n = Integer.parseInt(br.readLine());
        for(int i = 0; i < n; i++) {
            int num = Integer.parseInt(br.readLine());
            System.out.println(dp[num]);
        }
    }
}
