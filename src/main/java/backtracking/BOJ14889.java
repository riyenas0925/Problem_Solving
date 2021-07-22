package backtracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ14889 {
    static int[][] arr = new int[20][20];
    static int[] nums = new int[20];
    static boolean[] use = new boolean[20];
    static int ans = Integer.MAX_VALUE;

    static void func(int n, int k, int idx) {
        if(n / 2 == k) {
            for(int i = 0; i < n / 2; i++) {
                System.out.print(nums[i] + " ");
            }
            System.out.println("");

            int sumStart = 0;
            int sumLink = 0;

            use = new boolean[20];

            for(int i = 0; i < n / 2; i++) {
                for(int j = 0; j < n / 2; j++) {
                    if(i == j) continue;
                    sumStart += arr[nums[i]][nums[j]];
                    use[nums[i]] = true;
                }
            }

            for(int i = 0; i < n; i++) {
                if(use[i]) continue;
                for(int j = 0; j < n; j++) {
                    if(i == j || use[j]) continue;
                    sumLink += arr[i][j];
                }
            }

            ans = Math.min(ans, Math.abs(sumLink - sumStart));
            System.out.println(ans);
        }

        for(int i = idx; i < n; i++) {
            nums[k] = i;
            func(n, k + 1, i + 1);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        for(int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        func(n, 0, 0);

        System.out.println(ans);
    }
}
