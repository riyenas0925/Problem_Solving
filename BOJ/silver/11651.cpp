#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if(p1.second == p2.second) {
        return p1.first < p2.first;
    } else {
        return p1.second < p2.second;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<pair<int, int>> v;

    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < n; i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }
}