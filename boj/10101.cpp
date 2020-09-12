#include<iostream>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    if((a == 60)&&(b == 60)&&(c == 60)) {
        cout << "Equilateral" << endl;
    } else if((a + b + c) != 180) {
        cout << "Error" << endl;
    } else if((a == b)||(b == c)||(c == a)) {
        cout << "Isosceles" << endl;
    } else {
        cout << "Scalene" << endl;
    }
}