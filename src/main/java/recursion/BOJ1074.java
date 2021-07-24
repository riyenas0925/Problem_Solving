package recursion;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ1074 {
    static int func(int n, int r, int c) {
        int mid = (int) Math.pow(2, n - 1);
        // base condition
        if(n == 0) return 0;
        // recursion
        if(mid <= c && mid > r) return mid * mid + func(n, r, c - mid);
        else if(mid > c && mid > r) return func(n-1, r, c);
        else if(mid > c && mid <= r) return (2 * mid * mid) + func(n, r - mid, c);
        else if(mid <= c && mid <= r) return (3 * mid * mid) + func(n, r - mid, c - mid);
        return 0;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        System.out.println(func(n, r, c));
    }
}
