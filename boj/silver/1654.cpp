#include<iostream>

using namespace std;

int main() {
    int k, n; cin >> k >> n;
    long long arr[10001] = { 0, };

    long long low = 0;
    long long high;

    for(int i = 0; i < k; i++) {
        cin >> arr[i];

        if(arr[i] > high) {
            high = arr[i];
        }
    }
    
    int ans = 0;

    while(low <= high) {
        long long mid = (low + high) / 2;
        int cnt = 0;

        for(int j = 0; j < k; j++) {
            cnt = cnt + (arr[j] / mid);
        }

        if(n > cnt) {
            high = mid - 1;
        } else if(n <= cnt) {
            if(mid > ans) {
                ans = mid;
            }
            low = mid + 1;
        }
    }

    cout << ans << endl;
}