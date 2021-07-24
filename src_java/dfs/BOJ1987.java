package dfs;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ1987 {
    static char board[][] = new char[21][21];
    static int dist[][] = new int[21][21];
    static boolean alp[] = new boolean[26];
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
        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
//        int ans = 0;

        for(int i = 0; i < r; i++) {
            String str = br.readLine();
            for(int j = 0; j < c; j++) {
                board[i][j] = str.charAt(j);
            }
        }
//
//        Stack<Pair> S = new Stack<>();
//        S.push(new Pair(0, 0));
//        alp[board[0][0] - 'A'] = true;
//        dist[0][0] = 1;
//
//        while(!S.empty()) {
//            Pair cur = S.peek(); S.pop();
//            System.out.print("(" + cur.X + ", " + cur.Y + ") -> ");
//            for(int dir = 0; dir < 4; dir++) {
//                int nx = cur.X + dx[dir];
//                int ny = cur.Y + dy[dir];
//                if(nx >= c || ny >= r || nx < 0 || ny < 0) continue;
//                if(dist[ny][nx] > 0) continue;
//                if(alp[board[ny][nx] - 'A']) continue;
//                S.push(new Pair(nx, ny));
//                dist[ny][nx] = dist[cur.Y][cur.X] + 1;
//                alp[board[ny][nx] - 'A'] = true;
//                ans = Math.max(ans, dist[ny][nx]);
//            }
//        }
//
//        System.out.println(ans);
    }
}
