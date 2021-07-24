package backtracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ10819 {
    static int nums[] = new int[8];
    static int arr[] = new int[8];
    static boolean use[] = new boolean[8];
    static int ans = 0;

    static void func(int n, int k) {
        if(k == n) {
            int sum = 0;

            for(int i = 0; i < n - 1; i++) {
                sum += Math.abs(arr[i] - arr[i+1]);
            }

            ans = Math.max(ans, sum);
            return;
        }

        for(int i = 0; i < n; i++) {
            if(!use[i]) {
                arr[k] = nums[i];
                use[i] = true;
                func(n,k + 1);
                use[i] = false;
            }
        }
    }

    // nPr * n = 8P8 * 8 = 40320 * 8 = 322560
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        for(int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
        }

        func(n, 0);

        System.out.println(ans);
    }
}
