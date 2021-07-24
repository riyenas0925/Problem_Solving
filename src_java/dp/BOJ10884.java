package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ10884 {
    public static int cache[][] = new int[101][10];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        long sum = 0;

        cache[0][0] = 0; cache[0][1] = 1; cache[0][2] = 1; cache[0][3] = 1; cache[0][4] = 1;
        cache[0][5] = 1; cache[0][6] = 1; cache[0][7] = 1; cache[0][8] = 1; cache[0][9] = 1;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < 10; j++) {
                if(j == 0) cache[i][0] = cache[i-1][1];
                else if(j == 9) {
                    cache[i][9] = cache[i-1][8];
                } else  cache[i][j] = (cache[i-1][j-1] + cache[i-1][j+1]) % 1000000000;
            }
        }

        for(int i = 0; i < 10; i++) {
            sum += cache[n-1][i];
        }

        System.out.println(sum % 1000000000);
    }
}
