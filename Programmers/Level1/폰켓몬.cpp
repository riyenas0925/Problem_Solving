#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int pickNums = nums.size() / 2;

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    /*
        unordered_set<int> s(nums.begin(), nums.end());
    */

    int uniqueLen = nums.size();

    return answer = pickNums <= uniqueLen ? pickNums : uniqueLen;
}