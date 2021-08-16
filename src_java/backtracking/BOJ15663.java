package backtracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ15663 {
    static int N, M;
    static int[] arr;
    static boolean[] vis;
    static int[] pick;
    static ArrayList<String> ar = new ArrayList<>();
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static void rec(int k) {
        if(k == M) {
            StringBuilder sb = new StringBuilder();
            for(int i = 0; i < M; i++) {
                sb.append(pick[i]).append(" ");
            }
            if(!ar.contains(sb.toString())) {
                ar.add(sb.toString());
            }
        } else {
            for(int i = 0; i < N; i++) {
                if(vis[i] == true) continue;
                pick[k] = arr[i];
                vis[i] = true;
                rec(k + 1);
                pick[k] = 0;
                vis[i] = false;
            }
        }
    }

    static void pro() {
        Arrays.sort(arr);
        rec(0);
        for(String str : ar) {
            System.out.println(str);
        }
    }

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new int[N];
        vis = new boolean[N];
        pick = new int[M];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        pro();
    }
}
