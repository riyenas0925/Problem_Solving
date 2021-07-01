#include<iostream>
#include<unordered_map>

using namespace std;

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    unordered_map<string, vector<string>> um;
    
    for(int i = 0; i < clothes.size(); i++) {
        um[clothes[i][1]].push_back(clothes[i][0]);
    }
    
    for(auto i : um) {
        for(auto j : i) answer++;
    }
    
    return answer;
}

int main() {
    solution({{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}});
}