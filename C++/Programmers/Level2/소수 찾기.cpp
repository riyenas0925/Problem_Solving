#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

unordered_set<int> us;

bool isPrime(int num) {
    int cnt = 0;
    if(num == 0 || num == 1) return false;
    for(int i = 2; i*i <= num; i++) {
        if(num % i == 0) return false;
    }
    return true;
}

void Permutation(vector<bool> visited, vector<char> vec, vector<char> res, int depth)
{
    if (depth == res.size()) {
        string str = "";
        for (int i = 0; i < res.size(); i++) {
            str.push_back(res[i]);   
        }
        int num = stoi(str);
        cout << num << "\n";
        if(isPrime(num)) us.insert(num);
        return;
    }

    for (int i = 0; i < vec.size(); i++) {
        if(visited[i] == true) continue;
        visited[i] = true;
        res[depth] = vec[i];   
        Permutation(visited, vec, res, depth + 1); 
        visited[i] = false;
    }
}

int solution(string numbers) {
    vector<char> vec(numbers.begin(), numbers.end());
    vector<bool> visited(vec.size());
    
    for(int i = 1; i <= vec.size(); i++) {
        vector<char> res(i);
        Permutation(visited, vec, res, 0);
    }
    return us.size();
}

int main() {
    solution("2222222");
}