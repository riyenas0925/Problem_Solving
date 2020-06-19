#include<iostream>

using namespace std;

int main(){
    int c; cin >> c;

    for(int i = 0; i < c; i++){
        int n; cin >> n;
        int score[1000] = {0};
        double total = 0, cnt = 0; 

        for(int j = 0; j < n; j++){
            cin >> score[j];
            total = total + score[j];
        }

        for(int j = 0; j < n; j++){
            double avg = total / n;

            if(score[j] > avg){
                cnt++;
            }
        }

        cout.setf(ios::fixed);
        cout.precision(3);
        cout << (cnt / n) * 100 << "%" << endl;
    }
    
    return 0;
}