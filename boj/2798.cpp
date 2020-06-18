#include<iostream>

using namespace std;

int main(){
    int n, m; cin >> n >> m;
    int card[100] = {0};
    int max = 0;

    for(int i = 0; i < n; i++){
        cin >> card[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                int sum = card[i] + card[j] + card[k];

                if(max < sum && sum <= m){
                    max = sum;
                }
            }
        }
    }

    cout << max << endl;

    return 0;
}