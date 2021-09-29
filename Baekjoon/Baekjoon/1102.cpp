#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 987654321

int n, p, ans = INF;
int d[1 << 16]; // bitmask 사용
vector<vector<int>> vec;

// state 상태에서 num번째 발전소를 켜는데 필요한 최소 cost를 구하는 함수
int minCost(int state, int num) {
	int cost = 51;

	for (int i = 0; i < n; i++) {
		if ((1 << i) & state) {
			cost = min(cost, vec[i][num]);
		}
	}
	return cost;
}

// state에서 비트 1의 개수를 구하는 함수
int bit_Count(int state) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if ((1 << i) & state)
			cnt++;
	}
	return cnt;
}

// 우선순위 큐에서 오름차순 정렬을 위한 구조체
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
	q.push({0, state}); // 초기비용 0과 현재 state를 push
	d[state] = 0;
	cin >> p;

	if (!cnt && p != 0) // p개의 발전소를 켤 수 없는 상황
		ans = -1;
	else {
		while (!q.empty()) {
			int s = q.top().second;
			int cost = q.top().first;
			q.pop();

			if (bit_Count(s) >= p && ans > cost) { // 켜져있는 발전소가 p개 이상이고 이 때의 cost가 최소라면 ans 갱신
				ans = cost;
			}
			for (int i = 0; i < n; i++) { // 꺼져있는 발전소를 찾아 현재의 state에서 그 발전소를 켜는데 필요한 최소 cost를 더해서 push
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