#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string s) {
    vector<int> v;
    int ptr = 0;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ' || i == s.size() - 1) {
            v.push_back(stoi(s.substr(ptr, i)));   
            ptr = i;
        }
    }
    
    int nmin = *min_element(v.begin(), v.end());
    int nmax = *max_element(v.begin(), v.end());
    
    return to_string(nmin) + " " + to_string(nmax);
}