#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define inf 100000000
using namespace std;

typedef pair<int, int> p;

int n, m, c;
vector<p> graph[30001];
int d[30001];

void go(int start) {
	priority_queue<p> pq;
	pq.push({ 0, start });
	d[start] = 0;

	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (dist > d[now]) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int cost = dist + graph[now][i].second;
			if (cost < d[graph[now][i].first]) {
				d[graph[now][i].first] = cost;
				pq.push({ -cost, graph[now][i].first });
			}
		}
	}
}

int main() {
	cin >> n >> m >> c;

	fill(d, d + 30001, inf);
	for (int i = 1; i <= m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		graph[a].push_back({ b, t });
	}

	int max_time = 0, cnt = 0;
	go(c);

	for (int i = 1; i <= n; i++) {
		max_time = max(max_time, d[i]);
		if (d[i] != inf)
			cnt++;
	}
	cout << cnt - 1 << ' ' << max_time << '\n';

	return 0;
}