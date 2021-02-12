#include<iostream>

using namespace std;

int main(){
    int a, b, v; cin >> a >> b >> v;

    cout << (v - b - 1) / (a - b) + 1 << endl;

    return 0;
}