#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[100001] = { 0, };
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> s;
    string str;
    cin >> str;

    // 괄호값 맞추기
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '(') {
            s.push(str[i]);
        } else if (str[i] == '['){
            s.push(str[i]);
        } else {
            if(!s.empty()) {
                if(s.top() == '(' || s.top() == '[') {
                    s.pop();
                }
            } else {
                s.push(str[i]);
            }
        }
    }

    if(!s.empty()) {
        cout << "NO";
    } else {
        cout << "YES";
    }
}