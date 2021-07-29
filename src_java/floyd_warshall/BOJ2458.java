package floyd_warshall;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ2458 {

    static final int INF = (int) 1e9;
    static int N, M;
    static int[][] graph = new int[501][501];
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        // 전부 INF로 초기화
        for(int i = 0; i < 501; i++) {
            Arrays.fill(graph[i], INF);
        }

        // 자기 자신
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(i == j) graph[i][j] = 0;
            }
        }

        for(int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            graph[from][to] = 1;
        }
    }

    static void pro() {
        for(int k = 1; k <= N; k++) {
            for(int from = 1; from <= N; from++) {
                for(int to = 1; to <= N; to++) {
                    graph[from][to] = Math.min(graph[from][to], graph[from][k] + graph[k][to]);
                }
            }
        }

        int cnt = 0;
        for(int i = 1; i <= N; i++) {
            boolean flag = true;
            for(int j = 1; j <= N; j++) {
                if(i == j) continue;
                if(graph[i][j] == INF && graph[j][i] == INF) {
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }

        System.out.println(cnt);
    }

    public static void main(String[] args) throws IOException {
        input();
        pro();
    }
}
