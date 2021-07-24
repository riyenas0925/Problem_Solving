#include<iostream>

using namespace std;

int arr[10001];
int pos;

void push(int val) {
    arr[pos] = val;
    pos++;
}

int size() {
    return pos;
}

int pop() {
    if(size() == 0) return -1;
    int val = arr[pos - 1];
    pos--;
    return val;
}

int top() {
    if(size() == 0) return -1;
    return arr[pos - 1];
}

int empty() {
    return size() == 0 ? 1 : 0;
}

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        string cmd; cin >> cmd;
        if(cmd == "push") {
            int val; cin >> val;
            push(val);
        }
        else if(cmd == "pop") cout << pop() << endl;
        else if(cmd == "size") cout << size() << endl;
        else if(cmd == "top") cout << top() << endl;
        else if(cmd == "empty") cout << empty() << endl;
    }
}