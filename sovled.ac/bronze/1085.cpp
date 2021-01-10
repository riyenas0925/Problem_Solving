#include<iostream>

using namespace std;

int main() {
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    if(x > w / 2) {
        if(y > h / 2) {
            cout << min(w - x, h - y) << endl;
        }
        else {
            cout << min(w - x, y) << endl; 
        }
    } else {
        if(y > h / 2) {
            cout << min(x, h - y) << endl;
        }
        else {
            cout << min(x, y) << endl; 
        }
    }
}