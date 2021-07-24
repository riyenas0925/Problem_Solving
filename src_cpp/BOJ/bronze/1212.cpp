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
    
    string bit[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};
    string str; cin >> str;

    for(int i = 0; i < str.length(); i++) {\
        if(i == 0) {
            cout << stoll(bit[str[i] - '0']);
        } else {
            cout << bit[str[i] - '0'];
        }
    }
}
