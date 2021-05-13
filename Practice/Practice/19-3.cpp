#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct shark_state {
	int dir;
	int x;
	int y;
	int alive;
};

int n, m, k, map[20][20], priority[401][4][4], time = 0, remain;
int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, -1, 1 };
pair<int, int> scent[20][20];
struct shark_state shark[401];

void make_scent() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] != 0) {
				scent[i][j] = { map[i][j], k };
			}
		}
	}
}

void move() {
	for (int i = 1; i <= m; i++) {
		if (!shark[i].alive) continue;
		int save_dir = 0;
		bool flag = false;
		for (int j = 0; j < 4; j++) {
			int dir = priority[i][shark[i].dir - 1][j];
			int nx = shark[i].x + dx[dir];
			int ny = shark[i].y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (scent[nx][ny].first != 0) {
				if (save_dir == 0 && scent[nx][ny].first==i)
					save_dir = dir;
				continue;
			}
			else {
				flag = true;
				if (map[nx][ny] != 0) {
					remain--;
					if (map[nx][ny] < i) {
						shark[i].alive = false;
						map[shark[i].x][shark[i].y] = 0;
					}
					else {
						shark[map[nx][ny]].alive = false;
						map[shark[i].x][shark[i].y] = 0;
						map[nx][ny] = i;
					}
				}
				else {
					map[nx][ny] = i;
					map[shark[i].x][shark[i].y] = 0;
				}
				shark[i].x = nx;
				shark[i].y = ny;
				shark[i].dir = dir;
				break;
			}
		}
		if (!flag) {
			int dir = save_dir;
			int nx = shark[i].x + dx[dir];
			int ny = shark[i].y + dy[dir];
			map[shark[i].x][shark[i].y] = 0;
			map[nx][ny] = i;
			shark[i].x = nx;
			shark[i].y = ny;
			shark[i].dir = dir;
		}
	}
}

void scent_reduce() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (scent[i][j].first != 0) {
				scent[i][j].second--;
				if (scent[i][j].second == 0)
					scent[i][j].first = 0;
			}
}

void solution() {
	remain = m;
	make_scent();
	while (1) {
		time++;
		move();
		scent_reduce();
		make_scent();

		if (time > 1000) {
			cout << -1 << '\n';
			break;
		}
		if (remain == 1) {
			cout << time << '\n';
			break;
		}
	}

}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			scent[i][j] = { 0, 0 };
			if (map[i][j] != 0) {
				shark[map[i][j]] = { 0,i,j,true };
			}
		}
	for (int i = 1; i <= m; i++) {
		cin >> shark[i].dir;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < 4; j++)
			for (int l = 0; l < 4; l++)
				cin >> priority[i][j][l];
	}

	solution();


	return 0;
}