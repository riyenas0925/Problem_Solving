#include<iostream>

using namespace std;

int fac(int a){
    if(a == 0) {
        return 1;
    } else if(a == 1) {
        return 1;
    } else {
        return a * fac(a - 1);
    }
}

int main(){
    int n; cin >> n;
    cout << fac(n) << endl;
    return 0;
}