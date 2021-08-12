package snippet;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Back_Tracking {
    static int N;
    static int M;
    static boolean used[] = new boolean[10];
    static int selected[] = new int[10];
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    // 조합
    static void rec_func1(int k) {
        if(k == M + 1) {
            for(int i = 1; i <= M; i++) sb.append(selected[i]).append(" ");
            sb.append("\n");
        } else {
            int start = selected[k - 1];
            if(start == 0) start = 1;
            for(int cand = start; cand <= N; cand++) {
                if(used[cand] == true) continue;
                selected[k] = cand;
                used[cand] = true;
                rec_func1(k + 1);
                selected[k] = 0;
                used[cand] = false;
            }
        }
    }

    // 중복 조합
    static void rec_func2(int k) {
        if(k == M + 1) {
            for(int i = 1; i <= M; i++) sb.append(selected[i]).append(" ");
            sb.append("\n");
        } else {
            int start = selected[k - 1];
            if(start == 0) start = 1;
            for(int cand = start; cand <= N; cand++) {
                selected[k] = cand;
                rec_func2(k + 1);
                selected[k] = 0;
            }
        }
    }

    // 순열
    static void rec_func3(int k) {
        if(k == M + 1) {
            for(int i = 1; i <= M; i++) sb.append(selected[i]).append(" ");
            sb.append("\n");
        } else {
            for(int cand = 1; cand <= N; cand++) {
                if(used[cand] == true) continue;
                selected[k] = cand;
                used[cand] = true;
                rec_func3(k + 1);
                selected[k] = 0;
                used[cand] = false;
            }
        }
    }

    // 중복 순열
    static void rec_func4(int k) {
        if(k == M + 1) {
            for (int i = 1; i <= M; i++) sb.append(selected[i]).append(" ");
            sb.append("\n");
        } else {
            for(int cand = 1; cand <= N; cand++) {
                selected[k] = cand;
                rec_func4(k + 1);
                selected[k] = 0;
            }
        }
    }

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
    }

    public static void main(String[] args) throws IOException {
        input();
        rec_func1(1);
        System.out.println(sb);
    }
}
