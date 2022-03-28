package sort;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ10825 {

    static int n;
    static Elem[] arr;

    static StringBuilder sb = new StringBuilder();

    static class Elem implements Comparable<Elem> {

        public String name;
        public int kor, eng, math;

        @Override
        public int compareTo(Elem o) {
            if(kor != o.kor) return o.kor - kor;
            if(eng != o.eng) return eng - o.eng;
            if(math != o.math) return o.math - math;
            return name.compareTo(o.name);
        }
    }

    private static void pro() {
        Arrays.sort(arr);
        for(int i = 0; i < n; i++) sb.append(arr[i].name).append('\n');
        System.out.println(sb.toString());
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        arr = new Elem[n];
        for(int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            arr[i] = new Elem();
            arr[i].name = st.nextToken();
            arr[i].kor = Integer.parseInt(st.nextToken());
            arr[i].eng = Integer.parseInt(st.nextToken());
            arr[i].math = Integer.parseInt(st.nextToken());
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        pro();
    }
}
