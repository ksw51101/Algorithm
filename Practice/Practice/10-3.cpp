#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, time[501], indegree[501], max_time[501];
vector<int> vec[501];
queue<int> que;

void start() {
	for (int i = 1; i <= n; i++) {
		max_time[i] = time[i];
		if (indegree[i] == 0) {
			que.push(i);
		}
	}
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		for (int i = 0; i < vec[now].size(); i++) {
			indegree[vec[now][i]]--;
			if (indegree[vec[now][i]] == 0)
				que.push(vec[now][i]);
			max_time[vec[now][i]] = max(max_time[vec[now][i]], max_time[now] + time[vec[now][i]]);
		}
	}
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int t, temp;
		cin >> t;
		time[i] = t;
		while (1) {
			cin >> temp;
			if (temp == -1) break;
			indegree[i]++;
			vec[temp].push_back(i);
		}
	}

	start();

	for (int i = 1; i <= n; i++)
		cout << max_time[i] << '\n';

	return 0;
}