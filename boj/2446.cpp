#include<iostream>

using namespace std;

int main(){
    int n; cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            cout << " ";
        }

        for(int j = 0; j < 2 * n - 1 -2 * i; j++){
            cout << "*";
        }
        cout << endl;
    }

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 2 - i; j++){
            cout << " ";
        }
        for(int j = 0; j < 3 + 2 * i; j++){
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}