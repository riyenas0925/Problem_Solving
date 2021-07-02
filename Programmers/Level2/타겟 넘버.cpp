#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;

void bfs(vector<int> nums, int target, int sum, int idx) {
    if(idx == nums.size()) {
        if(sum == target) cnt++;
        return;
    }
    
    bfs(nums, target, sum + nums[idx], idx + 1);
    bfs(nums, target, sum - nums[idx], idx + 1);
}

int solution(vector<int> numbers, int target) {
    vector<bool> vis(numbers.size());
    bfs(numbers, target, 0, 0);
    return cnt;
}