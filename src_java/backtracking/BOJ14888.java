package backtracking;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;

public class BOJ14888 {

    static int nums[] = new int[11];
    static char arr[] = new char[11];
    static char opers[] = new char[11];
    static boolean use[] = new boolean[11];
    static int ansMax = Integer.MIN_VALUE, ansMin = Integer.MAX_VALUE;

    static void func(int n, int k) {
        if(n == k) {
            for(int i = 0; i < n; i++) {
                System.out.print(arr[i] + " ");
            }
            System.out.println();

            int result = nums[0];
            for(int i = 1; i < n + 1; i++) {
                if(arr[i - 1] == '+') result += nums[i];
                else if(arr[i - 1] == '-') result -= nums[i];
                else if(arr[i - 1] == '*') result *= nums[i];
                else result /= nums[i];
            }

            ansMax = Math.max(ansMax, result);
            ansMin = Math.min(ansMin, result);
            return;
        }

        for(int i = 0; i < n; i++) {
            if(!use[i]) {
                arr[k] = opers[i];
                use[i] = true;
                func(n, k + 1);
                use[i] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer input = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(input.nextToken());
        }
        input = new StringTokenizer(br.readLine());
        ArrayList<Character> temp = new ArrayList<>();
        for(int i = 0; i < 4; i++) {
            int num = Integer.parseInt(input.nextToken());

            if(i == 0) {
                for(int j = 0; j < num; j++) {
                    temp.add('+');
                }
            } else if(i == 1) {
                for(int j = 0; j < num; j++) {
                    temp.add('-');
                }
            } else if(i == 2) {
                for(int j = 0; j < num; j++) {
                    temp.add('*');
                }
            } else {
                for(int j = 0; j < num; j++) {
                    temp.add('/');
                }
            }
        }

        opers = temp.stream()
                .map(ch -> ch.toString())
                .collect(Collectors.joining())
                .toCharArray();

        func(n - 1, 0);

        System.out.println(ansMax);
        System.out.println(ansMin);
    }
}
