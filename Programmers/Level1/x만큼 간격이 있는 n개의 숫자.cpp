#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;

    int cnt = 0;

    for(int i = x; cnt != n; i = i + x) {
        answer.push_back(i);
        cnt++;
    }

    return answer;
}

int main() {
    int x, n;
    cin >> x >> n;

    vector<long long> ans = solution(x, n);

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }   
}