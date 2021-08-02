package prefixsum;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ11660 {
    static int N, M;
    static int[][] sum;
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static void pro() throws IOException {
        for(int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int y1 = Integer.parseInt(st.nextToken());
            int x1 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());

            System.out.println(sum[y2][x2] + sum[y1-1][x1-1] - sum[y2][x1 - 1] - sum[y1 - 1][x2]);
        }
    }

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        sum = new int[N + 1][N + 1];

        for(int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j = 1; j <= N; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + Integer.parseInt(st.nextToken());
            }
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        pro();
    }
}
