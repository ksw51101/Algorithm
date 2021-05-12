#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, n, m;
vector<int> r;
int d[501];
bool graph[501][501];

bool check(int a, int b) {
	for (int i = 0; i < r.size(); i++) {
		if (r[i] == a)
			return true;
		if (r[i] == b)
			return false;
	}
}

int main() {

	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		cin >> n;
		fill(&d[0], &d[501], 0);
		fill(&graph[0][0], &graph[500][501], false);
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			r.push_back(temp);
		}
		for (int i = 0; i < r.size() - 1; i++) {
			for (int j = i + 1; j < r.size(); j++) {
				graph[r[i]][r[j]] = true;
				d[r[j]]++;
			}
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			if (graph[a][b]) {
				graph[a][b] = false;
				graph[b][a] = true;
				d[b]--;
				d[a]++;
			}
			else {
				graph[b][a] = false;
				graph[a][b] = true;
				d[a]--;
				d[b]++;
			}
		}
		queue<int> q;
		for (int i = 1; i <= n; i++)
			if (d[i] == 0)
				q.push(i);

		vector<int> ans;
		for (int i = 0; i < n; i++) {
			if (q.empty()) {
				cout << "IMPOSSIBLE" << '\n';
				break;
			}
			if (q.size() >= 2) {
				cout << "?" << '\n';
				break;
			}
			int now = q.front();
			q.pop();
			ans.push_back(now);
			for (int j = 1; j <= n; j++) {
				if (graph[now][j]) {
					graph[now][j] = false;
					d[j]--;
					if (d[j] == 0)
						q.push(j);
				}
			}
		}

		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << ' ';
		cout << '\n';
	}

	return 0;
}