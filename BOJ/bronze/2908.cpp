#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int reverse(int num){
    int n1 = num % 10;
    int n10 = (num / 10) % 10;
    int n100 = num / 100;

    return n1 * 100 + n10 * 10 + n100;
}

int main(){
    int a, b; cin >> a >> b;

    if(reverse(a) > reverse(b)){
        cout << reverse(a) << endl;
    } else {
        cout << reverse(b) << endl;
    }
    
    return 0;
}