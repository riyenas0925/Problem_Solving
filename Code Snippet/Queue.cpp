#include<iostream>

using namespace std;

int arr[10000007];
int head, tail;

void push(int val) {
    arr[tail] = val;
    tail++;
}

int size() {
    return tail - head;
}

int pop() {
    if(size() == 0) return -1;
    int val = arr[head];
    head++;
    return val;
}

int empty() {
    return size() == 0 ? 1 : 0;
}

int front() {
    if(size() == 0) return -1;
    return arr[head];
}

int back() {
    if(size() == 0) return -1;
    return arr[tail - 1];
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
        else if(cmd == "front") cout << front() << endl;
        else if(cmd == "back") cout << back() << endl;
        else if(cmd == "empty") cout << empty() << endl;
    }
}