#include<iostream>

using namespace std;

int main(){
    int h, m; cin >> h >> m;
    
    if(m >= 45){
        m = m - 45;
    } else {
        if(h == 0){
            h = 23;
            m = m + 15;
        } else {
            h = h - 1;
            m = m + 15;
        }
    }

    cout << h << " " << m << endl;

    return 0;
}