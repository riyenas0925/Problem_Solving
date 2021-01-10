/*
M*N 크기의 보드로 체스판 제작
체스판은 검은색과 흰색이 번갈아서 칠해져 있어야함
변을 공유하는 두 개의 사각형은 다른 색으로 칠해져 있어야 함
색칠하는 경우는 두가지 맨 왼쪽 흰색 또는 검은색

경우의 수
맨왼쪽 흰색 : 00(흰), 11(흰), 01(흑), 10(흑)
맨왼쪽 흑색 : 00(흑), 11(흑), 10(흰), 01(흰)
*/

#include<iostream>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    char b[51][51];
    int ans = 64;

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for(int k = 0; k <= n - 8; k++) {
        for(int v = 0; v <= m - 8; v++) {
            int cnt = 0;

            for(int i = k; i < k + 8; i++) {
                // 맨왼쪽 흰색일떄 맞는 경우
                for(int j = v; j < v + 8; j++) {
                    if((b[i][j] - 'W') == ((i % 2) ^ (j % 2))) {
                        cnt++;
                    }

                    if((b[i][j] - 'B' + 1) == ((i % 2) ^ (j % 2))) { 
                        cnt++;    
                    }
                } 
            }

            ans = min(ans, cnt);        // 맨왼쪽 흰색일때 맞는 경우
            ans = min(ans, 64 - cnt);   // 맨왼쪽 흑색일때 맞는 경우
        }
    }

    cout << ans << endl;
}