#include <iostream>
using namespace std;

int n, m, k, arr1[100][100], arr2[100][100], ans[100][100];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr1[i][j];

	cin >> m >> k;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < k; j++)
			cin >> arr2[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			for (int p = 0; p < m; p++) {
				ans[i][j] += arr1[i][p] * arr2[p][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}