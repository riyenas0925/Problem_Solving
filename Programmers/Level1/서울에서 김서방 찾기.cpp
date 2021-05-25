#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int index = 0;

    for(int i = 0; i < seoul.size(); i++) {
        if(seoul[i].find("Kim") != -1) {
            index = i;
        }
    }

    // int index = find(seoul.begin(),seoul.end(),"Kim")-seoul.begin();

    answer = "김서방은 " + to_string(index) + "에 있다";

    return answer;
}

int main() {
    vector<string> s = {"Jane", "Kim"};
    cout << solution(s);
}