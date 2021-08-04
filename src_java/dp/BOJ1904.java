package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ1904 {
    /*
    N = 1 -> 1
    N = 2 -> 00, 11
    N = 3 -> 001 100, 111
    N = 4 -> 1100 1111 1001 1100 1111
    N = 5 -> 00001 00100 00111 11100 11111 11001 11100 11111
     */

    static int[] cache;
    static int n;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static void pro() {
        cache[1] = 1;
        cache[2] = 2;
        for(int i = 3; i <= n; i++) {
            cache[i] = (cache[i-1] + cache[i-2]) % 15746;
        }
        System.out.println(cache[n]);
    }

    static void input() throws IOException {
        n = Integer.parseInt(br.readLine());
        cache = new int[1000000 + 1];
    }

    public static void main(String[] args) throws IOException {
        input();
        pro();
    }
}