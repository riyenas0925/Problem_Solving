#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;


int solution(int n) {    
    bool arr[n+1];
    int answer = 0;

    for(int i = 2; i <= n; i++) {
        arr[i] = i;
    }

    for(int i = 2; i <= n; i++) {
        if(arr[i] == false) continue;

        for(int j = 2 * i; j <= n; j = j + i) {
            arr[j] = false;
        }
    }

    for(int i = 2; i <= n; i++) {
        if(arr[i]) {
            answer++;
        }
    }

    return answer;
}

int main() {
    int n; cin >> n;
    cout << solution(n);
}