#include <string>
#include <vector>
#include <cctype>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
    string head;
    string number;
    string tail;
}fileType;

pair<string, string> splitHead(string f) {
    int pos;
    for(pos = 0; pos < f.length(); pos++) {
        if(isdigit(f[pos]))
            break;
    }
    return {f.substr(0, pos), f.substr(pos, f.length())};
}

pair<string, string> splitNumber(string f) {
    int pos;
    for(pos = 0; pos < f.length(); pos++) {
        if(!isdigit(f[pos]))
            break;
    }
    return {f.substr(0, pos), f.substr(pos, f.length())};
}

bool cmp(fileType f1, fileType f2) {
    string head1 = f1.head, head2 = f2.head;
    transform(head1.begin(), head1.end(), head1.begin(), ::tolower);
    transform(head2.begin(), head2.end(), head2.begin(), ::tolower);
    int num1 = stoi(f1.number), num2 = stoi(f2.number);

    cout << head1 << " " << head2 << "->"; 

    if(head1 == head2) {
        return num1 < num2;
    } else {
        return head1 < head2;
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<fileType> repo;

    for(int i = 0; i < files.size(); i++) {
        pair<string, string> splitHeadStr = splitHead(files[i]);
        //cout << splitHeadStr.first << "|" << splitHeadStr.second << "->";
        pair<string, string> splitNumberStr = splitNumber(splitHeadStr.second);
        //cout << splitHeadStr.first << "|" << splitNumberStr.first << "|" << splitNumberStr.second << "->";
        repo.push_back({splitHeadStr.first, splitNumberStr.first, splitNumberStr.second});
    }

    stable_sort(repo.begin(), repo.end(), cmp);

    for(auto i : repo) {
        //cout << i.head << i.number << i.tail << "->";
        answer.push_back(i.head + i.number + i.tail);
    }

    return answer;
}