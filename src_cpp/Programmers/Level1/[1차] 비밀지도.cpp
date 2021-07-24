#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string to_binary(int num, int n) {
    string str;
        
    for(int i = 0; i < n; i++) {
        if(num % 2 == 0) {
            str += ' ';
        } else {
            str += '#';
        }
        
        num /= 2;
    }
    
    reverse(str.begin(), str.end());
    
    return str;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i < arr1.size(); i++) {
        answer.push_back(to_binary(arr1[i] | arr2[i] , n));
    }
    
    return answer;
}