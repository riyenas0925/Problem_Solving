package graphsearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ1260 {

    static int n, m, v;
    static ArrayList<Integer>[] adj;
    static boolean[] visit;
    static BufferedReader br;
    static StringTokenizer st;
    static StringBuilder sb;

    static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        v = Integer.parseInt(st.nextToken());

        adj = new ArrayList[n + 1];
        for(int i = 1; i <=n; i++) {
            adj[i] = new ArrayList<>();
        }
        for(int i = 1; i <= m; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            adj[x].add(y);
            adj[y].add(x);
        }
        for(int i = 1; i <= n; i++) {
            Collections.sort(adj[i]);
        }

        sb = new StringBuilder();
    }

    private static void bfs(int x) {
        Queue<Integer> q = new LinkedList<>();
        q.add(x);
        visit[x] = true;

        while(!q.isEmpty()) {
            x = q.poll();
            sb.append(x).append(' ');

            for(int y : adj[x]) {
                if(visit[y] == true) continue;
                q.add(y);
                visit[y] = true;
            }
        }
    }

    private static void dfs(int x) {
        visit[x] = true;
        sb.append(x).append(' ');

        for(int y : adj[x]) {
            if(visit[y] == true) continue;
            dfs(y);
        }
    }

    static void pro() {
        visit = new boolean[n + 1];
        dfs(v);
        sb.append('\n');
        visit = new boolean[n + 1];
        bfs(v);
    }

    public static void main(String[] args) throws IOException {
        input();
        pro();
        System.out.println(sb.toString());
    }

}