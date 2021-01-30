#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> v;
    long long n, k; cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int num; cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    cout << v[k - 1] << endl;
}