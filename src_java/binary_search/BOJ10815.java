package binary_search;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ10815 {
    static int deck[] = new int[500001];

    static boolean binarySearch(int[] arr, int n) {
        int first = 0;
        int last = deck.length - 1;
        int mid = 0;

        while(first <= last) {
            mid = (first + last) / 2;

            if(n == arr[mid]) {
                return true;
            } else {
                if(n < arr[mid]) {
                    last = mid - 1;
                } else {
                    first = mid + 1;
                }
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer input = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) {
            deck[i] = Integer.parseInt(input.nextToken());
        }
        Arrays.sort(deck);
        int m = Integer.parseInt(br.readLine());
        input = new StringTokenizer(br.readLine());
        for(int i = 0; i < m; i++) {
            int num = Integer.parseInt(input.nextToken());
            if(binarySearch(deck, num)) {
                System.out.print(1 + " ");
            } else {
                System.out.print(0 + " ");
            }
        }
    }
}
