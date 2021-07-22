#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int t; cin >> t;

    for(int i = 0; i < t; i++) {
        int h, w, n; cin >> h >> w >> n;
        int cnt = 0;
        int j, k;
        
        for(j = 1; j <= w; j++) {
            for(k = 1; k <= h; k++) {

                cnt++;

                if(cnt == n) {
                    break;
                }
            }

            if(cnt == n) {
                break;
            } 
        }

        cout << k;
        cout.width(2);
        cout.fill('0');
        cout << j << endl;
    }
}