#include <iostream>
using namespace std;

int n, m, cnt = 0;
char ice[1000][1000];

void start(int x, int y) {
	if (x > 0 && ice[x - 1][y] == '0') {
		ice[x - 1][y] = '1';
		start(x - 1, y);
	}
	if (y > 0 && ice[x][y - 1] == '0') {
		ice[x][y - 1] = '1';
		start(x, y - 1);
	}
	if (x < n - 1 && ice[x+1][y] == '0') {
		ice[x + 1][y] = '1';
		start(x + 1, y);
	}
	if (y < m - 1 && ice[x][y + 1] == '0') {
		ice[x][y + 1] = '1';
		start(x, y + 1);
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> ice[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (ice[i][j] == '0') {
				cnt++;
				ice[i][j] = '1';
				start(i, j);
			}

	cout << cnt << '\n';

	return 0;
}