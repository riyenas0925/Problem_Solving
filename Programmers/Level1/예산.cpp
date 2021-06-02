#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(), d.end(), less<int>());
    
    for(answer = 0; answer < d.size(); answer++) {
        budget = budget - d[answer];
        
        if(budget < 0) {
            break;
        }
    }
    
    return answer;
}