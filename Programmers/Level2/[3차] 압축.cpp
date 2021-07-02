#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<string, int> dic;

string match(string msg, int mx, int st) {
    string str, res;
    for(int i = 1; i <= mx; i++) {
        str = msg.substr(st, i);
        //cout << str << ",";
        if(dic.find(str) != dic.end()) res = dic.find(str)->first;
    }
    return res;
}

vector<int> solution(string msg) {
    vector<int> answer;
    pair<string, int> last;
    string w, c;
    int mx = 1;
        
    for(int i  = 1; i <= 26; i++) {
        string str(1, 'A' + i - 1);
        dic[str] = i;
    }
    
    last = {"Z", 26};            
    for(int i = 0; i < msg.length(); i++) {
        w = match(msg, mx, i);
        c = msg.substr(i+w.length(), 1);
        
        //cout << w << "," << c << " ->";
        // 사전에서 찾음
        answer.push_back(dic[w]);

        // 사전에 새로운 단어 추가
        //cout << w + c;
        dic[w + c] = last.second + 1;
        last = {w + c, dic[w + c]};
        cout << w + c << ", ";
        mx = max(mx, (int)last.first.length());
        i = i+w.length() - 1;
    }
    
    //for(auto i : dic) cout << "(" << i.fisrt << "," << i.second << ")->";
    //for(auto i : answer) cout << i << ", ";
    return answer;
}