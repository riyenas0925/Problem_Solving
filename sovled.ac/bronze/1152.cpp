#include<iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt = 0;
    string str;
    getline(cin, str);

    for(int i = 0; i < str.length(); i++) {
        if(str.at(i) == ' ') {
            cnt++;
        }
    }

    if(str.front() == ' ') {
        cnt = cnt - 1;
    }

    if(str.back() == ' ') {
        cnt = cnt - 1;
    }

    cout << cnt + 1 << endl;
}