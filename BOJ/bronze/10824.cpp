#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c, d;

    cin >> a >> b >> c >> d;

    string str1 = to_string(a) + to_string(b);
    string str2 = to_string(c) + to_string(d);

    long long num1 = stoll(str1);
    long long num2 = stoll(str2);

    cout << num1 + num2 << endl; 
}