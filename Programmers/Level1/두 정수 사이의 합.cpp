#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    int min_n = min(a, b);
    int max_n = max(a, b);
    
    for(long long i = min_n; i <= max_n; i++) {
        answer += i;
    }

    /*
    if (a > b) a ^= b ^= a ^= b;
    answer = (long long)b * -~b / 2 - (long long)a * ~-a / 2;
    */
    
    return answer;
}

int main() {
    int a, b; cin >> a >> b;
    cout << solution(a, b);
}
