package snippet;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Sort {
    static int N;
    static Elem[] students;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static class Elem implements Comparable<Elem> {
        public String name;
        public int kor, eng, math;

        @Override
        public int compareTo(Elem other) {
            // 내림차순
            if(kor != other.kor) return other.kor - kor;
            // 오름차순
            if(eng != other.eng) return eng - other.eng;
            // 내림차순
            if(math != other.math) return other.math - math;
            // 사전순
            return name.compareTo(other.name);
        }
    }

    static void input() throws IOException {
        N = Integer.parseInt(br.readLine());
        students = new Elem[N];
        for(int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            students[i] = new Elem();
            students[i].name = st.nextToken();
            students[i].kor = Integer.parseInt(st.nextToken());
            students[i].eng = Integer.parseInt(st.nextToken());
            students[i].math = Integer.parseInt(st.nextToken());
        }
    }

    static void pro() {
        Arrays.sort(students);
        for(int i = 0; i < N; i++) {
            System.out.println(students[i].name);
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        pro();
    }
}
