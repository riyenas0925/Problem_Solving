#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    int parSize = participant.size();
    
    for(int i = 0; i < parSize; i++) {
        if(participant[i] != completion[i]) {
            return participant[i];
        }
    }

    return participant[participant.size() - 1];

    /*
    unordered_multiset<string> names;

    for(int i = 0; i < participant.size(); i++) {
        names.insert(participant[i]);
    }

    for(int i = 0; i < completion.size(); i++) {
        unordered_multiset<string>::iterator itr = names.find(completion[i]);
        names.erase(itr);
    }

    return *names.begin();
    */
}

int main() {
    vector<string> par = {"leo", "kiki", "eden"};
    vector<string> com = {"eden", "kiki"};

    cout << solution(par, com);
}