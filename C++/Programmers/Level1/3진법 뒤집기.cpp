#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0, k = 1;
    vector<int> num;
    
    while(n > 0) {
        num.push_back(n % 3);
        n /= 3;
    }

    while(!num.empty()) {
        answer += k * num.back();
        num.pop_back();
        k *= 3;
    }

    return answer;
}