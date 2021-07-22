#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> s;
        
    for(int i = 0; i < numbers.size(); i++) {
        for(int j = 0; j < numbers.size(); j++) {
            if(i == j) {
                continue;
            } else {
                s.insert(numbers.at(i) + numbers.at(j));
            }
        }
    }
    
    answer.assign(s.begin(), s.end());
    
    return answer;
}