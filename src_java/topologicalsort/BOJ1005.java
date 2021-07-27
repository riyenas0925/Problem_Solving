package topologicalsort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ1005 {

    static int T, N, K, W;
    static int[] indeg;
    static int[] cost;
    static int[] time;
    static ArrayList<Integer>[] adj;
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        cost = new int[N + 1];
        indeg = new int[N + 1];
        time = new int[N + 1];
        adj = new ArrayList[N + 1];
        for(int i = 1; i <= N; i++) {
            adj[i] = new ArrayList();
        }

        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= N; i++) {
            cost[i] = Integer.parseInt(st.nextToken());
        }

        for(int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            adj[from].add(to);
            indeg[to]++;
        }

        W = Integer.parseInt(br.readLine());
    }

    static void pro() {
        Deque<Integer> dq = new LinkedList<>();

        for(int i = 1; i <= N; i++) {
            if(indeg[i] == 0) {
                dq.add(i);
                time[i] = cost[i];
            }
        }

        while(!dq.isEmpty()) {
            int cur = dq.poll();
            for(int i : adj[cur]) {
                indeg[i]--;
                time[i] = Math.max(time[cur] + cost[i], time[i]);
                if(indeg[i] == 0) dq.add(i);
            }
        }

        System.out.println(time[W]);
    }

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for(int i = 0; i < T; i++) {
            input();
            pro();
        }
    }
}
