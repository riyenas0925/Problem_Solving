#include<iostream>

using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t, a, b; cin >> t;

    for(int i = 0; i < t; i++){
        cin >> a >> b;
        cout << a + b << "\n";
    }

    return 0;
}