#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int n, arr[5][5], ans[5][5];
ll b;

void multi(int a[5][5], int b[5][5]) {
	int temp[5][5];
	fill(&temp[0][0], &temp[4][5], 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int p = 0; p < n; p++) {
				temp[i][j] += a[i][p] * b[p][j];
			}
			temp[i][j] %= 1000;
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = temp[i][j];
}

void pow(ll b) {
	if (b == 0) {
		return;
	}
	if (b % 2 == 1) {
		multi(ans, arr);
	}
	multi(arr, arr);
	pow(b / 2);	
}

int main() {
	cin >> n >> b;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			ans[i][i] = 1;
		}

	pow(b);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}