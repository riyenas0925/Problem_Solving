#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
    vector<int> V = {1, 3, 5, 4, 2};
    int mn, mx;

    mx = *max_element(V.begin(), V.end());
    cout << "*max_element" << endl;
    cout << "최대값 : " << mx << endl;

    mx = max({V[0], V[1], V[2], V[3], V[4]});
    cout << "max" << endl;
    cout << "최대값 : " << mx << endl;

    mn = *min_element(V.begin(), V.end());
    cout << "*min_element" << endl;
    cout << "최소값 : " << mn << endl;

    mx = min({V[0], V[1], V[2], V[3], V[4]});
    cout << "min" << endl;
    cout << "최소값 : " << mn << endl;

    pair<int, int> min_max = minmax({V[0], V[1], V[2], V[3], V[4]});
    cout << "minmax" << endl;
    cout << "최소값(first) : " << min_max.first << ", 최대값(second) : " << min_max.second << endl;
}