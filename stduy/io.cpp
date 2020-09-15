#include <iostream>

using namespace std;

int main(){
    
    /*
        빈 줄이 주어질 수도 있고
        각 줄의 앞 뒤에 공백이 있을 수도 있다.

            Hello
        Baekjoon     
           Online Judge
    */
    string str;

    for(int i = 0; i < 100; i++) {
        getline(cin, str);
        cout << str << endl;
    }

    /*
        각 줄은 공백으로 시작하지 않고
        공백으로 끝나지 않는다.

        Hello
        Baekjoon
        Online Judge
    */    
    while(true) {
        getline(cin, str);
        if(str=="") {
            break;
        }
        cout << str << endl;
    }

    /*
        A와 B는 콤마(,)로 구분되어 있다.

        1,2
        1,1
    */
    int a, b;
    char c;

    cin >> a >> c >> b;

    cout << a + b << endl;
}