package topologicalsort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ1516 {
    static int N;
    static ArrayList<Integer>[] adj;
    static int indeg[];
    static int time[];
    static int build[];

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        adj = new ArrayList[N + 1];
        for(int i = 1; i <= N; i++) {
            adj[i] = new ArrayList<>();
        }
        indeg = new int[N + 1];
        time = new int[N + 1];
        build = new int[N + 1];
        for(int i = 1; i <= N; i++) {
            StringTokenizer in = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(in.nextToken());
            time[i] = t;
            while(true) {
                int from = Integer.parseInt(in.nextToken());
                if(from == -1) break;
                adj[from].add(i);
                indeg[i]++;
            }
        }
    }

    static void pro() {
        Queue<Integer> dq = new LinkedList<>();

        for(int i = 1; i <= N; i++) {
            if(indeg[i] == 0) {
                dq.add(i);
                build[i] = time[i];
            }
        }

        while(!dq.isEmpty()) {
            int cur = dq.poll();

            for(int i : adj[cur]) {
                indeg[i]--;
                build[i] = Math.max(build[cur] + time[i], build[i]);
                if(indeg[i] == 0) {
                    dq.add(i);
                }
            }
        }

        for(int i = 1; i <= N; i++) {
            System.out.println(build[i]);
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        pro();
    }
}
