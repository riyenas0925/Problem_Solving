#include<iostream>

using namespace std;

int main(){
    int n, total = 0;
    string nums; 
    
    cin >> n >> nums;

    for(int i = 0; i < n; i++){
        total = total + nums[i] - '0';
    }

    cout << total << endl;

    return 0;
}