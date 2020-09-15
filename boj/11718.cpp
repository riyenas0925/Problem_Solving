#include <iostream>

using namespace std;

int main(){
    string str;

    while(true) {
        getline(cin, str);
        if(str=="") {
            break;
        }
        cout << str << endl;
    }
}