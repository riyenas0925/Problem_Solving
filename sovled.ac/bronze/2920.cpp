#include<iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // c d e f g a b C 
    // 1 2 3 4 5 6 7 8

    int a = 1, b = 1;
    int num[8] = {};

    for(int i = 0; i < 8; i++) {
        cin >> num[i];
    }

    for(int i = 0; i < 8; i++) {
        if(i != num[i]) {
            a = 0;
            break;
        }
    }

    for(int i = 0; i < 8; i++) {
        if((8 - i) != num[i]) {
            b = 0;
            break;
        }
    }

    if(a == 0 && b == 0) {
        cout << "mixed" << endl;
    } else if(a == 0 && b == 1) {
        cout << "descending" << endl;
    } else if(a == 1 && b == 0){
        cout << "ascending" << endl;
    }
}