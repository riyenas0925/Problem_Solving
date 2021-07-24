#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    int len = arr.size();

    sort(arr.begin(), arr.end());

    for(int i = len; ; i++) {
        int j;
        for(j = 0; j < len; j++) {
            if(i % arr[j] == 0) {
                continue;
            }
            else {
                break;
            }
        }
        if(j == len) {
            return i;
        }
    }
}