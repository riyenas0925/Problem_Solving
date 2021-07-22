package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ1904 {
    /*
    1(1) : 1
    2(2) : 00 11
    3(3) : 001 100 111
    4(5) : 0000 1100 0011 1111 1001
    00100 10000 11100
    00001 11001 00111 11111 10011

     */
    public static int cache[] = new int[1000001];
    public static int dp(int n) {
        if(n == 1) {
            return 1;
        } else if(n == 2) {
            return 2;
        } else if(cache[n] != 0) {
            return cache[n];
        } else {
            return cache[n] = (dp(n - 1) + dp(n-2)) % 15746;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(br.readLine());
        System.out.println(dp(num));
    }
}
