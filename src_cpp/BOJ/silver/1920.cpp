#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int arr[100000];

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> m;
    
    sort(arr, arr + n);

    for(int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        cout << binary_search(arr, arr + n, temp) << "\n";
    }
}