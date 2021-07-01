#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool isAlpha(char c) {
    return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}

bool isAlphaPair(char c1, char c2) {
    return isAlpha(c1) && isAlpha(c2);
}

int solution(string str1, string str2) {
    vector<string> A, B;
    vector<string> multiUni, multiInter;
    unordered_set<string> uni; 
    int answer = 0;
    
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    for(int i = 0; i < str1.length() - 1; i++) {
        if(isAlphaPair(str1[i], str1[i+1])) {
            string str = str1.substr(i, 2);
            A.push_back(str);  
            uni.insert(str);
        }
    }
        
    for(int i = 0; i < str2.length() - 1; i++) {
        if(isAlphaPair(str2[i], str2[i+1])) {
            string str = str2.substr(i, 2);
            B.push_back(str);
            uni.insert(str);
        }
    }
    
    for(string i : uni) {
        int an = count(A.begin(), A.end(), i);
        int bn = count(B.begin(), B.end(), i);
        int mx = max(an, bn);
        int mn = min(an, bn);
        for(int j = 0; j < mx; j++) multiUni.push_back(i);
        for(int j = 0; j < mn; j++) multiInter.push_back(i);
    }

    int multiUniSize = multiUni.size();
    int multiInterSize = multiInter.size();
    
    if(multiInterSize == 0 && multiUniSize == 0) answer = 65536;
    else answer = (int)((double)multiInterSize / multiUniSize * 65536);
    
    return answer;
}