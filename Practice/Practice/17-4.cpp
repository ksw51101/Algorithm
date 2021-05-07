#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 1000000000

int n, m, d[20000];
vector<pair<int, int>> graph[20000];

int main() {
	cin >> n >> m;

	fill(&d[0], &d[n], INF);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a - 1].push_back({ b - 1, 1 });
		graph[b - 1].push_back({ a - 1, 1 });
	}
	int start = 0;
	d[0] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (dist > d[now]) continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int cost = dist + graph[now][i].second;
			if (d[graph[now][i].first] > cost) {
				d[graph[now][i].first] = cost;
				pq.push({ -cost, graph[now][i].first });
			}
		}
	}
	int ans = 0, index = n, cnt = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, d[i]);
	for(int i=0;i<n;i++)
		if (d[i] == ans) {
			index = min(index, i);
			cnt++;
		}
	cout << index + 1 << ' ' << ans << ' '<< cnt << '\n';

	return 0;
}