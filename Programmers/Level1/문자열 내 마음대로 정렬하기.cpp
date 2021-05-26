#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int index;

bool cmp(const string &s1, const string &s2) {

    /*
    if(s1[index] != s2[index]) {
        return s1[index] < s2[index];
    } else {
        return s1 < s2;
    }
    */

    return s1[index] == s2[index] ? s1 < s2 : s1[index] < s2[index];
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer = strings;
    index = n;
    
    sort(answer.begin(), answer.end(), cmp);
    
    return answer;
}

int main() {
    vector<string> v = {"abce", "abcd", "cdx"};
    solution(v, 2);
}