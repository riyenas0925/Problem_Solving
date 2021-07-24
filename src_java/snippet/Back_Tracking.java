package snippet;

public class Back_Tracking {
    static int n;
    static int m;
    static int arr[] = new int[10];
    static boolean use[] = new boolean[10];

    public static void func(int k) {
        if(k == m) {
            for(int i = 0; i < m; i++) {
                System.out.print(arr[i] + " ");
            }
            System.out.println();
            return;
        }

        for(int i = 1; i <= n; i++) {
            if(!use[i]) {
                arr[k] = i;
                use[i] = true;
                func(k+1);
                use[i] = false;
            }
        }
    }

    public static void main(String[] args) {
        n = 4; m = 3;
        func(0);
    }
}
