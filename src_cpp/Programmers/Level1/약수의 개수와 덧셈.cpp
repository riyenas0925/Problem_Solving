#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool func(int n) {
    int cnt = 0;
    
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            cnt++;        
        }
    }
    
    
    return cnt % 2 == 0 ? true : false;
}

int solution(int left, int right) {
    int answer = 0;
    
    for(int i = left; i <= right; i++) {
        if(func(i)) {
            answer += i;
        } else {
            answer -= i;
        }
    }
    
    return answer;
}