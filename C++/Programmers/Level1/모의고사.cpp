#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int cnt1 = 0, cnt2 = 0, cnt3 = 0;

    int ans1[5] = { 1, 2, 3, 4, 5};
    int ans2[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
    int ans3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    for(int i = 0; i < answers.size(); i++) {
        if(answers[i] == ans1[i % 5]) {
            cnt1++;
        }

        if(answers[i] == ans2[i % 8]) {
            cnt2++;
        }

        if(answers[i] == ans3[i % 10]) {
            cnt3++;
        }
    }
    
    int temp = max(cnt1, max(cnt2, cnt3));
    
    if(temp == cnt1) {
        answer.push_back(1);
    }
    
    if(temp == cnt2) {
        answer.push_back(2);
    }
    
    if(temp == cnt3) {
        answer.push_back(3);
    }

    return answer;
}