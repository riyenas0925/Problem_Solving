package backtracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ2661 {
    // 숫자 1, 2, 3으로만 이루어지는 수열
    // 임의의 길이의 인접한 두 개의 부분 수열이 동일한 것이 있으면 -> 나쁜 수열

    static char arr[];
    static int N;
    static StringBuilder sb = new StringBuilder();
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static void rec(int k) {
        for(int j = 1; j <= k / 2; j++) {
            String a = sb.substring(k - 2 * j , k - j);
            String b = sb.substring(k - j , k);

            if(a.equals(b)) {
                return;
            }
        }

        if(k == N) {
            System.out.println(sb);
            System.exit(0);
        } else {
            for(int i = 0; i < 3; i++) {
                sb.append(arr[i]);
                rec(k + 1);
                sb.deleteCharAt(k);
            }
        }
    }

    static void pro() {
        rec(0);
    }

    static void input() throws IOException {
        N = Integer.parseInt(br.readLine());
        arr = new char[]{'1', '2', '3'};
    }

    public static void main(String[] args) throws IOException {
        input();
        pro();
    }
}
