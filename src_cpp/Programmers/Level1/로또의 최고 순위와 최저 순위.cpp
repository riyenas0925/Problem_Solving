#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    vector<int> score = {6, 6, 5, 4, 3, 2, 1};
    int cntEqual = 0;
    int cntZero = 0;
    
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    
    for(int i = 0; i < 6; i++) {
        if(lottos[i] == 0) {
            cntZero++;
        }
        
        for(int j = 0; j < 6; j++) {
            if(lottos[i] == win_nums[j]) {
                cntEqual++;
                break;
            }
        }
    }
    
    answer.push_back(score[cntEqual + cntZero]);
    answer.push_back(score[cntEqual]);
        
    return answer;
}