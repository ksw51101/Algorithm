#include <iostream>
using namespace std;

int n, cnt = 0;
char hall[6][6];
bool flag, ans = false;

void check(int x, int y, int dir) {
	if (x < 0 || y < 0 || x >= n || y >= n || hall[x][y] == 'O')
		return;
	if (hall[x][y] == 'S') {
		flag = false;
		return;
	}
	switch (dir) {
	case 0:
		return check(x, y + 1, dir);
		break;
	case 1:
		return check(x - 1, y, dir);
		break;
	case 2:
		return check(x, y - 1, dir);
		break;
	case 3:
		return check(x + 1, y, dir);
		break;
	}
}

void start() {
	if (cnt == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (hall[i][j] == 'T') {
					flag = true;
					for (int k = 0; k < 4; k++) {
						check(i, j, k);
						if (flag == false)
							return;
					}
				}
			}
		}
		if (flag == true) {
			ans = true;
			return;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (hall[i][j] == 'X') {
				hall[i][j] = 'O';
				cnt++;
				start();
				hall[i][j] = 'X';
				cnt--;
			}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> hall[i][j];

	start();
	if (ans)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';

	return 0;
}