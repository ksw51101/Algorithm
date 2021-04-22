#include <iostream>
#include <vector>
#include <queue>
#define inf 9999999
using namespace std;

typedef pair<int, int> p;
int n, m, x, k;
vector<p> link[101];

int solve(int start, int des) {
	int d[101];
	priority_queue<p> pq;

	fill(d, d + 101, inf);
	d[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (dist > d[now]) continue;

		for (int i = 0; i < link[now].size(); i++) {
			int cost = dist + 1;
			if (cost < d[link[now][i].first]) {
				d[link[now][i].first] = cost;
				pq.push({-cost, link[now][i].first });
			}
		}
	}
	return d[des];
}

int main() {
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		link[a].push_back({ b, 1 });
		link[b].push_back({ a, 1 });
	}
	cin >> x >> k;

	int ans = solve(1, k) + solve(k, x);
	if (ans >= inf)
		cout << -1 << '\n';
	else
		cout << ans << '\n';

	return 0;
}