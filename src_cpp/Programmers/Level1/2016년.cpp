#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
    int temp = 0;
    vector<string> day = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    vector<int> month = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    for(int i = 0; i < a - 1; i++) {
        temp += month[i];
    }
    
    temp += b - 1;
    temp %= 7;
    
    return day[temp];
}