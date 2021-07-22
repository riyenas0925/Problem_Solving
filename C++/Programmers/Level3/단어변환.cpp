#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

unordered_map<string, vector<string>> adj;
unordered_map<string, int> dist;

int bfs(string st, string end) {
    queue<string> Q;
    Q.push(st);
    dist[st] = 0;
    while(!Q.empty()) {
        string cur = Q.front();
        Q.pop();
        if(cur == end) return dist[cur] + 1;
        for(int i = 0; i < adj[cur].size(); i++) {
            string nxt = adj[cur][i];
            if(dist[nxt] != -1) continue;
            Q.push(nxt);
            dist[nxt] = dist[cur]+1;
        }
    }
}

bool isSimilar(string begin, string word) {
    int cnt = 0;
    for(int i = 0; i < begin.length(); i++) {
        if(begin[i] != word[i]) cnt++;
    }
    return cnt == 1 ? true : false;
}

int solution(string begin, string target, vector<string> words) {
    vector<string> start;
    int mn = words.size();
    if(find(words.begin(), words.end(), target) == words.end()) return 0;
    for(int i = 0; i < words.size(); i++) {
        for(int j = 0; j < words.size(); j++) {
            if(i == j) continue;
            if(isSimilar(words[i], words[j])) {
                adj[words[i]].push_back(words[j]);
                dist.insert({words[i], -1});
            }
        }    
        if(isSimilar(begin, words[i])) start.push_back(words[i]);
    }
    
    for(auto i :  start) {
        for(auto& j : dist) j.second=-1;
        cout << i << ", ";
        mn = min(mn, bfs(i, target));
    }
    return mn;
}

int main() {
    cout << solution("hit", "dog", {"hot", "dot", "dog", "lot", "log", "cog"});
}