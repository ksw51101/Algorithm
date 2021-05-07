#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[500][500], maximum[500][500] = { 0, };

int main() {
	cin >> n;
	int row = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < row; j++) {
			cin >> arr[i][j];
		}
		row++;
	}
	maximum[0][0] = arr[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < row; j++) {
			if (j == 0)
				maximum[i][j] = maximum[i - 1][j] + arr[i][j];
			else if (j == row - 1)
				maximum[i][j] = maximum[i - 1][j - 1] + arr[i][j];
			else
				maximum[i][j] = max(maximum[i - 1][j - 1], maximum[i - 1][j]) + arr[i][j];
		}
		row++;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, maximum[n - 1][i]);
	cout << ans << '\n';

	return 0;
}