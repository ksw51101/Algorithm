#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 10000000000
int T, n, arr[125][125], d[125][125];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main() {

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				cin >> arr[j][k];
		fill(&d[0][0], &d[n - 1][n], INF);

		int x = 0, y = 0;
		priority_queue<pair<int, pair<int, int>>> pq;
		pq.push({ -arr[x][y], {x, y} });
		d[x][y] = arr[x][y];
		while (!pq.empty()) {
			int dist = -pq.top().first;
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			pq.pop();
			if (dist > d[x][y]) continue;
			for (int j=0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n)
					continue;
				int cost = dist + arr[nx][ny];
				if (cost < d[nx][ny]) {
					d[nx][ny] = cost;
					pq.push({ -cost, {nx, ny} });
				}
			}
		}
		cout << d[n - 1][n - 1] << '\n';
	}

	return 0;
}