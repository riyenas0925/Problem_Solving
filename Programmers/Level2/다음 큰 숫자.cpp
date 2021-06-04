#include <string>
#include <vector>

using namespace std;

int bin(int n) {
    int cnt = 0;
    
    for(int i = 0; n > 0; i++) {
        if(n % 2 == 0) {
            n /= 2;
        } else {
            n /= 2;
            cnt++;
        }
    }
    
    return cnt;
}

int solution(int n) {
    int answer = 0;
    int count = bin(n);
    
    for(answer = n + 1; ; answer++) {
        if(count == bin(answer)) {
            break;
        }
    }
    
    return answer;
}