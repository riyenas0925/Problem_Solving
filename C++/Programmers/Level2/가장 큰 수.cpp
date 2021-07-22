#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b) {
    string sa = to_string(a);
    string sb = to_string(b);
    
    return stoi(sa + sb) > stoi(sb + sa);
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), comp);
    
    for(int i = 0; i < numbers.size(); i++) {
        if(answer[0] == '0') {
            answer = '0';
        } else {
            answer += to_string(numbers.at(i));
        }
    }
    
    return answer;
}