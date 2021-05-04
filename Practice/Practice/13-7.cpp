#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, a[51][51], l, r, ans = 0;
int dir_x[4] = { 0, 0, 1, -1 };
int dir_y[4] = { 1, -1, 0, 0 };
bool visited[51][51];
vector<pair<int, int>> u[2500];

void start(int x, int y, int u_num) {
	u[u_num].push_back({ x, y });
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int d_x = x + dir_x[i];
		int d_y = y + dir_y[i];
		if (abs(a[d_x][d_y] - a[x][y]) >= l && abs(a[d_x][d_y] - a[x][y]) <= r && d_x > 0 && d_y > 0 && d_x <= n && d_y <= n && visited[d_x][d_y] == false)
			start(x + dir_x[i], y + dir_y[i], u_num);
	}
}

int main() {
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];

	
	while (1) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				visited[i][j] = false;

		int u_num = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (visited[i][j] == false) {
					start(i, j, u_num);
					u_num++;
				}
		for (int i = 0; i < u_num; i++) {
			int sum = 0;
			for (int j = 0; j < u[i].size(); j++) {
				sum += a[u[i][j].first][u[i][j].second];
			}
			sum /= u[i].size();
			for (int j = 0; j < u[i].size(); j++) {
				a[u[i][j].first][u[i][j].second] = sum;
			}
		}
		if (u_num == n * n) break;
		ans++;
		for (int i = 0; i < u_num; i++)
			u[i].clear();
	}
	cout << ans << '\n';

	return 0;
}