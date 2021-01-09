#include<iostream>

using namespace std;

int main(void) {
	string text;

	cin >> text;

	for (int i = 0; i < text.length(); i++) {
		if ((i % 10 == 0) && (i != 0)) {
			cout << "\n";
		}

		cout << text[i];
	}

	return 0;
}