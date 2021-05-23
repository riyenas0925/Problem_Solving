#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    for(int i = 0; i < arr1.size(); i++) {
        vector<int> vec1 = arr1[i];
        vector<int> vec2 = arr2[i];
        vector<int> vec_sum;

        for(int j = 0; j < vec1.size(); j++) {
            vec_sum.push_back(vec1[j] + vec2[j]);
        }

        answer.push_back(vec_sum);
    }

    return answer;
}

int main() {
    vector<vector<int>> arr1 = {{1, 2},{2, 3}};
    vector<vector<int>> arr2 = {{3, 4},{5, 6}};

    vector<vector<int>> answer = solution(arr1, arr2);

    for(int i = 0; i < answer.size(); i++) {
        vector<int> ans = answer[i];

        for(int j = 0; j < ans.size(); j++) {
            printf("%d ", ans[j]);
        }
    }
}