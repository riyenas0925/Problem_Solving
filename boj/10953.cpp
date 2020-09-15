#include <iostream>
#include <string>

using namespace std;

int main(){
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        int a, b;
        char c;

        cin >> a >> c >> b;

        cout << a + b << endl;
    }
}