#include<iostream>
#include<list>

using namespace std;

int main() {
    list<int> L = {1,2};
    list<int>::iterator t = L.begin();
    L.push_front(10);
    L.insert(t, 6);
    t++;
    t = L.erase(t);

    cout << *t << '\n';
    for(auto i : L) cout << i << ' ';
    cout << '\n';
    for(list<int>::iterator it = L.begin(); it != L.end(); it++) 
        cout << *it << ' ';
}