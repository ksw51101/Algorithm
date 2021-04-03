#include <iostream>
using namespace std;

int T, M, N, K, X, Y;
int arr[51][51], num;
bool flag;

void check(int a, int b) {
	if (arr[a][b] == 1) {

		if (flag == false) {
			num++;
			arr[a][b] = 0;
			flag = true;
		}
		else {
			arr[a][b] = 0;
		}


		if (a > 0 && arr[a - 1][b] == 1)
			check(a - 1, b);
		if (a < 50 && arr[a + 1][b] == 1)
			check(a + 1, b);
		if (b > 0 && arr[a][b - 1] == 1)
			check(a, b - 1);
		if (b < 50 && arr[a][b + 1] == 1)
			check(a, b + 1);
	}
}

int main() {

	cin >> T;

	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 50; j++) {
			for (int k = 0; k < 50; k++) {
				arr[j][k] = 0;
			}
		}
		num = 0;
		cin >> M >> N >> K;

		for (int j = 0; j < K; j++) {
			cin >> X >> Y;
			arr[X][Y] = 1;
		}

		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				flag = false;
				check(j, k);
			}
		}

		cout << num << endl;

	}

	return 0;
}