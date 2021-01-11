#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main() {
    string s;

    while(1) {
        cin >> s;
        string temp = s;

        if(s == "0") {
            break;
        }

        reverse(s.begin(), s.end());

        if(temp == s) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}