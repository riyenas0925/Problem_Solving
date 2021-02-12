#include<iostream>
#include<set>

using namespace std;

int main(){
    int arr[100];
    
    set<int> m;

    for(int i = 1; i < 11; i++){
        cin>>arr[i];
        m.insert(arr[i]%42);
    }

    cout<<m.size()<<"\n";
}