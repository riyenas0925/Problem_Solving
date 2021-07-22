#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

bool cmp1(pair<int,int> p1, pair<int,int> p2) {
    if(p1.second == p2.second) {
        return p1.first < p2.first;
    } else {
        return p1.second > p2.second;
    }
}

bool cmp2(pair<string, int> p1, pair<string, int> p2) {
    return p1.second > p2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, vector<pair<int, int>>> album;
    vector<pair<string, int>> genresPlay;
    vector<int> answer;
    
    for(int i = 0; i < genres.size(); i++) {
        album[genres[i]].push_back({i, plays[i]});
    }

    for(auto& i : album) {
        sort(i.second.begin(), i.second.end(), cmp1);
    }

    for(auto i : album) {
        int sum = 0;
        for(auto j : i.second) {
            sum += j.second;
        }
        genresPlay.push_back({i.first, sum});
    }

    sort(genresPlay.begin(), genresPlay.end(), cmp2);

    for(int i = 0; i < genresPlay.size(); i++) {
        answer.push_back(album.find(genresPlay[i].first)->second[0].first);    
        
        if(album.find(genresPlay[i].first)->second.size() > 1) {
            answer.push_back(album.find(genresPlay[i].first)->second[1].first);    
        }
    }

    return answer;
}

int main() {
    solution({"classic", "pop", "classic", "classic", "pop"}, {500, 600, 150, 800, 2500});
}