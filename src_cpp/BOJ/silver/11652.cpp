#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long arr[100001];
    int n; cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    long long cnt = 0;
    long long max = 0, ans = arr[0];

    for(int i = 0; i < n; i++) {
        if(arr[i] == arr[i + 1]) {
            cnt++;
        } else {
            cnt = 0;
        }

        if(max < cnt) {
            max = cnt;
            ans = arr[i];
        }
    }

    cout << ans << endl;
}