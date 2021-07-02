#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//2진수에서 16진수까지 변환
string notation(int n, int num) {
    string str = "";
    if(num == 0) return "0";
    vector<char> alp = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    while(num > 0) {
        str.push_back(alp[num % n]);
        num = num / n;
    }
    reverse(str.begin(), str.end());
    return str;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string arr = "";
    for(int i = 0; i <= m * t; i++) {
        arr += notation(n, i);
    }
    
    for(int i = 0; i < t; i++) {
        answer.push_back(arr[m*i + p - 1]);
    }
    
    return answer;
}