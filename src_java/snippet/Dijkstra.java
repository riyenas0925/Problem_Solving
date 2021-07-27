package snippet;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Dijkstra {
    static int[] dist;
    static int N;
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
        for (int i = 1; i <= N; i++) dist[i] = Integer.MAX_VALUE;

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

    static void input() {

    }

    static void pro() {

    }

    public static void main(String[] args) {
        input();
        pro();
    }
}
