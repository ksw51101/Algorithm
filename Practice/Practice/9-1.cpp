#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define inf 100000000

vector<pair<int, int>> graph[1001];
int d[1001];

void go(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	d[start] = 0;

	while (!pq.empty()) {
		int dis = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (dis > d[now])
			continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int cost = dis + graph[now][i].second;
			if (cost < d[graph[now][i].first]) {
				d[graph[now][i].first] = cost;
				pq.push({ -cost, graph[now][i].first });
			}
		}
	}
}

int main() {
	int a, b, c, n, m, start;
	cin >> n >> m >> start;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}
	fill(d, d + 1001, inf);

	go(start);

	for (int i = 1; i <= n; i++)
		if (d[i] == inf)
			cout << "갈 수 없습니다." << '\n';
		else
			cout << d[i] << '\n';
	
	return 0;
}
