package bruteforce;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ1759 {

    static int l, c;
    static char arr[];
    static char sel[];
    static boolean vis[];
    static BufferedReader br;
    static StringTokenizer st;
    static StringBuilder sb;

    public static void main(String[] args) throws IOException {
        input();
        Arrays.sort(arr);
        pro(1, 0, 0);
        System.out.println(sb.toString());
    }

    private static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        l = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());

        arr = new char[c + 1];
        sel = new char[c + 1];
        vis = new boolean[c + 1];
        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= c; i++) {
            arr[i] = st.nextToken().charAt(0);
        }
        sb = new StringBuilder();
    }

    private static void pro(int k, int mo, int ja) {
        if(k == l + 1) {
            if(mo >= 1 && ja >= 2) {
                for(int i = 1; i <= l; i++) sb.append(sel[i]);
                sb.append('\n');
            }
        } else {
            for(int cand = 1; cand <= c; cand++) {
                if(vis[cand]) continue;
                if(sel[k - 1] > arr[cand]) continue;

                sel[k] = arr[cand];
                vis[cand] = true;

                if(isMo(sel[k])) {
                    pro(k + 1, mo + 1, ja);
                } else {
                    pro(k + 1, mo, ja + 1);
                }

                sel[k] = 0;
                vis[cand] = false;
            }
        }
    }

    private static boolean isMo(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}
