#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int n, arr[20][20], s_size = 2, time = 0, x, y, eat = 0;
bool visited[20][20];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

struct compare {
	bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
		if (a.first == b.first) {
			if (a.second.first == b.second.first) {
				return a.second.second > b.second.second;
			}
			return a.second.first > b.second.first;
		}
		return a.first > b.first;
	}
};

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				x = i;
				y = j;
				arr[i][j] = 0;
			}
		}

	while (true) {
		priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare> pq;
		fill(&visited[0][0], &visited[19][20], false);
		queue<pair<int, pair<int, int>>> q;
		visited[x][y] = true;
		q.push({ 0, {x, y } });
		while (!q.empty()) {
			int dist = q.front().first;
			int now_x = q.front().second.first;
			int now_y = q.front().second.second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int cost = dist + 1;
				int n_x = now_x + dx[i];
				int n_y = now_y + dy[i];
				if (n_x < 0 || n_y<0 || n_x >= n || n_y >= n || arr[n_x][n_y]>s_size || visited[n_x][n_y])
					continue;
				visited[n_x][n_y] = true;
				q.push({ cost, { n_x, n_y } });
				if (arr[n_x][n_y] > 0 && arr[n_x][n_y] < s_size) {
					pq.push({ cost, {n_x, n_y} });
				}
			}
		}
		if (!pq.empty()) {
			time += pq.top().first;
			eat++;
			if (eat == s_size) {
				eat = 0;
				s_size++;
			}
			x = pq.top().second.first;
			y = pq.top().second.second;
			arr[x][y] = 0;
		}
		else {
			cout << time << '\n';
			break;
		}
	}

	return 0;
}
