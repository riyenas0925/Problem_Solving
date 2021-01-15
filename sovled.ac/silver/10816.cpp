#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int arrN[500001], arrM[500001];
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arrN[i];
    }

    cin >> m;

    sort(arrN, arrN + n);
    
    for(int i = 0; i < m; i++) {
        cin >> arrM[i];
        cout << upper_bound(arrN, arrN + n, arrM[i]) - lower_bound(arrN, arrN + n, arrM[i]) << " ";
    }
}