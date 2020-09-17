#include<iostream>
#include<algorithm>

using namespace std;

int main(){
   	cin.tie(NULL);

    int n; cin >> n;
    int arr[1000001];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << "\n";
    }
}
