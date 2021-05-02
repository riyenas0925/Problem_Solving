#include<iostream>
#include<string>

using namespace std;

int main(){
    string str; cin >> str;
    string croatia[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    for(int i = 0; i < 8; i++){

        while(str.find(croatia[i]) != string::npos){
            string::size_type pos = str.find(croatia[i]);
            
            if(pos != string::npos){
                str.replace(pos, croatia[i].length(), "*");
            }
        }
    }
    cout << str.length() << endl;

    return 0;
}