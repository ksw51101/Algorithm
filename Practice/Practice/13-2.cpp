#include <iostream>
#include <algorithm>
using namespace std;

int n, m, map[8][8], temp[8][8], wall, answer;

void virus(int x, int y) {
	if (x<0 || x>=n || y<0 || y>=m) {
		return;
	}
	if (temp[x][y] == 1 || temp[x][y] == 2)
		return;

	temp[x][y] = 2;
	virus(x + 1, y);
	virus(x - 1, y);
	virus(x, y + 1);
	virus(x, y - 1);
}

void start() {
	if (wall == 3) {
		int cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				temp[i][j] = map[i][j];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (temp[i][j] == 2) {
					virus(i + 1, j);
					virus(i - 1, j);
					virus(i, j + 1);
					virus(i, j - 1);
				}
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (temp[i][j] == 0)
					cnt++;
		answer = max(answer, cnt);
		
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				wall++;
				start();
				map[i][j] = 0;
				wall--;
			}

		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	}
	wall = 0;
	answer = 0;

	start();

	cout << answer << '\n';

	return 0;
}