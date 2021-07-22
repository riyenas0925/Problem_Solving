#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int cnt = 0;

    int len = s.length();

    if(len != 4 && len != 6) {
        answer = false;
    }

    for(int i = 0; i < len; i++) {
        if('0' <= s[i] && s[i] <= '9') {
            cnt++;
        }
    }

    if(len != cnt) {
        answer = false;
    }

    return answer;
}

int main() {
    string s; cin >> s;
    cout << solution(s);
}