#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<math.h>

using namespace std;

using ll = long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str; cin >> str;

    if(str.length() % 3 == 1) {
        cout << (str[0] - '0');
    } 
    
    if(str.length() % 3 == 2) {
        cout << (str[0] - '0') * 2 + (str[1] - '0');
    }

    for(int i = str.length() % 3; i < str.length(); i = i + 3) {
        cout << (str[i] - '0') * 4 + (str[i+1] - '0') * 2 + (str[i+2] - '0');
    }
}