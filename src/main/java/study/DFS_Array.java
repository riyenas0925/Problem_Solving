package study;

import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;

public class DFS_Array {
    static class Pair {
        Integer X;
        Integer Y;

        public Pair(Integer X, Integer Y) {
            this.X = X;
            this.Y = Y;
        }
    }

    static int board[][] = new int[][]{
            {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
            {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
            {1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    static boolean vis[][] = new boolean[502][502];
    static int dx[] = {1, 0, -1, 0};
    static int dy[] = {0, 1, 0, -1};
    static int n = 7;
    static int m = 10;

    public static void main(String[] args) throws IOException {
        Queue<Pair> Q = new LinkedList<>();
        vis[0][0] = true;
        Q.add(new Pair(0, 0));

        while (!Q.isEmpty()) {
            Pair cur = Q.peek();
            Q.remove();
            System.out.println("(" + cur.X + ", " + cur.Y + ") -> ");
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(vis[nx][ny] || board[nx][ny] != 1) continue;
                vis[nx][ny] = true;
                Q.add(new Pair(nx, ny));
            }
        }
    }
}
