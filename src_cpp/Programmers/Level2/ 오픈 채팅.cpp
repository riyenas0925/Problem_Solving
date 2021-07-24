#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cctype>

using namespace std;

vector<string> split(string str, char delimiter) {
	vector<string> vs;
	string temp;

	for (int i = 0; i <= str.length(); i++) {
		if(str[i] == delimiter || str[i] == '\0') {
			vs.push_back(temp);
            //cout << temp << ", ";
			temp.clear();
            continue;
		}
		if(isalpha(str[i]) || isdigit(str[i]))
            temp.push_back(str[i]);
	}

	vs.push_back(temp); 
	return vs;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string>> log;
    unordered_map<string, string> id;
    
    for(int i = 0; i < record.size(); i++) {
        vector<string> com = split(record[i], ' ');
        
        //cout << com[0] << ":" << com[1] << ":" << com[2] << "->";
        
        if(com[0] != "Change")
            log.push_back({com[1], com[0]});
        if(com[0] == "Enter") id[com[1]] = com[2];
        if(com[0] == "Change") id[com[1]] = com[2];
    }
    
    for(int i = 0; i < log.size(); i++) {
        //cout << id[log[i].first] << "(" << log[i].first << ", " << log[i].second << ")->";
        if(log[i].second == "Enter") answer.push_back(id[log[i].first] + "님이 들어왔습니다.");
        if(log[i].second == "Leave") answer.push_back(id[log[i].first] + "님이 나갔습니다.");
    }
    
    return answer;
}