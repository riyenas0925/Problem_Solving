#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;

    getline(cin, str);

    for(int i = 0; i < str.length(); i++) {
        if('a' <= str[i] && str[i] <= 'z') {
            if('z' - str[i] < 13) {
                str[i] = 'a' + str[i] - 'n';
            }else {
                str[i] = str[i] + 13;
            }
        } else if('A' <= str[i] && str[i] <= 'Z') {     
            if('Z' - str[i] < 13) {
                str[i] = 'A' + str[i] - 'N';
            }else {
                str[i] = str[i] + 13;
            }        
        }
    }
    cout << str << endl;
}