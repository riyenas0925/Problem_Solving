#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

long long solution(long long n) {
    long long answer = 0;

    /*
    if (sqrt(n) == floor(sqrt(n))) {
        return pow(sqrt(n)+1,2);
    }
    else {
        return -1;
    }
    */

    for(answer = 0; answer < 7071067; answer++) {
        if(n == answer * answer) {
            break;
        }
    }

    return answer == 707106 ? -1 : (answer + 1) * (answer + 1);
}

int main() {
    long long n;
    cin >> n;
    cout << solution(n);
}