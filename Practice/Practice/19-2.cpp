#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 0;
int dx[] = {0, -1,-1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

struct fish_pos {
	int dir;
	int x;
	int y;
	bool alive;
};

bool cango(struct fish_pos fish, int map[][4]) {
	int nx = fish.x + dx[fish.dir];
	int ny = fish.y + dy[fish.dir];
	if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4 || map[nx][ny]==-1)
		return false;
	return true;
}

void move_fish(int map[][4], struct fish_pos *fish) {
	for (int i = 1; i <= 16; i++) {
		if (!fish[i].alive) continue;
		int cnt = 0;
		bool flag = true;
		while (!cango(fish[i], map)) {
			fish[i].dir++;
			if (fish[i].dir == 9)
				fish[i].dir = 1;
			cnt++;
			if (cnt == 8) {
				flag = false;
				break;
			}
		}
		if (!flag) continue;
		int targetx = fish[i].x + dx[fish[i].dir];
		int targety = fish[i].y + dy[fish[i].dir];
		int target_fish = map[targetx][targety];
		if (target_fish == 0) {
			map[fish[i].x][fish[i].y] = 0;
			fish[i].x = targetx;
			fish[i].y = targety;
			map[fish[i].x][fish[i].y] = i;
		}
		else {
			fish_pos temp = fish[i];
			map[fish[i].x][fish[i].y] = target_fish;
			fish[i].x = fish[target_fish].x;
			fish[i].y = fish[target_fish].y;
			fish[target_fish].x = temp.x;
			fish[target_fish].y = temp.y;
			map[fish[i].x][fish[i].y] = i;
		}
	}

}

vector<pair<int, int>> move_shark(int x, int y, int dir, int map[][4]) {
	vector<pair<int, int>> temp;
	while (!(x < 0 || y < 0 || x >= 4 || y >= 4)) {
		if (map[x][y] != 0 && map[x][y] != -1)
			temp.push_back({ x, y });
		x += dx[dir];
		y += dy[dir];
	}
	return temp;
}

void DFS(int x, int y, int dir, int score, int (*map)[4], struct fish_pos *fish) {
	int c_map[4][4];
	fish_pos c_fish[17];
	move_fish(map, fish);
	vector<pair<int, int>> target = move_shark(x, y, dir, map);
	if (target.empty()) {
		ans = max(score, ans);
		return;
	}
	for (int i = 0; i < target.size(); i++) {
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				c_map[i][j] = map[i][j];
		for (int i = 1; i <= 16; i++)
			c_fish[i] = fish[i];
		int target_fish = c_map[target[i].first][target[i].second];
		c_fish[target_fish].alive = false;
		c_map[x][y] = 0;
		c_map[target[i].first][target[i].second] = -1;
		DFS(target[i].first, target[i].second, fish[target_fish].dir, score + target_fish, c_map, c_fish);
	}
}

int main() {
	int map[4][4];
	struct fish_pos fish[17];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;
			map[i][j] = a;
			fish[a] = { b, i, j, true };
		}
	}
	fish[map[0][0]].alive = false;
	int score = map[0][0];
	int s_dir = fish[map[0][0]].dir;
	map[0][0] = -1;
	DFS(0, 0, s_dir, score, map, fish);

	cout << ans << '\n';

	return 0;
}
