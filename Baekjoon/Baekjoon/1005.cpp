#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int T, n, k, w;

int main() {

	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		cin >> n >> k;

		vector<pair<int, int>> infor(n + 1, { 0, 0 }); // n번째 건물의 건설시간, 직전에 건설되어야 하는 건물의 개수를 pair로 묶음
		vector<vector<int>> order(n + 1); // a건물을 지어야 b건물을 지을 수 있으면 order[a]에 b를 push_back 함
		vector<int> ans(n + 1, 0); // n번째 건물이 건설되기 위한 최소시간
		queue<int> q; // 위상정렬을 위한 queue

		for (int i = 1; i <= n; i++) {
			int temp;
			cin >> temp;
			infor[i].first = temp;
		}
		for (int i = 0; i < k; i++) {
			int first, second;
			cin >> first >> second;
			order[first].push_back(second);
			infor[second].second++;
		}
		cin >> w;

		for (int i = 1; i <= n; i++) {
			if (infor[i].second == 0) {
				q.push(i);
				ans[i] = infor[i].first; // 선행건물이 없을 경우 i번째 건물의 건설시간이 최소 건설시간
			}				
		}
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int i = 0; i < order[now].size(); i++) {
				int target = order[now][i];
				ans[target] = max(ans[target], ans[now] + infor[target].first); // target 건물의 현재 최소 건설시간보다 선행건물의 건설시간이 길다면 긴것으로 갱신
				infor[target].second--;
				if (infor[target].second == 0) 
					q.push(target);				
			}
		}
		cout << ans[w] << '\n';
	}

	return 0;
}