#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int cnt1 = 0, cnt2 = 0;

    for(int i = 0; i < s.length(); i++) {
        if(tolower(s[i]) == 'p') {
            cnt1++;
        }

        if(tolower(s[i]) == 'y') {
            cnt2++;
        }
    }

    return cnt1 == cnt2 ? true : false;
}

int main() {
    string s; cin >> s;
    cout << solution(s);
}