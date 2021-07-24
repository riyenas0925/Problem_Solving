#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int arr[10001];
    int answer = 0;
    int start = 0, end = 0;
    int sum = 0;

    for(int i = 0; i < 10001; i++) {
        arr[i] = i + 1;
    }

    while(start <= end && start < 10001) {
        if(sum < n) {
            sum += arr[end++];
        } else if(sum > n){
            sum -= arr[start++];
        } else {
            sum -= arr[start++];
            answer++;
        }
    }

    return answer;
}