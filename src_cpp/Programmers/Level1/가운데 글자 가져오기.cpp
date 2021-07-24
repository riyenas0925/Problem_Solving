#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    int size = s.size();

    if(s.size() % 2 == 0) {
        return s.substr(size/2-1,2);
    } else {
        return s.substr(size/2,1);
    }
}

int main() {
    string s; cin >> s;
    cout << solution(s);
}