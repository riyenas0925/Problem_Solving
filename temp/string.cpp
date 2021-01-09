#include<iostream>

using namespace std;

int main(){
    /*
        find
        값이 있으면 index 반환
        값이 없으면 18446744073709551615(2^64-1, string::npos) 반환
     */
    string str = "test string find";
    string find = "find";
    
    string::size_type pos = str.find(find);
    //string::size_type pos = str.find("find", 3);

    if(pos != string::npos){
        cout << "위치 : " << pos << endl;
    } else {
        cout << "값 없음" << endl;
    }

    /* 
        replace
        문자열을 찾아서 치환
     */
    string replace = "replace";
    str.replace(pos, find.length(), replace);
    cout << str << endl;

    return 0;
}