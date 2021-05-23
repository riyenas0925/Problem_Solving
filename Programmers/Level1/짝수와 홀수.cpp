#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int num) {
    string answer = "";
    return num % 2 == 1 ? "Odd" : "Even";
}

int main() {
    int num;
    cin >> num;
    cout << solution(num);
}