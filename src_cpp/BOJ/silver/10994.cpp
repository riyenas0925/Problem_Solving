#include<iostream>
#include<cmath>
using namespace std;

int n;
char  star[500][500];

void func(int dep) {
    if(dep == 0) return;

    int num = 4 * (dep - 1) + 1;
    int shift = 2 * (n - dep);

    for(int i = 0; i < num; i++) {
        for(int j = 0; j < num; j++) {
            if(i == 0 || i == num-1 || j == 0 || j == num-1) 
                star[shift + i][shift + j] = 1;
        }
    }

    func(dep - 1);
}

int main() {
    cin >> n;
    func(n);

    for(int i = 0; i < 4 * (n - 1) + 1; i++) {
        for(int j = 0; j < 4 * (n - 1) + 1; j++) {
            if(star[i][j] == 1) cout << "*";
            else cout << " ";
        }   
        cout << endl;
    }
}