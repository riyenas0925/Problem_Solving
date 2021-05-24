#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = stoi(s);
    return answer;
}

int main() {
    string s; cin >> s;
    cout << solution(s);
}