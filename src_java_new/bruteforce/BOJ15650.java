package bruteforce;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
    중복 허용 안함, 순서 없음
 */

public class BOJ15650 {

    static int N, M;
    static int[] selected, used;
    static StringBuilder sb = new StringBuilder();


    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        selected = new int[N + 1];
        used = new int[N + 1];
    }

    private static void recursion(int k) {
        if(k == M + 1) {
            for(int i = 1; i <= M; i++) sb.append(selected[i]).append(' ');
            sb.append('\n');
        } else {
            int start = selected[k - 1];
            if(start == 0) start = 1;

            for(int cand = start; cand <= N; cand++) {
                if(used[cand] == 1) continue;

                selected[k] = cand; used[cand] = 1;
                recursion(k + 1);
                selected[k] = 0; used[cand] = 0;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        recursion(1);
        System.out.println(sb.toString());
    }

}