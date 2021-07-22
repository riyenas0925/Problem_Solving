#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            answer.append("수");
        } else {
            answer.append("박");
        }
    }

    /*
    for(int i = 0; i < n; i++)
        i & 1 ? answer += "박" : answer += "수";
    */
    
    return answer;
}