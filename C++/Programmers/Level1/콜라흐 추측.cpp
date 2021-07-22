#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int num) {
    int answer = 0;

    for(answer = 0; answer < 500; answer++) {
        if(num == 1) {
            break;
        } else if(num % 2 == 0) {
            num = num / 2;
        } else if(num % 2 == 1) {
            num = num * 3 + 1;
        }
    }

    return answer == 500 ? -1 : answer;
}

int main() {
    int num; cin >> num;
    cout << solution(num);
}