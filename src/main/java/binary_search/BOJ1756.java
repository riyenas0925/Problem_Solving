package binary_search;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ1756 {
    static int oven[] = new int[300001];

    static int binarySearch(int[] arr, int num, int depth) {
        int first = 0;
        int last = depth;
        int mid = 0;

        while(first < last) {
            mid = (last + first) / 2;

            if(arr[mid] >= num) {
                first = mid + 1;
            } else {
                last = mid;
            }
        }
        return last - 1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer dn = new StringTokenizer(br.readLine());
        StringTokenizer ds = new StringTokenizer(br.readLine());
        StringTokenizer ns = new StringTokenizer(br.readLine());

        int d = Integer.parseInt(dn.nextToken());
        int n = Integer.parseInt(dn.nextToken());

        for(int i = 0; i < d; i++) {
            int size = Integer.parseInt(ds.nextToken());

            if(i == 0) {
                oven[0] = size;
            } else if(oven[i-1] < size) {
                oven[i] = oven[i-1];
            } else {
                oven[i] = size;
            }
        }

        int depth = d;

        for(int i = 0; i < n; i++) {
            int num = Integer.parseInt(ns.nextToken());
            depth = binarySearch(oven, num, depth);
            if(depth == -1) break;
            System.out.println(depth);
        }

        if(depth == -1) {
            System.out.println(0);
        } else {
            System.out.println(depth + 1);
        }
    }
}
