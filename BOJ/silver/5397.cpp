#include<iostream>
#include<list>
#include<cctype>

using namespace std;

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        string str; cin >> str;
        list<char> L;
        list<char>::iterator t = L.begin();

        for(int j = 0; j < str.length(); j++) {
            char c = str[j];
            if(c == '<' && t != L.begin()) t--;
            if(c == '>' && t != L.end()) t++;
            if(c == '-' && t != L.begin()) t = L.erase(--t);
            if(isalpha(c) || isdigit(c)) L.insert(t, c);
        }

        for(auto i : L) cout << i; 
        cout << endl;
    }
}