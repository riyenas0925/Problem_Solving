package bfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ14502 {
    static int board[][] = new int[8][8];
    static boolean vis[][] = new boolean[8][8];
    static int dx[] = {0, 1, 0, -1};
    static int dy[] = {1, 0, -1, 0};
    static class Pair {
        int X;
        int Y;

        Pair(int X, int Y) {
            this.X = X;
            this.Y = Y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Pair pair = (Pair) o;
            return X == pair.X && Y == pair.Y;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int ans = 0;

        for(int i = 0; i < n; i++) {
            StringTokenizer input = new StringTokenizer(br.readLine());
            for(int j = 0; j < m; j++) {
                board[i][j] = Integer.parseInt(input.nextToken());
            }
        }

        for(int a = 0; a < n; a++) {
            for(int b = 0; b < n; b++) {
                for(int c = 0; c < n; c++) {
                    for(int d = 0; d < m; d++) {
                        for(int e = 0; e < m; e++) {
                            for(int f = 0; f < m; f++) {
                                Pair p1 = new Pair(d, a);
                                Pair p2 = new Pair(e, b);
                                Pair p3 = new Pair(f, c);
                                if (p1.equals(p2) || p2.equals(p3) || p3.equals(p1)) continue;
                                if (board[p1.Y][p1.X] != 0 || board[p2.Y][p2.X] != 0 || board[p3.Y][p3.X] != 0) continue;
                                //System.out.println("(" + p1.X + "," + p1.Y + "), " + "(" + p2.X + "," + p2.Y + "), " + "(" + p3.X + "," + p3.Y + ")");
                                vis = new boolean[8][8];
                                board[p1.Y][p1.X] = 1; board[p2.Y][p2.X] = 1; board[p3.Y][p3.X] = 1;

                                for(int i = 0; i < n; i++) {
                                    for(int j = 0; j < m; j++) {
                                        if(board[i][j] == 0 || board[i][j] == 1 || vis[i][j]) continue;
                                        Queue<Pair> Q = new LinkedList<>();
                                        Q.add(new Pair(j, i));
                                        vis[i][j] = true;

                                        while(!Q.isEmpty()) {
                                            Pair cur = Q.peek(); Q.remove();
                                            for(int dir = 0; dir < 4; dir++) {
                                                int nx = cur.X + dx[dir];
                                                int ny = cur.Y + dy[dir];
                                                if(nx >= m || ny >= n || nx < 0 || ny < 0) continue;
                                                if(vis[ny][nx] || board[ny][nx] == 2 || board[ny][nx] == 1) continue;
                                                Q.add(new Pair(nx, ny));
                                                vis[ny][nx] = true;
                                            }
                                        }
                                    }
                                }

                                int cnt = 0;

                                for(int i = 0; i < n; i++) {
                                    for(int j = 0; j < m; j++) {
                                        if(vis[i][j] == false && board[i][j] == 0) {
                                            cnt++;
                                        }
                                    }
                                }

                                board[p1.Y][p1.X] = 0; board[p2.Y][p2.X] = 0; board[p3.Y][p3.X] = 0;

                                ans = Math.max(ans, cnt);
                                //System.out.println(cnt);
                            }
                        }
                    }
                }
            }
        }

        System.out.println(ans);
    }
}
