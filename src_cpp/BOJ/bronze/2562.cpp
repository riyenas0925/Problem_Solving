#include <iostream>
#include <string>

using namespace std;

int main(){
    int arr[100];
    int index = 0;
    int max = 0;

    for(int i = 1; i < 10; i++){
        cin>>arr[i];
        
        if(max < arr[i]){
            max = arr[i];
            index = i;
        }
    }

    cout<<max<<"\n";
    cout<<index<<"\n"; 
    
    return 0;
}