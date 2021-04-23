#include <iostream>
#include <queue>
using namespace std;

int n, k, l, map[101][101] = { 0, }, dir = 0;
queue<pair<int, char>> q;
queue<pair<int, int>> pos;

bool check_apple(int x, int y) {
	if (map[x][y] == 3)
		return true;
	else
		return false;
}

bool check(int x, int y) {
	if (map[x][y] == 1 || x < 1 || x > n || y < 1 || y > n)
		return false;
	if (check_apple(x, y)) {
		map[pos.back().first][pos.back().second] = 1;
		map[x][y] = 2;
		pos.push({ x, y });
	}
	else {
		map[pos.back().first][pos.back().second] = 1;
		map[x][y] = 2;
		map[pos.front().first][pos.front().second] = 0;
		pos.pop();
	}
	return true;
}

int start(int x, int y) {
	int time = 0;
	while (1) {
		pos.push({ x, y });
		if (time == q.front().first) {
			if (q.front().second == 'L') {
				dir++;
				if (dir == 4)
					dir = 0;
			}
			else {
				dir--;
				if (dir == -1)
					dir = 3;
			}
			q.pop();
		}
		switch (dir) {
		case 0:
			y++;
			if (!check(x, y))
				return time;
			break;
		case 1:
			x--;
			if (!check(x, y))
				return time;
			break;
		case 2:
			y--;
			if (!check(x, y))
				return time;
			break;
		case 3:
			x++;
			if (!check(x, y))
				return time;
			break;
		}
		time++;
	}
}


int main() {
	cin >> n >> k;

	map[1][1] = 2;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y] = 3;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int t;
		char d;
		cin >> t >> d;
		q.push({ t, d });
	}
	cout << start(1, 1) << '\n';

	return 0;
}