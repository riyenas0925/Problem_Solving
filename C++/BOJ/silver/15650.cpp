#include<iostream>
#include<vector>

using namespace std;

void Combination(vector<int> vec, vector<int> res, int index, int depth) {
    if (depth == res.size()) {
        for(int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << "\n";
        
        return;
    }
    else {
        for(int i = index; i < vec.size(); i++)
        {
            res[depth] = vec[i];
            Combination(vec, res, i + 1, depth + 1);
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    vector<int> vec;
    for(int i = 1; i <= n; i++) vec.push_back(i);
    vector<int> res(m);
    vector<bool> visited(n);
    Combination(vec, res, 0, 0);
}