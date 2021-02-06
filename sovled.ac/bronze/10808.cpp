#include<iostream>
#include<algorithm>

using namespace std;

int alp[26] = { 0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str; cin >> str;

    for(int i = 0; i < str.length(); i++) {
        alp[str[i] - 'a']++;
    }

    for(int i = 0; i < 26; i++) {
        cout << alp[i] << " ";
    }
}