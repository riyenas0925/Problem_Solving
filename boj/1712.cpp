/* 
고정비용 : A = 1000 (판매 대수에 상관없이  매년 임대료, 재산세, 보험료, 급여)
단독비용 : B = 70 (재료비 인건비)

한대 생산하는데 1070만원
열대 생산하는데 1700만원

노트북 가격이 C 만원

A + Bx < Cx
A < x(C - B)
A / (C - B) < x

 */

#include <iostream>
#include <string>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    if(b >= c) {
        cout << -1 << endl;
    } else {
        cout << (a / (c - b)) + 1 << endl;
    }
    return 0;
}