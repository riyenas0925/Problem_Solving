#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<int> st;
    
    
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            st.push(s[i]);
        } else {
            if(st.empty()) {
                return false;
            } else {
                st.pop();
            }
        }
    }

    return answer = (st.empty() == true) ? true : false;
}