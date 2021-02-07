#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;

    while (getline(cin, str)) {
        int a = 0, b = 0, c = 0, d = 0;

        for(int i = 0; i < str.length(); i++) {
            if('a' <= str[i] && str[i] <= 'z') {
                a++;
            } else if('A' <= str[i] && str[i] <= 'Z') {
                b++;
            } else if('0' <= str[i] && str[i] <= '9') {
                c++;
            } else if(' ' == str[i]) {
                d++;
            }
        }

        cout << a << " " << b << " " << c << " " << d << endl;
    }
}