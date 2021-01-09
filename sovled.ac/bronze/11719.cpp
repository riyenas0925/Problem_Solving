#include<iostream>

using namespace std;

int main() {
    string str;

    for(int i = 0; i < 100; i++) {
        getline(cin, str);
        cout << str << endl;
    }
}