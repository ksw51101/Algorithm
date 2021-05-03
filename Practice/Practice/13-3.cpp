#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, arr[201][201], s, x, y, cnt = 0;

void increase(int v_num, int v_x, int v_y) {
	if (v_x <= 0 || v_x > n || v_y <= 0 || v_y > n)
		return;
	else if (arr[v_x][v_y] == 0)
		arr[v_x][v_y] = v_num;
}

void start() {
	vector<pair<int, pair<int, int>>> pos;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int q = 1; q <= k; q++)
				if (arr[i][j] == q)
					pos.push_back({ q, {i, j} });
		}
	}
	sort(pos.begin(), pos.end());
	for (int i = 0; i < pos.size(); i++) {
		increase(pos[i].first, pos[i].second.first - 1, pos[i].second.second);
		increase(pos[i].first, pos[i].second.first + 1, pos[i].second.second);
		increase(pos[i].first, pos[i].second.first, pos[i].second.second - 1);
		increase(pos[i].first, pos[i].second.first, pos[i].second.second + 1);
	}
}

int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	cin >> s >> x >> y;

	for (int i = 0; i < s; i++)
		start();

	cout << arr[x][y] << '\n';

	return 0;
}