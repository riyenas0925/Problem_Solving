#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    /*
    vector<int> answer;
    int minNum = arr[0], minIndex = 0;

    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] < minNum) {
            minNum = arr[i];
            minIndex = i;
        }
    }

    for(int i = 0; i < arr.size(); i++) {
        if(minIndex != i) {
            answer.push_back(arr[i]);
        } 
    }
    */

    vector<int> answer = arr;

    int nMin = *min_element(arr.begin(), arr.end());
    int pos = find(answer.begin(), answer.end(), nMin) - answer.begin();
    answer.erase(pos + answer.begin());
    
    return answer.empty() ? vector<int>(1, -1) : answer;
}

int main() {
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(2);
    arr.push_back(1);

    vector<int> ans = solution(arr);

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}