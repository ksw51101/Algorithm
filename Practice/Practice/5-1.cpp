#include <iostream>
using namespace std;

int n, m, cnt = 0;
char ice[1000][1000];

void start(int x, int y) {
	if (x<0 || y<0 || x>(n - 1) || y>(n - 1))
		return;
	if (ice[x][y] == '0') {
		ice[x][y] = '1';
		start(x + 1, y);
		start(x - 1, y);
		start(x, y + 1);
		start(x, y - 1);
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
				start(i, j);
			}

	cout << cnt << '\n';

	return 0;
}