#include <iostream>
using namespace std;

int T, k, n, arr[15][15] = { 0, };

int main() {

	cin >> T;

	for (int i = 1; i < 15; i++) {
		arr[0][i] = i;
	}

	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			for (int z = 1; z <= j; z++)
				arr[i][j] += arr[i - 1][z];
		}

	}

	for (int i = 0; i < T; i++) {
		cin >> k >> n;

		cout << arr[k][n] << endl;

	}

	return 0;
}