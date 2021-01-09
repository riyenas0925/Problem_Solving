#include <iostream>
#include <random>

using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());

    // dis(시작 번호, 끝 번호)
    uniform_int_distribution<int> dis(0,99);

    cout << dis(gen) << endl;
}