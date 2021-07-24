#include <deque>
#include <iostream>

using namespace std;

int main() {
    deque<int> dq;

    // 덱의 앞에 넣는다.
    dq.push_back(1);

    // 덱의 뒤에 넣는다.
    dq.push_front(2);

    // 덱의 가장 앞에 있는 수를 뺀다.
    dq.pop_front();

    // 덱의 가장 뒤에 있는 수를 뺀다.
    dq.pop_back();

    // 덱 사이즈 출력
    cout << dq.size() << endl;

    // 덱이 비어있으면 1 아니면 0
    cout << dq.empty() << endl;

    dq.push_front(9); dq.push_front(10);

    // 덱의 가장 앞에 있는 정수를 출력
    cout << dq.front() << endl;

    // 덱의 가장 뒤에 있는 정수를 출력
    cout << dq.back() << endl;
}