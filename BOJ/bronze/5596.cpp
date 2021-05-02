#include <iostream>
#include <random>

using namespace std;

int main() {
    int min = 0;
    int man = 0;

    for (int i = 0; i < 4; i++) {
        int num; cin >> num;
        min = min + num;
    }

    for (int i = 0; i < 4; i++) {
        int num; cin >> num;
        man = man + num;    
    }

    cout << max(min, man) << endl;
}