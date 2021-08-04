package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ1003 {
    static int[][] cache;
    static int t;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static int fibonacci(int n) {
        if(n == 0) {
            cache[0][0] = 0; cache[0][1] = 1;
            return 0;
        } else if(n == 1) {
            cache[1][0] = 1; cache[1][2] = 1;
            return 1;
        } else {
            if (cache[n][0] == 0) {
                cache[n][0] = fibonacci(n - 1) + fibonacci(n - 2);
                cache[n][1] = cache[n - 1][1] + cache[n - 2][1];
                cache[n][2] = cache[n - 1][2] + cache[n - 2][2];
            }
            return cache[n][0];
        }
    }

    static void input() throws IOException {
        t = Integer.parseInt(br.readLine());
        for(int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());
            cache = new int[n + 1][3];
            fibonacci(n);
            System.out.println(cache[n][1] + " " + cache[n][2]);
        }
    }

    public static void main(String[] args) throws IOException {
        input();
    }
}
