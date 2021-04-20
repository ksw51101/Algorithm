#include <iostream>
using namespace std;

int n, m, x, y, dir, cnt = 1, map[51][51];

void manual_1() {
	dir--;
	if (dir == -1)
		dir = 3;
}

bool manual_2() {
	switch (dir) {
	case 0:
		if (map[x - 1][y] == 0) {
			map[x - 1][y] = 2;
			cnt++;
			x--;
			return true;
		}
		return false;
	case 1:
		if (map[x][y + 1] == 0) {
			map[x][y + 1] = 2;
			cnt++;
			y++;
			return true;
		}
		return false;
	case 2:
		if (map[x + 1][y] == 0) {
			map[x + 1][y] = 2;
			cnt++;
			x++;
			return true;
		}
		return false;
	case 3:
		if (map[x][y - 1] == 0) {
			map[x][y - 1] = 2;
			cnt++;
			y--;
			return true;
		}
		return false;
	}
}

bool manual_3() {
	switch (dir) {
	case 0:
		if (map[x + 1][y] == 1)
			return false;
		else {
			x++;
			return true;
		}
	case 1:
		if (map[x][y - 1] == 1)
			return false;
		else {
			y--;
			return true;
		}
	case 2:
		if (map[x - 1][y] == 1)
			return false;
		else {
			x--;
			return true;
		}
	case 3:
		if (map[x][y + 1] == 1)
			return false;
		else {
			y++;
			return true;
		}
	}
}

int main() {
	cin >> n >> m;

	fill(&map[0][0], &map[51][52], 1);

	cin >> x >> y >> dir;
	x++;
	y++;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];

	map[x][y] = 2;
	while (1) {
		if (!(map[x - 1][y] == 0) && !(map[x + 1][y] == 0) && !(map[x][y - 1] == 0) && !(map[x][y + 1] == 0)) {
			if (!manual_3())
				break;
			else
				continue;
		}
		manual_1();
		if (!manual_2())
			continue;
	}
	cout << cnt << '\n';

	return 0;
}