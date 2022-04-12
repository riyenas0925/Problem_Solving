package graphsearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ3184 {
    static int n, m;
    static String[] arr;
    static boolean[][] visit;
    static int[][] cur = {{1,0},{-1,0},{0,1},{0,-1}};
    static int wolf, sheep;
    static int totalWolf, totalSheep;

    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        input();
        pro();
        System.out.println(sb.toString());
    }

    private static void dfs(int x, int y) {
        visit[x][y] = true;

        if(arr[x].charAt(y) == 'v') wolf++;
        if(arr[x].charAt(y) == 'o') sheep++;

        for(int k = 0; k < 4; k++) {
            int nx = x + cur[k][0];
            int ny = y + cur[k][1];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(arr[nx].charAt(ny) == '#') continue;
            if(visit[nx][ny]) continue;

            dfs(nx, ny);
        }

    }

    private static void pro() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visit[i][j] && arr[i].charAt(j) != '#') {
                    wolf = 0; sheep = 0;
                    dfs(i, j);
                    if(wolf < sheep) totalSheep += sheep;
                    else totalWolf += wolf;
                }
            }
        }

        sb.append(totalSheep).append(' ').append(totalWolf);
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        visit = new boolean[n][m];
        arr = new String[n];
        for(int i = 0; i < n; i++) {
            arr[i] = br.readLine();
        }
    }

}
