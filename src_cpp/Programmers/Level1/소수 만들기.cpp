#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool func(int n) {
    int cnt = 0;
    
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            cnt++;
        }
    }
    
    return cnt == 2 ? true : false;
}

int solution(vector<int> nums) {
    int answer = 0;
        
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i+1; j < nums.size(); j++) {
            for(int k = j+1; k < nums.size(); k++) {
                if(i == j || j == k || k == i) {
                    continue;
                } else {
                    int sum = nums.at(i) + nums.at(j) + nums.at(k);
                    if(func(sum)) {
                        answer++;
                    }
                }
            }
        }
    }
    
    return answer;
}