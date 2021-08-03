package jjum;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ14501 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int N;
    static int [][] TP;
    static int [] DP;

    static void pro() {
        for(int i = N; i > 0; i--) {
            int next = i + TP[i][0];
            if(next > N + 1) {
                DP[i] = DP[i + 1];
            } else {
                DP[i] = Math.max(DP[i + 1], DP[next] + TP[i][1]);
            }
        }
        System.out.println(DP[1]);
    }

    static void input() throws IOException {
        N = Integer.parseInt(br.readLine());
        TP = new int[N + 2][2];
        DP = new int[N + 2];
        for(int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            TP[i][0] = Integer.parseInt(st.nextToken());
            TP[i][1] = Integer.parseInt(st.nextToken());
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        pro();
    }
}
