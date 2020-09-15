#include <iostream>

using namespace std;

int main() {
    int chess[6] = {1,1,2,2,2,8};
    int peace[6];

    for (int i = 0; i < 6; i++) {
        cin >> peace[i];
    }

    for (int i = 0; i < 6; i++) {
        cout <<  chess[i] - peace[i] << " ";
    }
}