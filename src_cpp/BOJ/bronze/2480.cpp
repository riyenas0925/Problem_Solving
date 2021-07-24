#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    
    if(arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[0]) cout << 10000 + arr[0] * 1000;
    else if(arr[0] == arr[1]) cout << 1000 + arr[0] * 100;
    else if(arr[1] == arr[2]) cout << 1000 + arr[1] * 100;
    else if(arr[2] == arr[0]) cout << 1000 + arr[2] * 100;
    else cout << max({arr[0], arr[1], arr[2]}) * 100;
}