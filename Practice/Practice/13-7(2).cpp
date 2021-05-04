#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int n, a[50][50], united[50][50], l, r, ans = 0;
int dir_x[4] = { 0, 0, 1, -1 };
int dir_y[4] = { 1, -1, 0, 0 };

void start(int p,int q, int u_num) {
	queue<pair<int, int>> que;
	vector<pair<int, int>> same_united;
	united[p][q] = u_num;
	que.push({ p, q });

	same_united.push_back({ p, q });
	int sum = a[p][q];
	int united_cnt = 1;

	while (!que.empty()) {
		int x = que.front().first;
		int y = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dir_x[i];
			int ny = y + dir_y[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < n && united[nx][ny] == -1) {
				if (abs(a[x][y] - a[nx][ny]) >= l && abs(a[x][y] - a[nx][ny]) <= r) {
					sum += a[nx][ny];
					united_cnt++;
					united[nx][ny] = u_num;
					same_united.push_back({ nx, ny });
					que.push({ nx, ny });
				}
			}
		}
	}
	for (int i = 0; i < same_united.size(); i++)
		a[same_united[i].first][same_united[i].second] = sum / united_cnt;
}

int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];


	while (1) {
		int u_num = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				united[i][j] = -1;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (united[i][j] == -1) {
					start(i, j, u_num);
					u_num++;
				}
			}
		}
		if (u_num == n * n) break;
		ans++;
	}


	cout << ans << '\n';

	return 0;
}