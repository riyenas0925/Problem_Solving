package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BOJ14002 {
    static int[] arr;
    static int[] dp;
    static ArrayList<Integer>[] adj;
    static int N, ans = 0, idx;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static void input() throws IOException {
        N = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        arr = new int[N + 1];
        dp = new int[N + 1];
        adj = new ArrayList[N + 1];
        for(int i = 0; i < N + 1; i++) {
            adj[i] = new ArrayList<>();
        }
        for(int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
    }

    static void pro() {
        for(int i = 0; i < N; i++) {
            dp[i] = 1;
            adj[i].add(arr[i]);
            for(int j = 0; j < i; j++) {
                if(arr[j] < arr[i]) {
                    if(dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        adj[i] = new ArrayList<>(adj[j]);
                        adj[i].add(arr[i]);
                    }
                }
            }

            if(ans < dp[i]) {
                ans = dp[i];
                idx = i;
            }
        }
        System.out.println(ans);
        for(int i = 0; i < ans; i++) {
            System.out.print(adj[idx].get(i) + " ");
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        pro();
    }
}
