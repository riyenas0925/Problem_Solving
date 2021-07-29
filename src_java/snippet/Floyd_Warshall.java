package snippet;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Floyd_Warshall {
    static final int INF = (int) 1e9;
    static int N, M;
    static int[][] graph = new int[101][101];
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static void input() throws IOException {
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        // 모든 거리를 INF로 초기화 한다.
        for(int i = 0; i < 101; i++) {
            Arrays.fill(graph[i], INF);
        }

        // 자기자신의 거리는 0이다.
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(i == j) graph[i][j] = 0;
            }
        }

        for(int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            graph[from][to] = Math.min(graph[from][to], cost);
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

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(graph[i][j] == INF) {
                    System.out.print(0 + " ");
                } else {
                    System.out.print(graph[i][j] + " ");
                }
            }
            System.out.println();
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        pro();
    }
}
