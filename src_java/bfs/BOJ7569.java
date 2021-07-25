package bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ7569 {
    static int board[][][] = new int[101][101][101];
    static int dist[][][] = new int[101][101][101];
    static int dx[] = {0, 0, 1, 0, 0, -1};
    static int dy[] = {0, 1, 0, 0, -1, 0};
    static int dz[] = {1, 0, 0, -1, 0, 0};

    static class Pair {
        int Z;
        int Y;
        int X;

        Pair(int Z, int Y, int X) {
            this.Y = Y;
            this.X = X;
            this.Z = Z;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());
        for(int k = 0; k < h; k++) {
            for(int i = 0; i < n; i++) {
                StringTokenizer input = new StringTokenizer(br.readLine());
                for(int j = 0; j < m; j++) {
                    board[k][i][j] = Integer.parseInt(input.nextToken());
                }
            }
        }

        Queue<Pair> Q = new LinkedList<>();

        for(int k = 0; k < h; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(board[k][i][j] == 1) {
                        Q.add(new Pair(k, i, j));
                    }
                    if(board[k][i][j] == 0) {
                        dist[k][i][j] = -1;
                    }
                }
            }
        }

        while(!Q.isEmpty()) {
            Pair cur = Q.peek(); Q.remove();
            for(int dir = 0; dir < 6; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                int nz = cur.Z + dz[dir];
                if(nx >= m || ny >= n || nz >= h || nx < 0 || ny < 0 || nz < 0) continue;
                if(dist[nz][ny][nx] > 0 || board[nz][ny][nx] != 0) continue;
                Q.add(new Pair(nz, ny, nx));
                dist[nz][ny][nx] = dist[cur.Z][cur.Y][cur.X] + 1;
            }
        }

        int ans = 0;
        for(int k = 0; k < h; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if(dist[k][i][j] == -1) {
                        System.out.println(-1);
                        System.exit(0);
                    }
                    ans = Math.max(ans, dist[k][i][j]);
                }
            }
        }

        System.out.println(ans);
    }
}
