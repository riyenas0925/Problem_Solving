#include <string>
#include <vector>
#include <iostream>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    
    for(int i = 0; i < arr.size(); i++) {
        answer += arr[i];
    }
    
    // #include <numeric>
    // double answer = accumulate(arr.begin(), arr.end(), 0);

    return answer / arr.size();
}