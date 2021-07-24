package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ1003 {
    private static int[][] cache = new int[42][3];

    private static int fibonacci(int n) {
        if(n == 0) {
            cache[0][0] = 0; cache[0][1] = 1; cache[0][2] = 0;
            return 0;
        } else if(n == 1) {
            cache[1][0] = 1; cache[1][1] = 0; cache[1][2] = 1;
            return cache[1][0] = 1;
        } else if(cache[n][0] != 0) {
            return cache[n][0];
        } else {
            cache[n][0] = fibonacci(n-1) + fibonacci(n-2);
            cache[n][1] = cache[n-1][1] + cache[n-2][1];
            cache[n][2] = cache[n-1][2] + cache[n-2][2];
            return cache[n][0];
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        for(int i = 0; i < n; i++) {
            int num = Integer.parseInt(br.readLine());
            fibonacci(num);
            System.out.println(cache[num][1] + " " + cache[num][2]);
        }
    }
}
