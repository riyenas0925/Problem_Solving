#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, vector<string>> clothesMap;
    
    for(int i = 0; i < clothes.size(); i++) {
        clothesMap[clothes[i][1]].push_back(clothes[i][0]);
    }
    
    for(auto clothes : clothesMap) {
        answer *= clothes.second.size() + 1;
    }
    
    return answer - 1;
}