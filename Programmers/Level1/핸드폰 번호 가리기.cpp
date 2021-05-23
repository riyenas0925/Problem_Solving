#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string phone_number) {
    int len = phone_number.length();

    for(int i = len - 5; i >= 0; i--) {
        phone_number[i] = '*';
    }
    return phone_number;
}

int main() {
    string s;
    cin >> s;
    cout << solution(s);
}