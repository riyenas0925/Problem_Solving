#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int arrN[500001], arrM[500001];

int main(void) {
	int N, M;

	cin.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arrN[i];
	}

	sort(arrN, arrN + N);

	cin >> M;

	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;

		if (binary_search(arrN, arrN + N, num)) {
			cout << "1 ";
		}
		else {
			cout << "0 ";
		}
	}

	return 0;
}