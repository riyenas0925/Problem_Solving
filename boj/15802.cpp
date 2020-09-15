#include <iostream>
#include <random>

using namespace std;

int main() {
    string str; cin >> str;

    random_device rd;
    mt19937 gen(rd());

    // dis(시작 번호, 끝 번호)
    uniform_int_distribution<int> dis(0,1);

    cout << 0 << endl;
}