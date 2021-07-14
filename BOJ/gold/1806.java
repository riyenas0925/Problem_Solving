import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer input = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(input.nextToken());
        int s = Integer.parseInt(input.nextToken());
        int arr[] = new int[100001];
        StringTokenizer nums = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(nums.nextToken());
        }
        int low = 0, high = 0, sum = arr[0], ans = Integer.MAX_VALUE;

        while(high < n && high >= low) {
            if(sum < s) {
                high++;
                sum += arr[high];
            } else if (sum == s){
                ans = Math.min(high - low + 1, ans);
                high++;
                sum += arr[high];
            } else {
                ans = Math.min(high - low + 1, ans);
                sum -= arr[low];
                low++;
            }
        }

        if(ans == Integer.MAX_VALUE) {
            System.out.println(0);
        } else {
            System.out.println(ans);
        }
    }
}