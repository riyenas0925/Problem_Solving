#include<iostream>
#include<vector>

using namespace std;

void Permutation(vector<bool> visited, vector<int> vec, vector<int> res, int depth)
{
    if (depth == res.size())
    {
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < vec.size(); i++) 
    {
        if(visited[i] == true) continue;
        visited[i] = true;
        res[depth] = vec[i];   
        Permutation(visited, vec, res, depth + 1); 
        visited[i] = false;
    }
}

int main() {
    int n, m; cin >> n >> m;
    vector<int> vec;
    for(int i = 1; i <= n; i++) vec.push_back(i);
    vector<int> res(m);
    vector<bool> visited(n);
    Permutation(visited, vec, res, 0);
}