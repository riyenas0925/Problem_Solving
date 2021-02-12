#include<iostream>

using namespace std;

int main(){
    int score = 0;

    for (int i = 0; i < 5; i++) {
        int temp;
        cin >> temp;

        score = score + temp;
    }

    cout << score << endl;
}