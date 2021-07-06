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

		vector<pair<int, int>> infor(n + 1, { 0, 0 }); // n��° �ǹ��� �Ǽ��ð�, ������ �Ǽ��Ǿ�� �ϴ� �ǹ��� ������ pair�� ����
		vector<vector<int>> order(n + 1); // a�ǹ��� ����� b�ǹ��� ���� �� ������ order[a]�� b�� push_back ��
		vector<int> ans(n + 1, 0); // n��° �ǹ��� �Ǽ��Ǳ� ���� �ּҽð�
		queue<int> q; // ���������� ���� queue

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
				ans[i] = infor[i].first; // ����ǹ��� ���� ��� i��° �ǹ��� �Ǽ��ð��� �ּ� �Ǽ��ð�
			}				
		}
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int i = 0; i < order[now].size(); i++) {
				int target = order[now][i];
				ans[target] = max(ans[target], ans[now] + infor[target].first); // target �ǹ��� ���� �ּ� �Ǽ��ð����� ����ǹ��� �Ǽ��ð��� ��ٸ� ������� ����
				infor[target].second--;
				if (infor[target].second == 0) 
					q.push(target);				
			}
		}
		cout << ans[w] << '\n';
	}

	return 0;
}