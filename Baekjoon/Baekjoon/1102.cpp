#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 987654321

int n, p, ans = INF;
int d[1 << 16]; // bitmask ���
vector<vector<int>> vec;

// state ���¿��� num��° �����Ҹ� �Ѵµ� �ʿ��� �ּ� cost�� ���ϴ� �Լ�
int minCost(int state, int num) {
	int cost = 51;

	for (int i = 0; i < n; i++) {
		if ((1 << i) & state) {
			cost = min(cost, vec[i][num]);
		}
	}
	return cost;
}

// state���� ��Ʈ 1�� ������ ���ϴ� �Լ�
int bit_Count(int state) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if ((1 << i) & state)
			cnt++;
	}
	return cnt;
}

// �켱���� ť���� �������� ������ ���� ����ü
struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a > b;
	}
};

int main() {
	cin >> n;
	fill(&d[0], &d[1 << 16], INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;

	for (int i = 0; i < n; i++) {
		vector<int> temp(n);
		for (int j = 0; j < n; j++) {
			cin >> temp[j];
		}
		vec.push_back(temp);
	}
	int state = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		char temp;
		cin >> temp;
		if (temp == 'Y') {
			state = state | (1 << i);
			cnt++;
		}
	}
	q.push({0, state}); // �ʱ��� 0�� ���� state�� push
	d[state] = 0;
	cin >> p;

	if (!cnt && p != 0) // p���� �����Ҹ� �� �� ���� ��Ȳ
		ans = -1;
	else {
		while (!q.empty()) {
			int s = q.top().second;
			int cost = q.top().first;
			q.pop();

			if (bit_Count(s) >= p && ans > cost) { // �����ִ� �����Ұ� p�� �̻��̰� �� ���� cost�� �ּҶ�� ans ����
				ans = cost;
			}
			for (int i = 0; i < n; i++) { // �����ִ� �����Ҹ� ã�� ������ state���� �� �����Ҹ� �Ѵµ� �ʿ��� �ּ� cost�� ���ؼ� push
				if (!((1 << i) & s) && d[s | (1 << i)] > cost + minCost(s, i)) {
					d[s | (1 << i)] = cost + minCost(s, i);
					q.push({ d[s | (1 << i)], s | (1 << i) });
				}
			}
		}
	}
	cout << ans << '\n';

	return 0;
}