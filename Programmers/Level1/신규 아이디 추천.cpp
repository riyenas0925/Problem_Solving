#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    string temp = "";
    
    for(int i = 0; i < new_id.length(); i++) {
        if('a' <= new_id[i] && new_id[i] <= 'z' || 'A' <= new_id[i] && new_id[i] <= 'Z' || 
           '0' <= new_id[i] && new_id[i] <= '9' || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') {
            answer += tolower(new_id[i]);    
        }
    }
        
    while(answer[0] == '.' || answer[answer.end() - answer.begin() - 1] == '.') {
        if(answer[0] == '.') {
            answer.erase(answer.begin());   
        }
        
        if(answer[answer.end() - answer.begin() - 1] == '.') {
            answer.erase(answer.end() - answer.begin() - 1);
        }
    }
    
    for(int i = 0; i < answer.length(); i++) {
        if(temp[temp.end() - temp.begin() - 1] != '.' || answer[i] != '.') {
            temp += answer[i];
        }
    }
    
    answer = temp;
    
    if(answer.length() == 0) {
        answer = 'a';   
    }
    
    if(answer.length() >= 16) {
        answer = answer.substr(0,15);
        
        while(answer[0] == '.' || answer[answer.end() - answer.begin() - 1] == '.') {
            if(answer[0] == '.') {
                answer.erase(answer.begin());   
            }

            if(answer[answer.end() - answer.begin() - 1] == '.') {
                answer.erase(answer.end() - answer.begin() - 1);
            }
        }
    }
    
    if(answer.length() <= 2) {
        for(int i = answer.length(); i < 3; i++) {
            answer += answer[answer.end() - answer.begin() - 1];
        }
    }
    
    return answer;
}