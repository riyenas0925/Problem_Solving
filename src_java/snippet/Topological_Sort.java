package snippet;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Topological_Sort {
    /*
    1. 정점들의 Indegree, Indeg[1...N] 계산하기 → O(V)
    2. 들어오는 간선이 0개인 (Indeg[i] == 0) 정점들을 찾아서 자료구조 D에 넣기 → O(E)
    3. D가 빌 때까지
        - D에서 원소 x를 꺼내서 "정렬" 시키기
        - Graph 에서 정점 x "제거"하기
        - "새롭게 정렬 가능한 점"을 찾아서 D에 넣기
     */
    static int indeg[];
    static int N,M;
    static ArrayList<Integer>[] adj;

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        indeg = new int[N + 1];
        adj = new ArrayList[N + 1];
        for(int i = 1; i <=N; i++) {
            adj[i] = new ArrayList<>();
        }
        for(int i = 0; i < M; i++) {
            StringTokenizer input = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(input.nextToken());
            int b = Integer.parseInt(input.nextToken());
            adj[a].add(b);
            indeg[b]++;
        }
    }

    static void pro() {
        Deque<Integer> dq = new LinkedList<>();
        StringBuilder sb = new StringBuilder();

        // 들어오는 간선이 0개인 정점들을 찾아서 dq에 넣기
        for(int i = 1; i <= N; i++) {
            if(indeg[i] == 0) dq.add(i);
        }

        while(!dq.isEmpty()) {
            int x = dq.poll();
            sb.append(x).append(' ');
            for(int y : adj[x]) {
                indeg[y]--;
                if(indeg[y] == 0) dq.add(y);
            }
        }

        System.out.println(sb);
    }

    public static void main(String[] args) throws IOException {
        input();
        pro();
    }
}
