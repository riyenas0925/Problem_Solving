#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int temp = 1;
    string num = "";
    
    for(int i = 0; n > 0; i++) {
        num += to_string(n % 3);
        n /= 3;
    }
    
    for(int i = 0; i < num.length(); i++) {
        answer += (num[num.length() - i -1] - '0') * temp;
        temp *= 3;
    }
    
    return answer;
}