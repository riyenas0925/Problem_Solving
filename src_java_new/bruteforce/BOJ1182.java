package bruteforce;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ1182 {

    static int n, s, result;
    static int[] arr;
    static boolean[] sel;
    static BufferedReader br;
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        input();
        pro(1, 0);
        if(s == 0) result--;
        System.out.println(result);
    }

    private static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        s = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        arr = new int[n + 1];
        sel = new boolean[n + 1];
        for(int i = 1; i <= n; i++) arr[i] = Integer.parseInt(st.nextToken());
        result = 0;
    }

    private static void pro(int k, int sum) {
        if(k == n + 1) {
            if(sum == s) result++;
        } else {
            // Include
            pro(k + 1, sum + arr[k]);
            // Not Include
            pro(k + 1, sum);
        }
    }
}
