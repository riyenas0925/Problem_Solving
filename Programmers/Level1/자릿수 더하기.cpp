#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    
    while(n > 0) {
        answer += n % 10;
        n /= 10;
    }

    /*
    string s = to_string(n);
    for(int i = 0; i < s.size(); i++) answer += (s[i] - '0');
    */
   
    return answer;
}