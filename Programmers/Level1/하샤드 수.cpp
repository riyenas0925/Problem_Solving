#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(int x) {
    bool answer = true;

    int sum = 0, temp = x;

    for(int i = 0; temp != 0; i++) {
        sum += temp % 10;
        temp /= 10;
    }

    if(x % sum != 0) {
        answer = false;
    }

    return answer;
}

int main() {
    int x;
    cin >> x;
    cout << solution(x); 
}