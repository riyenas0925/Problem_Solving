package dijkstra;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ1753 {
    static int[] dist;
    static int V, E, K;
    static ArrayList<Edge>[] edges;

    static class Edge {
        int to;
        int weight;

        public Edge(int to, int weight) {
            this.to = to;
            this.weight = weight;
        }
    }

    static class Info {
        int idx;
        int dist;

        Info(int idx, int dist) {
            this.dist = dist;
            this.idx = idx;
        }
    }

    static void dijkstra(int start) {
        // 모든 지점을 무한대로 초기화
        for (int i = 1; i <= V; i++) dist[i] = Integer.MAX_VALUE;

        PriorityQueue<Info> pq = new PriorityQueue<Info>(Comparator.comparingInt(o -> o.dist));
        //PriorityQueue<Info> pq = new PriorityQueue<Info>((o1, o2) -> o1.dist - o2.dist);

        pq.add(new Info(start, 0));
        dist[start] = 0;

        while(!pq.isEmpty()) {
            Info info = pq.poll();

            if(dist[info.idx] < info.dist) continue;
            for(Edge e : edges[info.idx]) {
                if(dist[info.idx] + e.weight >= dist[e.to]) continue;

                dist[e.to] = dist[info.idx] + e.weight;
                pq.add(new Info(e.to, dist[e.to]));
            }
        }
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(br.readLine());
        dist = new int[V + 1];
        edges = new ArrayList[V + 1];
        for (int i = 1; i <= V; i++) edges[i] = new ArrayList<>();
        for(int i = 1; i <= E; i++) {
            StringTokenizer input = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(input.nextToken());
            int to = Integer.parseInt(input.nextToken());
            int weight = Integer.parseInt(input.nextToken());
            edges[from].add(new Edge(to, weight));
        }
    }

    static void pro() {
        dijkstra(K);
        for(int i = 1; i <= V; i++) {
            if(dist[i] == Integer.MAX_VALUE) {
                System.out.println("INF");
            } else {
                System.out.println(dist[i]);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        pro();
    }
}
