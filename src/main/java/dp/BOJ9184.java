package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ9184 {
    public static int[][][] cache= new int[102][102][102];

    public static int w(int a, int b, int c) {
        if(cache[a+50][b+50][c+50] != 0) {
            return cache[a+50][b+50][c+50];
        }
        else if(a <= 0 || b <= 0 || c <= 0) {
            return 1;
        } else if(a > 20 || b > 20 || c > 20) {
            if(cache[a + 50][b + 50][c + 50] == 0) {
                cache[a + 50][b + 50][c + 50] = w(20, 20, 20);
            }
            return cache[a+50][b+50][c+50];
        } else if((a < b) && (b < c)) {
            if(cache[a + 50][b + 50][c + 50] == 0) {
                cache[a + 50][b + 50][c + 50] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);;
            }
            return cache[a + 50][b + 50][c + 50];
        } else {
            if(cache[a + 50][b + 50][c + 50] == 0) {
                cache[a + 50][b + 50][c + 50] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
            }
            return cache[a + 50][b + 50][c + 50];
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while(true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            if(a == -1 && b == -1 && c == -1) break;
            System.out.println("w(" + a + ", " + b + ", " + c + ") = " + w(a, b, c));
        }
    }
}
