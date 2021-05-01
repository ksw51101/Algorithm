#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define inf 1000000000
using namespace std;

int n, m, k, x;
vector<int> vec[300001];
int d[300001];

void start(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	d[start] = 0;
	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (dist > d[now]) continue;
		for (int i = 0; i < vec[now].size(); i++) {
			int cost = dist + 1;
			if (d[vec[now][i]] > cost) {
				d[vec[now][i]] = cost;
				pq.push({ -cost, vec[now][i] });
			}
		}
	}
}


int main() {
	cin >> n >> m >> k >> x;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
	}
	fill(d, d + 300001, inf);
	start(x);

	bool flag = false;
	for (int i = 1; i <= n; i++) {
		if (d[i] == k) {
			cout << i << '\n';
			flag = true;
		}
	}
	if (flag == false)
		cout << -1 << '\n';
	return 0;
}