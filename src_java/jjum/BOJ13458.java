package jjum;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ13458 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int N, B, C;
    static int [] A;

    static void input() throws IOException {
        N = Integer.parseInt(br.readLine());
        A = new int[N + 1];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        B = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
    }

    static void pro() {
        long sum = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] <= B) {
                sum++;
            } else {
                sum++;
                A[i] -= B;
                sum += A[i] / C;
                if(A[i] % C != 0) sum++;
            }
        }
        System.out.println(sum);
    }

    public static void main(String[] args) throws IOException {
        input();
        pro();
    }
}
