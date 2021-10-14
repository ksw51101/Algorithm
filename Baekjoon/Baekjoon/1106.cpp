#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int c, n, dp[1001]; // dp[a] : 고객이 a명일 때 필요한 돈의 최솟값
vector<pair<int, int>> vec;

int solution(int num) {
	if (num <= 0) // 고객이 c명이상이므로 return 0
		return 0;

	if (dp[num] > 0) // 이미 최솟값이 구해져 있으므로 사용
		return dp[num];

	int m = 100 * 1000;
	int cost;
	for (auto temp : vec) {
		cost = solution(num - temp.second) + temp.first;
		m = m < cost ? m : cost;
	}
	dp[num] = m;

	return m;
}

int main() {
	cin >> c >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		vec.emplace_back(a, b);
	}

	cout << solution(c) << '\n';
	

	return 0;
}