#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int distance(pair<int, int> from, pair<int, int> to) {
    int x = abs(from.first - to.first);
    int y = abs(from.second - to.second);
    return x + y;
}

bool isNextLeft(int keyNum) {
    return keyNum == 1 || keyNum == 4 || keyNum == 7;
}

bool isNextRight(int keyNum) {
    return keyNum == 3 || keyNum == 6 || keyNum == 9;
}

string solution(vector<int> numbers, string hand) {
    int key[4][3];
    string answer = "";
    pair<int, int> curL = {0, 3}, curR = {2,3}; 
    vector<pair<int, int>> point = {
        {1,3}, 
        {0,0}, {1,0}, {2,0}, 
        {0,1}, {1,1}, {2,1}, 
        {0,2}, {1,2}, {2,2}
    };

    for(int i = 0; i < numbers.size(); i++) {
        int keyNum = numbers[i];
        pair<int, int> curNext = point[keyNum];
        
        if(isNextLeft(keyNum)) {
            answer.push_back('L');
            curL = curNext;
        } else if(isNextRight(keyNum)) {
            answer.push_back('R');
            curR = curNext;
        } else {
            int disL = distance(curL, curNext);
            int disR = distance(curR, curNext);
            
            if(disL > disR) {
                answer.push_back('R');
                curR = curNext;
            } else if(disL < disR) {
                answer.push_back('L');
                curL = curNext;
            } else {
                if(hand == "left") {
                    answer.push_back('L');
                    curL = curNext;
                } else {
                    answer.push_back('R');
                    curR = curNext;
                } 
            }
        }

    }
    return answer;
}