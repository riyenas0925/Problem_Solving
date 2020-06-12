#include<iostream>

using namespace std;

int main(){
    int cnt;
    string testCase;

    cin >> cnt;

    for(int i = 0; i < cnt; i++){
        cin >> testCase;
        int bonus = 0;
        int total = 0;

        for(int j = 0; j < testCase.length(); j++){
            if(testCase[j] == 'O'){
                total = total + bonus + 1;
                if(testCase[j] == testCase[j+1]){
                    bonus = bonus + 1;
                }
            } else {
                bonus = 0;
            }
        }
        cout << total << endl;
    }
    return 0;
}
