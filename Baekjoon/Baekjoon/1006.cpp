#include <iostream>
#include <algorithm>
using namespace std;

int N, W, enemy[2][10000], a[10001], b[10000], c[10000];

void go(int start);

int main() {
	int T, answer;

	cin >> T;

	while(T--) {
		cin >> N >> W;

		for (int j = 0; j < N; j++) {
			cin >> enemy[1][j];
		}
		for (int k = 0; k < N; k++) {
			cin >> enemy[0][k];
		}
		a[0] = 0;
		b[0] = c[0] = 1;
		go(0);
		answer = a[N];

		if (N > 1 && enemy[0][0] + enemy[0][N - 1] <= W) {
			a[1] = 1;
			b[1] = 2;
			c[1] = enemy[1][0] + enemy[1][1] <= W ? 1 : 2;
			go(1);
			answer = min(answer, c[N - 1] + 1);
		}
		if (N > 1 && enemy[1][0] + enemy[1][N - 1] <= W) {
			a[1] = 1;
			c[1] = 2;
			b[1] = enemy[0][0] + enemy[0][1] <= W ? 1 : 2;
			go(1);
			answer = min(answer, b[N - 1] + 1);
		}
		if (N > 1 && enemy[1][0] + enemy[1][N - 1] <= W && enemy[0][0] + enemy[0][N - 1] <= W) {
			a[1] = 0;
			b[1] = 1;
			c[1] = 1;
			go(1);
			answer = min(answer, a[N - 1] + 2);
		}

		cout << answer << endl;
	}


	return 0;
}

void go(int start) {
	for (int i = start; i < N; i++) {
		a[i + 1] = min(b[i] + 1, c[i] + 1);
		if (enemy[0][i] + enemy[1][i] <= W)
			a[i + 1] = min(a[i + 1], a[i] + 1);
		if (i > 0 && enemy[0][i - 1] + enemy[0][i] <= W && enemy[1][i - 1] + enemy[1][i] <= W) 
			a[i + 1] = min(a[i + 1], a[i - 1] + 2);
		if (i < N - 1) {
			b[i + 1] = a[i + 1] + 1;
			if (enemy[0][i] + enemy[0][i + 1] <= W)
				b[i + 1] = min(b[i + 1], c[i] + 1);

			c[i + 1] = a[i + 1] + 1;
			if (enemy[1][i] + enemy[1][i + 1] <= W)
				c[i + 1] = min(c[i + 1], b[i] + 1);
		}
		
	}
}