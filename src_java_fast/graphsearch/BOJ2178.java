package graphsearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ2178 {

    static int n, m;
    static String[] maze;
    static int[][] dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    static int[][] dist;

    static StringBuilder sb = new StringBuilder();
    static BufferedReader br;

    public static void main(String[] args) throws IOException {
        input();
        pro();
        System.out.println(sb.toString());
    }

    private static void bfs(int x, int y) {
        Queue<Integer> q = new LinkedList<>();
        q.add(x);
        q.add(y);
        dist[x][y] = 1;

        while(!q.isEmpty()) {
            x = q.poll();
            y = q.poll();

            for(int k = 0; k < 4; k++) {
                int nx = x + dir[k][0];
                int ny = y + dir[k][1];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(dist[nx][ny] > 0) continue;
                if(maze[nx].charAt(ny) == '0') continue;

                dist[nx][ny] = dist[x][y] + 1;
                q.add(nx);
                q.add(ny);
            }
        }
    }

    private static void pro() {
        bfs(0, 0);
        sb.append(dist[n - 1][m - 1]);
    }

    private static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        dist = new int[n][m];
        maze = new String[n];
        for(int i = 0; i < n; i++) {
            maze[i] = br.readLine();
        }
    }
}
