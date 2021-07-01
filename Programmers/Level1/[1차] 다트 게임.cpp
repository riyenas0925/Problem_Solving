#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> v;
    string numStr = "";
    for(int i = 0; i < dartResult.length(); i++) {
        char c = dartResult[i];
        if('0' <= c && c <= '9') numStr += c;
        if(c == 'S' || c == 'D' || c == 'T') {
            int num = stoi(numStr);
            numStr = "";
            if(c == 'S') v.push_back(num);
            if(c == 'D') v.push_back(num * num);
            if(c == 'T') v.push_back(num * num * num);
        }
        if(c == '*' || c == '#') {
            if(c == '*') {
                int st = (v.size() >= 2) ? v.size() - 2 : 0;
                for(int j = st; j < v.size(); j++) v[j] *= 2;
            }
            if(c == '#') {
                v.back() = -1 * v.back();
            }
        }
    }
    
    for(auto i : v) {
        cout << i << ", ";
        answer += i;
    }
    
    return answer;
}