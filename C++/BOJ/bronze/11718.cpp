#include<iostream>

using namespace std;

int main() {
    string str;

    while (1) {
        getline(cin, str);
        if (str == "")
            break;
        cout << str << '\n';
    }
}