#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 987654321

int n, p, ans = INF;
int d[1 << 16];
vector<vector<int>> vec;

int minCost(int num1, int num2) {
	int cost = 51;

	for (int i = 0; i < n; i++) {
		if ((1 << i) & num1) {
			cost = min(cost, vec[i][num2]);
		}
	}
	return cost;
}

int bit_Count(int B)
{
	int Cnt = 0;
	while (B != 0)
	{
		Cnt = Cnt + (B & 1);
		B = B >> 1;
	}
	return Cnt;
}


void DFS(int s) {
	if (d[s] > ans) return;
	if (bit_Count(s) >= p) {
		ans = min(ans, d[s]);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!((1 << i) & s) && d[s | (1 << i)] > d[s] + minCost(s, i)) {
			int ns = s | (1 << i);
			d[ns] = min(d[ns], d[s] + minCost(s, i));
			DFS(ns);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n;
	fill(&d[0], &d[1 << 16], INF);

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
	d[state] = 0;
	cin >> p;

	if (!cnt && p != 0)
		ans = -1;
	else
		DFS(state);

	cout << ans << '\n';

	return 0;
}