#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int c, n, dp[1001]; // dp[a] : ���� a���� �� �ʿ��� ���� �ּڰ�
vector<pair<int, int>> vec;

int solution(int num) {
	if (num <= 0) // ���� c���̻��̹Ƿ� return 0
		return 0;

	if (dp[num] > 0) // �̹� �ּڰ��� ������ �����Ƿ� ���
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