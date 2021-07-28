package topologicalsort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class BOJ2056 {

    static ArrayList<Integer>[] adj;
    static int[] indeg;
    static int[] cost;
    static int[] time;
    static int N, ans = 0 ;
    static BufferedReader br;
    static StringTokenizer st;

    static void input() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        cost = new int[N + 1];
        indeg = new int[N + 1];
        time = new int[N + 1];
        adj = new ArrayList[N + 1];
        for(int i = 1; i <= N; i++) {
            adj[i] = new ArrayList<>();
        }
        for(int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            cost[i] = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());
            for(int j = 0; j < n; j++) {
                int from = Integer.parseInt(st.nextToken());
                adj[from].add(i);
                indeg[i]++;
            }
        }
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

            for(int nxt : adj[cur]) {
                indeg[nxt]--;
                time[nxt] = Math.max(time[cur] + cost[nxt], time[nxt]);
                if(indeg[nxt] == 0) dq.add(nxt);
            }
        }

        for(int i = 1; i <= N; i++) {
            ans = Math.max(ans, time[i]);
        }

        System.out.println(ans);
    }

    public static void main(String[] args) throws IOException {
        input();
        pro();
    }
}
