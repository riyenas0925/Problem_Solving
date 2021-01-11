/*
정렬
1. 길이가 짧은 것부터
2. 길이가 같으면 사전 순으로
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(string a, string b) {
    if(a.length() == b.length()) {
        return a < b;
    } else {
        return a.length() < b.length();
    }   
}

int main() {
    vector<string> v;
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        string b; cin >> b;
        v.push_back(b);
    }

    sort(v.begin(), v.end(), cmp);
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}