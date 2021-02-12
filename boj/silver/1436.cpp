#include<iostream>

using namespace std;


int main(){
    int n; cin >> n;
    int num, i = 0, result ,cnt = 0;
    
    while(true){
        int num = i;

        for(int j = 0; j < 8; j++){
            int test = num % 1000;

            if(test == 666){
                cnt++;
                result = i;
                break;
            }

            num = num / 10;
        }

        if(cnt == n) {
            break;
        }
        
        i++;
    }

    cout << result << endl;

    return 0;
}