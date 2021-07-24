package bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ2178 {
    static int board[][] = new int[101][101];
    static int dist[][] = new int[101][101];
    static int dx[] = {0, 1, 0, -1};
    static int dy[] = {1, 0, -1, 0};

    static class Pair {
        int X;
        int Y;

        Pair(int X, int Y) {
            this.X = X;
            this.Y = Y;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()); 
        int m = Integer.parseInt(st.nextToken());

        for(int i = 0; i < n; i++) {
            String str = br.readLine();
            for(int j = 0; j < m; j++) {
                board[i][j] = str.charAt(j) - '0';
            }
        }

        Queue<Pair> Q = new LinkedList<>();
        Q.add(new Pair(0,0));
        dist[0][0] = 1;

        while(!Q.isEmpty()) {
            Pair cur = Q.peek(); Q.remove();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx >= m || ny >= n || nx < 0 || ny < 0) continue;
                if(board[ny][nx] == 0 || dist[ny][nx] > 0) continue;
                Q.add(new Pair(nx, ny));
                dist[ny][nx] = dist[cur.Y][cur.X] + 1;
            }
        }

        System.out.println(dist[n-1][m-1]);
    }
}
