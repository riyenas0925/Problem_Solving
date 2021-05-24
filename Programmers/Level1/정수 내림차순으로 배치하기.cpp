#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> arr;

    while(n > 0) {
        arr.push_back(n % 10);
        n /= 10;
    }

    sort(arr.begin(), arr.end(), greater<int>());

    for(int i = 0; i < arr.size(); i++) {
        answer = answer * 10 + arr[i];
    }

    return answer / 10;
}

int main() {
    int n; cin >> n;
    cout << solution(n);
}