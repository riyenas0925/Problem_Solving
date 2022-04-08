package graphsearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

public class BOJ2667 {
    static int n;
    static String[] arr;
    static ArrayList<Integer> group;
    static int groupCnt;
    static boolean[][] visit;
    static int[][] dir = {{1,0}, {0, 1}, {-1, 0}, {0, -1}};

    static StringBuilder sb = new StringBuilder();
    static BufferedReader br;

    public static void main(String[] args) throws IOException {
        input();
        pro();
        System.out.println(sb.toString());
    }

    private static void dfs(int x, int y) {
        groupCnt++;
        visit[x][y] = true;

        for (int k = 0; k < 4; k++) {
            int nx = x + dir[k][0];
            int ny = y + dir[k][1];
            if(nx < 0 || ny < 0 || ny >= n || nx >= n) continue;
            if(arr[nx].charAt(ny) == '0') continue;
            if(visit[nx][ny]) continue;
            dfs(nx, ny);
        }
    }

    private static void pro() {
        group = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(arr[i].charAt(j) == '1' && !visit[i][j]) {
                    groupCnt = 0;
                    dfs(i, j);
                    group.add(groupCnt);
                }
            }
        }

        Collections.sort(group);
        sb.append(group.size()).append('\n');
        for(int cnt : group) sb.append(cnt).append('\n');
    }

    private static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new String[n];

        for(int i = 0; i < n; i++) {
            arr[i] = br.readLine();
        }
        visit = new boolean[n][n];
    }

}
