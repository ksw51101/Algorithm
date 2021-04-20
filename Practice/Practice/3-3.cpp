#include <iostream>
#include <algorithm>
using namespace std;

int n, m, arr[100][100], min_row, max_column;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	//for (int i = 0; i < n; i++)
	//	sort(arr[i], arr[i] + m);

	//maximum = arr[0][0];
	//for (int i = 1; i < n; i++)
	//	maximum = max(maximum, arr[i][0]);

	max_column = 0;
	for (int i = 0; i < n; i++) {
		min_row = arr[i][0];
		for (int j = 1; j < m; j++) {
			min_row = min(arr[i][j], min_row);
		}
		max_column = max(max_column, min_row);
	}
	cout << max_column << '\n';

	return 0;
}