#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> stackBoard[50];
    stack<int> basket;
    
    int width = board[0].size();
    int height = board.size();
    
    for(int i = 0; i < width; i++) {
        for(int j = height-1; j >= 0; j--) {
            int doll = board[j][i];
            if(doll > 0) {
                stackBoard[i].push(doll);
            }
            cout << doll << "(" << i << "," << j << ")" << ", ";
        }
        cout << endl;
    }
    
    for(int i = 0; i < moves.size(); i++) {
        if(!stackBoard[moves[i] - 1].empty()) {
            int doll = stackBoard[moves[i] - 1].top();
            stackBoard[moves[i] - 1].pop();

            if(basket.empty()) basket.push(doll);
            else if(basket.top() == doll) {
                basket.pop();
                answer += 2;
            }
            else basket.push(doll);
        }
    }
    
    return answer;
}
int main() {
    solution({{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}}, {1,5,3,5,1,2,1,4});
}

