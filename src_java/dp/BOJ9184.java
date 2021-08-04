package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ9184 {
    static int cache [][][];
    static int shift = 50;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static int w(int a, int b, int c) {
        if(a <= 0 || b <= 0 || c <= 0) {
            cache[0 + shift][0 + shift][0 + shift] = 1;
            return 1;
        } else if(a > 20 || b > 20 || c > 20) {
            if(cache[a + shift][b + shift][c + shift] == 0) {
                cache[a + shift][b + shift][c + shift] = w(20, 20, 20);
            }
            return cache[a + shift][b + shift][c + shift];
        } else if(a < b && b < c) {
            if(cache[a + shift][b + shift][c + shift] == 0) {
                cache[a + shift][b + shift][c + shift] = w(a, b, c - 1) + w(a, b - 1, c -1) - w(a, b - 1, c);
            }
            return cache[a + shift][b + shift][c + shift];
        } else {
            if(cache[a + shift][b + shift][c + shift] == 0) {
                cache[a + shift][b + shift][c + shift] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
            }
            return cache[a + shift][b + shift][c + shift];
        }
    }

    static void input() throws IOException {
        cache = new int[101][101][101];
        while(true) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            if(a == -1 && b == -1 && c == -1) {
                break;
            }

            System.out.println("w(" + a + ", " + b + ", " + c + ") = " + w(a, b, c));
        }
    }

    public static void main(String[] args) throws IOException {
        input();
    }
}
