package backtracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ1759 {
    static int L, C;
    static char[] arr;
    static boolean[] vis;
    static char[] pick;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    static void pro() {
        Arrays.sort(arr);
        rec(0, 0, 0);
        System.out.println(sb);
    }

    static void rec(int k, int ja, int mo) {
        if(k == L) {
            if(ja >= 1 && mo >= 2) {
                for(int i = 0; i < L; i++) {
                    sb.append(pick[i]);
                }
                sb.append("\n");
            }
        } else {
            for(int i = 0; i < C; i++) {
                if(vis[i] == true) continue;
                if(k != 0 && pick[k - 1] > arr[i]) continue;
                pick[k] = arr[i];
                vis[i] = true;
                if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
                    rec(k + 1, ja + 1, mo);
                } else {
                    rec(k + 1, ja, mo + 1);
                }
                pick[k] = 0;
                vis[i] = false;
            }
        }
    }

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        L = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        pick = new char[L + 1];
        arr = new char[C];
        vis = new boolean[C];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < C; i++) {
            arr[i] = st.nextToken().charAt(0);
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        pro();
    }
}
