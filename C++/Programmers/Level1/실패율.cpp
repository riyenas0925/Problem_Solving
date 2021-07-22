#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<int,double> p1, pair<int,double> p2) {
    if(p1.second == p2.second) {
        return p1.first < p2.first;
    } else {
        return p1.second > p2.second;
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int,double>> fail;
    
    sort(stages.begin(), stages.end());
    
    for(int i = 1; i <= N; i++) {
        int cnt1 = 0, cnt2 = 0;
        
        for(int j = 0; j < stages.size(); j++) {
            if(i == stages[j]) {
                cnt1++;
            }
            
            if(i <= stages[j]) {
                cnt2++;
            }
        }
        
        if(cnt2 != 0) {
            fail.push_back({i, cnt1 / (double)cnt2});    
        } else {
            fail.push_back({i, 0.0});    
        }
        
    }
    
    sort(fail.begin(), fail.end(), cmp);
    
    for(int i = 0; i < N; i++) {
        answer.push_back(fail[i].first);
    }
        
    return answer;
}