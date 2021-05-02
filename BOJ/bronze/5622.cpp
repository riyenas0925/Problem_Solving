/* 
숫자 선택후 처음위치로 돌아감
1을 거는데 2초 한칸옆에 있는 수는 1초씩 더걸림
UNUCIC -> 868242
 */
#include<iostream>

using namespace std;

int main(){
    string str; cin >> str;
    int phone[16] = {0};
    int total = 0;
    
    for(int i = 0; i < str.size(); i++){
        int time = (str[i] - 'A') / 3 + 3 ;
        
        if(str[i] == 'S' || str[i] == 'V' || str[i] == 'Y' || str[i] == 'Z'){
            time--;
        }

        total = total + time;
    }

    cout << total <<endl;

    return 0;
}