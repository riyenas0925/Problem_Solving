#include <bits/stdc++.h>

using namespace std;

void Permutation(vector<bool> visited, vector<char> arr, vector<char> perm, int depth) {
    if (depth == perm.size()) {
        for (int i = 0; i < perm.size(); i++)
            cout << perm[i] << " ";
        cout << endl;
        return;
    }

    for (int i = 0; i < arr.size(); i++) {
        if(visited[i] == true) continue;
        visited[i] = true;
        perm[depth] = arr[i];   
        Permutation(visited, arr, perm, depth + 1); 
        visited[i] = false;
    }
}

void Combination(vector<char> vec, vector<char> res, int index, int depth) {
    if (depth == res.size()) {
        for(int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        
        return;
	} else {
        for(int i = index; i < vec.size(); i++) {
            res[depth] = vec[i];
            Combination(vec, res, i + 1, depth + 1);
        }
    }
}

int main(void){	
	vector<char> vec = {'a', 'b', 'c', 'd', 'e'};
	int n = vec.size(); int r = 2;
	vector<char> res(r);
	vector<bool> visited(n);

	//Permutation(visited, vec, res, 0);
	Combination(vec, res, 0, 0);

	return 0;
}